/*
 * $Id: ExtractGeometry.cpp,v 1.3 1999/08/22 05:27:16 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>

#include <sdai.h>
#include <math.h>

#include "AP210SdaiModel.h"
#include "SdaiUtility.h"
#include "MathUtility.h"
#include "../OpenGl/MatrixUtilities.h"
#include "UnitUtility.h"
#include "SdaiStoredProceedures.h"
#include "../IDF2AP210/PopulateBaseCircle.h"
#include "../PWBDataBase.h"

#include "AP210MagicStrings.h"
#include "ExtractGeometry.h"
#include "AP210LP.h"
#include "AP210Point.h"
#include "AP210ObjectList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

AP210ObjectList ExtractGeometry::Lines = AP210ObjectList();
double ExtractGeometry::Factor;
double ExtractGeometry::DeltaX;
double ExtractGeometry::DeltaY;
double ExtractGeometry::U11;
double ExtractGeometry::U12;
double ExtractGeometry::U21;
double ExtractGeometry::U22;

AP210Point *ExtractGeometry::start;
AP210Point *ExtractGeometry::end;

void ExtractGeometry::Initialize() {
   Factor = 1.0;
   DeltaX = 0.0;
   DeltaY = 0.0;
   // set transformation matrix to identity.
   U11 = 1.0;
   U12 = 0.0;
   U21 = 0.0;
   U22 = 1.0;
   }
/*
 * ExtractGeometry::getLines()
 *
 * Need to pass a AP210ObjectList so this can
 * be multithreaded.  Current passing back a 
 * data member.
 */
AP210ObjectList *ExtractGeometry::getLines(SdaiModel AP210Model,
                                           PWBDataBase *PWB,
                                           SdaiNPL lines,
                                           SdaiAppInstance unit,
                                           SdaiAppInstance A2P_LOC) {
   // reset
   Initialize();

#ifdef CLOSEPOLYLINES
   // hack for no closed polylines
   start = NULL;
   end = NULL;
#endif
#ifdef VERBOSE
TRACE0("In ExtractGeometry::getLines()\r\n");
TRACE("unit: %s\n", _sdaiGetPart21Description(unit));
#endif

   if (unit != sdaiNULL) {
      Factor = getUnitConversionFactor(AP210Model, unit, &Factor);
   } 
#ifdef VERBOSE
TRACE("Factor: %f\r\n", Factor);
#endif
   if (A2P_LOC != sdaiNULL) {
      getOffset(AP210Model, A2P_LOC);
      }
#ifdef VERBOSE
TRACE("Offset: (%f, %f)\r\n", DeltaX, DeltaY);
TRACE("Rotation: (%f, %f) (%f, %f)\r\n", U11, U12, U21, U22);
#endif
   // empty the static lines list
   Lines.Empty();
   ExtractSdaiGeometry(AP210Model, PWB, lines);

#ifdef VERBOSE
TRACE0("Returning from ExtractGeometry::getLines()\r\n");
#endif
   return &Lines;
   }
