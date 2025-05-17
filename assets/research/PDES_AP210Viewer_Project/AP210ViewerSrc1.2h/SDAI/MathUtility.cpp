/*
 * $Id: MathUtility.cpp,v 1.2 1999/07/17 19:00:22 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <math.h>

#include "MathUtility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

double epsilon = 0.000000001;


const double pi = 3.141592653589793116;
const double twopi = 2.0*pi;

double Min(double a, double b) {
   if (a < b) {
      return a;
      }
   else {
      return b;
      }
   }
double Max(double a, double b) {
   if (a > b) {
      return a;
      }
   else {
      return b;
      }
   }
int NearZero(double val) {
   return (fabs(val) <= epsilon);
   }
/*
 * VectorAngle
 *
 *  Returns the angle in radians between the
 *  two vectors define by v1 and v2. Which are
 *  defined as: v1 -> [(x1, y1), (x2, y2)]
 *              v2 -> [(x1, y1), (x3, y3)]
 */
double VectorAngle(double x1, double y1, double x2, double y2, double x3, double y3)
   {
   double ang = 0.0;
   
   double pi = 3.141592653589793116;
   double twopi = 2.0*pi;

   double dx1 = x2 - x1;
   double dy1 = y2 - y1;

   if (   NearZero(dx1) && NearZero(dy1)) { /* bad input */
      return -1000.0;
      }
   double dx2 = x3 - x1;
   double dy2 = y3 - y1;


   if (   NearZero(dx2) && NearZero(dy2)) { /* bad input */
      return -1000.0;
      }
   double tem1 = atan2(dy2, dx2);
   double tem2 = atan2(dy1, dx1);

   ang = tem1 - tem2;

   /* Normalize the angle */
   if (fabs(ang) > pi) {
      if (ang > 0) {
         ang = ang - twopi;
         }
      else {
         ang = ang + twopi;
         }
      }
   return ang;
   }
