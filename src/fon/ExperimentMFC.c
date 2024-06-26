/* ExperimentMFC.c
 *
 * Copyright (C) 2001-2008 Paul Boersma
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
 * pb 2002/07/16 GPL
 * pb 2002/10/31 NUMlog2
 * pb 2003/03/08 inter-stimulus interval; version 2
 * pb 2003/09/14 MelderDir_relativePathToFile
 * pb 2004/06/22 added response keys; version 3
 * pb 2004/08/12 removed a bug (something said carrierBefore instead of carrierAfter)
 *     that caused Praat to crash if the carrier before was longer than the carrier after
 * pb 2005/11/21 added replay button; version 4
 * pb 2005/12/02 response sounds are read
 * pb 2006/10/28 erased MacOS 9 stuff
 * pb 2006/12/20 stereo
 * pb 2007/08/12 wchar_t
 * pb 2007/09/26 added font size; version 5
 * pb 2007/10/01 can write as encoding
 * pb 2008/04/08 in ExtractResults, check that a resonse was given
 */

#include "ExperimentMFC.h"

#include "oo_DESTROY.h"
#include "ExperimentMFC_def.h"
#include "oo_COPY.h"
#include "ExperimentMFC_def.h"
#include "oo_EQUAL.h"
#include "ExperimentMFC_def.h"
#include "oo_CAN_WRITE_AS_ENCODING.h"
#include "ExperimentMFC_def.h"
#include "oo_READ_TEXT.h"
#include "ExperimentMFC_def.h"
#include "oo_WRITE_TEXT.h"
#include "ExperimentMFC_def.h"
#include "oo_READ_BINARY.h"
#include "ExperimentMFC_def.h"
#include "oo_WRITE_BINARY.h"
#include "ExperimentMFC_def.h"
#include "oo_DESCRIPTION.h"
#include "ExperimentMFC_def.h"

class_methods (ExperimentMFC, Data) {
	us -> version = 5;
	class_method_local (ExperimentMFC, destroy)
	class_method_local (ExperimentMFC, description)
	class_method_local (ExperimentMFC, copy)
	class_method_local (ExperimentMFC, equal)
	class_method_local (ExperimentMFC, canWriteAsEncoding)
	class_method_local (ExperimentMFC, writeText)
	class_method_local (ExperimentMFC, readText)
	class_method_local (ExperimentMFC, writeBinary)
	class_method_local (ExperimentMFC, readBinary)
	class_methods_end
}

#include "enum_c.h"
#include "Experiment_enums.h"

static int readSound (ExperimentMFC me, const wchar_t *fileNameHead, const wchar_t *fileNameTail,
	double medialSilenceDuration, wchar_t **name, Sound *sound)
{
	wchar_t fileNameBuffer [256], pathName [256], *fileNames = & fileNameBuffer [0];
	structMelderFile file = { 0 };
	wcscpy (fileNameBuffer, *name);
	/*
	 * The following conversion is needed when fileNameHead is an absolute path,
	 * and the stimulus names contain slashes for relative paths.
	 * An ugly case, but allowed.
	 */
	#if defined (_WIN32)
		for (;;) { wchar_t *slash = wcschr (fileNames, '/'); if (! slash) break; *slash = '\\'; }
	#endif
	forget (*sound);
	/*
	 * 'fileNames' can contain commas, which separate partial file names.
	 * The separate files should be concatenated.
	 */
	for (;;) {
		/*
		 * Determine partial file name.
		 */
		wchar_t *comma = wcschr (fileNames, ',');
		if (comma) *comma = '\0';
		/*
		 * Determine complete (relative) file name.
		 */
		swprintf (pathName, 256, L"%ls%ls%ls", fileNameHead, fileNames, fileNameTail);
		/*
		 * Make sure we are in the correct directory.
		 */
		if (MelderDir_isNull (& my rootDirectory)) {
			/*
			 * Absolute file name.
			 */
			Melder_pathToFile (pathName, & file);
		} else {
			/*
			 * Relative or absolute file name.
			 */
			MelderDir_relativePathToFile (& my rootDirectory, pathName, & file);
			#if 0
				Melder_error3 (L"Full path name <", file.path, L">");
				MelderInfo_open ();
				MelderInfo_writeLine3 (L"Path name <", pathName, L">");
				MelderInfo_writeLine3 (L"Root directory <", my rootDirectory.path, L">");
				MelderInfo_writeLine3 (L"Full path name <", file.path, L">");
				MelderInfo_close ();
			#endif
		}
		cherror
		/*
		 * Read the substimulus.
		 */
		Sound substimulus = Sound_readFromSoundFile (& file); cherror
		/*
		 * Check whether all sounds have the same number of channels.
		 */
		if (my numberOfChannels == 0) {
			my numberOfChannels = substimulus -> ny;
		} else if (substimulus -> ny != my numberOfChannels) {
			forget (substimulus);
			error3 (L"The sound in file ", MelderFile_messageNameW (& file), L" has a different number of channels than some other sound.")
		}
		/*
		 * Check whether all sounds have the same sampling frequency.
		 */
		if (my samplePeriod == 0.0) {
			my samplePeriod = substimulus -> dx;   /* This must be the first sound read. */
		} else if (substimulus -> dx != my samplePeriod) {
			forget (substimulus);
			error3 (L"The sound in file ", MelderFile_messageNameW (& file), L" has a different sampling frequency than some other sound.")
		}
		/*
		 * Append the substimuli, perhaps with silent intervals.
		 */
		if (*sound == NULL) {
			*sound = substimulus;
		} else {
			Sound newStimulus = Sounds_append (*sound, medialSilenceDuration, substimulus);
			forget (substimulus);
			iferror goto end;
			Melder_assert (sound == & (*sound));
			forget (*sound);
			*sound = newStimulus;
		}
		/*
		 * Cycle.
		 */
		if (comma == NULL) break;
		fileNames = & comma [1];
	}
end:
	iferror return 0;
	return 1;
}

