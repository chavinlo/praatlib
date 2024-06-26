#ifndef _Eigen_h_
#define _Eigen_h_
/* Eigen.h
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
 djmw 20070620 Latest modification 
*/

#ifndef _Data_h_
	#include "Data.h"
#endif
#ifndef _Collection_h_
	#include "Collection.h"
#endif
#ifndef _Graphics_h_
	#include "Graphics.h"
#endif
#ifndef _Strings_h_
	#include "Strings.h"
#endif

#define Eigen_members Data_members \
	long numberOfEigenvalues, dimension;	\
	double *eigenvalues;	\
	double **eigenvectors; /* eigenvectors stored in row */
#define Eigen_methods Data_methods
class_create (Eigen, Data);

Eigen Eigen_create (long numberOfEigenvalues, long dimension);

int Eigen_init (I, long numberOfEigenvalues, long dimension);

int Eigen_initFromSymmetricMatrix_f (I, float **a, long n);
int Eigen_initFromSymmetricMatrix (I, double **a, long n);

int Eigen_initFromSquareRoot (I, double **a, long numberOfRows,
	long numberOfColumns);
/*
	Calculate eigenstructure for symmetric matrix A'A (e.g. covariance matrix),
	when only A is given.
	Precondition: numberOfRows > 1
	Method: SVD.
*/

int Eigen_initFromSquareRootPair (I, double **a, long numberOfRows,
	long numberOfColumns, double **b, long numberOfRows_b);
/*
	Calculate eigenstructure for A'Ax - lambda B'Bx = 0
	Preconditions: numberOfRows >= numberOfColumns &&
		numberOfRows_b >= numberOfColumns
	Method: Generalized SVD.
*/

long Eigen_getNumberOfEigenvectors (I);

long Eigen_getDimensionOfComponents (I);

double Eigen_getCumulativeContributionOfComponents (I, long from, long to);

long Eigen_getDimensionOfFraction (I, double fraction);

double Eigen_getEigenvectorElement (I, long ivec, long element);

double Eigen_getSumOfEigenvalues (I, long from, long to);


void Eigen_sort (I);
/*
	Sort eigenvalues and corresponding eigenvectors in decreasing order.
*/

void Eigen_invertEigenvector (I, long ivec);

void Eigen_drawEigenvalues (I, Graphics g, long first, long last, double ymin, double ymax, 
	int fractionOfTotal, int cumulative, double size_mm, const wchar_t *mark, int garnish);
	
void Eigen_drawEigenvector (I, Graphics g, long ivec, long first, long last,
	double minimum, double maximum, int weigh, double size_mm, const wchar_t *mark,
	int connect, wchar_t **rowLabels, int garnish);
/*
	Draw eigenvector. When rowLabels != NULL, draw row text labels on bottom axis.
*/
	
int Eigens_alignEigenvectors (Ordered me);
/*
	Correlate all eigenvectors with the eigenvectors of the first Eigen.
	If r < 0 then mirror the eigenvectors of 
*/

double Eigens_getAngleBetweenEigenplanes_degrees (I, thou);
/*
	Get angle between the eigenplanes, spanned by the first two eigenvectors, .
*/
#endif /* _Eigen_h_ */

/* End of file Eigen.h */
