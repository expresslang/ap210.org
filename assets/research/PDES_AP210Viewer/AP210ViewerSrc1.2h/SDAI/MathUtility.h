#ifndef MATHUTILITY_H
#define MATHUTILITY_H
/*
 * $Id: MathUtility.h,v 1.1 1999/07/05 06:09:49 keenan Exp $
 * Auth: Michael T. Keenan
 */
//extern double epsilon;


extern const double pi;
extern const double twopi;

double Min(double a, double b);
double Max(double a, double b);
int NearZero(double val);
double VectorAngle(double x1, double y1, double x2, double y2, double x3, double y3);

#endif