static void permuteRandomly (ExperimentMFC me, long first, long last) {
	long itrial;
	for (itrial = first; itrial < last; itrial ++) {
		long jtrial = NUMrandomInteger (itrial, last), dummy;
		dummy = my stimuli [jtrial];
		my stimuli [jtrial] = my stimuli [itrial];
		my stimuli [itrial] = dummy;
	}
}

int ExperimentMFC_start (ExperimentMFC me) {
	long istim, iresp, itrial, ireplica;
	long maximumStimulusPlaySamples, maximumResponsePlaySamples, maximumPlaySamples;
	long stimulusCarrierBeforeSamples = 0, stimulusCarrierAfterSamples = 0, maximumStimulusSamples = 0;
	long responseCarrierBeforeSamples = 0, responseCarrierAfterSamples = 0, maximumResponseSamples = 0;
	Melder_warningOff ();
	my trial = 0;
	NUMlvector_free (my stimuli, 1);
	NUMlvector_free (my responses, 1);
	NUMdvector_free (my goodnesses, 1);
	forget (my playBuffer);
	my pausing = FALSE;
	my numberOfTrials = my numberOfDifferentStimuli * my numberOfReplicationsPerStimulus;
	my stimuli = NUMlvector (1, my numberOfTrials); cherror
	my responses = NUMlvector (1, my numberOfTrials); cherror
	my goodnesses = NUMdvector (1, my numberOfTrials); cherror
	/*
	 * Read all the sounds. They must all have the same sampling frequency and number of channels.
	 */
	my samplePeriod = 0.0;
	my numberOfChannels = 0;
	if (my stimuliAreSounds) {
		if (my stimulusCarrierBefore. name && my stimulusCarrierBefore. name [0]) {
			readSound (me, my stimulusFileNameHead, my stimulusFileNameTail, my stimulusMedialSilenceDuration,
				& my stimulusCarrierBefore. name, & my stimulusCarrierBefore. sound); cherror
			stimulusCarrierBeforeSamples = my stimulusCarrierBefore. sound -> nx;
		}
		if (my stimulusCarrierAfter. name && my stimulusCarrierAfter. name [0]) {
			readSound (me, my stimulusFileNameHead, my stimulusFileNameTail, my stimulusMedialSilenceDuration,
				& my stimulusCarrierAfter. name, & my stimulusCarrierAfter. sound); cherror
			stimulusCarrierAfterSamples = my stimulusCarrierAfter. sound -> nx;
		}
		for (istim = 1; istim <= my numberOfDifferentStimuli; istim ++) {
			readSound (me, my stimulusFileNameHead, my stimulusFileNameTail, my stimulusMedialSilenceDuration,
				& my stimulus [istim]. name, & my stimulus [istim]. sound); cherror
			if (my stimulus [istim]. sound -> nx > maximumStimulusSamples)
				maximumStimulusSamples = my stimulus [istim]. sound -> nx;
		}
	}
	if (my responsesAreSounds) {
		if (my responseCarrierBefore. name && my responseCarrierBefore. name [0]) {
			readSound (me, my responseFileNameHead, my responseFileNameTail, my responseMedialSilenceDuration,
				& my responseCarrierBefore. name, & my responseCarrierBefore. sound); cherror
			responseCarrierBeforeSamples = my responseCarrierBefore. sound -> nx;
		}
		if (my responseCarrierAfter. name && my responseCarrierAfter. name [0]) {
			readSound (me, my responseFileNameHead, my responseFileNameTail, my responseMedialSilenceDuration,
				& my responseCarrierAfter. name, & my responseCarrierAfter. sound); cherror
			responseCarrierAfterSamples = my responseCarrierAfter. sound -> nx;
		}
		for (iresp = 1; iresp <= my numberOfDifferentResponses; iresp ++) {
			readSound (me, my responseFileNameHead, my responseFileNameTail, my responseMedialSilenceDuration,
				& my response [iresp]. name, & my response [iresp]. sound); cherror
			if (my response [iresp]. sound -> nx > maximumResponseSamples)
				maximumResponseSamples = my response [iresp]. sound -> nx;
		}
	}
	/*
	 * Create the play buffer.
	 */
	maximumStimulusPlaySamples = floor (my stimulusInitialSilenceDuration / my samplePeriod + 0.5)
		+ stimulusCarrierBeforeSamples + maximumStimulusSamples + stimulusCarrierAfterSamples + 1;
	maximumResponsePlaySamples = floor (my responseInitialSilenceDuration / my samplePeriod + 0.5)
		+ responseCarrierBeforeSamples + maximumResponseSamples + responseCarrierAfterSamples + 1;
	maximumPlaySamples = maximumStimulusPlaySamples > maximumResponsePlaySamples ? maximumStimulusPlaySamples : maximumResponsePlaySamples;
	my playBuffer = Sound_create (my numberOfChannels, 0.0, maximumPlaySamples * my samplePeriod,
		maximumPlaySamples, my samplePeriod, 0.5 * my samplePeriod); cherror
	/*
	 * Determine the order in which the stimuli will be presented to the subject.
	 */
	if (my randomize == enumi (Experiment_RANDOMIZE, CyclicNonRandom)) {
		for (itrial = 1; itrial <= my numberOfTrials; itrial ++)
			my stimuli [itrial] = (itrial - 1) % my numberOfDifferentStimuli + 1;
	} else if (my randomize == enumi (Experiment_RANDOMIZE, PermuteAll)) {
		for (itrial = 1; itrial <= my numberOfTrials; itrial ++)
			my stimuli [itrial] = (itrial - 1) % my numberOfDifferentStimuli + 1;
		permuteRandomly (me, 1, my numberOfTrials);
	} else if (my randomize == enumi (Experiment_RANDOMIZE, PermuteBalanced)) {
		for (ireplica = 1; ireplica <= my numberOfReplicationsPerStimulus; ireplica ++) {
			long offset = (ireplica - 1) * my numberOfDifferentStimuli;
			for (istim = 1; istim <= my numberOfDifferentStimuli; istim ++)
				my stimuli [offset + istim] = istim;
			permuteRandomly (me, offset + 1, offset + my numberOfDifferentStimuli);
		}
	} else if (my randomize == enumi (Experiment_RANDOMIZE, PermuteBalancedNoDoublets)) {
		for (ireplica = 1; ireplica <= my numberOfReplicationsPerStimulus; ireplica ++) {
			long offset = (ireplica - 1) * my numberOfDifferentStimuli;
			for (istim = 1; istim <= my numberOfDifferentStimuli; istim ++)
				my stimuli [offset + istim] = istim;
			do {
				permuteRandomly (me, offset + 1, offset + my numberOfDifferentStimuli);
			} while (ireplica != 1 && my stimuli [offset + 1] == my stimuli [offset] && my numberOfDifferentStimuli > 1);
		}
	} else if (my randomize == enumi (Experiment_RANDOMIZE, WithReplacement)) {
		for (itrial = 1; itrial <= my numberOfTrials; itrial ++)
			my stimuli [itrial] = NUMrandomInteger (1, my numberOfDifferentStimuli);
	}
end:
	Melder_warningOn ();
	iferror {
		my numberOfTrials = 0;
		my stimuli = NULL;
		return 0;
	}
	return 1;
}

