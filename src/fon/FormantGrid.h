#ifndef _FormantGrid_h_
#define _FormantGrid_h_
/* FormantGrid.h
 *
 * Copyright (C) 2008 Paul Boersma & David Weenink
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
 * pb 2008/04/27
 */

#ifndef _RealTier_h_
	#include "RealTier.h"
#endif
#ifndef _Sound_h_
	#include "Sound.h"
#endif
#ifndef _Formant_h_
	#include "Formant.h"
#endif

#include "FormantGrid_def.h"
#define FormantGrid_methods Function_methods
oo_CLASS_CREATE (FormantGrid, Function);

FormantGrid FormantGrid_createEmpty (double tmin, double tmax, long numberOfFormants);

FormantGrid FormantGrid_create (double tmin, double tmax, long numberOfFormants,
	double initialFirstFormant, double initialFormantSpacing,
	double initialFirstBandwidth, double initialBandwidthSpacing);

double FormantGrid_getFormantAtTime (FormantGrid me, long iformant, double t);
double FormantGrid_getBandwidthAtTime (FormantGrid me, long iformant, double t);

int FormantGrid_addFormantPoint (FormantGrid me, long iformant, double t, double value);
int FormantGrid_addBandwidthPoint (FormantGrid me, long iformant, double t, double value);
void FormantGrid_removeFormantPointsBetween (FormantGrid me, long iformant, double tmin, double tmax);
void FormantGrid_removeBandwidthPointsBetween (FormantGrid me, long iformant, double tmin, double tmax);

void Sound_FormantGrid_filter_inline (Sound me, FormantGrid formantGrid);
Sound Sound_FormantGrid_filter (Sound me, FormantGrid formantGrid);
Sound Sound_FormantGrid_filter_noscale (Sound me, FormantGrid formantGrid);

Sound FormantGrid_to_Sound (FormantGrid me, double samplingFrequency,
	double tStart, double f0Start, double tMid, double f0Mid, double tEnd, double f0End,
	double adaptFactor, double maximumPeriod, double openPhase, double collisionPhase, double power1, double power2);
int FormantGrid_playPart (FormantGrid me, double tmin, double tmax, double samplingFrequency,
	double tStart, double f0Start, double tMid, double f0Mid, double tEnd, double f0End,
	double adaptFactor, double maximumPeriod, double openPhase, double collisionPhase, double power1, double power2,
	int (*playCallback) (void *playClosure, int phase, double tmin, double tmax, double t), void *playClosure);

FormantGrid Formant_downto_FormantGrid (Formant me);

/* End of file FormantGrid.h */
#endif
