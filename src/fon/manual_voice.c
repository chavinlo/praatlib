/* manual_Voice.c
 *
 * Copyright (C) 1992-2006 Paul Boersma
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

void manual_voice_init (ManPages me);
void manual_voice_init (ManPages me) {

MAN_BEGIN (L"Voice", L"ppgb", 20061028)
INTRO (L"This tutorial describes how you can do voice analysis with P\\s{RAAT}. "
	"To understand this tutorial, you have to be familiar with the @Intro, "
	"which describes the more general features of the @SoundEditor window.")
NORMAL (L"Most of P\\s{RAAT}'s voice analysis methods start from the glottal pulses that are visible in the @SoundEditor window "
	"as blue vertical lines through the waveform. If you do not see these lines, "
	"choose @@Show pulses@ from the #Pulses menu. If your sound is long, you may have to zoom in "
	"in order to see the separate pulses. You may notice that for some sounds, the time location of the pulses "
	"can vary when you zoom or scroll. This is because only the visible part of the sound is used for the analysis. "
	"The measurement results will also vary slightly when you zoom or scroll.")
NORMAL (L"The Pulse menu contains the command @@Voice report@, which will show in the Info window "
	"the results of many voice measurements for the visible part of the selection "
	"(or for the visible part of the whole sound, if there is a cursor instead of a selection or if the selection is not visible).")
ENTRY (L"Pitch settings")
NORMAL (L"The results of the voice measurements will depend on your @@Pitch settings...|Pitch settings@. "
	"In general, you will want to be careful about the pitch range. The standard range is 75\\--600 Hertz, "
	"but take a range of e.g. 50\\--200 Hertz for pathological male voices if that is the typical range. "
	"You may also want to choose ##Optimize for voice analysis#; otherwise, the voice report will complain about possible inaccuracies. "
	"The `advanced' pitch settings like ##Silence threshold# and ##Octave jump cost# can stay at their standard values.")
LIST_ITEM (L"@@Voice 1. Voice breaks@")
LIST_ITEM (L"@@Voice 2. Jitter@")
LIST_ITEM (L"@@Voice 3. Shimmer@")
LIST_ITEM (L"@@Voice 4. Additive noise@ (HNR, harmonicity)")
LIST_ITEM (L"@@Voice 5. Comparison with other programs@")
LIST_ITEM (L"@@Voice 6. Automating voice analysis with a script@")
MAN_END

MAN_BEGIN (L"Voice 1. Voice breaks", L"ppgb", 20030916)
INTRO (L"Normal voices can easily maintain phonation for some time when saying [a]. "
	"Some pathological voices have trouble with it. This can be measured in P\\s{RAAT} "
	"in two ways.")
ENTRY (L"Fraction of locally unvoiced pitch frames")
NORMAL (L"This is the fraction of pitch frames that are analysed as unvoiced (MDVP calls it DUV). If the pitch floor is 75 Hz, "
	"your Sound editor window will contain pitch measurements that are 0.01 seconds apart, so that if you select one second, "
	"there will be 100 pitch frames. If 86 of these are locally voiced, the Fraction will be 14 percent.")
NORMAL (L"The usual pitch analysis contains a %%path finder% that searches for a smooth path through the local "
	"pitch candidates. This path finder is temporarily switched off to determine the fraction of locally unvoiced frames. "
	"A frame is regarded as %locally unvoiced if it has a voicing strength below the %%voicing threshold% (whose standard value is 0.45), "
	"or a local peak below the %%silence threshold% (whose standard value is 0.03).")
NORMAL (L"In the voice report, the fraction of unvoiced frames will be reported as follows:")
CODE (L"Fraction of locally unvoiced frames: 14.000\\%  (14/100)")
NORMAL (L"The numbers between parentheses are the number of unvoiced frames and the total number of frames, "
	"respectively (in MDVP, these are called NUV and SEG, respectively).")
NORMAL (L"The normative value for the fraction of unvoiced frames is 0, i.e., normal healthy voices should "
	"have no trouble maintaining voicing during a sustained vowel. Every non-zero value can be considered "
	"a sign of pathology (like a common cold). "
	"Naturally, you will not select the leading and trailing silences when measuring this parameter.")
ENTRY (L"Number of voice breaks")
NORMAL (L"The number of distances between consecutive pulses that are longer than 1.25 divided by the pitch floor. "
	"Thus, if the pitch floor is 75 Hz, all inter-pulse intervals longer than 16.6667 milliseconds are regarded as voice breaks.")
ENTRY (L"Degree of voice breaks")
NORMAL (L"This is the total duration of the breaks between the voiced parts of the signal, "
	"divided by the total duration of the analysed part of the signal (MDVP calls it DVB). Since silences at the beginning "
	"and the end of the signal are not considered breaks, you will probably not want to select these silences "
	"when measuring this parameter.")
NORMAL (L"In the voice report, the degree of voice breaks will be reported like this:")
CODE (L"Degree of voice breaks: 29.529\\%  (1.163061 s / 3.938685 s)")
NORMAL (L"The numbers between parentheses are the total duration of the voice breaks and the duration of the analysed part of the signal, "
	"respectively.")
MAN_END

MAN_BEGIN (L"Voice 2. Jitter", L"ppgb", 20030531)
NORMAL (L"You can measure jitter in the Sound editor window, after choosing @@Show pulses@ from the #Pulses menu. "
	"You will see blue lines that can be thought of as representing the glottal closures. "
	"Use the Pulse menu to get the jitter in the selected part. You typically perform jitter measurements only on "
	"long sustained vowels. The voice report gives five kinds of jitter measurements.")
ENTRY (L"Jitter (local)")
NORMAL (L"This is the average absolute difference between consecutive periods, divided by the average period. "
	"MDVP calls this parameter %Jitt, and gives 1.040\\%  as a threshold for pathology.")
ENTRY (L"Jitter (local, absolute)")
NORMAL (L"This is the average absolute difference between consecutive periods. "
	"MDVP calls this parameter %Jita, and gives 83.200 \\mus as a threshold for pathology.")
ENTRY (L"Jitter (rap)")
NORMAL (L"This is the Relative Average Perturbation, "
	"the average absolute difference between a period and the average of it and its two neighbours, divided by the average period. "
	"MDVP gives 0.680\\%  as a threshold for pathology.")
ENTRY (L"Jitter (ppq5)")
NORMAL (L"This is the five-point Period Perturbation Quotient, "
	"the average absolute difference between a period and the average of it and its four closest neighbours, divided by the average period. "
	"MDVP calls this parameter %PPQ, and gives 0.840\\%  as a threshold for pathology.")
ENTRY (L"Jitter (ddp)")
NORMAL (L"This is the average absolute difference between consecutive differences between consecutive periods, divided by the average period. "
	"This is P\\s{RAAT}'s original ##Get jitter#. The value is three times RAP.")
MAN_END

MAN_BEGIN (L"Voice 3. Shimmer", L"ppgb", 20030521)
NORMAL (L"You can measure shimmer in the Sound editor window, after choosing @@Show pulses@ from the #Pulses menu. "
	"You will see blue lines that can be thought of as representing the glottal closures. "
	"Use the Pulse menu to get the shimmer in the selected part. You typically perform shimmer measurements only on "
	"long sustained vowels. The voice report gives six kinds of shimmer measurements.")
ENTRY (L"Shimmer (local)")
NORMAL (L"This is the average absolute difference between the amplitudes of consecutive periods, divided by the average amplitude. "
	"MDVP calls this parameter %Shim, and gives 3.810\\%  as a threshold for pathology.")
ENTRY (L"Shimmer (local, dB)")
NORMAL (L"This is the average absolute base-10 logarithm of the difference between the amplitudes of consecutive periods, multiplied by 20. "
	"MDVP calls this parameter %ShdB, and gives 0.350 dB as a threshold for pathology.")
ENTRY (L"Shimmer (apq3)")
NORMAL (L"This is the three-point Amplitude Perturbation Quotient, "
	"the average absolute difference between the amplitude of a period and the average of the amplitudes of its neighbours, "
	"divided by the average amplitude.")
ENTRY (L"Shimmer (apq5)")
NORMAL (L"This is the five-point Amplitude Perturbation Quotient, "
	"the average absolute difference between the amplitude of a period and the average of the amplitudes of it and its four closest neighbours, "
	"divided by the average amplitude.")
ENTRY (L"Shimmer (apq11)")
NORMAL (L"This is the 11-point Amplitude Perturbation Quotient, "
	"the average absolute difference between the amplitude of a period and the average of the amplitudes of it and its ten closest neighbours, "
	"divided by the average amplitude. "
	"MDVP calls this parameter %APQ, and gives 3.070\\%  as a threshold for pathology.")
ENTRY (L"Shimmer (ddp)")
NORMAL (L"This is the average absolute difference between consecutive differences between the amplitudes of consecutive periods. "
	"This is P\\s{RAAT}'s original ##Get shimmer#. The value is three times APQ3.")
MAN_END

MAN_BEGIN (L"Voice 4. Additive noise", L"ppgb", 20021206)
NORMAL (L"For a signal that can be assumed periodic (i.e., a sustained vowel), "
	"the signal-to-noise ratio equals the harmonics-to-noise ratio, which you get can get "
	"by selecting a Sound and choosing one of the \"To Harmonicity...\" commands from the Periodicity menu "
	"(for the algorithm, see @@Sound: To Harmonicity (ac)...@ or @@Sound: To Harmonicity (cc)...@). "
	"These are the world's most sensitive HNR measurements (up to 90 dB). "
	"For more information, see the @Harmonicity manual page.")
MAN_END

MAN_BEGIN (L"Voice 5. Comparison with other programs", L"ppgb", 20060111)
INTRO (L"Voicing, jitter, and shimmer measurements made by P\\s{RAAT} cannot always be compared directly with those made by other "
	"programs such as MDVP. The causes are the voicing decision strategy and the accuracy of period and peak determination.")
ENTRY (L"5.1. Voicing decisions: slightly different")
NORMAL (L"Different programs use very different methods for deciding whether an irregular part of the signal is voiced or not. "
	"A comparison of @@Boersma (1993)@ for P\\s{RAAT} and @@Deliyski (1993)@ for MDVP leads to the "
	"following considerations. Both P\\s{RAAT} and MDVP use an autocorrelation method for "
	"pitch analysis, but MDVP quantizes the amplitudes into the values -1, 0, and +1 before computing "
	"the autocorrelation, whereas P\\s{RAAT} uses the original amplitude. Also, P\\s{RAAT} corrects "
	"the autocorrelation function by dividing it by the autocorrelation function of the window, "
	"unlike any other program. Lastly, P\\s{RAAT} uses sinc interpolation to compute an accurate "
	"estimate of the height of the autocorrelation peaks, unlike any other program. "
	"All three of these differences (and there are more) influence the measurement of the height "
	"of the autocorrelation peak at 1/F0. This height is generally taken as a criterion for voicing: "
	"if it is more than the %%voicing threshold% (which you can change with @@Pitch settings...@, "
	"the frame is considered voiced, otherwise voiceless. "
	"In P\\s{RAAT}, the standard voicing threshold is 0.45, in MDVP it is 0.29, which suggests that MDVP "
	"tends to regard more frames as voiced than P\\s{RAAT}. But the difference between these two numbers "
	"may partly be explained by the fact that MDVP does not correct the autocorrelation function and that MDVP "
	"does not do an accurate sinc interpolation: both of these properties cause "
	"the measured height of the peak at 1/F0 (in MDVP) to be lower than the real height, as explained by @@Boersma (1993)@.")
ENTRY (L"5.2. Jitter measurements: sometimes very different")
NORMAL (L"The jitter measures in various programs may yield different results, with Praat often giving much lower values than MDVP, "
	"especially for noisy sounds. I will now explain where the difference comes from.")
NORMAL (L"If a sound is computer-generated as a glottal source signal with a random period duration variation of 1 percent (around a constant F0), "
	"then filtered with the characteristics of a vocal tract configuration corresponding to a sustained vowel, "
	"both Praat and MDVP will measure this sound as having a \"jitter\" of 1 percent. "
	"For non-noisy jittery sginals, therefore, the two programs give equally accurate results.")
NORMAL (L"If a sound is computer-generated as a glottal source signal with a constant period, "
	"then filtered with the characteristics of a vocal tract configuration corresponding to a sustained vowel, "
	"both Praat and MDVP will measure this sound as having a \"jitter\" of less than 0.01 percent. "
	"The two programs, therefore, have a comparable sensitivity in measuring small jitter values.")
NORMAL (L"So far, the two programs give comparable results. The difference between the two programs comes when noise is added.")
NORMAL (L"If a sound is computer-generated as a glottal source signal with a constant period, "
	"then filtered with the characteristics of a vocal tract configuration corresponding to a sustained vowel, "
	"and if then 1 percent additive \"white\" noise (a quite usual amount) is added, "
	"Praat will measure this sound as having a \"jitter\" of 0.02 percent, "
	"whereas MDVP will measure this sound as having a \"jitter\" of 0.6 percent. "
	"In other words, Praat will tell you that there is almost no jitter, "
	"whereas MDVP will tell you that the jitter is of an almost pathological level. "
	"The relevant curves can be seen in my paper \"Stemmen meten met Praat\", "
	"and the numbers are confirmed by Deliyski, Shaw & Evans (Journal of Voice, 2005: 23).")
NORMAL (L"One can see that Praat's \"jitter\" measure attempts to separate the influence of period duration variation "
	"(which it reports as \"jitter\") from the influence of additive noise (which is does not report as \"jitter\"), "
	"and that MDVP's \"jitter\" measure combines the influence of period duration variation with the influence of additive noise "
	"(both of which it reports as \"jitter\").")
NORMAL (L"The difference between Praat's and MDVP's jitter measures is due to a difference between the way in which periods are measured. "
	"Praat uses %%waveform-matching%, in which the duration of a period is determined by looking for best matching wave shapes "
	"(a \"cross-correlation\" maximum). MDVP uses %%peak-picking% instead, where the duration of a period is determined by "
	"measuring the time difference between two locally highest peaks in the wave form. The waveform-matching method "
	"averages away much of the influence of additive noise, whereas peak-picking is highly sensitive to additive noise.")
MAN_END

MAN_BEGIN (L"Voice 6. Automating voice analysis with a script", L"ppgb", 20061028)
INTRO (L"In a Praat script you usually do not want to raise a Sound window. "
	"Instead, you probably want to work with objects in the Objects window only. "
	"This page tells you how to do that for voice analysis.")
ENTRY (L"1. Creating the pulses in the Objects window")
NORMAL (L"The pulses you see as blue lines are a @PointProcess object. You can see this if "
	"you choose ##Extract visible pulses# from the #Pulses menu in the Sound window: "
	"a PointProcess object will appear in the list.")
NORMAL (L"You can also create a PointProcess in the Objects window directly. To do this, "
	"select a Sound and choose @@Sound: To PointProcess (periodic, cc)...@ from the #Periodicity menu.")
NORMAL (L"You can also do this in two steps. First you create a Pitch with "
	"@@Sound: To Pitch...@ or @@Sound: To Pitch (ac)...@ or @@Sound: To Pitch (cc)...@. "
	"Then you select the resulting Pitch %together with the original Sound "
	"and choose @@Sound & Pitch: To PointProcess (cc)@.")
NORMAL (L"Since the direct method of @@Sound: To PointProcess (periodic, cc)...@ actually uses the AC method "
	"for computing the Pitch (which is optimal for intonation analysis), "
	"you may prefer the two-step version if your goal is to do voice analysis. "
	"In that case, you use @@Sound: To Pitch (cc)...@ as the first step, "
	"and @@Sound & Pitch: To PointProcess (cc)@ as the second step. "
	"This is also how the Sound window does it: if you choose ##Optimize for voice analysis# in the @@Pitch settings...|Pitch settings@, "
	"Praat uses @@Sound: To Pitch (cc)...@ for pitch analysis.")
NORMAL (L"What you should %not do if you want to perform voice analysis is to create the PointProcess "
	"by selecting a Pitch only and then choosing @@Pitch: To PointProcess@. In that way, "
	"the resulting pulses would not be aligned to the periods in the Sound.")
ENTRY (L"2. Measuring jitter from a script")
NORMAL (L"Once you have a PointProcess that represents the periods in the Sound, "
	"you can select it and choose some ##Get jitter# commands from the #Query menu.")
ENTRY (L"3. Measuring shimmer from a script")
NORMAL (L"Once you have a PointProcess that represents the periods in the Sound, "
	"you can select it together with the Sound, then choose some ##Get shimmer# commands from the #Query menu.")
ENTRY (L"4. Getting the whole voice report from a script")
NORMAL (L"If you select the Sound, the Pitch, and the PointProcess together (all three), "
	"there will be a button that says ##Voice report...#. If you press it, the voice report "
	"will be written to the Info window. This is identical to the voice report in the Sound window, "
	"although you will have to specify the time range by manually typing it.")
NORMAL (L"In a script, you can get the jitter and shimmer from the voice report by doing something like:")
CODE (L"voiceReport\\$  = Voice report... 0 0 75 500 1.3 1.6 0.03 0.45")
CODE (L"jitter = extractNumber (voiceReport\\$ , \"Jitter (local): \")")
CODE (L"shimmer = extractNumber (voiceReport\\$ , \"Shimmer (local): \")")
CODE (L"echo Jitter = 'jitter:3\\% ', shimmer = 'shimmer:3\\% '")
ENTRY (L"5. Disadvantage of automating voice analysis")
NORMAL (L"In all the commands mentioned above, you have to guess the time range, "
	"and you would usually supply \"0.0\" and \"0.0\", in which case "
	"you will get the average jitter and shimmer for the whole sound. "
	"This may include parts of the sound that you are often not interested in, such as false starts. "
	"You do not have these problems when asking for a voice report in the sound window, "
	"because there you would make an explicit time selection by hand after judging what part of the sound is relevant.")
MAN_END

MAN_BEGIN (L"Voice report", L"ppgb", 20030316)
INTRO (L"A command in the #Pulses menu that will write to the Info window an extensive report "
	"about many voice parameters. See the @Voice tutorial.")
MAN_END
}

/* End of file manual_Voice.c */
