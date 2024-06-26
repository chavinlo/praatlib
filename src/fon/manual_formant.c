/* manual_formant.c
 *
 * Copyright (C) 1992-2008 Paul Boersma
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

#include "ManPagesM.h"

void manual_formant_init (ManPages me);
void manual_formant_init (ManPages me) {

MAN_BEGIN (L"Create FormantGrid...", L"ppgb", 20080425)
INTRO (L"A command in the @@New menu@ to create an empty @FormantGrid object.")
ENTRY (L"Settings")
TAG (L"%%Start time% (s), %%End time% (s)")
DEFINITION (L"the @@time domain@ of the resulting FormantGrid.")
TAG (L"%%Number of formants% (e.g. 10)")
DEFINITION (L"the number of formants in the resulting FormantGrid. For instance, if you set this to 10, "
	"the resulting FormantGrid will contain 10 formant tiers (for F1 through F10) "
	"and 10 bandwidth tiers (for B1 through B10). Each of these 20 tiers will contain one point.")
TAG (L"%%Initial first formant% (e.g. 550 Hz)")
DEFINITION (L"the frequency value of the single formant point in the first formant tier. "
	"Because of @@constant extrapolation@, F1 will have this value throughout the time domain.")
TAG (L"%%Initial formant spacing% (e.g. 1100 Hz)")
DEFINITION (L"the difference between the frequency values of the points in adjacent formant tiers. "
	"For instance, the example values mentioned here cause F2 to be 1650 Hz throughout the time domain; "
	"F3 will be 2750 Hz, F4 will be 3850 Hz, and so on.")
TAG (L"%%Initial first bandwidth% (e.g. 60 Hz)")
DEFINITION (L"the value of the single bandwidth point in the first bandwidth tier. "
	"Because of @@constant extrapolation@, B1 will have this value throughout the time domain.")
TAG (L"%%Initial bandwidth spacing% (e.g. 50 Hz)")
DEFINITION (L"the difference between the values of the points in adjacent bandwidth tiers. "
	"For instance, the example values mentioned here cause B2 to be 110 Hz throughout the time domain; "
	"B3 will be 160 Hz, B4 will be 210 Hz, and so on.")
NORMAL (L"To add some points to it, use @@FormantGrid: Add formant point...@ and @@FormantGrid: Add bandwidth point...@.")
NORMAL (L"For more examples, see @@Source-filter synthesis@.")
MAN_END

MAN_BEGIN (L"Formant", L"ppgb", 20050427)
INTRO (L"One of the @@types of objects@ in Praat. "
	"A Formant object represents spectral structure as a function of time: a %%formant contour%. "
	"Unlike the time-stamped @FormantGrid object, it is sampled into a number of %frames centred around equally spaced times, "
	"Each frame contains frequency and bandwidth information about several formants.")
ENTRY (L"Inside a Formant object")
NORMAL (L"With @Inspect, you will see the following attributes:")
TAG (L"%xmin")
DEFINITION (L"start time, in seconds.")
TAG (L"%xmax")
DEFINITION (L"end time, in seconds.")
TAG (L"%nx")
DEFINITION (L"the number of frames (\\>_ 1).")
TAG (L"%dx")
DEFINITION (L"time step = frame length = frame duration, in seconds.")
TAG (L"%x1")
DEFINITION (L"the time associated with the first frame, in seconds. "
	"This will usually be in the range [%xmin, %xmax]. "
	"The time associated with the last frame (i.e., %x1 + (%nx \\-- 1) %dx)) "
	"will also usually be in that range.")
TAG (L"%frame__%i_, %i = 1 ... %nx")
DEFINITION (L"the frames (see below).")
ENTRY (L"Attributes of a formant frame")
NORMAL (L"Each %frame__%i_ contains the following attributes:")
TAG (L"%intensity")
DEFINITION (L"an indication of the maximum intensity (a squared sound amplitude) in this frame.")
TAG (L"%nFormants")
DEFINITION (L"the number of formants in this frame (usually between 2 and 6).")
TAG (L"%formant__%j_, %j = 1 ... %nFormants")
DEFINITION (L"the information about each formant (see below).")
ENTRY (L"Attributes of each formant")
NORMAL (L"Each %formant__%j_ contains the following attributes:")
TAG (L"%frequency")
DEFINITION (L"the formant's centre frequency (in Hz).")
TAG (L"%bandwidth")
DEFINITION (L"the formant's bandwidth (in Hz).")
ENTRY (L"See also")
NORMAL (L"##Linear Prediction#")
MAN_END

MAN_BEGIN (L"Formant: Down to FormantGrid", L"ppgb", 20080427)
INTRO (L"A command to convert every selected @Formant into a @FormantGrid.")
NORMAL (L"This performs a trivial copying of frames to points. "
	"Each formant tier and each bandwidth tier of the resulting FormantGrid contains a point for each original frame. "
	"The intensity information is lost.")
MAN_END

MAN_BEGIN (L"Formant: Draw tracks...", L"ppgb", 19980321)
INTRO (L"A command to draw the selected @Formant objects to the @@Picture window@.")
ENTRY (L"Behaviour")
NORMAL (L"Every formant value is drawn as one or two short line segments, connected, if possible, "
	"with a line segment of the corresponding formant values in the adjacent frames.")
ENTRY (L"Arguments")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the time domain of the drawing. If %%To time% is not greater than %%From time%, "
	"the entire formant contour is drawn.")
TAG (L"%%Maximum frequency% (Hz)")
DEFINITION (L"the height of the %y axis. For speech, 5000 Hz is a usual value.")
TAG (L"%%Garnish")
DEFINITION (L"determines whether axes, numbers, and texts (\"Time\", \"Formant frequency\") will be drawn in the margins around the picture. "
	"Turn this button off if you prefer to garnish your picture by yourself with the @Margins menu.")
ENTRY (L"Usage")
NORMAL (L"Unlike @@Formant: Speckle...@, this procedure assumes that e.g. the second formant in frame %i "
	"has something to do with the second formant in frame %i+1. To make this assumption more plausible, "
	"use @@Formant: Track...@ first.")
MAN_END

MAN_BEGIN (L"Formant: Formula (bandwidths)...", L"ppgb", 19980323)
INTRO (L"A command to modify each selected @Formant object with a specified formula.")
NORMAL (L"For what you can do with formulas, see @@Matrix: Formula...@. "
	"The %%i%th row contains the values of the %%i%th bandwidth contour.")
NORMAL (L"See @@Formant: Formula (frequencies)...@ for more information.")
MAN_END

MAN_BEGIN (L"Formant: Formula (frequencies)...", L"ppgb", 19981221)
INTRO (L"A command to modify each selected @Formant object with a specified formula.")
NORMAL (L"For what you can do with formulas, see @@Matrix: Formula...@. "
	"The %%i%th row contains the values of the %%i%th frequency contour.")
NORMAL (L"For an example, see @@Source-filter synthesis@.")
MAN_END

MAN_BEGIN (L"Formant: Get bandwidth at time...", L"ppgb", 19991016)
INTRO (L"A @query to the selected @Formant object for the bandwidth of the specified formant at the specified time.")
ENTRY (L"Arguments")
TAG (L"%%Formant number")
DEFINITION (L"the ordinal number of the formant, counting up from 0 Hz. Specify \"2\" for %F__2_ etc.")
TAG (L"%%Time% (s)")
DEFINITION (L"the time at which to evaluate the bandwidth.")
TAG (L"%Units")
DEFINITION (L"the units of the result (Hertz or Bark).")
ENTRY (L"Return value")
NORMAL (L"the estimated bandwidth in Hertz or Bark. "
	"If %Time is not within half a frame width of any frame centre, or "
	"If the specified %%Formant number% is greater than the number of formants in the frame, "
	"the return value is @undefined; "
	"otherwise, the formant is considered to belong to the frame whose centre is nearest to the specified time.")
ENTRY (L"Algorithm")
NORMAL (L"If possible (i.e. if the adjacent frame has enough formants), "
	"a linear interpolation is performed between the centre of the frame and the centre of the adjacent frame. "
	"With Bark units, the Hertz-to-Bark transformation is performed "
	"on the two frequencies %F \\+_ 1/2 %B (after interpolation), and the result is the difference between these two values")
MAN_END

MAN_BEGIN (L"Formant: Get maximum...", L"ppgb", 19991016)
INTRO (L"A @query to ask the selected @Formant object for the maximum value of the specified formant.")
ENTRY (L"Return value")
NORMAL (L"the maximum, in Hertz or Bark.")
ENTRY (L"Arguments")
TAG (L"%%Formant number")
DEFINITION (L"the ordinal number of the formant, counting up from 0 Hz. Specify \"2\" for %F__2_ etc.")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the selected time domain. Values outside this domain are ignored. "
	"If %%To time% is not greater than %%From time%, the entire time domain of the formant contour is considered.")
TAG (L"%Units")
DEFINITION (L"the units of the result (Hertz or Bark).")
TAG (L"%Interpolation")
DEFINITION (L"the interpolation method (none or parabolic). See @@vector peak interpolation@.")
MAN_END

MAN_BEGIN (L"Formant: Get mean...", L"ppgb", 19991016)
INTRO (L"A @query to ask the selected @Formant object for the mean value of the specified formant.")
ENTRY (L"Return value")
NORMAL (L"the mean, in Hertz or Bark.")
ENTRY (L"Arguments")
TAG (L"%%Formant number")
DEFINITION (L"the ordinal number of the formant, counting up from 0 Hz. Specify \"2\" for %F__2_ etc.")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the selected time domain. Values outside this domain are ignored. "
	"If %%To time% is not greater than %%From time%, the entire time domain of the formant contour is considered.")
TAG (L"%Units")
DEFINITION (L"the units of the result (Hertz or Bark).")
ENTRY (L"Scripting")
NORMAL (L"You can use this command to put the mean into a script variable:")
CODE (L"select Formant hallo")
CODE (L"mean = Get mean... 2 0 0 Hertz")
NORMAL (L"In this case, the value will not be written into the Info window.")
MAN_END

MAN_BEGIN (L"Formant: Get minimum...", L"ppgb", 19991016)
INTRO (L"A @query to ask the selected @Formant object for the minimum value of the specified formant.")
ENTRY (L"Return value")
NORMAL (L"the minimum, in Hertz or Bark.")
ENTRY (L"Arguments")
TAG (L"%%Formant number")
DEFINITION (L"the ordinal number of the formant, counting up from 0 Hz. Specify \"2\" for %F__2_ etc.")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the selected time domain. Values outside this domain are ignored. "
	"If %%To time% is not greater than %%From time%, the entire time domain of the formant contour is considered.")
TAG (L"%Units")
DEFINITION (L"the units of the result (Hertz or Bark).")
TAG (L"%Interpolation")
DEFINITION (L"the interpolation method (none or parabolic). See @@vector peak interpolation@.")
MAN_END

MAN_BEGIN (L"Formant: Get number of formants", L"ppgb", 19991016)
INTRO (L"A @query to ask the selected @Formant object for the number of formants in a specified frame.")
ENTRY (L"Argument")
TAG (L"%%Frame number")
DEFINITION (L"the frame number whose formant count is sought.")
ENTRY (L"Return value")
NORMAL (L"the number of formants.")
MAN_END

MAN_BEGIN (L"Formant: Get quantile...", L"ppgb", 19991016)
INTRO (L"A @query to ask the selected @Formant object for an estimation of the specified quantile of the distribution "
	"that underlies the attested values of the specified formant.")
ENTRY (L"Return value")
NORMAL (L"the quantile, in Hertz or Bark.")
ENTRY (L"Arguments")
TAG (L"%%Formant number")
DEFINITION (L"the ordinal number of the formant, counting up from 0 Hz. Specify \"2\" for %F__2_ etc.")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the selected time domain. Values outside this domain are ignored. "
	"If %%To time% is not greater than %%From time%, the entire time domain of the formant contour is considered.")
TAG (L"%Units")
DEFINITION (L"the units of the result (Hertz or Bark).")
TAG (L"%Quantile")
DEFINITION (L"the fraction (between 0 and 1) of the values of the underlying distribution expected to lie below the result. "
	"For instance, if %Quantile is 0.10, the algorithm estimates the formant value below which 10\\%  of all formant values "
	"are expected to lie. To get an estimate of the %median of the underlying distribution, specify a quantile of 0.50.")
ENTRY (L"Algorithm")
NORMAL (L"First, the available formant values within the selected time domain are collected in an array. "
	"This array is then sorted and the @@quantile algorithm@ is performed. With Bark units, "
	"the Hertz-to-Bark transformation is performed before the quantile algorithm.")
MAN_END

MAN_BEGIN (L"Formant: Get standard deviation", L"ppgb", 19991016)
INTRO (L"A @query to ask the selected @Formant object for the standard deviation of the attested values of the specified formant "
	"within a specified time domain.")
ENTRY (L"Return value")
NORMAL (L"the standard deviation, in Hertz or Bark.")
ENTRY (L"Arguments")
TAG (L"%%Formant number")
DEFINITION (L"the ordinal number of the formant, counting up from 0 Hz. Specify \"2\" for %F__2_ etc.")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the selected time domain. Values outside this domain are ignored. "
	"If %%To time% is not greater than %%From time%, the entire time domain of the formant contour is considered.")
TAG (L"%Units")
DEFINITION (L"the units of the result (Hertz or Bark).")
MAN_END

MAN_BEGIN (L"Formant: Get time of maximum...", L"ppgb", 19991016)
INTRO (L"A @query to ask the selected @Formant object for the time associated with the maximum value "
	"of a specified formant within a specified time domain.")
ENTRY (L"Argument")
TAG (L"%%Formant number")
DEFINITION (L"the ordinal number of the formant, counting up from 0 Hz. Specify \"2\" for %F__2_ etc.")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the selected time domain. Values outside this domain are ignored, except for interpolation. "
	"If %%To time% is not greater than %%From time%, the entire time domain of the formant contour is considered.")
TAG (L"%Units")
DEFINITION (L"the units of the result (Hertz or Bark).")
TAG (L"%Interpolation")
DEFINITION (L"the interpolation method (None or Parabolic). See @@vector peak interpolation@.")
ENTRY (L"Return value")
NORMAL (L"the time expressed in seconds. If no relevant formants are found, the value is @undefined.")
MAN_END

MAN_BEGIN (L"Formant: Get time of minimum...", L"ppgb", 19991016)
INTRO (L"A @query to ask the selected @Formant object for the time associated with the minimum value "
	"of a specified formant within a specified time domain.")
ENTRY (L"Argument")
TAG (L"%%Formant number")
DEFINITION (L"the ordinal number of the formant, counting up from 0 Hz. Specify \"2\" for %F__2_ etc.")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the selected time domain. Values outside this domain are ignored, except for interpolation. "
	"If %%To time% is not greater than %%From time%, the entire time domain of the formant contour is considered.")
TAG (L"%Units")
DEFINITION (L"the units of the result (Hertz or Bark).")
TAG (L"%Interpolation")
DEFINITION (L"the interpolation method (None or Parabolic). See @@vector peak interpolation@.")
ENTRY (L"Return value")
NORMAL (L"the time expressed in seconds. If no relevant formants are found, the value is @undefined.")
MAN_END

MAN_BEGIN (L"Formant: Get value at time...", L"ppgb", 19991016)
INTRO (L"A @query to ask the selected @Formant object for the frequency of the specified formant at the specified time.")
ENTRY (L"Arguments")
TAG (L"%%Formant number")
DEFINITION (L"the ordinal number of the formant, counting up from 0 Hz. Specify \"2\" for %F__2_ etc.")
TAG (L"%%Time% (s)")
DEFINITION (L"the time at which to evaluate the formant frequency.")
TAG (L"%Units)")
DEFINITION (L"the units of the result (Hertz or Bark).")
TAG (L"%%Interpolation")
DEFINITION (L"the interpolation method, see @@vector value interpolation@. "
	"Always Linear.")
ENTRY (L"Return value")
NORMAL (L"the bandwidth in Hertz or Bark. "
	"If %Time is not within half a frame width of any frame centre, or "
	"if the specified %%Formant number% is greater than the number of formants in the frame, "
	"the value is @undefined; "
	"otherwise, the formant is considered to belong to the frame whose centre is nearest to the specified time.")
ENTRY (L"Algorithm")
NORMAL (L"If possible (i.e. if the adjacent frame has enough formants), "
	"a linear interpolation is performed between the centre of the frame and the centre of the adjacent frame. "
	"With Bark units, the Hertz-to-Bark transformation is performed before interpolation.")
MAN_END

MAN_BEGIN (L"Formant: Speckle...", L"ppgb", 20030916)
INTRO (L"A command to draw the selected @Formant objects to the @@Picture window@.")
ENTRY (L"Behaviour")
NORMAL (L"Every formant value is drawn as a small circle, filled with the current colour.")
ENTRY (L"Arguments")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the time domain of the drawing. If %%To time% is not greater than %%From time%, "
	"the entire formant contour is drawn.")
TAG (L"%%Maximum frequency% (Hz)")
DEFINITION (L"the height of the %y axis. For speech, 5000 Hz is a usual value.")
TAG (L"%%Dynamic range% (dB)")
DEFINITION (L"determines the signal intensity (as stored in each formant frame) below which "
	"no formants will be drawn. If zero, all formants will be drawn. The standard value is 30 dB, "
	"which would mean that formants in frames with intensities less than the maximum intensity minus 30 dB will not be drawn.")
TAG (L"%%Garnish")
DEFINITION (L"determines whether axes, numbers, and texts (\"Time\", \"Formant frequency\") will be drawn in the margins around the picture. "
	"Turn this button off if you prefer to garnish your picture by yourself with the @Margins menu.")
MAN_END

MAN_BEGIN (L"Formant: Track...", L"ppgb", 20020308)
INTRO (L"A command to extract a specified number of formant tracks from each selected @Formant object. "
	"The tracks represent the cheapest paths through the measured formant values in consecutive frames.")
ENTRY (L"How to use")
NORMAL (L"In order to be capable of producing three tracks (i.e. F1, F2, and F3), there must be at least "
	"three formant candidates in %every frame of the Formant object. The typical use of "
	"this command, therefore, is to analyse five formants with @@Sound: To Formant (burg)...@ "
	"and then use the tracking command to extract three tracks.")
ENTRY (L"When to use, when not")
NORMAL (L"This command only makes sense if the whole of the formant contour makes sense. "
	"For speech, formant contours make sense only for vowels and the like. "
	"During some consonants, the Formant object may have fewer than three formant values, "
	"and trying to create three tracks through them will fail. "
	"You will typically use this command for the contours in diphthongs, if at all.")
ENTRY (L"Arguments")
NORMAL (L"To be able to interpret the arguments, you should know that the aim of the procedure is "
	"to minimize the sum of the %costs associated with the three tracks.")
TAG (L"%%Number of tracks")
DEFINITION (L"the number of formant tracks that the procedure must find. If this number is 3, "
	"the procedure will try to find tracks for F1, F2, and F3; if the Formant object contains "
	"a frame with less than three formants, the tracking procedure will fail.")
TAG (L"%%Reference F1% (Hertz)")
DEFINITION (L"the preferred value near which the first track wants to be. "
	"For average (i.e. adult female) speakers, this value will be around "
	"the average F1 for vowels of female speakers, i.e. 550 Hz.")
TAG (L"%%Reference F2% (Hertz)")
DEFINITION (L"the preferred value near which the second track wants to be. "
	"A good value will be around "
	"the average F2 for vowels of female speakers, i.e. 1650 Hz.")
TAG (L"%%Reference F3% (Hertz)")
DEFINITION (L"the preferred value near which the third track wants to be. "
	"A good value will be around "
	"the average F3 for vowels of female speakers, i.e. 2750 Hz. "
	"This argument will be ignored if you choose to have fewer than three tracks, "
	"i.e., if you are only interested in F1 and F2.")
TAG (L"%%Reference F4% (Hertz)")
DEFINITION (L"the preferred value near which the fourth track wants to be. "
	"A good value may be around 3850 Hz, but you will usually not want to "
	"track F4, because traditional formant lore tends to ignore it "
	"(however inappropriate this may be for the vowel [i]), "
	"and because Formant objects often contain not more than three formant values "
	"in some frames. So you will not usually specify a higher %%Number of tracks% than 3, "
	"and in that case, this argument will be ignored.")
TAG (L"%%Reference F5% (Hertz)")
DEFINITION (L"the preferred value near which the five track wants to be. "
	"In the unlikely case that you want five tracks, "
	"a good value may be around 4950 Hz.")
TAG (L"%%Frequency cost% (per kiloHertz)")
DEFINITION (L"the local cost of having a formant value in your track that deviates "
	"from the reference value. For instance, if a candidate (i.e. any formant in a frame "
	"of the Formant object) has a formant frequency of 800 Hz, "
	"and the %%Frequency cost% is 1.0/kHz, "
	"the cost of putting this formant in the first track is 0.250, "
	"because the distance to the reference F1 of 550 Hz is 250 Hz. "
	"The cost of putting the formant in the second track would be 0.850 "
	"(= (1.650 kHz - 0.600 kHz) \\.c 1.0/kHz), so we see that the procedure "
	"locally favours the inclusion of the 800 Hz candidate into the F1 track. "
	"But the next two cost factors may override this local preference.")
TAG (L"%%Bandwidth cost%")
DEFINITION (L"the local cost of having a bandwidth, relative to the formant frequency. "
	"For instance, if a candidate has a formant frequency of 400 Hz and "
	"a bandwidth of 80 Hz, and the %%Bandwidth cost% is 1.0, "
	"the cost of having this formant in any track is (80/400) \\.c 1.0 = 0.200. "
	"So we see that the procedure locally favours the inclusion of candidates "
	"with low relative bandwidths.")
TAG (L"%%Transition cost% (per octave)")
DEFINITION (L"the cost of having two different consecutive formant values in a track. "
	"For instance, if a proposed track through the candidates has two consecutive formant "
	"values of 300 Hz and 424 Hz, and the %%Transition cost% is 1.0/octave, "
	"the cost of having this large frequency jump is (0.5 octave) \\.c (1.0/octave) = 0.500.")
ENTRY (L"Algorithm")
NORMAL (L"This command uses a Viterbi algorithm with multiple planes. For instance, if the selected Formant object "
	"contains up to five formants per frame, and you request three tracks, the Viterbi algorithm will have to choose "
	"between ten candidates (the number of combinations of three out of five) for each frame.")
NORMAL (L"The formula for the cost of e.g. track 3, with proposed values %F__2%i_ (%i = 1...%N, "
	"where %N is the number of frames) is:")
FORMULA (L"\\su__%i=1..%N_ %frequencyCost\\.c\\|f%F__3%i_ \\-- %referenceF3\\|f/1000 +")
FORMULA (L"+ \\su__%i=1..%N_ %bandWidthCost\\.c%B__3%i_/%F__3%i_ +")
FORMULA (L"+ \\su__%i=1..%N-1_ %transitionCost\\.c\\|flog__2_(%F__3%i_/%F__3,%i+1_)\\|f")
NORMAL (L"Analogous formulas compute the cost of track 1 and track 2. "
	"The procedure will assign those candidates to the three tracks that minimize "
	"the sum of three track costs.")
MAN_END

MAN_BEGIN (L"FormantGrid", L"ppgb", 20080427)
INTRO (L"One of the @@types of objects@ in Praat.")
NORMAL (L"A FormantGrid object represents spectral structure as a function of time: a %%formant contour%. "
	"Unlike the evenly sampled @Formant object, it consists of a number of formant tiers and bandwidth tiers, "
	"each of which contains a number of formant or bandwidth %points (or %targets), sorted by time.")
NORMAL (L"For examples, see @@Source-filter synthesis@.")
ENTRY (L"FormantGrid commands")
NORMAL (L"Creation:")
LIST_ITEM (L"From scratch:")
LIST_ITEM (L"\\bu @@Create FormantGrid...")
LIST_ITEM (L"\\bu @@FormantGrid: Add formant point...")
LIST_ITEM (L"\\bu @@FormantGrid: Add bandwidth point...")
LIST_ITEM (L"Copy from another object:")
LIST_ITEM (L"\\bu @@Formant: Down to FormantGrid@: trivial copying of frames to points.")
//NORMAL (L"Conversion:")
//LIST_ITEM (L"\\bu @@FormantGrid: Down to PointProcess@: copy times.")
NORMAL (L"Synthesis:")
LIST_ITEM (L"\\bu @@Sound & FormantGrid: Filter@: see @@Source-filter synthesis@.")
//NORMAL (L"Queries:")
//LIST_ITEM (L"\\bu @@Get low index from time...")
//LIST_ITEM (L"\\bu @@Get high index from time...")
//LIST_ITEM (L"\\bu @@Get nearest index from time...")
NORMAL (L"Modification:")
LIST_ITEM (L"\\bu @@FormantGrid: Add formant point...")
LIST_ITEM (L"\\bu @@FormantGrid: Add bandwidth point...")
//LIST_ITEM (L"\\bu @@Remove point...")
//LIST_ITEM (L"\\bu @@Remove point near...")
LIST_ITEM (L"\\bu @@FormantGrid: Remove formant points between...")
LIST_ITEM (L"\\bu @@FormantGrid: Remove bandwidth points between...")
MAN_END

MAN_BEGIN (L"FormantGrid: Add bandwidth point...", L"ppgb", 20080425)
INTRO (L"A command to add a bandwidth point to each selected @FormantGrid.")
NORMAL (L"For examples, see @@Source-filter synthesis@.")
ENTRY (L"Settings")
TAG (L"%%Formant number")
DEFINITION (L"the number of the formant (e.g. 1, 2,...) to which a bandwidth point is to be added.")
TAG (L"%Time (s)")
DEFINITION (L"the time at which a bandwidth point is to be added.")
TAG (L"%%Bandwidth (Hz)")
DEFINITION (L"the bandwidth value of the requested new point.")
ENTRY (L"Example")
NORMAL (L"To set the bandwidth of F2 at 0.3 seconds to 130 Hz, "
	"you set %%formant number% to 2, %time to 0.3, and %bandwidth to 130.")
ENTRY (L"Behaviour")
NORMAL (L"The formant tier is modified so that it contains the new point. "
	"If a bandwidth point at the specified time was already present in the formant tier, nothing happens.")
MAN_END

MAN_BEGIN (L"FormantGrid: Add formant point...", L"ppgb", 20080425)
INTRO (L"A command to add a formant point to each selected @FormantGrid.")
NORMAL (L"For examples, see @@Source-filter synthesis@.")
ENTRY (L"Settings")
TAG (L"%%Formant number")
DEFINITION (L"the number of the formant (e.g. 1, 2,...) to which a formant point is to be added.")
TAG (L"%Time (s)")
DEFINITION (L"the time at which a formant point is to be added.")
TAG (L"%%Frequency (Hz)")
DEFINITION (L"the formant frequency value of the requested new point.")
ENTRY (L"Example")
NORMAL (L"To set the value of F2 at 0.3 seconds to 2200 Hz, "
	"you set %%formant number% to 2, %time to 0.3, and %frequency to 2200.")
ENTRY (L"Behaviour")
NORMAL (L"The formant tier is modified so that it contains the new point. "
	"If a formant point at the specified time was already present in the formant tier, nothing happens.")
MAN_END

MAN_BEGIN (L"FormantGrid: Remove bandwidth points between...", L"ppgb", 20080427)
INTRO (L"A command to remove some points from a bandwidth tier in every selected @FormantGrid.")
ENTRY (L"Settings")
TAG (L"%%Formant number")
DEFINITION (L"the formant (1, 2,...) from whose bandwidth tier you want to remove some points.")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the times between which you want to remove all bandwidth points.")
ENTRY (L"Example")
NORMAL (L"If you want to remove all bandwidth points in F2 between 0.5 and 0.7 seconds, "
	"you set %%formant number% to 2, %%from time% to 0.5, and %%to time% to 0.7.")
MAN_END

MAN_BEGIN (L"FormantGrid: Remove formant points between...", L"ppgb", 20080427)
INTRO (L"A command to remove some points from a formant tier in every selected @FormantGrid.")
ENTRY (L"Settings")
TAG (L"%%Formant number")
DEFINITION (L"the formant (1, 2,...) from which you want to remove some points.")
TAG (L"%%From time% (s), %%To time% (s)")
DEFINITION (L"the times between which you want to remove all formant points.")
ENTRY (L"Example")
NORMAL (L"If you want to remove all formant points in F2 between 0.5 and 0.7 seconds, "
	"you set %%formant number% to 2, %%from time% to 0.5, and %%to time% to 0.7.")
MAN_END

MAN_BEGIN (L"FormantTier", L"ppgb", 20080427)
INTRO (L"One of the @@types of objects@ in Praat. You are advised to use instead the much more flexible @FormantGrid, "
	"which moreover comes with an editing window. The commands that create FormantTier objects are now hidden, "
	"but they are still available in Praat scripts, for backward compatibility.")
NORMAL (L"A FormantTier object represents spectral structure as a function of time: a %%formant contour%. "
	"Unlike the evenly sampled @Formant object, it consists of a number of formant %points (or %targets), sorted by time. "
	"Each point contains contains several formant/bandwidth pairs.")
ENTRY (L"FormantTier commands")
NORMAL (L"Creation:")
LIST_ITEM (L"From scratch:")
LIST_ITEM (L"\\bu ##Create FormantTier...#: the resulting object will have the specified name and time domain, "
	"but contain no formant points. "
	"To add some points to it, use:")
LIST_ITEM (L"\\bu ##FormantTier: Add point...#: to get three formants at "
	"500, 1500, and 2500 Hz with bandwidths of 50, 100, and 150 Hz, respectively, "
	"you specify \"500 50 1500 100 2500 150\".")
LIST_ITEM (L"Copy from another object:")
LIST_ITEM (L"\\bu ##Formant: Down to FormantTier#: trivial copying of frames to points. "
	"The resulting FormantTier contains a point for each original frame. The number of formants "
	"in the result is limited to 10. The intensity information is lost.")
NORMAL (L"Conversion:")
LIST_ITEM (L"\\bu ##FormantTier: Down to PointProcess#: the times of all the formant points are trivially copied, and so is the time domain. "
	"The formant information is lost.")
NORMAL (L"Synthesis:")
LIST_ITEM (L"\\bu ##Sound & FormantTier: Filter#: comparable to @@Sound & FormantGrid: Filter@.")
LIST_ITEM (L"\\bu ##Sound & FormantTier: Filter (no scale)#: comparable to @@Sound & FormantGrid: Filter (no scale)@.")
NORMAL (L"Queries:")
LIST_ITEM (L"\\bu @@Get low index from time...")
LIST_ITEM (L"\\bu @@Get high index from time...")
LIST_ITEM (L"\\bu @@Get nearest index from time...")
NORMAL (L"Modification:")
LIST_ITEM (L"\\bu @@Remove point...")
LIST_ITEM (L"\\bu @@Remove point near...")
LIST_ITEM (L"\\bu @@Remove points between...")
LIST_ITEM (L"\\bu ##FormantTier: Add point...#")
MAN_END

MAN_BEGIN (L"Sound: To Formant (burg)...", L"ppgb", 20031003)
INTRO (L"A command that creates a @Formant object from every selected @Sound object. "
	"It performs a short-term spectral analysis, approximating the spectrum of each "
	"analysis frame by a number of formants.")
ENTRY (L"Arguments")
TAG (L"%%Time step% (seconds)")
DEFINITION (L"the time between the centres of consecutive analysis frames. If the sound is 2 seconds long, "
	"and the time step is 0.01 seconds, there will be approximately 200 analysis frames. "
	"The actual number is somewhat lower (usually 195), because we cannot measure very well "
	"near the edges. If you set the time step to 0.0 (the standard), Praat will use a time step "
	"that is equal to 25 percent of the analysis window length (see below).")
TAG (L"%%Maximum number of formants%")
DEFINITION (L"for most analyses of human speech, you will want to extract 5 formants per frame. "
	"This, in combination with the %%Maximum formant% argument, is the only way "
	"in which this procedure will give you results compatible with how people "
	"tend to interpret formants for vowels, i.e. in terms of "
	"vowel height (F1) and vowel place (F2).")
TAG (L"%%Maximum formant% (Hertz)")
DEFINITION (L"the ceiling of the formant search range. It is crucial that you set this argument to a value suitable for your speaker. "
	"The standard value of 5500 Hz is suitable for an average adult female. For a male, use 5000 Hz; "
	"if you use 5500 Hz for an adult male, you may end up with too few formants in the low frequency region, "
	"e.g. analysing an [u] as having a single formant near 500 Hz whereas you want two formants at 300 and 600 Hz. "
	"For a young child, use a value much higher than 5500 Hz, for instance 8000 Hz (experiment with it on steady vowels).")
TAG (L"%%Window length% (seconds)")
DEFINITION (L"the effective duration of the analysis window. The actual length is twice this value, "
	"because Praat uses a Gaussian-like analysis window with sidelobes below -120 dB. "
	"For instance, if the %%Window length% is 0.025 seconds, the actual Gaussian window duration "
	"is 0.050 seconds. This window has values below 4\\%  outside the central 0.025 seconds, "
	"and its frequency resolution (-3 dB point) is 1.298 / (0.025 s) = 51.9 Hz, as computed "
	"with the formula given at @@Sound: To Spectrogram...@. This is comparable to the bandwidth "
	"of a Hamming window of 0.025 seconds, which is 1.303 / (0.025 s) = 52.1 Hz, "
	"but that window (which is the window most often used in other analysis programs) "
	"has three spectral lobes of about -42 dB on each side.")
TAG (L"%%Pre-emphasis from% (Hertz)")
DEFINITION (L"the +3 dB point for an inverted low-pass filter with a slope of +6 dB/octave. "
	"If this value is 50 Hz, then frequencies below 50 Hz are not enhanced, "
	"frequencies around 100 Hz are amplified by 6 dB, frequencies around 200 Hz are amplified by 12 dB, "
	"and so forth. The point of this is that vowel spectra tend to fall by 6 dB per octave; "
	"the pre-emphasis creates a flatter spectrum, which is better for formant analysis "
	"because we want our formants to match the local peaks, not the global spectral slope. "
	"See the @@source-filter synthesis@ tutorial for a technical explanation, "
	"and @@Sound: Pre-emphasize (in-line)...@ for the algorithm.")
ENTRY (L"Algorithm")
NORMAL (L"The sound will be resampled to a sampling frequency of twice the value of %%Maximum formant%, "
	"with the algorithm described at @@Sound: Resample...@. "
	"After this, pre-emphasis is applied with the algorithm described at @@Sound: Pre-emphasize (in-line)...@. "
	"For each analysis window, Praat applies a Gaussian-like window, "
	"and computes the LPC coefficients with the algorithm by Burg, as given by @@Childers (1978)@ "
	"and @@Press et al. (1992)@.")
NORMAL (L"This algorithm can initially find formants at very low or high frequencies. "
	"In order for you to be able to identify the traditional F1 and F2, "
	"all formants below 50 Hz and all formants above %%Maximum formant% minus 50 Hz, "
	"are removed. If you don't want this, you may experiment with @@Sound: To Formant (keep all)...@ instead. "
	"If you prefer an algorithm that always yields the requested number of formants, nicely distributed "
	"across the frequency domain, you may try the otherwise rather unreliable Split-Levinson procedure @@Sound: To Formant (sl)...@.")
MAN_END

MAN_BEGIN (L"Sound: To Formant (keep all)...", L"ppgb", 20000210)
INTRO (L"A command that creates a @Formant object from every selected @Sound object. Not recommended for general use.")
ENTRY (L"Purpose")
NORMAL (L"to perform a short-term spectral analysis, approximating the spectrum of each frame by a number of formants.")
ENTRY (L"Arguments")
NORMAL (L"The same as with @@Sound: To Formant (burg)...@.")
ENTRY (L"Algorithm")
NORMAL (L"The same as with @@Sound: To Formant (burg)...@. In contrast with that command, "
	"however, all formant values are kept, even those below 50 Hz and those above %%Maximum formant% minus 50 Hz. "
	"Although this makes the identification of the traditional F1 and F2 more difficult, "
	"this might give better results in resynthesis (see @@Sound & Formant: Filter@), but it usually generates funny values instead.")
MAN_END

MAN_BEGIN (L"Sound: To Formant (sl)...", L"ppgb", 20021215)
INTRO (L"A command that creates a @Formant object from every selected @Sound object. Not recommended for general use.")
ENTRY (L"Purpose")
NORMAL (L"to perform a short-term spectral analysis, approximating the spectrum of each frame by a number of formants.")
ENTRY (L"Arguments")
NORMAL (L"The same as with @@Sound: To Formant (burg)...@.")
ENTRY (L"Algorithm")
NORMAL (L"The algorithm is based on the implementation of the `Split Levinson' algorithm by @@Willems (1986)@. "
	"This algorithm will always find the requested number of formants in every frame, even if they do not exist. "
	"The standard routine (@@Sound: To Formant (burg)...@) yields much more reliable formant values, though it is more sensitive "
	"to the %%Maximum formant% argument.")
NORMAL (L"Because of the general funny behaviour of the Split-Levinson algorithm, we did not bother to implement an analysis "
	"of the bandwidths. They are all set arbitrarily to 50 Hz.")
MAN_END

MAN_BEGIN (L"Sound & Formant: Filter", L"ppgb", 19991119)
INTRO (L"A command to create a new Sound from the selected @Sound and @Formant objects.")
NORMAL (L"For examples, see @@Source-filter synthesis@.")
NORMAL (L"The resulting Sound is scaled so that its maximum absolute amplitude is 0.99. "
	"If you don't want this, use @@Sound & Formant: Filter (no scale)@ instead.")
MAN_END

MAN_BEGIN (L"Sound & Formant: Filter (no scale)", L"ppgb", 19991119)
INTRO (L"A command to create a new Sound from the selected @Sound and @Formant objects.")
NORMAL (L"For examples, see @@Source-filter synthesis@.")
NORMAL (L"Unlike what happens in @@Sound & Formant: Filter@, "
	"the resulting Sound is not scaled. This allows generation of a series "
	"of signals with controlled relative intensities.")
MAN_END

MAN_BEGIN (L"Sound & FormantGrid: Filter", L"ppgb", 20080425)
INTRO (L"A command to create a new Sound from the selected @Sound and @FormantGrid objects.")
NORMAL (L"For examples, see @@Source-filter synthesis@.")
NORMAL (L"The resulting Sound is scaled so that its maximum absolute amplitude is 0.99. "
	"If you don't want this, use @@Sound & FormantGrid: Filter (no scale)@ instead.")
MAN_END

MAN_BEGIN (L"Sound & FormantGrid: Filter (no scale)", L"ppgb", 20080425)
INTRO (L"A command to create a new Sound from the selected @Sound and @FormantGrid objects.")
NORMAL (L"For examples, see @@Source-filter synthesis@.")
NORMAL (L"Unlike what happens in @@Sound & FormantGrid: Filter@, "
	"the resulting Sound is not scaled. This allows generation of a series "
	"of signals with controlled relative intensities.")
MAN_END

}

/* End of file manual_formant.c */
