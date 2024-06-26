#ifndef _FunctionEditor_h_
#define _FunctionEditor_h_
/* FunctionEditor.h
 *
 * Copyright (C) 1992-2007 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * pb 2007/09/21
 */

#ifndef _Editor_h_
	#include "Editor.h"
#endif
#ifndef _Graphics_h_
	#include "Graphics.h"
#endif
#ifndef _Function_h_
	#include "Function.h"
#endif

struct FunctionEditor_picture {
	/* KEEP IN SYNC WITH PREFS. */
	bool garnish;
};

#define FunctionEditor_members Editor_members \
	/* Subclass may change the following attributes, */ \
	/* but has to respect the invariants, */ \
	/* and has to call FunctionEditor_marksChanged () */ \
	/* immediately after making the changes. */ \
	double tmin, tmax, startWindow, endWindow; \
	double startSelection, endSelection; /* Markers. */ \
		/* These attributes are all expressed in seconds. Invariants: */ \
		/*    tmin <= startWindow < endWindow <= tmax; */	 \
		/*    tmin <= (startSelection, endSelection) <= tmax; */ \
	double arrowScrollStep; \
	\
	Graphics graphics;   /* Used in the 'draw' method. */ \
	short width, height;   /* Size of drawing area in pixels. */ \
	Widget text;   /* Optional text at top. */ \
	int shiftKeyPressed;   /* Information for the 'play' method. */ \
	int playingCursor, playingSelection;   /* Information for end of play. */ \
	struct FunctionEditor_picture picture; \
	\
	/* Private attributes: */ \
	Widget drawingArea, scrollBar, groupButton, bottomArea; \
	bool group, enableUpdates; \
	int nrect; \
	struct { double left, right, bottom, top; } rect [8]; \
	double marker [1 + 3], playCursor; \
	int numberOfMarkers;

#define FunctionEditor_methods Editor_methods \
	void (*draw) (I); \
	void (*prepareDraw) (I);   /* For less flashing. */ \
	const wchar_t *format_domain, *format_short, *format_long, *format_units, *format_totalDuration, *format_window, *format_selection; \
	int fixedPrecision_long; \
	int hasText; \
	void (*play) (I, double tmin, double tmax); \
	int (*click) (I, double xWC, double yWC, int shiftKeyPressed); \
	int (*clickB) (I, double xWC, double yWC); \
	int (*clickE) (I, double xWC, double yWC); \
	void (*key) (I, unsigned char key); \
	int (*playCallback) (I, int phase, double tmin, double tmax, double t); \
	void (*updateText) (I); \
	void (*prefs_addFields) (I, EditorCommand cmd); \
	void (*prefs_setValues) (I, EditorCommand cmd); \
	void (*prefs_getValues) (I, EditorCommand cmd); \
	void (*createMenuItems_file_draw) (I, EditorMenu menu); \
	void (*createMenuItems_file_extract) (I, EditorMenu menu); \
	void (*createMenuItems_file_write) (I, EditorMenu menu); \
	void (*createMenuItems_view) (I, EditorMenu menu); \
	void (*createMenuItems_view_timeDomain) (I, EditorMenu menu); \
	void (*createMenuItems_view_audio) (I, EditorMenu menu); \
	void (*highlightSelection) (I, double left, double right, double bottom, double top); \
	void (*unhighlightSelection) (I, double left, double right, double bottom, double top); \
	double (*getBottomOfSoundAndAnalysisArea) (I); \
	void (*form_pictureSelection) (I, EditorCommand cmd); \
	void (*ok_pictureSelection) (I, EditorCommand cmd); \
	void (*do_pictureSelection) (I, EditorCommand cmd);

class_create (FunctionEditor, Editor);

/*
	Attributes:
		data: must be a Function.

	Methods:

	void draw (I);
		"draw your part of the data between startWindow and endWindow."

	void play (I, double tmin, double tmax);
		"user clicked in one of the rectangles above or below the data window."

	int click (I, double xWC, double yWC, int shiftKeyPressed);
		"user clicked in data window with the left (Mac: only) mouse button."
		'xWC' is the time; 'yWC' is a value between 0.0 (bottom) and 1.0 (top).
		'shiftKeyPressed' flags if the Shift key was held down during the click.
		Return FunctionEditor_UPDATE_NEEDED if you want a window update, i.e.,
			if your 'click' moves the cursor or otherwise changes the appearance of the data.
		Return FunctionEditor_NO_UPDATE_NEEDED if you do not want a window update, e.g.,
			if your 'click' method just 'plays' something or puts a dialog on the screen.
			In the latter case, the 'ok' callback of the dialog should
			call FunctionEditor_marksChanged if necessary.
		FunctionEditor::click moves the cursor to 'xWC', drags to create a selection, 
			or extends the selection.

	int clickB (I, double xWC, double yWC);
		"user clicked in data window with the middle mouse button (Mac: control- or option-click)."
		'xWC' is the time; 'yWC' is a value between 0.0 (bottom) and 1.0 (top).
		For the return value, see the 'click' method.
		FunctionEditor::clickB simply moves the start of the selection (B) to 'xWC',
			with the sole statement 'my startSelection = xWC'.

	int clickE (I, double xWC, double yWC);
		"user clicked in data window with the right mouse button (Mac: command-click)."
		'xWC' is the time; 'yWC' is a value between 0.0 (bottom) and 1.0 (top).
		For the return value, see the 'click' method.
		FunctionEditor::clickB simply moves the end of the selection (E) to 'xWC',
			with the sole statement 'my endSelection = xWC'.

	void key (I, unsigned char key);
		"user typed a key to the data window."
		FunctionEditor::key ignores this message.
*/
#define FunctionEditor_UPDATE_NEEDED  1
#define FunctionEditor_NO_UPDATE_NEEDED  0