static void playSound (ExperimentMFC me, Sound sound, Sound carrierBefore, Sound carrierAfter, double initialSilenceDuration) {
	long initialSilenceSamples = floor (initialSilenceDuration / my samplePeriod + 0.5);
	long carrierBeforeSamples = carrierBefore ? carrierBefore -> nx : 0;
	long soundSamples = sound ? sound -> nx : 0;
	long carrierAfterSamples = carrierAfter ? carrierAfter -> nx : 0;
	for (long channel = 1; channel <= my numberOfChannels; channel ++) {
		for (long i = 1; i <= initialSilenceSamples; i ++) {
			my playBuffer -> z [channel] [i] = 0.0;
		}
	}
	if (carrierBefore) {
		for (long channel = 1; channel <= my numberOfChannels; channel ++) {
			NUMdvector_copyElements (carrierBefore -> z [channel],
				my playBuffer -> z [channel] + initialSilenceSamples, 1, carrierBeforeSamples);
		}
	}
	if (sound) {
		for (long channel = 1; channel <= my numberOfChannels; channel ++) {
			NUMdvector_copyElements (sound -> z [channel],
				my playBuffer -> z [channel] + initialSilenceSamples + carrierBeforeSamples, 1, soundSamples);
		}
	}
	if (carrierAfter) {
		for (long channel = 1; channel <= my numberOfChannels; channel ++) {
			NUMdvector_copyElements (carrierAfter -> z [channel],
				my playBuffer -> z [channel] + initialSilenceSamples + carrierBeforeSamples + soundSamples, 1, carrierAfterSamples);
		}
	}
	Sound_playPart (my playBuffer, 0.0,
		(initialSilenceSamples + carrierBeforeSamples + soundSamples + carrierAfterSamples) * my samplePeriod,
		0, NULL);
}

