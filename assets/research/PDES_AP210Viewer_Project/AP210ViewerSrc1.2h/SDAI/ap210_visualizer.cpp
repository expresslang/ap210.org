/*
 * $Id: ap210_visualizer.cpp,v 1.3 1999/08/22 05:26:26 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdio.h>
#include <string.h>

#include <sdai.h>

#include "AP210SdaiModel.h"
#include "SdaiStoredProceedures.h"

#include "ap210_visualizer.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/*
 * GetComponentGeometry()
 *
 * Given a packaged_component representing a component
 * occurance return a shape_representation defined
 * for the "design profile".
 *
 */
SdaiAppInstance getComponentGeometry(SdaiModel AP210Model, SdaiAppInstance pc)
   {
   static SdaiAttr description = sdaiGetAttrDefinitionBN(AP210,
                                 "property_definition",
                                 "description");
   SdaiAppInstance p;
   SdaiAppInstance sr = sdaiNULL;
#ifdef VERBOSE
TRACE0("In GetComponentGeometry()\r\n");
TRACE("packaged_component: %s\r\n", _sdaiGetPart21Description(pc));
#endif
   // Get the packaged_components package
   p = getPackagedComponentPackage(AP210Model, pc);
#ifdef VERBOSE
TRACE("package: %s\r\n", _sdaiGetPart21Description(p));
#endif
   sr = getPackageGeometry(AP210Model, p);

   return(sr);
   }
/*
 * getPackageGeometry()
 *
 * Given a package return a shape_representation defined
 * for the "design profile".
 */
SdaiAppInstance getPackageGeometry(SdaiModel AP210Model, SdaiAppInstance p)
   {
   static SdaiAttr description = sdaiGetAttrDefinitionBN(AP210,
                                 "property_definition",
                                 "description");
   SdaiAppInstance sr = sdaiNULL;
   SdaiAppInstance geom_prop;
#ifdef VERBOSE
TRACE0("In getPackageGeometry()\r\n");
TRACE("package: %s\r\n", _sdaiGetPart21Description(p));
#endif

   // get a "design profile" property.
   geom_prop = getPropertyDefinition(AP210Model, p, "design profile", description);
#ifdef VERBOSE
TRACE("PlacementOutline: %s\r\n", _sdaiGetPart21Description(geom_prop));
#endif

   if (geom_prop != sdaiNULL) {
      sr = getGraphicPropertiesShapeRep(AP210Model, geom_prop);
      }
#ifdef VERBOSE
TRACE("Shape Rep: %s\r\n", _sdaiGetPart21Description(sr));
#endif
   return(sr);
   }
