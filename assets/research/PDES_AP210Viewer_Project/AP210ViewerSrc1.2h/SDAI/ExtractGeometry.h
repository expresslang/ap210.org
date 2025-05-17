#ifndef EXTRACTGEOMETRY_H
#define EXTRACTGEOMETRY_H
/*
 * $Id: ExtractGeometry.h,v 1.2 1999/08/22 05:27:29 keenan Exp $
 * Auth: Michael T. Keenan
 */

#include "sdai.h"

#include "AP210ObjectList.h"

class AP210LP;
class ComponentDefinition;
class BoardComponent;

#define CLOSEPOLYLINES

class ExtractGeometry {
   private:
      static double Factor;
      static double DeltaX;
      static double DeltaY;
      static double U11;
      static double U12;
      static double U21;
      static double U22;
#ifdef CLOSEPOLYLINES
      static AP210Point *start; // hack for no closed polylines
      static AP210Point *end;   // hack for no closed polylines
#endif
      static AP210ObjectList Lines;

   public:
      static AP210ObjectList *getLines(SdaiModel AP210Model,
                                       PWBDataBase *PWB, 
                                       SdaiNPL lines,
                                       SdaiAppInstance unit = sdaiNULL,
                                       SdaiAppInstance A2P_LOC = sdaiNULL);
      static int getLocation(double *x, double *y,
                             double *rotation,
                             SdaiModel AP210Model,
                             SdaiAppInstance A2P_LOC = sdaiNULL,
                             SdaiAppInstance unit = sdaiNULL);
      static int getTransformationMatrix(double m[16],
                                         SdaiModel AP210Model,
                                         SdaiAppInstance A2P_LOC,
                                         SdaiAppInstance unit);
      static void setTransformationMatrix(double m[16],
                                         SdaiModel AP210Model,
                                         SdaiAppInstance A2P_LOC,
                                         SdaiAppInstance unit);
   private:
      static void Initialize();

      static void BuildArc(PWBDataBase *PWB,
                           SdaiBoolean sense_agreement,
                           AP210Point *Start,
                           AP210Point *End,
                           AP210Point *Center);
      static void BuildCircle(PWBDataBase *PWB,
                              SdaiReal Radius,
                              AP210Point *Center);
      static double CalculateAngle(AP210Point *Start,
                                   AP210Point *End,
                                   AP210Point *Center);
      static void getOffset(SdaiModel AP210Model,
                            SdaiAppInstance A2P_LOC);
      static void setOffset(SdaiModel AP210Model,
                            SdaiAppInstance A2P_LOC);
      static void ExtractSdaiGeometry(SdaiModel AP210Model,
                                      PWBDataBase *PWB,
                                      SdaiNPL lines);
      static void ExtractPolyLine(PWBDataBase *PWB,
                                  SdaiAppInstance pl);
      static void ExtractTrimmedCurve(SdaiModel AP210Model,
                                      PWBDataBase *PWB,
                                      SdaiAppInstance tc);
      static void ExtractCircle(SdaiModel AP210Model,
                                PWBDataBase *PWB,
                                SdaiAppInstance circle);
      static AP210Point *ExtractTrimSelectCoordinate(SdaiModel AP210Model,
                                                     PWBDataBase *PWB, 
                                                     SdaiAggr trim);
   private:
      ExtractGeometry();
   public:
      ~ExtractGeometry();
   };
#endif 