int FunctionEditor_init (I, Widget parent, const wchar_t *title, Any data);
/*
	Function:
		creates an Editor with a drawing area, a scroll bar and some buttons.
	Preconditions:
		parent != NULL;
		Thing_member (data, classFunction);
	Postconditions:
		my cursorMenu contains the following entries:
			Move cursor to B
			Move cursor to E
			Move cursor to...
			Move cursor by...
		my beginMenu contains:
			Move B to cursor
			Move B to E
			Move B to...
			Move B by...
		my endMenu contains:
			Move E to cursor
			Move E to B
			Move E to...
			Move E by...
		my drawingArea is attached to the form at all sides,
		my scrollBar only to the bottom, left and right sides.
		The other members are 0.0 or NULL.
		The inheritor should call
			'GuiObject_show (my dialog); GuiObject_show (my shell);'
			before calling FunctionEditor_open (me).
*/ 

void FunctionEditor_marksChanged (I);
/*
	Function:
		update optional text field, the scroll bar, the drawing area and the buttons,
		from the current total time, window, cursor, and selection,
		and redraw the contents. This will be done for all the editors in the group.
	Usage:
		call this after a change in any of the markers or in the duration of the data.
*/

void FunctionEditor_shift (I, double shift);
/*
	Function:
		shift (scroll) the window through time, keeping the window length constant.
	Usage:
		call this after a search.
*/

void FunctionEditor_updateText (I);
/*
	Function:
		update the optional text widget.
	Usage:
		call this after moving the cursor, if that would have to change the text.
		The generic FunctionEditor also calls this if one of the other marks have changed.
	Behaviour:
		we just call the updateText method, which the inheritor will have to modify,
		since FunctionEditor::updateText does nothing.
*/

void FunctionEditor_redraw (I);
/*
	Function:
		update the drawing area of a single editor.
	Usage:
		calls this after she changes a view option (font, scaling, hide/show xx)
		or after any of the data have changed. In the latter case, also call Editor_broadcastChange.
	Behaviour:
		we just call Graphics_updateWs (my graphics).
*/

void FunctionEditor_enableUpdates (I, int enable);
/*
	Function:
		temporarily disable update event to cause 'draw' messages.
	Usage:
		If you call from your 'draw' method routines that may trigger expose events,
		you should bracket those routines between
			FunctionEditor_enableUpdates (me, FALSE);
		and
			FunctionEditor_enableUpdates (me, TRUE);
		This may happen if you call an analysis routine which calls Melder_progress.
*/

void FunctionEditor_ungroup (I);
/*
	Function:
		force me out of the group.
	Usage:
		Start cut or paste methods by calling this routine,
		as the grouped editors will not be synchronized
		after either of those actions. Worse, the selection
		may get outside the common interval of the editors.
*/

void FunctionEditor_prefs (void);

/* Some routines to enforce common look to all function editors. */
/* The x axis of the window is supposed to have been set to [my startWindow, my endWindow]. */
/* Preconditions: default line type, default line width. */
/* Postconditions: default line type, default line width, undefined colour, undefined text alignment. */
void FunctionEditor_drawRangeMark (I, double yWC, const wchar_t *yWC_string, const wchar_t *units, int verticalAlignment);
void FunctionEditor_drawCursorFunctionValue (I, double yWC, const wchar_t *yWC_string, const wchar_t *units);
void FunctionEditor_insertCursorFunctionValue (I, double yWC, const wchar_t *yWC_string, const wchar_t *units, double minimum, double maximum);
void FunctionEditor_drawHorizontalHair (I, double yWC, const wchar_t *yWC_string, const wchar_t *units);
void FunctionEditor_drawGridLine (I, double yWC);

void FunctionEditor_insetViewport (I);

void FunctionEditor_garnish (I);   // Optionally selection times and selection hairs.

/* End of file FunctionEditor.h */
#endif
