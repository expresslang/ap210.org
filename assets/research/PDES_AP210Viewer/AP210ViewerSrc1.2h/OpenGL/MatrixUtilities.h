#ifndef MATRIXUTILITIES_H
#define MATRIXUTILITIES_H

#define TORAD(x) ((M_PI/180.0)*(x))
#define TODEG(x) ((180.0/M_PI)*(x))

extern double Y180Degrees[16];

void normalize(GLfloat v[3]);
void ncrossprod(float v1[3], float v2[3], float cp[3]);

void _glIdentityMatrixd(double m[16]);
void _glCopyMatrixd(double from[16], double to[16]);
void _glMultiplyMatrixd(double m1[16], double m2[16], double result[16]);
void _glTraceMatrixd(double m[16]);
void _glDefineMatrixd(double m[16], char *name);

#endif