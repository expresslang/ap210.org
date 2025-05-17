/*
 *  tess.c
 *  This module is required due to the callbacks
 *  not be compiled in C++.
 */
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "tess.h"

#ifndef CALLBACK 
#define CALLBACK
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

GLUtesselator *tobj;

void CALLBACK beginCallback(GLenum which)
{
   glBegin(which);
}

void CALLBACK errorCallback(GLenum errorCode)
{
   const GLubyte *estring;

   estring = gluErrorString(errorCode);
//   TRACE("Tessellation Error: %s\n", estring);
//   exit(0);
}
void CALLBACK endCallback(void)
{
   glEnd();
}
/*  combineCallback is used to create a new vertex when edges
 *  intersect.  coordinate location is trivial to calculate,
 *  but weight[4] may be used to average color, normal, or texture
 *  coordinate data.  In this program, color is weighted.
 */
void CALLBACK combineCallback(GLdouble coords[3], 
                     GLdouble *vertex_data[4],
                     GLfloat weight[4], GLdouble **dataOut )
{
   GLdouble *vertex;
#ifdef WEIGHTCOLOR
   int i;
#endif
   vertex = (GLdouble *) malloc(6 * sizeof(GLdouble));

   vertex[0] = coords[0];
   vertex[1] = coords[1];
   vertex[2] = coords[2];
#ifdef WEIGHTCOLOR
   for (i = 3; i < 6; i++)
      vertex[i] = weight[0] * vertex_data[0][i] 
                  + weight[1] * vertex_data[1][i]
                  + weight[2] * vertex_data[2][i] 
                  + weight[3] * vertex_data[3][i];
#endif
   *dataOut = vertex;
}
/* Create display list with Torus and initialize state */
void InitTess(void) {
   tobj = gluNewTess();
   gluTessCallback(tobj, GLU_TESS_BEGIN, 
                   beginCallback);

   // GLU_TESS_EDGE_FLAG ?

   gluTessCallback(tobj, GLU_TESS_VERTEX, 
                   glVertex3dv);
   gluTessCallback(tobj, GLU_TESS_END, 
                   endCallback);
   gluTessCallback(tobj, GLU_TESS_ERROR, 
                   errorCallback);
//   gluTessCallback(tobj, GLU_TESS_COMBINE, 
//                   (GLvoid (CALLBACK*) ()) &combineCallback);
   }
