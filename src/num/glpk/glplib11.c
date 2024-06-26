/* glplib11.c (miscellaneous routines) */

/***********************************************************************
*  This code is part of GLPK (GNU Linear Programming Kit).
*
*  Copyright (C) 2000, 01, 02, 03, 04, 05, 06, 07, 08 Andrew Makhorin,
*  Department for Applied Informatics, Moscow Aviation Institute,
*  Moscow, Russia. All rights reserved. E-mail: <mao@mai2.rcnet.ru>.
*
*  GLPK is free software: you can redistribute it and/or modify it
*  under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  GLPK is distributed in the hope that it will be useful, but WITHOUT
*  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
*  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
*  License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with GLPK. If not, see <http://www.gnu.org/licenses/>.
***********************************************************************/

#include "glplib.h"
#define xfault xerror

/*----------------------------------------------------------------------
*  NAME
*
*  str2int - convert character string to value of int type
*
*  SYNOPSIS
*
*  #include "util.h"
*  int str2int(const char *str, int *val);
*
*  DESCRIPTION
*
*  The routine str2int converts the character string str to a value of
*  integer type and stores the value into location, which the parameter
*  val points to (in the case of error content of this location is not
*  changed).
*
*  RETURNS
*
*  The routine returns one of the following error codes:
*
*  0 - no error;
*  1 - value out of range;
*  2 - character string is syntactically incorrect. */

int str2int(const char *str, int *_val)
{     int d, k, s, val = 0;
      /* scan optional sign */
      if (str[0] == '+')
         s = +1, k = 1;
      else if (str[0] == '-')
         s = -1, k = 1;
      else
         s = +1, k = 0;
      /* check for the first digit */
      if (!isdigit((unsigned char)str[k])) return 2;
      /* scan digits */
      while (isdigit((unsigned char)str[k]))
      {  d = str[k++] - '0';
         if (s > 0)
         {  if (val > INT_MAX / 10) return 1;
            val *= 10;
            if (val > INT_MAX - d) return 1;
            val += d;
         }
         else
         {  if (val < INT_MIN / 10) return 1;
            val *= 10;
            if (val < INT_MIN + d) return 1;
            val -= d;
         }
      }
      /* check for terminator */
      if (str[k] != '\0') return 2;
      /* conversion has been done */
      *_val = val;
      return 0;
}

/*----------------------------------------------------------------------
*  NAME
*
*  str2num - convert character string to value of double type
*
*  SYNOPSIS
*
*  #include "util.h"
*  int str2num(const char *str, double *val);
*
*  DESCRIPTION
*
*  The routine str2num converts the character string str to a value of
*  double type and stores the value into location, which the parameter
*  val points to (in the case of error content of this location is not
*  changed).
*
*  RETURNS
*
*  The routine returns one of the following error codes:
*
*  0 - no error;
*  1 - value out of range;
*  2 - character string is syntactically incorrect. */

int str2num(const char *str, double *_val)
{     int k;
      double val;
      /* scan optional sign */
      k = (str[0] == '+' || str[0] == '-' ? 1 : 0);
      /* check for decimal point */
      if (str[k] == '.')
      {  k++;
         /* a digit should follow it */
         if (!isdigit((unsigned char)str[k])) return 2;
         k++;
         goto frac;
      }
      /* integer part should start with a digit */
      if (!isdigit((unsigned char)str[k])) return 2;
      /* scan integer part */
      while (isdigit((unsigned char)str[k])) k++;
      /* check for decimal point */
      if (str[k] == '.') k++;
frac: /* scan optional fraction part */
      while (isdigit((unsigned char)str[k])) k++;
      /* check for decimal exponent */
      if (str[k] == 'E' || str[k] == 'e')
      {  k++;
         /* scan optional sign */
         if (str[k] == '+' || str[k] == '-') k++;
         /* a digit should follow E, E+ or E- */
         if (!isdigit((unsigned char)str[k])) return 2;
      }
      /* scan optional exponent part */
      while (isdigit((unsigned char)str[k])) k++;
      /* check for terminator */
      if (str[k] != '\0') return 2;
      /* perform conversion */
      {  char *endptr;
         val = strtod(str, &endptr);
         if (*endptr != '\0') return 2;
      }
      /* check for overflow */
      if (!(-DBL_MAX <= val && val <= +DBL_MAX)) return 1;
      /* check for underflow */
      if (-DBL_MIN < val && val < +DBL_MIN) val = 0.0;
      /* conversion has been done */
      *_val = val;
      return 0;
}

/***********************************************************************
*  NAME
*
*  strspx - remove all spaces from character string
*
*  SYNOPSIS
*
*  #include "glplib.h"
*  char *strspx(char *str);
*
*  DESCRIPTION
*
*  The routine strspx removes all spaces from the character string str.
*
*  RETURNS
*
*  The routine returns a pointer to the character string.
*
*  EXAMPLES
*
*  strspx("   Errare   humanum   est   ") => "Errarehumanumest"
*
*  strspx("      ")                       => "" */