// Currently get the rotation angle.
// I can see getting an OpenGL transformation matrix since
// one is available.
int ExtractGeometry::getLocation(double *x, double *y, double *rotation,
                                 SdaiModel AP210Model,
                                 SdaiAppInstance A2P_LOC,
                                 SdaiAppInstance unit) {
   int result = 0;
   *x = 0.0;
   *y = 0.0;
   *rotation = 0.0;

   // reset
   Initialize();

   if (A2P_LOC != sdaiNULL) {
      if (unit != sdaiNULL) {
         Factor = getUnitConversionFactor(AP210Model, unit, &Factor);
         }
      getOffset(AP210Model, A2P_LOC);
      }
   result = 1;
   *x = DeltaX;
   *y = DeltaY;
   *rotation = asin(U21);

#if 1
   if (*rotation < 0.0) {
      *rotation = *rotation + 2*M_PI;
      }
   else {
      *rotation = acos(U11);
      }
#endif
   // Rotate, Mirror and Translate
//   x = orgx * U11 + orgy * U12 + DeltaX;
//   y = orgx * U21 + orgy * U22 + DeltaY;

#ifdef VERBOSE
TRACE("In ExtractGeometry::getLocation()\r\n");
TRACE("U11: %f, rotation: %f, %f degrees\r\n", U11, acos(U11),  360*(acos(U11)/(2*M_PI)));
TRACE("U21: %f, rotation: %f, %f degrees\r\n", U21, asin(U21),  360*(asin(U21)/(2*M_PI)));
TRACE("U12: %f, rotation: %f, %f degrees\r\n", U12, asin(-U12), 360*(asin(-U12)/(2*M_PI)));
TRACE("U22: %f, rotation: %f, %f degrees\r\n", U22, acos(U22),  360*(acos(U22)/(2*M_PI)));
double m[16];
   _glIdentityMatrixd(m);
   m[0] = U11;
   m[1] = U21;
   m[4] = U12;
   m[5] = U22;
   m[12] = DeltaX;
   m[13] = DeltaY;
_glTraceMatrixd(m);
#endif
   // normalize rotation value
#if 0
   while (*rotation < 0.0) {
TRACE("*rotation: %f\r\n", *rotation);
      *rotation = *rotation + 2*M_PI;
      }
#endif
   return result;
   }
int ExtractGeometry::getTransformationMatrix(double m[16],
                                             SdaiModel AP210Model,
                                             SdaiAppInstance A2P_LOC,
                                             SdaiAppInstance unit) {
	int result = 0;
   // Initialize to identify matrix.

   _glIdentityMatrixd(m);

   // reset
   Initialize();

   if (A2P_LOC != sdaiNULL) {
      if (unit != sdaiNULL) {
         Factor = getUnitConversionFactor(AP210Model, unit, &Factor);
         }
	  getOffset(AP210Model, A2P_LOC);

      result = 1;
      }
   m[0] = U11;
   m[1] = U21;
   m[4] = U12;
   m[5] = U22;

   m[12] = DeltaX;
   m[13] = DeltaY;
#ifdef VERBOSE
TRACE("In ExtractGeometry::getTransformationMatrix()\r\n");
TRACE("U11: %f, rotation: %f, %f degrees\r\n", U11, acos(U11),  360*(acos(U11)/(2*M_PI)));
TRACE("U21: %f, rotation: %f, %f degrees\r\n", U21, asin(U21),  360*(asin(U21)/(2*M_PI)));
TRACE("U12: %f, rotation: %f, %f degrees\r\n", U12, asin(-U12), 360*(asin(-U12)/(2*M_PI)));
TRACE("U22: %f, rotation: %f, %f degrees\r\n", U22, acos(U22),  360*(acos(U22)/(2*M_PI)));
TRACE("2D Determinant: %f\r\n", (U11*U22)-(U12*U21));
_glTraceMatrixd(m);
#endif
   return result;
   }
void ExtractGeometry::setTransformationMatrix(double m[16],
                                              SdaiModel AP210Model,
                                              SdaiAppInstance A2P_LOC,
                                              SdaiAppInstance unit) {
   int result = 0;

   if (A2P_LOC != sdaiNULL) {
      // reset
      Initialize();

      U11 = m[0];
      U21 = m[1];
      U12 = m[4];
      U22 = m[5];

      DeltaX = m[12];
      DeltaY = m[13];

      if (unit != sdaiNULL) {
         Factor = getUnitConversionFactor(AP210Model, unit, &Factor);
         }
      setOffset(AP210Model, A2P_LOC);
      result = 1;
      }

#ifdef VERBOSE
TRACE("In ExtractGeometry::setTransformationMatrix()\r\n");
TRACE("U11: %f, rotation: %f, %f degrees\r\n", U11, acos(U11),  360*(acos(U11)/(2*M_PI)));
TRACE("U21: %f, rotation: %f, %f degrees\r\n", U21, asin(U21),  360*(asin(U21)/(2*M_PI)));
TRACE("U12: %f, rotation: %f, %f degrees\r\n", U12, asin(-U12), 360*(asin(-U12)/(2*M_PI)));
TRACE("U22: %f, rotation: %f, %f degrees\r\n", U22, acos(U22),  360*(acos(U22)/(2*M_PI)));
_glTraceMatrixd(m);
#endif
   }
