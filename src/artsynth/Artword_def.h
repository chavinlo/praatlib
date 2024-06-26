/* Artword_def.h
 *
 * Copyright (C) 1992-2002 Paul Boersma
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
 * pb 1996/06/14
 * pb 2002/07/16 GPL
 */


#define ooSTRUCT ArtwordData
oo_DEFINE_STRUCT (ArtwordData)

	oo_INT (numberOfTargets)
	oo_DOUBLE_VECTOR (targets, my numberOfTargets)
	oo_DOUBLE_VECTOR (times, my numberOfTargets)
	#if oo_DECLARING
		oo_INT (_iTarget)
	#endif
	#if oo_READING
		double *newTargets = NUMdvector (1, 100);
		double *newTimes = NUMdvector (1, 100);
		if (my numberOfTargets > 0) {
			NUMdvector_copyElements (my targets, newTargets, 1, my numberOfTargets);
			NUMdvector_copyElements (my times, newTimes, 1, my numberOfTargets);
			NUMdvector_free (my targets, 1);
			NUMdvector_free (my times, 1);
		}
		my targets = newTargets;
		my times = newTimes;
	#endif

oo_END_STRUCT (ArtwordData)
#undef ooSTRUCT


#define ooSTRUCT Artword
oo_DEFINE_CLASS (Artword, Data)

	oo_DOUBLE (totalTime)
	oo_STRUCT_SET (ArtwordData, data, Art_MUSCLE)

oo_END_CLASS (Artword)
#undef ooSTRUCT


/* End of file Artword_def.h */
