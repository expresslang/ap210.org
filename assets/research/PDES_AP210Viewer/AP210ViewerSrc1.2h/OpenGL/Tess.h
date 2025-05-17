#ifndef TESS_H
#define TESS_H
/*
 *  tess.h
 *  This module is required due to the callbacks
 *  not compiling in C++.
 */

#ifdef __cplusplus
extern "C" {
#endif

extern GLUtesselator *tobj;

/* Create display list with Torus and initialize state */
void InitTess(void);

#ifdef __cplusplus
}
#endif
#endif