void ExtractGeometry::getOffset(SdaiModel AP210Model, SdaiAppInstance A2P_LOC) {
   // assuming that A2P_LOC.context_of_items.coordinate_space_dimension is 2.
   static SdaiEntity CTO2D = sdaiGetEntity(AP210Model, "cartesian_transformation_operator_2d");
   static SdaiAttr CTO2D_LO = sdaiGetAttrDefinition(CTO2D, "local_origin");
   static SdaiAttr CTO2D_A1 = sdaiGetAttrDefinition(CTO2D, "axis1");
   static SdaiAttr CTO2D_A2 = sdaiGetAttrDefinition(CTO2D, "axis2");

   static SdaiAttr CP_C = sdaiGetAttrDefinitionBN(AP210, "cartesian_point", "coordinates");
   static SdaiAttr D_R = sdaiGetAttrDefinitionBN(AP210, "direction", "direction_ratios");
   SdaiAppInstance unit = sdaiNULL;
   SdaiAppInstance cro_2d;
   SdaiAppInstance offset;
   SdaiAggr coords;
   SdaiAppInstance axis1 = sdaiNULL;
   SdaiAppInstance axis2 = sdaiNULL;
   SdaiAggr ratios;
   double factor = 1.0; // coordinate location unit conversion factor.

#ifdef VERBOSE
TRACE0("In ExtractGeometry::getOffset()\r\n");
TRACE("For %s\n", _sdaiGetPart21Description(A2P_LOC));
#endif
   if ((unit = getRepresentationLengthUnit(AP210Model, A2P_LOC)) != sdaiNULL) {
      factor = getUnitConversionFactor(AP210Model, unit, &factor); 
      }
   else {
      TRACE("ERROR: No units defined for %s\n",
             _sdaiGetPart21Description(A2P_LOC));
      } 
#ifdef VERBOSE
TRACE("unit: %s\n", _sdaiGetPart21Description(unit));
TRACE("factor: %f\n", factor);
#endif

   cro_2d = _sdaiGetSingleRepresentationItemOfType(A2P_LOC, CTO2D);
#ifdef VERBOSE
TRACE("cro_2d: %s\n", _sdaiGetPart21Description(cro_2d));
#endif

   if (cro_2d != sdaiNULL) {
      sdaiGetAttr(cro_2d, CTO2D_LO, sdaiINSTANCE, &offset);

#ifdef VERBOSE
TRACE("offset: %s\n", _sdaiGetPart21Description(offset));
#endif
      // Get the coordinates LIST
      sdaiGetAttr(offset, CP_C, sdaiAGGR, &coords);

      sdaiGetAggrByIndex(coords, 0, sdaiREAL, &DeltaX);
      sdaiGetAggrByIndex(coords, 1, sdaiREAL, &DeltaY);
      DeltaX = DeltaX * factor;
      DeltaY = DeltaY * factor;

      // Get the rotation LIST and populate the
      // transformation matrix.
      // Reference: base_axis function part42 when
      //            axis1 and axis2 are available.
      // Axis1
      sdaiGetAttr(cro_2d, CTO2D_A1, sdaiINSTANCE, &axis1);
      if (axis1 != sdaiNULL) {
#ifdef VERBOSE
TRACE("axis1: %s\n", _sdaiGetPart21Description(axis1));
#endif
         sdaiGetAttr(axis1, D_R, sdaiAGGR, &ratios);

         sdaiGetAggrByIndex(ratios, 0, sdaiREAL, &U11);
         sdaiGetAggrByIndex(ratios, 1, sdaiREAL, &U21);
#ifdef VERBOSE
TRACE("Read axis1[0]: %g, axis1[1]: %g\r\n", U11, U21);
#endif
         }
      else {
         TRACE("WARNING: axis1 not present in %s\r\n", 
                _sdaiGetPart21Description(cro_2d));
         }
      // Axis2
      sdaiGetAttr(cro_2d, CTO2D_A2, sdaiINSTANCE, &axis2);
      if (axis2 != sdaiNULL) {
#ifdef VERBOSE
TRACE("FOUND A axis2: %s\n", _sdaiGetPart21Description(axis2));
#endif
         sdaiGetAttr(axis2, D_R, sdaiAGGR, &ratios);

         sdaiGetAggrByIndex(ratios, 0, sdaiREAL, &U12);
         sdaiGetAggrByIndex(ratios, 1, sdaiREAL, &U22);
#ifdef VERBOSE
TRACE("Read axis2[0]: %g, axis2[1]: %g\r\n", U12, U22);
#endif
         }
      else {
TRACE("WARNING NO AXIS2\r\n");
         // The second axis may not be provided in a 2D
         // system it needs to be created.
     
         // set U12,U22 to the orthogonal_complment of 
         // U11, U21 per ISO 10303-42:1994(E) build_2axes.
         // assuming that U11 and U21 are normalized.
         U12 = -U21;
         U22 = U11;
          }
      }
   else {
      TRACE("WARNING: No cartesian_transformation_operator_2d found for:\r\n         %s.\r\n", 
            _sdaiGetPart21Description(A2P_LOC));
      }
   }
