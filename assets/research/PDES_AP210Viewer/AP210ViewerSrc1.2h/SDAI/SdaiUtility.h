#ifndef SDAIUTILITY_H
#define SDAIUTILITY_H
/*
 * $Id: SdaiUtility.h,v 1.2 1999/07/17 18:59:56 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include <sdai.h>

// sdai utilities
void _sdaiDisplayNPL(SdaiNPL npl);
const char *_sdaiGetPart21Description(SdaiAppInstance obj);

unsigned long _sdaiGetPart21Id(SdaiAppInstance obj);

SdaiNPL _sdaiInstanceAttributeValueQuery(SdaiNPL inputList,
                                         SdaiAttr attribute,   
                                         SdaiPrimitiveType valueType,
                                         void *value,
                                         SdaiNPL resultList);


SdaiAppInstance _sdaiFindSingleSubTypeInstanceUsedIn(SdaiAppInstance obj,
                                                     SdaiEntity entity,
                                                     SdaiAttr role);

SdaiAppInstance _sdaiFindSingleSubTypeKindOfUsedIn(SdaiAppInstance obj,
                                                   SdaiEntity entity,
                                                   SdaiAttr role);

SdaiNPL _sdaiFindSubTypeInstanceUsedIn(SdaiAppInstance obj,
                                       SdaiEntity entity,
                                       SdaiAttr role,
                                       SdaiNPL resultList);

SdaiString _sdaiGetStringAttrWithQuotesBN(SdaiInstance instance, 
                                          SdaiString attributeName, 
                                          SdaiString *value
                                          );

// General Data navigation utilities 
SdaiAppInstance _sdaiGetSingleRepresentationItemOfType(SdaiAppInstance obj,
                                                       SdaiEntity entity);

void getCartesianLocation(SdaiAppInstance A2P_LOC, double *DeltaX, double *DeltaY, double *angle);

#endif
