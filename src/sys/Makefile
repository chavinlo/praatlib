# Makefile of the library "sys"
# Paul Boersma, April 12, 2008

include ../makefile.defs
CFLAGS = -I ../num -I ../sys -I ../dwsys -I ../kar -I ../audio -I ../FLAC -I ../mp3

OBJECTS = enum.o abcio.o lispio.o complex.o \
   melder_ftoa.o melder_atof.o melder_error.o melder_alloc.o melder.o melder_strings.o \
   melder_token.o melder_files.o melder_audio.o melder_audiofiles.o \
   melder_debug.o melder_sysenv.o melder_info.o melder_quantity.o \
   melder_encodings.o melder_console.o melder_time.o \
   Thing.o Data.o Simple.o Collection.o Strings.o \
   Graphics.o Graphics_linesAndAreas.o Graphics_text.o Graphics_colour.o \
   Graphics_image.o Graphics_mouse.o Graphics_record.o \
   Graphics_utils.o Graphics_grey.o Graphics_altitude.o \
   GraphicsPostscript.o Graphics_surface.o \
   ManPage.o ManPages.o Script.o machine.o \
   GraphicsScreen.o Printer.o \
   Preferences.o site.o \
   Picture.o Ui.o UiFile.o Editor.o DataEditor.o HyperPage.o Manual.o TextEditor.o \
   praat.o praat_actions.o praat_menuCommands.o praat_picture.o sendpraat.o sendsocket.o \
   praat_script.o praat_statistics.o praat_logo.o \
   praat_objectMenus.o InfoEditor.o ScriptEditor.o ButtonEditor.o Interpreter.o Formula.o \
   StringsEditor.o \
   motifEmulator.o GuiText.o GuiWindow.o Gui.o GuiObject.o GuiDrawingArea.o \
   GuiMenu.o GuiButton.o GuiLabel.o GuiCheckButton.o GuiRadioButton.o \
   GuiDialog.o GuiRowColumn.o GuiList.o

all: libsys.a
libsys.a: $(OBJECTS)
	touch libsys.a
	rm libsys.a
	ar cq libsys.a $(OBJECTS)
	$(RANLIB) libsys.a

$(OBJECTS): *.h ../num/NUM.h ../dwsys/*.h ../kar/*.h ../audio/*.h ../FLAC/*.h ../mp3/mp3.h