void ExtractGeometry::setOffset(SdaiModel AP210Model, SdaiAppInstance A2P_LOC) {
   // assuming that A2P_LOC.context_of_items.coordinate_space_dimension is 2.
   static SdaiEntity CTO2D = sdaiGetEntity(AP210Model, "cartesian_transformation_operator_2d");
   static SdaiAttr CTO2D_LO = sdaiGetAttrDefinition(CTO2D, "local_origin");
   static SdaiAttr CTO2D_A1 = sdaiGetAttrDefinition(CTO2D, "axis1");
   static SdaiAttr CTO2D_A2 = sdaiGetAttrDefinition(CTO2D, "axis2");

   static SdaiAttr coordinates = sdaiGetAttrDefinitionBN(AP210, "cartesian_point", "coordinates");
   static SdaiEntity D = sdaiGetEntity(AP210Model, "direction");
   static SdaiAttr D_DR = sdaiGetAttrDefinition(D, "direction_ratios");
   SdaiAppInstance unit = sdaiNULL;
   SdaiAppInstance cro_2d;
   SdaiAppInstance offset;
   SdaiAggr coords;
   SdaiAppInstance axis1 = sdaiNULL;
   SdaiAppInstance axis2 = sdaiNULL;
   SdaiAggr ratios;
   double factor = 1.0; // coordinate location unit conversion factor.

#ifdef VERBOSE
TRACE0("In ExtractGeometry::setOffset()\r\n");
TRACE("For %s\n", _sdaiGetPart21Description(A2P_LOC));
#endif
   if ((unit = getRepresentationLengthUnit(AP210Model, A2P_LOC)) != sdaiNULL) {
      factor = getUnitConversionFactor(AP210Model, unit, &factor); 
      }
   else {
      TRACE("ERROR: No units defined for %s\n",
             _sdaiGetPart21Description(A2P_LOC));
      } 
#ifdef VERBOSE
TRACE("unit: %s\n", _sdaiGetPart21Description(unit));
TRACE("factor: %f\n", factor);
#endif

   cro_2d = _sdaiGetSingleRepresentationItemOfType(A2P_LOC, CTO2D);
#ifdef VERBOSE
TRACE("cro_2d: %s\n", _sdaiGetPart21Description(cro_2d));
#endif

   if (cro_2d != sdaiNULL) {
      sdaiGetAttr(cro_2d, CTO2D_LO, sdaiINSTANCE, &offset);

      // Get the coordinates LIST
      sdaiGetAttr(offset, coordinates, sdaiAGGR, &coords);

      DeltaX = DeltaX/factor;
      DeltaY = DeltaY/factor;

      sdaiPutAggrByIndex(coords, 0, sdaiREAL, DeltaX);
      sdaiPutAggrByIndex(coords, 1, sdaiREAL, DeltaY);

      // Get the rotation LIST and populate the
      // transformation matrix.
      // Reference: base_axis function part42 when
      //            axis1 and axis2 are available.
      // Axis1
      sdaiGetAttr(cro_2d, CTO2D_A1, sdaiINSTANCE, &axis1);
      if (axis1 != sdaiNULL) {
#ifdef VERBOSE
TRACE("axis1: %s\n", _sdaiGetPart21Description(axis1));
TRACE("set U11: %g, U21: %g\r\n", U11, U21);
#endif
         sdaiGetAttr(axis1, D_DR, sdaiAGGR, &ratios);

         sdaiPutAggrByIndex(ratios, 0, sdaiREAL, U11);
         sdaiPutAggrByIndex(ratios, 1, sdaiREAL, U21);
         }
      else {
         TRACE("WARNING: axis1 not present in %s\r\n", 
                _sdaiGetPart21Description(cro_2d));
         }
      // Axis2
      sdaiGetAttr(cro_2d, CTO2D_A2, sdaiINSTANCE, &axis2);
      if (axis2 != sdaiNULL) {
#ifdef VERBOSE
TRACE("axis2: %s\n", _sdaiGetPart21Description(axis2));
TRACE("set U12: %g, U22: %g\r\n", U12, U22);
#endif
         sdaiGetAttr(axis2, D_DR, sdaiAGGR, &ratios);

         sdaiPutAggrByIndex(ratios, 0, sdaiREAL, U12);
         sdaiPutAggrByIndex(ratios, 1, sdaiREAL, U22);
         }
      else {
         axis2 = sdaiCreateInstance(AP210Model, D);
         sdaiPutAttr(cro_2d, CTO2D_A2, sdaiINSTANCE, axis2);
#ifdef VERBOSE
TRACE("Creating axis 2\r\n");
TRACE("axis2: %s\n", _sdaiGetPart21Description(axis2));
TRACE("set U12: %g, U22: %g\r\n", U12, U22);
#endif
         sdaiCreateAggr(axis2, D_DR);
         sdaiGetAttr(axis2, D_DR, sdaiAGGR, &ratios);
         sdaiPutAggrByIndex(ratios, 0, sdaiREAL, U12);
         sdaiPutAggrByIndex(ratios, 1, sdaiREAL, U22);
         }
      }
   else {
      TRACE("WARNING: No cartesian_transformation_operator_2d found for:\r\n         %s.\r\n", 
            _sdaiGetPart21Description(A2P_LOC));
      }
   }
