#ifndef _LPC_and_Formant_h_
#define  _LPC_and_Formant_h_
/* LPC_and_Formant.h
 *
 * Copyright (C) 1994-2003 David Weenink
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 djmw 20030524 GPL header
*/

#include "LPC.h"
#include "Polynomial.h"
#include "Formant.h"

Formant LPC_to_Formant (LPC me, double margin);

LPC Formant_to_LPC (Formant me, double samplingPeriod);

int LPC_Frame_into_Formant_Frame (LPC_Frame me, Formant_Frame thee, 
	double samplingPeriod, double margin);

int Formant_Frame_into_LPC_Frame (Formant_Frame me, LPC_Frame thee, double samplingPeriod);

void Formant_Frame_scale (Formant_Frame me, double scale);

int Roots_into_Formant_Frame (Roots me, Formant_Frame thee, double samplingFrequency, double margin);

int Formant_Frame_init (Formant_Frame me, long nFormants);

#endif /* _LPC_and_Formant_h_ */
