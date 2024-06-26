/* Sound_to_PointProcess.h
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
 * pb 2007/01/28
 */

#ifndef _Sound_h_
	#include "Sound.h"
#endif
#ifndef _PointProcess_h_
	#include "PointProcess.h"
#endif

PointProcess Sound_to_PointProcess_extrema (Sound me, long channel, int interpolation, int includeMaxima, int includeMinima);
PointProcess Sound_to_PointProcess_maxima (Sound me, long channel, int interpolation);
PointProcess Sound_to_PointProcess_minima (Sound me, long channel, int interpolation);
PointProcess Sound_to_PointProcess_allExtrema (Sound me, long channel, int interpolation);

PointProcess Sound_to_PointProcess_zeroes (Sound me, long channel, int includeRaisers, int includeFallers);

PointProcess Sound_to_PointProcess_periodic_cc (Sound me, double fmin, double fmax);

PointProcess Sound_to_PointProcess_periodic_peaks (Sound me, double fmin, double fmax, int includeMaxima, int includeMinima);

/* End of file Sound_to_PointProcess.h */