void ExtractGeometry::ExtractSdaiGeometry(SdaiModel AP210Model, PWBDataBase *PWB, SdaiNPL lines) {
   static SdaiEntity PL = sdaiGetEntity(AP210Model, "polyline");
   static SdaiEntity C = sdaiGetEntity(AP210Model, "circle");
   static SdaiEntity TC = sdaiGetEntity(AP210Model, "trimmed_curve");
#ifdef CLOSEPOLYLINES
   int count = 0; // hack for no closed polylines
#endif
   SdaiAppInstance geom;
   SdaiIterator itor = sdaiCreateIterator(lines);
#ifdef VERBOSE
   TRACE0("In ExtractGeometry::ExtractSdaiGeometry()\r\n");
#ifdef CLOSEPOLYLINES
   TRACE0("CLOSEPOLYLINES active\r\n");
#endif
#endif

   while(sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &geom);

      if (sdaiIsInstanceOf(geom, PL)) {
#ifdef CLOSEPOLYLINES
         count++; // hack for no closed polylines
#endif
#ifdef VERBOSE
TRACE0("Found a polyline\r\n");
#endif
         ExtractPolyLine(PWB, geom);
         }
      else if (sdaiIsInstanceOf(geom, TC)) {
#ifdef CLOSEPOLYLINES
         count++; // hack for no closed polylines
#endif
#ifdef VERBOSE
TRACE0("Found a trimmed_curve\r\n");
#endif
         ExtractTrimmedCurve(AP210Model, PWB, geom);
         }
      else if (sdaiIsInstanceOf(geom, C)) {
#ifdef CLOSEPOLYLINES
         count++; // hack for no closed polylines
#endif
#ifdef VERBOSE
TRACE0("Found a circle\r\n");
#endif
         ExtractCircle(AP210Model, PWB, geom);
         }
      else {
#ifdef CLOSEPOLYLINES
         count++; // hack for no closed polylines
#endif
         TRACE0("WARNING: Currently unsupport geometry type\r\n");
         TRACE("          %s\n", _sdaiGetPart21Description(geom));
         _sdaiDisplay(geom);
         }
      }
   sdaiDeleteIterator(itor);

