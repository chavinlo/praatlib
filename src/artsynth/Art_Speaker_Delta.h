/* Art_Speaker_Delta.h
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
 * pb 1995/09/20
 * pb 2002/07/16 GPL
 */

#ifndef _Articulation_h_
	#include "Articulation.h"
#endif
#ifndef _Speaker_h_
	#include "Speaker.h"
#endif
#ifndef _Delta_h_
	#include "Delta.h"
#endif

void Art_Speaker_intoDelta (Art art, Speaker speaker, Delta delta);

/* End of file Art_Speaker_Delta.h */