void ExperimentMFC_playStimulus (ExperimentMFC me, long istim) {
	playSound (me, my stimulus [istim]. sound,
		my stimulusCarrierBefore. sound, my stimulusCarrierAfter. sound, my stimulusInitialSilenceDuration);
}

void ExperimentMFC_playResponse (ExperimentMFC me, long iresp) {
	playSound (me, my response [iresp]. sound,
		my responseCarrierBefore. sound, my responseCarrierAfter. sound, my responseInitialSilenceDuration);
}

class_methods (ResultsMFC, Data) {
	us -> version = 1;
	class_method_local (ResultsMFC, destroy)
	class_method_local (ResultsMFC, description)
	class_method_local (ResultsMFC, copy)
	class_method_local (ResultsMFC, equal)
	class_method_local (ResultsMFC, canWriteAsEncoding)
	class_method_local (ResultsMFC, writeText)
	class_method_local (ResultsMFC, readText)
	class_method_local (ResultsMFC, writeBinary)
	class_method_local (ResultsMFC, readBinary)
	class_methods_end
}

ResultsMFC ResultsMFC_create (long numberOfTrials) {
	ResultsMFC me = new (ResultsMFC);
	if (! me) return NULL;
	my numberOfTrials = numberOfTrials;
	if ((my result = NUMstructvector (TrialMFC, 1, my numberOfTrials)) == NULL)
		{ forget (me); return NULL; }
	return me;
}

ResultsMFC ExperimentMFC_extractResults (ExperimentMFC me) {
	ResultsMFC thee = NULL;
	if (my trial == 0 || my trial <= my numberOfTrials)
		return Melder_errorp ("(ExperimentMFC_extractResults:) Experiment not finished.");
	thee = ResultsMFC_create (my numberOfTrials); cherror
	for (long trial = 1; trial <= my numberOfTrials; trial ++) {
		wchar_t *pipe = my stimulus [my stimuli [trial]]. visibleText ?
			wcschr (my stimulus [my stimuli [trial]]. visibleText, '|') : NULL;
		if (pipe) {
			long nameLength = wcslen (my stimulus [my stimuli [trial]]. name);
			long buttonTextLength = wcslen (pipe);
			thy result [trial]. stimulus = Melder_calloc (wchar_t, nameLength + buttonTextLength + 1); cherror
			wcscpy (thy result [trial]. stimulus, my stimulus [my stimuli [trial]]. name);
			wcscat (thy result [trial]. stimulus, pipe);
		} else {
			thy result [trial]. stimulus = Melder_wcsdup (my stimulus [my stimuli [trial]]. name); cherror
		}
		if (my responses [trial] < 1) error3 (L"No response for trial ", Melder_integer (trial), L".")
		thy result [trial]. response = Melder_wcsdup (my response [my responses [trial]]. name); cherror
		thy result [trial]. goodness = my goodnesses [trial];
	}
end:
	iferror { forget (thee); return NULL; }
	return thee;
}