#ifdef CLOSEPOLYLINES
#ifdef VERBOSE
TRACE0("Checking for a closed polyline\r\n");
#endif
   // hack for no closed polylines
   if (count == 1 && start != end && start != NULL && end != NULL ) {
#ifdef VERBOSE
TRACE0("Closing a polyline\r\n");
#endif
      Lines.Add(AP210LP::Construct(PWB, end, start));
      }
#endif
   }
void ExtractGeometry::ExtractPolyLine(PWBDataBase *PWB, SdaiAppInstance pl) {
   static SdaiAttr pointsattr = sdaiGetAttrDefinitionBN(AP210, "polyline", "points");

   SdaiAggr points;
   SdaiAppInstance point;
   AP210Point *p1 = NULL;
   AP210Point *p2 = NULL;
   // get the points LIST
   sdaiGetAttr(pl, pointsattr, sdaiAGGR, &points);

   SdaiIterator itor = sdaiCreateIterator(points);

   while(sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &point);

      p2 = AP210Point::Construct(PWB, point, Factor, DeltaX, DeltaY,
                                 U11, U12, U21, U22);
#ifdef CLOSEPOLYLINES
      // hack for no closed polylines
      if (start == NULL) {
         start = p2;
         }
#endif
      if (p1 != NULL) {
         if (p1 != p2) {
            Lines.Add(AP210LP::Construct(PWB, p1, p2));
            }
         else {
            TRACE("E WARNING: Attempt to create a zero length line at (%f, %f)\r\n",
                  p1->X, p1->Y);
            } 
         }
      p1 = p2;
      }

#ifdef CLOSEPOLYLINES
   // hack for no closed polylines
   end = p2;
#endif
   sdaiDeleteIterator(itor);
   }
void ExtractGeometry::ExtractTrimmedCurve(SdaiModel AP210Model,
                                          PWBDataBase *PWB, 
                                          SdaiAppInstance tc) {
   static SdaiEntity C = sdaiGetEntity(AP210Model, "circle");
   static SdaiAttr C_R = sdaiGetAttrDefinition(C, "radius");
   static SdaiAttr C_P = sdaiGetAttrDefinition(C, "position");

   static SdaiEntity P = sdaiGetEntity(AP210Model, "placement");
   static SdaiAttr P_L = sdaiGetAttrDefinition(P, "location");

   static SdaiEntity TC = sdaiGetEntity(AP210Model, "trimmed_curve");
   static SdaiAttr TC_BC = sdaiGetAttrDefinition(TC, "basis_curve");
   static SdaiAttr TC_T1 = sdaiGetAttrDefinition(TC, "trim_1");
   static SdaiAttr TC_T2 = sdaiGetAttrDefinition(TC, "trim_2");
   static SdaiAttr TC_SA = sdaiGetAttrDefinition(TC, "sense_agreement");
   AP210Point *p1;
   AP210Point *p2;
#if 0
   AP210Point *tp;  // swap pointer
#endif
   SdaiBoolean sense_agreement;
   SdaiAggr trim;
   SdaiAppInstance basis_curve;
   SdaiReal radius;
   SdaiAppInstance position;
   SdaiAppInstance location;
   AP210Point *center;

   sdaiGetAttr(tc, TC_BC, sdaiINSTANCE, &basis_curve);
#ifdef VERBOSE
TRACE("Get p1\r\n");
#endif

   // A trimmed_curve
   sdaiGetAttr(tc, TC_T1, sdaiAGGR, &trim);
   p1 = ExtractTrimSelectCoordinate(AP210Model, PWB, trim);
#ifdef VERBOSE
TRACE("Get p2\r\n");
#endif

   sdaiGetAttr(tc, TC_T2, sdaiAGGR, &trim);
   p2 = ExtractTrimSelectCoordinate(AP210Model, PWB, trim);

   // if the sense_agreement is false swap the points.
   sdaiGetAttr(tc, TC_SA, sdaiBOOLEAN, &sense_agreement);
#if 0
   if (sense_agreement == sdaiFALSE) {
      tp = p1;
      p1 = p2;
      p2 = tp;
      }
#endif
   if (sdaiIsInstanceOf(basis_curve, C)) {
      // Found a circle
      sdaiGetAttr(basis_curve, C_R, sdaiREAL, &radius);
      sdaiGetAttr(basis_curve, C_P, sdaiINSTANCE, &position);
      sdaiGetAttr(position, P_L, sdaiINSTANCE, &location);
      center = AP210Point::Construct(PWB, location, Factor,
                                     DeltaX, DeltaY,
                                     U11, U12, U21, U22);
      BuildArc(PWB, sense_agreement, p1, p2, center);

#ifdef IDFDELETEBUG
      delete center;
#endif
	   }
   else {
      // Idealize as a line segment if the basis_curve is
      // not a circle.
      Lines.Add(AP210LP::Construct(PWB, p1, p2));
	   }
   }
