#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <math.h>

#include "MatrixUtilities.h"

// Transformation matrix for 180 degree rotation about the Y axis.
double Y180Degrees[16] = { -1.000000, 0.000000,  0.000000, 0.000000, 
                            0.000000, 1.000000,  0.000000, 0.000000, 
                            0.000000, 0.000000, -1.000000, 0.000000, 
                            0.000000, 0.000000,  0.000000, 1.000000 };

/***************************************************************/
/*********************** VECTOR STUFF **************************/
/***************************************************************/
/*
Name        : gemmw
Description : a highly portable Level 3 BLAS implementation of Winograd's
              variant of Strassen's matrix multiplication algorithm
Where       : in misc on Netlib
Author      : Craig C. Douglas, douglas-craig@CS.YALE.EDU
Version     : 22 May 1992

OpenGL has no equivalent to the polarview function.
You can replace it easily with a translation and three rotations.
For example, you can translate: 
polarview(distance, azimuth, incidence, twist);
 
to: 

glTranslatef( 0.0, 0.0, -distance); 
glRotatef( -twist, 0.0, 0.0, 1.0); 
glRotatef( -incidence, 1.0, 0.0, 0.0); 
glRotatef( -azimuth, 0.0, 0.0, 1.0); 

*/
  /* normalizes v */
void normalize(GLfloat v[3])
{
  GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);

  if (d == 0)
    fprintf(stderr, "Zero length vector in normalize\n");
  else
    v[0] /= d; v[1] /= d; v[2] /= d;
}

  /* calculates a normalized crossproduct to v1, v2 */
void ncrossprod(float v1[3], float v2[3], float cp[3])
{
  cp[0] = v1[1]*v2[2] - v1[2]*v2[1];
  cp[1] = v1[2]*v2[0] - v1[0]*v2[2];
  cp[2] = v1[0]*v2[1] - v1[1]*v2[0];
  normalize(cp);
}
void _glIdentityMatrixd(double m[16]) {
   m[0] = 1.0;
   m[1] = 0.0;
   m[2] = 0.0;
   m[3] = 0.0;

   m[4] = 0.0;
   m[5] = 1.0;
   m[6] = 0.0;
   m[7] = 0.0;

   m[8] = 0.0;
   m[9] = 0.0;
   m[10] = 1.0;
   m[11] = 0.0;

   m[12] = 0.0;
   m[13] = 0.0;
   m[14] = 0.0;
   m[15] = 1.0;
   }

void _glCopyMatrixd(double from[16], double to[16]) {
   to[0] = from[0];
   to[1] = from[1];
   to[2] = from[2];
   to[3] = from[3];

   to[4] = from[4];
   to[5] = from[5];
   to[6] = from[6];
   to[7] = from[7];

   to[8] = from[8];
   to[9] = from[9];
   to[10] = from[10];
   to[11] = from[11];

   to[12] = from[12];
   to[13] = from[13];
   to[14] = from[14];
   to[15] = from[15];
   }
void _glMultiplyMatrixd(double m1[16], double m2[16], double result[16]) {
   double temp[16];

   temp[0]  = m1[0]*m2[0]  + m1[4]*m2[1]  + m1[8]*m2[2]  +m1[12]*m2[3];
   temp[4]  = m1[0]*m2[4]  + m1[4]*m2[5]  + m1[8]*m2[6]  +m1[12]*m2[7];
   temp[8]  = m1[0]*m2[8]  + m1[4]*m2[9]  + m1[8]*m2[10] +m1[12]*m2[11];
   temp[12] = m1[0]*m2[12] + m1[4]*m2[13] + m1[8]*m2[14] +m1[12]*m2[15];

   temp[1]  = m1[1]*m2[0]  + m1[5]*m2[1]  + m1[9]*m2[2]  + m1[13]*m2[3];
   temp[5]  = m1[1]*m2[4]  + m1[5]*m2[5]  + m1[9]*m2[6]  + m1[13]*m2[7];
   temp[9]  = m1[1]*m2[8]  + m1[5]*m2[9]  + m1[9]*m2[10] + m1[13]*m2[11];
   temp[13] = m1[1]*m2[12] + m1[5]*m2[13] + m1[9]*m2[14] + m1[13]*m2[15];

   temp[2]  = m1[2]*m2[0]  + m1[6]*m2[1]  + m1[10]*m2[2]  + m1[14]*m2[3];
   temp[6]  = m1[2]*m2[4]  + m1[6]*m2[5]  + m1[10]*m2[6]  + m1[14]*m2[7];
   temp[10] = m1[2]*m2[8]  + m1[6]*m2[9]  + m1[10]*m2[10] + m1[14]*m2[11];
   temp[14] = m1[2]*m2[12] + m1[6]*m2[13] + m1[10]*m2[14] + m1[14]*m2[15];

   temp[3]  = m1[3]*m2[0]  + m1[7]*m2[1]  + m1[11]*m2[2]  + m1[15]*m2[3];
   temp[7]  = m1[3]*m2[4]  + m1[7]*m2[5]  + m1[11]*m2[6]  + m1[15]*m2[7];
   temp[11] = m1[3]*m2[8]  + m1[7]*m2[9]  + m1[11]*m2[10] + m1[15]*m2[11];
   temp[15] = m1[3]*m2[12] + m1[7]*m2[13] + m1[11]*m2[14] + m1[15]*m2[15];

   _glCopyMatrixd(temp, result);
   }


void _glTraceMatrixd(double m[16]) {
#ifdef VERBOSE
TRACE("2D Determinant (m[0]*m[5])-(m[4]*m[1]): %f m[0]*m[5]): %f (m[4]*m[1]): %f\r\n ",
                 (m[0]*m[5])-(m[4]*m[1]), (m[0]*m[5]),(m[4]*m[1]));
#endif
   TRACE("Transformation Matrix\r\n");
   TRACE("+-\r\n");
   TRACE("| %f, %f, %f, %f |\r\n", m[0], m[4], m[8], m[12]);
   TRACE("| %f, %f, %f, %f |\r\n", m[1], m[5], m[9], m[13]);
   TRACE("| %f, %f, %f, %f |\r\n", m[2], m[6], m[10], m[14]);
   TRACE("| %f, %f, %f, %f |\r\n", m[3], m[7], m[11], m[15]);
   TRACE("+-\r\n");
   }

void _glDefineMatrixd(double m[16], char *name) {
   char str[256];
   sprintf(str, "double %s[16] = { ", name);
   int i;
   TRACE(str);

   for(i = 0; i < 16; i++) {
      TRACE("%f", m[i]);
      if (i != 15) {
         TRACE(", ");
         }
      if (i == 3 || i == 7 || i == 11) {
         char *p = &str[0];

         TRACE("\r\n");
         while(*p != '\0') {
            TRACE(" ");
            p++;
            }
         }
      }
   TRACE(" };\r\n");
   }