char *strspx(char *str)
{     char *s, *t;
      for (s = t = str; *s; s++) if (*s != ' ') *t++ = *s;
      *t = '\0';
      return str;
}

/***********************************************************************
*  NAME
*
*  strtrim - remove trailing spaces from character string
*
*  SYNOPSIS
*
*  #include "glplib.h"
*  char *strtrim(char *str);
*
*  DESCRIPTION
*
*  The routine strtrim removes trailing spaces from the character
*  string str.
*
*  RETURNS
*
*  The routine returns a pointer to the character string.
*
*  EXAMPLES
*
*  strtrim("Errare humanum est   ") => "Errare humanum est"
*
*  strtrim("      ")                => "" */

char *strtrim(char *str)
{     char *t;
      for (t = strrchr(str, '\0') - 1; t >= str; t--)
      {  if (*t != ' ') break;
         *t = '\0';
      }
      return str;
}

/***********************************************************************
*  NAME
*
*  strrev - reverse character string
*
*  SYNOPSIS
*
*  #include "glplib.h"
*  char *strrev(char *s);
*
*  DESCRIPTION
*
*  The routine strrev changes characters in a character string s to the
*  reverse order, except the terminating null character.
*
*  RETURNS
*
*  The routine returns the pointer s.
*
*  EXAMPLES
*
*  strrev("")                => ""
*
*  strrev("Today is Monday") => "yadnoM si yadoT" */

char *strrev(char *s)
{     int i, j;
      char t;
      for (i = 0, j = strlen(s)-1; i < j; i++, j--)
         t = s[i], s[i] = s[j], s[j] = t;
      return s;
}

/***********************************************************************
*  NAME
*
*  fp2rat - convert floating-point number to rational number
*
*  SYNOPSIS
*
*  #include "glplib.h"
*  int fp2rat(double x, double eps, double *p, double *q);
*
*  DESCRIPTION
*
*  Given a floating-point number 0 <= x < 1 the routine fp2rat finds
*  its "best" rational approximation p / q, where p >= 0 and q > 0 are
*  integer numbers, such that |x - p / q| <= eps.
*
*  RETURNS
*
*  The routine fp2rat returns the number of iterations used to achieve
*  the specified precision eps.
*
*  EXAMPLES
*
*  For x = sqrt(2) - 1 = 0.414213562373095 and eps = 1e-6 the routine
*  gives p = 408 and q = 985, where 408 / 985 = 0.414213197969543.
*
*  BACKGROUND
*
*  It is well known that every positive real number x can be expressed
*  as the following continued fraction:
*
*     x = b[0] + a[1]
*                ------------------------
*                b[1] + a[2]
*                       -----------------
*                       b[2] + a[3]
*                              ----------
*                              b[3] + ...
*
*  where:
*
*     a[k] = 1,                  k = 0, 1, 2, ...
*
*     b[k] = floor(x[k]),        k = 0, 1, 2, ...
*
*     x[0] = x,
*
*     x[k] = 1 / frac(x[k-1]),   k = 1, 2, 3, ...
*
*  To find the "best" rational approximation of x the routine computes
*  partial fractions f[k] by dropping after k terms as follows:
*
*     f[k] = A[k] / B[k],
*
*  where:
*
*     A[-1] = 1,   A[0] = b[0],   B[-1] = 0,   B[0] = 1,
*
*     A[k] = b[k] * A[k-1] + a[k] * A[k-2],
*
*     B[k] = b[k] * B[k-1] + a[k] * B[k-2].
*
*  Once the condition
*
*     |x - f[k]| <= eps
*
*  has been satisfied, the routine reports p = A[k] and q = B[k] as the
*  final answer.
*
*  In the table below here is some statistics obtained for one million
*  random numbers uniformly distributed in the range [0, 1).
*
*      eps      max p   mean p      max q    mean q  max k   mean k
*     -------------------------------------------------------------
*     1e-1          8      1.6          9       3.2    3      1.4
*     1e-2         98      6.2         99      12.4    5      2.4
*     1e-3        997     20.7        998      41.5    8      3.4
*     1e-4       9959     66.6       9960     133.5   10      4.4
*     1e-5      97403    211.7      97404     424.2   13      5.3
*     1e-6     479669    669.9     479670    1342.9   15      6.3
*     1e-7    1579030   2127.3    3962146    4257.8   16      7.3
*     1e-8   26188823   6749.4   26188824   13503.4   19      8.2
*
*  REFERENCES
*
*  W. B. Jones and W. J. Thron, "Continued Fractions: Analytic Theory
*  and Applications," Encyclopedia on Mathematics and Its Applications,
*  Addison-Wesley, 1980. */