void ExtractGeometry::ExtractCircle(SdaiModel AP210Model,
                                    PWBDataBase *PWB, 
                                    SdaiAppInstance circle) {
   static SdaiEntity C = sdaiGetEntity(AP210Model, "circle");
   static SdaiAttr C_R = sdaiGetAttrDefinition(C, "radius");
   static SdaiAttr C_P = sdaiGetAttrDefinition(C, "position");

   static SdaiEntity P = sdaiGetEntity(AP210Model, "placement");
   static SdaiAttr P_L = sdaiGetAttrDefinition(P, "location");

   SdaiReal radius;
   SdaiAppInstance position;
   SdaiAppInstance location;
   AP210Point *center;

   // Extract the circles parameters
   sdaiGetAttr(circle, C_R, sdaiREAL, &radius);
   sdaiGetAttr(circle, C_P, sdaiINSTANCE, &position);
   sdaiGetAttr(position, P_L, sdaiINSTANCE, &location);
   center = AP210Point::Construct(PWB, location, Factor,
                                  DeltaX, DeltaY,
                                  U11, U12, U21, U22);
   BuildCircle(PWB, radius, center);

#ifdef IDFDELETEBUG
   delete center;
#endif
   }
AP210Point *ExtractGeometry::ExtractTrimSelectCoordinate(SdaiModel AP210Model,
                                                         PWBDataBase *PWB,
                                                         SdaiAggr trim) {
   // This is an interesting case because trim is
   // a set that contains both SdaiReal and SdaiAppInstance.
   // Therefore an Attribute Data Block (SdaiADB) must be used.
   static SdaiEntity cartesian_point = sdaiGetEntity(AP210Model, "cartesian_point");
   AP210Point *point = sdaiNULL;
   SdaiADB adb = sdaiCreateEmptyADB();

   SdaiAppInstance coord;

   SdaiIterator itor = sdaiCreateIterator(trim);

   while(sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiADB, &adb);

      if (sdaiGetADBType(adb) == sdaiINSTANCE) {
         sdaiGetADBValue(adb, sdaiINSTANCE, &coord);

         if (sdaiIsInstanceOf(coord, cartesian_point)) {
            point = AP210Point::Construct(PWB, coord, Factor,
                                          DeltaX, DeltaY,
                                          U11, U12, U21, U22);
            }
         }
      }
   sdaiDeleteIterator(itor);
   sdaiDeleteADB(adb);
   return(point);
   }
