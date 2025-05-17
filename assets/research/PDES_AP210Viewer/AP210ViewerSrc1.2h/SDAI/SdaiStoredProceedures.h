#ifndef SDAISTOREDPROCEEDURES_H
#define SDAISTOREDPROCEEDURES_H
/*
 * $Id: SdaiStoredProceedures.h,v 1.5 1999/08/22 05:27:59 keenan Exp $
 * Auth: Michael T. Keenan
 */
// AP210 specific Data navigation utilities 
SdaiNPL getComponentDescriptiveRepresentationItemList(SdaiModel AP210Model,
                                                      SdaiAppInstance pc);
SdaiAppInstance getPropertyDefinition(SdaiModel AP210Model,
                                      SdaiAppInstance obj,
                                      char *value,
                                      SdaiAttr attribute);

SdaiAppInstance getNamedProductDefinitionRelationship(SdaiModel AP210Model,
                                                      SdaiAppInstance obj,
                                                      SdaiString pdrName,
                                                      SdaiAttr attribute); 

SdaiNPL getNamedProductDefinitionRelationships(SdaiModel AP210Model,
                                               SdaiAppInstance obj,
                                               SdaiString pdrName,
                                               SdaiAttr attribute,
                                               SdaiNPL uppdrlist);

SdaiAppInstance getGraphicPropertiesShapeRep(SdaiModel AP210Model, SdaiAppInstance prop);

SdaiAppInstance getRepresentationLengthUnit(SdaiModel AP210Model, SdaiAppInstance sr);
SdaiAppInstance getNamedProductDefinitionShapeAspect(SdaiModel AP210Model, SdaiAppInstance prod);

// Generic Geometry get routines.
SdaiNPL getGeometryFromShapeRep(SdaiModel AP210Model, SdaiAppInstance sr);
void getGeometryFromGeometricCurveSet(SdaiModel AP210Model, SdaiAppInstance gcs, SdaiIterator curveitor);
void getGeometryFromCompositeCurve(SdaiModel AP210Model, SdaiAppInstance cc, SdaiIterator curveitor);
void getGeometryFromAnnotationCurveOccurance(SdaiModel AP210Model, SdaiAppInstance aco, SdaiIterator curveitor);
void getGeometryFromCircle(SdaiModel AP210Model, SdaiAppInstance circle, SdaiIterator curveitor);

// Physical_Unit functions
SdaiAppInstance getPhysicalUnitsProductRelatedProductCategory(SdaiAppInstance pu);
SdaiAppInstance getPhysicalUnitsProduct(SdaiModel AP210Model, SdaiAppInstance p);
SdaiString getPhysicalUnitsPartNumber(SdaiModel AP210Model, SdaiAppInstance p);
double getPhysicalUnitsHeight(SdaiModel AP210Model, SdaiAppInstance p);
void setPhysicalUnitsHeight(SdaiModel AP210Model, SdaiAppInstance p, double height);

// Package functions
SdaiAppInstance getPackageShapeRepresentation(SdaiModel AP210Model, SdaiAppInstance pc);
double getPackageHeight(SdaiModel AP210Model, SdaiAppInstance p);
void setPackageHeight(SdaiModel AP210Model, SdaiAppInstance p, double height);

// Packaged_Part functions
SdaiAppInstance getPackagedPartProduct(SdaiModel AP210Model, SdaiAppInstance pp);
SdaiAppInstance getPackagedPartPackage(SdaiModel AP210Model, SdaiAppInstance pp);
SdaiString getPackagedPartPartNumber(SdaiModel AP210Model, SdaiAppInstance pp);

// Interconnect Module functions.
SdaiAppInstance getBoardOutlineDefinitions(char *designame);
SdaiAppInstance getInterconnectModuleEdgeShapeRep(SdaiModel AP210Model, SdaiAppInstance pu);
SdaiAppInstance getInterconnectModuleEdgeSurfaceShapeRep(SdaiModel AP210Model, SdaiAppInstance pu);
SdaiAppInstance getLocatedInterconnectModuleThickness(SdaiModel AP210Model, SdaiAppInstance pu);
double getPCBThickness(SdaiModel AP210Model, SdaiAppInstance pu);
void setPCBThickness(SdaiModel AP210Model, SdaiAppInstance pu, double thickness);
SdaiAppInstance getInterconnectModuleComponentDefinition(SdaiModel AP210Model, SdaiAppInstance pu);
SdaiNPL getMountingRestrictionAreas(SdaiModel AP210Model, SdaiNPL result, SdaiAppInstance cd);

// basic navigation functions
SdaiAppInstance getNamedRelatingShapeAspect(SdaiModel AP210Model, SdaiAppInstance obj, SdaiString name);
SdaiAppInstance getNamedRelatedShapeAspect(SdaiModel AP210Model, SdaiAppInstance obj, SdaiString name);
SdaiAppInstance getNamedRepresentation(SdaiModel AP210Model, SdaiAppInstance cd, SdaiString name);
SdaiAppInstance getNamedRepresentationItem(SdaiModel AP210Model, SdaiAppInstance rep, SdaiString name);
SdaiReal getLengthMeasureWithUnit(SdaiModel AP210Model, SdaiAppInstance length);
void setLengthMeasureWithUnit(SdaiModel AP210Model, SdaiAppInstance length, double value);

SdaiAppInstance getNamedRepresentationRelationship(SdaiModel AP210Model, 
                                                   SdaiAppInstance obj,
                                                   SdaiAttr attribute,
                                                   char *name);
// Packaged_Component functions
double getPackagedComponentHeight(SdaiModel AP210Model, SdaiAppInstance pc);
SdaiAppInstance getPackagedComponentPackagedPart(SdaiModel AP210Model, SdaiAppInstance pc);
SdaiAppInstance getPackagedComponentPackage(SdaiModel AP210Model, SdaiAppInstance pc);
SdaiAppInstance getPackagedComponentLocation(SdaiModel AP210Model, SdaiAppInstance nauo);

SdaiAppInstance getPackagedComponentProduct(SdaiModel AP210Model, SdaiAppInstance pc);
SdaiAppInstance getComponentDefinitionShapeRepresentation(SdaiModel AP210Model, SdaiAppInstance pc);

SdaiString getPackagedComponentPartNumber(SdaiModel AP210Model, SdaiAppInstance pc);


// Product_Definition functions
SdaiAppInstance getProductDefinitionProduct(SdaiModel AP210Model, SdaiAppInstance pd);
SdaiAppInstance getProductDefinitionPhysicalUnit(SdaiModel AP210Model, SdaiAppInstance pd);

#endif