int fp2rat(double x, double eps, double *p, double *q)
{     int k;
      double xk, Akm1, Ak, Bkm1, Bk, ak, bk, fk, temp;
      if (!(0.0 <= x && x < 1.0))
         xfault("fp2rat: x = %g; number out of range\n", x);
      for (k = 0; ; k++)
      {  xassert(k <= 100);
         if (k == 0)
         {  /* x[0] = x */
            xk = x;
            /* A[-1] = 1 */
            Akm1 = 1.0;
            /* A[0] = b[0] = floor(x[0]) = 0 */
            Ak = 0.0;
            /* B[-1] = 0 */
            Bkm1 = 0.0;
            /* B[0] = 1 */
            Bk = 1.0;
         }
         else
         {  /* x[k] = 1 / frac(x[k-1]) */
            temp = xk - floor(xk);
            xassert(temp != 0.0);
            xk = 1.0 / temp;
            /* a[k] = 1 */
            ak = 1.0;
            /* b[k] = floor(x[k]) */
            bk = floor(xk);
            /* A[k] = b[k] * A[k-1] + a[k] * A[k-2] */
            temp = bk * Ak + ak * Akm1;
            Akm1 = Ak, Ak = temp;
            /* B[k] = b[k] * B[k-1] + a[k] * B[k-2] */
            temp = bk * Bk + ak * Bkm1;
            Bkm1 = Bk, Bk = temp;
         }
         /* f[k] = A[k] / B[k] */
         fk = Ak / Bk;
#if 0
         print("%.*g / %.*g = %.*g", DBL_DIG, Ak, DBL_DIG, Bk, DBL_DIG,
            fk);
#endif
         if (fabs(x - fk) <= eps) break;
      }
      *p = Ak;
      *q = Bk;
      return k;
}

/***********************************************************************
*  NAME
*
*  jday - convert calendar date to Julian day number
*
*  SYNOPSIS
*
*  #include "glplib.h"
*  int jday(int d, int m, int y);
*
*  DESCRIPTION
*
*  The routine jday converts a calendar date, Gregorian calendar, to
*  corresponding Julian day number j.
*
*  From the given day d, month m, and year y, the Julian day number j
*  is computed without using tables.
*
*  The routine is valid for 1 <= y <= 4000.
*
*  RETURNS
*
*  The routine jday returns the Julian day number.
*
*  REFERENCES
*
*  R. G. Tantzen, Algorithm 199: conversions between calendar date and
*  Julian day number, Communications of the ACM, vol. 6, no. 8, p. 444,
*  Aug. 1963. */

int jday(int d, int m, int y)
{     int c, ya, j, dd;
      if (!(1 <= d && d <= 31 && 1 <= m && m <= 12 && 1 <= y &&
            y <= 4000))
#if 0
err:  xerror("jday: d = %d, m = %d, y = %d; invalid date\n", d, m, y);
#else
         return -1;
#endif
      if (m > 2) m -= 3; else m += 9, y--;
      c = y / 100;
      ya = y - 100 * c;
      j = (146097 * c) / 4 + (1461 * ya) / 4 + (153 * m + 2) / 5 + d +
         1721119;
      jdate(j, &dd, NULL, NULL);
#if 0
      if (d != dd) goto err;
#else
      if (d != dd) return -1;
#endif
      return j;
}

/***********************************************************************
*  NAME
*
*  jdate - convert Julian day number to calendar date
*
*  SYNOPSIS
*
*  #include "glplib.h"
*  void jdate(int j, int *d, int *m, int *y);
*
*  DESCRIPTION
*
*  The routine jdate converts a Julian day number j to corresponding
*  calendar date, Gregorian calendar.
*
*  The day d, month m, and year y are computed without using tables and
*  stored in corresponding locations.
*
*  The routine is valid for 1721426 <= j <= 3182395.
*
*  REFERENCES
*
*  R. G. Tantzen, Algorithm 199: conversions between calendar date and
*  Julian day number, Communications of the ACM, vol. 6, no. 8, p. 444,
*  Aug. 1963. */

void jdate(int j, int *_d, int *_m, int *_y)
{     int d, m, y;
      if (!(1721426 <= j && j <= 3182395))
         xerror("jdate: j = %d; Julian day number out of range\n", j);
      j -= 1721119;
      y = (4 * j - 1) / 146097;
      j = 4 * j - 1 - 146097 * y;
      d = j / 4;
      j = (4 * d + 3) / 1461;
      d = 4 * d + 3 - 1461 * j;
      d = (d + 4) / 4;
      m = (5 * d - 3) / 153;
      d = 5 * d - 3 - 153 * m;
      d = (d + 5) / 5;
      y = 100 * y + j;
      if (m < 10) m += 3; else m -= 9, y++;
      if (_d != NULL) *_d = d;
      if (_m != NULL) *_m = m;
      if (_y != NULL) *_y = y;
      return;
}

#if 0
int main(void)
{     int jbeg, jend, j, d, m, y;
      jbeg = jday(1, 1, 1);
      jend = jday(31, 12, 4000);
      for (j = jbeg; j <= jend; j++)
      {  jdate(j, &d, &m, &y);
         xassert(jday(d, m, y) == j);
      }
      xprintf("Routines jday and jdate work correctly.\n");
      return 0;
}
#endif

/* eof */