void ExtractGeometry::BuildCircle(PWBDataBase *PWB,
                                  SdaiReal Radius,
                                  AP210Point *Center) {
   SdaiReal radian;

   // added for arc work
   SdaiReal startx = Center->X;
   // scaling the radius by Factor.
   SdaiReal starty = Center->Y + Radius*Factor;
   AP210Point *Start;
   AP210Point *mid;
   AP210Point *End;
	SdaiReal midx;
	SdaiReal midy;
   SdaiReal Increment = 10;
	SdaiReal DeltaAngle;
   SdaiReal xc = Center->X;
   SdaiReal yc = Center->Y;

	End = AP210Point::Construct(PWB, startx, starty);
   Start = End;
   radian = 2 * M_PI; // CalculateAngle(Start, End, Center);

   // Determine the increment sign of the increment.
   DeltaAngle = (Increment/180.0)*M_PI;

   if (radian < 0.0) {
      DeltaAngle = -DeltaAngle;
      }
   radian -= DeltaAngle;

   // take angle to zero to count segments.
   while (fabs(radian) > fabs(DeltaAngle)) {
      // calculate a mid point
	   midx = (startx-xc)*cos(DeltaAngle) - (starty-yc)*sin(DeltaAngle) + xc;
      midy = (startx-xc)*sin(DeltaAngle) + (starty-yc)*cos(DeltaAngle) + yc;

		mid = AP210Point::Construct(PWB, midx, midy);
   	Lines.Add(AP210LP::Construct(PWB, Start, mid));
      Start = mid;
      startx = midx;
      starty = midy;

      radian -= DeltaAngle;
      }
   Lines.Add(AP210LP::Construct(PWB, Start, End));
   }
void ExtractGeometry::BuildArc(PWBDataBase *PWB,
                               SdaiBoolean sense_agreement,
                               AP210Point *Start,
                               AP210Point *End,
                               AP210Point *Center) {
   SdaiReal radian;

   // added for arc work
   SdaiReal startx = Start->X;
   SdaiReal starty = Start->Y;
   AP210Point *mid;
	SdaiReal midx;
	SdaiReal midy;
   SdaiReal Increment = 10;
	SdaiReal DeltaAngle;
   SdaiReal xc = Center->X;
   SdaiReal yc = Center->Y;

   radian = CalculateAngle(Start, End, Center);

   // Determine the increment sign of the increment.
   DeltaAngle = (Increment/180.0)*M_PI;

   if (sense_agreement == sdaiFALSE) {
      radian = -radian;
      }
   if (radian < 0.0) {
      DeltaAngle = -DeltaAngle;
      }
   radian -= DeltaAngle;

   // take angle to zero to count segments.
   while (fabs(radian) > fabs(DeltaAngle)) {
      // calculate a mid point
	   midx = (startx-xc)*cos(DeltaAngle) - (starty-yc)*sin(DeltaAngle) + xc;
      midy = (startx-xc)*sin(DeltaAngle) + (starty-yc)*cos(DeltaAngle) + yc;

		mid = AP210Point::Construct(PWB, midx, midy);
   	Lines.Add(AP210LP::Construct(PWB, Start, mid));
      Start = mid;
      startx = midx;
      starty = midy;

      radian -= DeltaAngle;
      }
   Lines.Add(AP210LP::Construct(PWB, Start, End));
   }
/*
 * CalculateAngle()
 *
 * Using the Law of Cosines calculate the sweep angle between
 * the Start and End points for an arc centered at Center.
 *
 *    Cos(radian) = (b*b + c*c - a*a)/(2*b*c)
 */
double ExtractGeometry::CalculateAngle(AP210Point *Start, AP210Point *End, AP210Point *Center) {
   
   double a = pythagorean_theorem((Start->X - End->X), (Start->Y - End->Y));
   double c = pythagorean_theorem((End->X - Center->X), (End->Y - Center->Y));
   double b = pythagorean_theorem((Start->X - Center->X), (Start->Y - Center->Y));

   double radian = acos((b*b + c*c - a*a)/(2*b*c));

   return radian;
   }