ResultsMFC ResultsMFC_removeUnsharedStimuli (ResultsMFC me, ResultsMFC thee) {
	ResultsMFC him = ResultsMFC_create (thy numberOfTrials); cherror
	his numberOfTrials = 0;
	for (long i = 1; i <= thy numberOfTrials; i ++) {
		int present = FALSE;
		for (long j = 1; j <= my numberOfTrials; j ++) {
			if (wcsequ (thy result [i]. stimulus, my result [j]. stimulus)) {
				present = TRUE;
				break;
			}
		}
		if (present) {
			his numberOfTrials ++;
			his result [his numberOfTrials]. stimulus = Melder_wcsdup (thy result [i]. stimulus); cherror
			his result [his numberOfTrials]. response = Melder_wcsdup (thy result [i]. response); cherror
		}
	}
	if (his numberOfTrials == 0) error1 (L"No shared stimuli.")
end:
	iferror { forget (him); return Melder_errorp ("(ResultsMFC_removeUnsharedStimuli:) Not performed."); }
	return him;
}

Table ResultsMFCs_to_Table (Collection me) {
	Table thee;
	long irow = 0, iresults, itrial;
	int hasGoodnesses = 0;
	for (iresults = 1; iresults <= my size; iresults ++) {
		ResultsMFC results = my item [iresults];
		for (itrial = 1; itrial <= results -> numberOfTrials; itrial ++) {
			irow ++;
			if (results -> result [itrial]. goodness != 0)
				hasGoodnesses = 1;
		}
	}
	thee = Table_create (irow, 3 + hasGoodnesses); cherror
	Table_setColumnLabel (thee, 1, L"subject");
	Table_setColumnLabel (thee, 2, L"stimulus");
	Table_setColumnLabel (thee, 3, L"response");
	if (hasGoodnesses) Table_setColumnLabel (thee, 4, L"goodness");
	irow = 0;
	for (iresults = 1; iresults <= my size; iresults ++) {
		ResultsMFC results = my item [iresults];
		for (itrial = 1; itrial <= results -> numberOfTrials; itrial ++) {
			irow ++;
			Table_setStringValue (thee, irow, 1, results -> name);
			Table_setStringValue (thee, irow, 2, results -> result [itrial]. stimulus);
			Table_setStringValue (thee, irow, 3, results -> result [itrial]. response);
			if (hasGoodnesses)
				Table_setNumericValue (thee, irow, 4, results -> result [itrial]. goodness);
		}
	}
end:
	iferror { forget (thee); return NULL; }
	return thee;
}

Categories ResultsMFC_to_Categories_stimuli (ResultsMFC me) {
	Categories thee = Categories_create ();
	long trial;
	if (! thee) return 0;
	for (trial = 1; trial <= my numberOfTrials; trial ++) {
		SimpleString category = SimpleString_create (my result [trial]. stimulus); cherror
		Collection_addItem (thee, category); cherror
	}
end:
	iferror { forget (thee); return NULL; }
	return thee;
}

Categories ResultsMFC_to_Categories_responses (ResultsMFC me) {
	Categories thee = Categories_create ();
	long trial;
	if (! thee) return 0;
	for (trial = 1; trial <= my numberOfTrials; trial ++) {
		SimpleString category = SimpleString_create (my result [trial]. response); cherror
		Collection_addItem (thee, category); cherror
	}
end:
	iferror { forget (thee); return NULL; }
	return thee;
}

static int compare (SimpleString me, SimpleString thee) {
	return wcscmp (my string, thy string);
}
void Categories_sort (Categories me) {
	NUMsort_p (my size, my item, (int (*) (const void *, const void *)) compare);
}

double Categories_getEntropy (Categories me) {
	long i, numberOfTokens = 0;
	wchar_t *previousString = NULL;
	double entropy = 0.0;
	me = Data_copy (me); iferror return NUMundefined;
	Categories_sort (me);
	for (i = 1; i <= my size; i ++) {
		SimpleString s = my item [i];
		wchar_t *string = s -> string;
		if (previousString != NULL && ! wcsequ (string, previousString)) {
			double p = (double) numberOfTokens / my size;
			entropy -= p * NUMlog2 (p);
			numberOfTokens = 1;
		} else {
			numberOfTokens ++;
		}
		previousString = string;
	}
	if (numberOfTokens) {
		double p = (double) numberOfTokens / my size;
		entropy -= p * NUMlog2 (p);
	}
	forget (me);
	return entropy;
}

/* End of file Formant.c */
