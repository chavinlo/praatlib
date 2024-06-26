#ifndef _Excitations_h_
#define _Excitations_h_
/* Excitations.h
 *
 * Copyright (C) 1993-2007 David Weenink
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
 djmw 20020813 GPL header
 djmw 20070620 Latest modification.
*/

#ifndef _Collection_h_
	#include "Collection.h"
#endif
#ifndef _Excitation_h_
	#include "Excitation.h"
#endif
#ifndef _Pattern_h_
	#include "Pattern.h"
#endif
#ifndef _TableOfReal_h_
	#include "TableOfReal.h"
#endif
#define Excitations_members Ordered_members
#define Excitations_methods Ordered_methods

class_create (Excitations, Ordered);

/* Excitations is a collection of objects of the same class Excitation */

Excitations Excitations_create (long initialCapacity);

Pattern Excitations_to_Pattern (Excitations me, long join);
/* Precondition: my size >= 1, all items have same dimension */

TableOfReal Excitations_to_TableOfReal (Excitations me);
/* Precondition: my size >= 1, all items have same dimension */

Any Excitations_getItem (Excitations m, long item);

#endif /* _Excitations_h_ */
