/*
 * $Id: SdaiStoredProceedures.cpp,v 1.7 1999/08/22 05:27:45 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <rose.h>
#include <sdai.h>

#include "AP210SdaiModel.h"
#include "AP210MagicStrings.h"
#include "SdaiUtility.h"
#include "UnitUtility.h"
#include "SdaiStoredProceedures.h"

#ifdef CACHETEST
#include "SdaiCache.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void tracePhysicalUnitView(SdaiModel AP210Model, SdaiAppInstance pu);

// These functions are general data navigation functions.
SdaiAppInstance getNamedRelatingShapeAspect(SdaiModel AP210Model, SdaiAppInstance obj, SdaiString name) {
   static SdaiEntity SAR = sdaiGetEntity(AP210Model, "shape_aspect_relationship");
   static SdaiAttr SAR_ED = sdaiGetAttrDefinition(SAR, "related_shape_aspect");
   static SdaiAttr SAR_NAME = sdaiGetAttrDefinition(SAR, "name");
   static SdaiAttr SAR_ING = sdaiGetAttrDefinition(SAR, "relating_shape_aspect");

   SdaiIterator itor;
   SdaiString attr_value;
   SdaiAppInstance sa = sdaiNULL;
   SdaiAppInstance sar;
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();
#ifdef VERBOSE
TRACE("In getNamedRelatedShapeAspect\r\n");
TRACE("obj: %S\r\n", _sdaiGetPart21Description(obj));
#endif
   // return a list of shape_aspect_relationships with obj as the definition
   sdaiFindInstanceUsedIn(obj, SAR_ED, domain, resultList);

   if (sdaiGetMemberCount(resultList) > 0) {
      itor = sdaiCreateIterator(resultList);
      while (sdaiNext(itor)) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &sar); 
         sdaiGetAttr(sar, SAR_NAME, sdaiSTRING, &attr_value);

#ifdef VERBOSE
TRACE("sar: %s\r\n", _sdaiGetPart21Description(sar));
#endif
         if (!strcmp(attr_value, name)) {
            sdaiGetAttr(sar, SAR_ING, sdaiINSTANCE, &sa);
#ifdef VERBOSE
TRACE("sa: %s\r\n", _sdaiGetPart21Description(sa));
#endif
            break;
            }
         }
      sdaiDeleteIterator(itor);

      sdaiDeleteNPL(domain);
      sdaiDeleteNPL(resultList);

      if (sa == sdaiNULL) {
         TRACE("WARNING: %s is not related to a shape_aspect\n",
                         _sdaiGetPart21Description(obj));
         TRACE("         with a name of \"%s\"\n", name);
         }
      }
   return sa;
   }
SdaiAppInstance getNamedRelatedShapeAspect(SdaiModel AP210Model, SdaiAppInstance obj, SdaiString name) {
   static SdaiEntity SAR = sdaiGetEntity(AP210Model, "shape_aspect_relationship");
   static SdaiAttr SAR_ED = sdaiGetAttrDefinition(SAR, "related_shape_aspect");
   static SdaiAttr SAR_NAME = sdaiGetAttrDefinition(SAR, "name");
   static SdaiAttr SAR_ING = sdaiGetAttrDefinition(SAR, "relating_shape_aspect");

   SdaiIterator itor;
   SdaiString attr_value;
   SdaiAppInstance sa = sdaiNULL;
   SdaiAppInstance sar;
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();
#ifdef VERBOSE
TRACE("In getNamedRelatedShapeAspect\r\n");
TRACE("obj: %S\r\n", _sdaiGetPart21Description(obj));
#endif
   // return a list of shape_aspect_relationships with obj as the definition
   sdaiFindInstanceUsedIn(obj, SAR_ING, domain, resultList);

   if (sdaiGetMemberCount(resultList) > 0) {
      itor = sdaiCreateIterator(resultList);
      while (sdaiNext(itor)) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &sar); 
         sdaiGetAttr(sar, SAR_NAME, sdaiSTRING, &attr_value);

#ifdef VERBOSE
TRACE("sar: %s\r\n", _sdaiGetPart21Description(sar));
#endif
         if (!strcmp(attr_value, name)) {
            sdaiGetAttr(sar, SAR_ED, sdaiINSTANCE, &sa);
#ifdef VERBOSE
TRACE("sa: %s\r\n", _sdaiGetPart21Description(sa));
#endif
            break;
            }
         }
      sdaiDeleteIterator(itor);

      sdaiDeleteNPL(domain);
      sdaiDeleteNPL(resultList);

      if (sa == sdaiNULL) {
         TRACE("WARNING: %s is not relating to a shape_aspect\n",
                         _sdaiGetPart21Description(obj));
         TRACE("         with a name of \"%s\"\n", name);
         }
      }
   return sa;
   }
SdaiAppInstance _sdaiGetSingleRepresentationItemOfType(SdaiAppInstance obj,
                                                       SdaiEntity entity)
   {
   static SdaiAttr role = sdaiGetAttrDefinitionBN(AP210, "representation", "items");
   SdaiAppInstance test;
   SdaiAppInstance item = sdaiNULL;
   SdaiIterator itor;
   SdaiAggr items; 
 
   sdaiGetAttr(obj, role, sdaiAGGR, &items);
   itor = sdaiCreateIterator(items);
   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &test); 

      if (sdaiIsInstanceOf(test, entity)) {
         item = test;
         break;
         }
      }
   return(item);
   }

#if 1
/*
 * getPropertyDefinition()
 *
 *  #26420=PACKAGE('','',#26418,#26419);
 *  #26691=PROPERTY_DEFINITION('','',#26420);
 *  #26701=PROPERTY_DEFINITION_REPRESENTATION(#26691,#26699);
 *  #26699=GEOMETRICALLY_BOUNDED_2D_WIREFRAME_REPRESENTATION('feature shape',(
 *     #26698,#26700),#26695);
 *  #26705=REPRESENTATION_RELATIONSHIP('','',#26699,#26704);
 *  #26704=REPRESENTATION('shape purpose',(#26702),#26703);
 *  #26702=DESCRIPTIVE_REPRESENTATION_ITEM('design profile','');
 */
SdaiAppInstance getPropertyDefinition(SdaiModel AP210Model, 
                                      SdaiAppInstance obj,
                                      char *value,
                                      SdaiAttr attribute)
   {
   static SdaiEntity PD = sdaiGetEntity(AP210Model, "property_definition");
   static SdaiAttr PD_DEF = sdaiGetAttrDefinition(PD, "definition");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "property_definition_representation");
   static SdaiAttr PDR_DEF = sdaiGetAttrDefinition(PDR, "definition");
   static SdaiAttr PDR_USED_REP = sdaiGetAttrDefinition(PDR, "used_representation");

   static SdaiEntity RR = sdaiGetEntity(AP210Model, "representation_relationship");
   static SdaiAttr RR_REP1 = sdaiGetAttrDefinition(RR, "rep_1");
   static SdaiAttr RR_REP2 = sdaiGetAttrDefinition(RR, "rep_2");

   static SdaiEntity REP = sdaiGetEntity(AP210Model, "representation");
   static SdaiAttr REP_ITEMS = sdaiGetAttrDefinition(REP, "items");

   static SdaiEntity DRI = sdaiGetEntity(AP210Model, "descriptive_representation_item");
   static SdaiAttr DRI_NAME = sdaiGetAttrDefinition(DRI, "name");

   SdaiIterator itor1;
   SdaiIterator itor2;
   SdaiIterator itor3;
   SdaiIterator itemsitor;
   SdaiString attr_value;
   SdaiString name;
   SdaiAppInstance test1 = sdaiNULL;
   SdaiAppInstance test2 = sdaiNULL;
   SdaiAppInstance test3 = sdaiNULL;
   SdaiAppInstance test4 = sdaiNULL;
   SdaiAppInstance rep1 = sdaiNULL;
   SdaiAppInstance rep2 = sdaiNULL;
   SdaiAppInstance pd = sdaiNULL;
   SdaiAggr items;

   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL pd_def_resultList = sdaiCreateNPL();
   SdaiNPL pdr_used_rep_resultList = sdaiCreateNPL();
   SdaiNPL rr_rep1_resultList = sdaiCreateNPL();

   // return a list of property definitions with obj as the definition
   sdaiFindInstanceUsedIn(obj, PD_DEF, domain, pd_def_resultList);

#ifdef VERBOSE
   TRACE("In getPropertyDefinition()\r\n", stdout);
   TRACE("%s\r\n   %s\r\n",
                   _sdaiGetPart21Description(obj), value);
#endif

   if (sdaiGetMemberCount(pd_def_resultList) > 0) {
      itor1 = sdaiCreateIterator(pd_def_resultList);

      while (sdaiNext(itor1) && (pd == sdaiNULL)) {
         sdaiGetAggrByIterator(itor1, sdaiINSTANCE, &test1); 
         sdaiGetAttr(test1, attribute, sdaiSTRING, &attr_value);
#ifdef REALLYVERBOSE
         TRACE("test1: %s\n", _sdaiGetPart21Description(test1));
#endif
         sdaiFindInstanceUsedIn(test1, PDR_DEF, domain, pdr_used_rep_resultList);
         itor2 = sdaiCreateIterator(pdr_used_rep_resultList);

         while (sdaiNext(itor2) && (pd == sdaiNULL)) {
            sdaiGetAggrByIterator(itor2, sdaiINSTANCE, &test2); 
#ifdef REALLYVERBOSE
            TRACE("test2: %s\n", _sdaiGetPart21Description(test2));
#endif
            sdaiGetAttr(test2, PDR_USED_REP, sdaiINSTANCE, &rep1);
#ifdef REALLYVERBOSE
            TRACE("rep1: %s\n", _sdaiGetPart21Description(rep1));
#endif
            sdaiFindInstanceUsedIn(rep1, RR_REP1, domain, rr_rep1_resultList);
            itor3 = sdaiCreateIterator(rr_rep1_resultList);

            while (sdaiNext(itor3) && (pd == sdaiNULL)) {
               sdaiGetAggrByIterator(itor3, sdaiINSTANCE, &test3); 
#ifdef REALLYVERBOSE
               TRACE("test3: %s\n", _sdaiGetPart21Description(test3));
#endif
               if (sdaiIsInstanceOf(test3, RR)) {
                  sdaiGetAttr(test3, RR_REP2, sdaiINSTANCE, &rep2);
#ifdef REALLYVERBOSE
                  TRACE("rep2: %s\n", _sdaiGetPart21Description(rep2));
#endif
                  sdaiGetAttr(rep2, REP_ITEMS, sdaiAGGR, &items);
                  itemsitor = sdaiCreateIterator(items);

                  while(sdaiNext(itemsitor) && (pd == sdaiNULL)) {
                     sdaiGetAggrByIterator(itemsitor, sdaiINSTANCE, &test4); 
#ifdef REALLYVERBOSE
                     TRACE("test4: %s\n", _sdaiGetPart21Description(test4));
#endif
                     if (sdaiIsInstanceOf(test4, DRI)) {
                        sdaiGetAttr(test4, DRI_NAME, sdaiSTRING, &name);
#ifdef REALLYVERBOSE
                        TRACE("name: %s, value: %s\n", name, value);
#endif
                        if (!strcmp(name, value)) {
                           pd = test1;
#ifdef VERBOSE
                           TRACE("Found It: %s\n", name);
                           TRACE("pd: %s\n", _sdaiGetPart21Description(pd));
                           TRACE("test2: %s\n", _sdaiGetPart21Description(test2));
                           TRACE("test3: %s\n", _sdaiGetPart21Description(test3));
                           TRACE("test4: %s\n\n", _sdaiGetPart21Description(test4));
#endif
                           }
                        }
                     }
                  sdaiDeleteIterator(itemsitor);
                  }
               }

            sdaiDeleteIterator(itor3);
            }
         sdaiDeleteIterator(itor2);
         }
      sdaiDeleteIterator(itor1);

      sdaiDeleteNPL(domain);
      sdaiDeleteNPL(pd_def_resultList);
      sdaiDeleteNPL(pdr_used_rep_resultList);
      sdaiDeleteNPL(rr_rep1_resultList);

#ifdef VERBOSE
      if (pd == sdaiNULL) {
         TRACE("WARNING: %s has no property_definition\n",
                         _sdaiGetPart21Description(obj));
         TRACE("         with a %s of \"%s\"\n", "attributeName value", value);
         }
#endif
      }
#ifdef VERBOSE
   else {
      TRACE("WARNING: no properties defined for %s\n",
                       _sdaiGetPart21Description(obj));
      }
#endif
   return(pd);
   }
#else
// The functions below really belong in an AP, Module or IR specific file.
SdaiAppInstance getPropertyDefinition(SdaiModel AP210Model, 
                                      SdaiAppInstance obj,
                                      char *value,
                                      SdaiAttr attribute)
   {
   static SdaiEntity PD = sdaiGetEntity(AP210Model, "property_definition");
   static SdaiAttr PD_DEF = sdaiGetAttrDefinition(PD, "definition");
   SdaiIterator itor;
   SdaiString attr_value;
   SdaiAppInstance test = sdaiNULL;
   SdaiAppInstance pd = sdaiNULL;
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();
   // return a list of property definitions with obj as the definition
#ifdef CACHETEST
   _sdaiFindInstanceUsedInCache(obj, PD_DEF, domain, resultList);
#else
   sdaiFindInstanceUsedIn(obj, PD_DEF, domain, resultList);
#endif
#ifdef VERBOSE
TRACE("In GetPropertyDefinition(%s)\r\n", value);
TRACE("obj: %s\n", _sdaiGetPart21Description(obj)); 
TRACE("count: %d\r\n", sdaiGetMemberCount(resultList));
#endif

   if (sdaiGetMemberCount(resultList) > 0) {

      itor = sdaiCreateIterator(resultList);
      while (sdaiNext(itor)) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &test); 

         if (sdaiIsInstanceOf(test, PD)) {
            sdaiGetAttr(test, attribute, sdaiSTRING, &attr_value);
#ifdef VERBOSE
TRACE("test: %s\n", _sdaiGetPart21Description(test)); 
TRACE("    '%s' '%s'\r\n", value, attr_value);
#endif
            if (!strcmp(attr_value, value)) {
               pd = test;
               break;
               }
            }
         }
      sdaiDeleteIterator(itor);

      sdaiDeleteNPL(domain);
      sdaiDeleteNPL(resultList);
      }
#ifdef VERBOSE
   if (pd == sdaiNULL) {
      TRACE("WARNING: %s has no property_definition\r\n",
                      _sdaiGetPart21Description(obj));
      TRACE("         with a %s of \"%s\"\r\n", "attributeName value", value);
      }
   else {
      TRACE("%s has a property_definition\r\n",
                      _sdaiGetPart21Description(obj));
      TRACE("         with a %s of \"%s\"\r\n", "attributeName value", value);
      TRACE("%s\r\n", _sdaiGetPart21Description(pd));
     }
#endif
   return(pd);
   }
#endif
SdaiAppInstance getPhysicalUnitsProductRelatedProductCategory(SdaiAppInstance pu)
   {
   static SdaiAttr formation = sdaiGetAttrDefinitionBN(AP210,
                                                       "physical_unit",
                                                       "formation");
   static SdaiAttr of_product = sdaiGetAttrDefinitionBN(AP210,
                                                        "product_definition_formation",
                                                        "of_product");
   static SdaiAttr role = sdaiGetAttrDefinitionBN(AP210,
                                                  "product_related_product_category",
                                                  "products");
   SdaiIterator itor;
   SdaiAppInstance pdf;  // product_definition_formation;
   SdaiAppInstance p;	 // product
   SdaiAppInstance prpc = NULL; // product_related_product_catagory
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();

   if (sdaiTestAttr(pu, formation) == sdaiTRUE) {
      sdaiGetAttr(pu, formation, sdaiINSTANCE, &pdf);
      if (sdaiTestAttr(pdf, of_product) == sdaiTRUE) {
         sdaiGetAttr(pdf, of_product, sdaiINSTANCE, &p);
         sdaiFindInstanceUsedIn(p, role, domain, resultList);
         itor = sdaiCreateIterator(resultList);

         while (sdaiNext(itor)) {
            sdaiGetAggrByIterator(itor, sdaiINSTANCE, &prpc);
            }
         sdaiDeleteIterator(itor);
         }
      } 
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(resultList);
   return(prpc);
   }
SdaiAppInstance getPackagedComponentPackage(SdaiModel AP210Model, SdaiAppInstance pc)
   {
   static SdaiEntity packaged_component = sdaiGetEntity(AP210Model, "packaged_component");

   static SdaiEntity pdr_entity = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr pdr_ed = sdaiGetAttrDefinition(pdr_entity,
                                                  "related_product_definition");
   static SdaiAttr pdr_ing = sdaiGetAttrDefinition(pdr_entity,
                                                   "relating_product_definition");

   SdaiAppInstance obj = sdaiNULL; // scratch object
   SdaiAppInstance pdr; // product_definition_relationship 
   SdaiAppInstance pp;  // packaged_part 
   SdaiAppInstance p = sdaiNULL;   // package 

#ifdef VERBOSE
TRACE0("In getPackagedComponentPackage()\r\n");
TRACE("packaged_component: %s\r\n", _sdaiGetPart21Description(pc));
#endif
   if (sdaiIsInstanceOf(pc, packaged_component)) {

      pdr = getNamedProductDefinitionRelationship(AP210Model, pc, "instantiated part", pdr_ed);
#ifdef VERBOSE
TRACE("pdr 1: %s\r\n", _sdaiGetPart21Description(pdr));
#endif

      if (pdr != sdaiNULL) {
         sdaiGetAttr(pdr, pdr_ing, sdaiINSTANCE, &pp);
#ifdef VERBOSE
TRACE("pp: %s\r\n", _sdaiGetPart21Description(pp));
#endif

         pdr = getNamedProductDefinitionRelationship(AP210Model, pp, "used package", pdr_ed);
#ifdef VERBOSE
TRACE("pdr 2: %s\r\n", _sdaiGetPart21Description(pdr));
#endif
         if (pdr != sdaiNULL) {
            sdaiGetAttr(pdr, pdr_ing, sdaiINSTANCE, &p);
#ifdef VERBOSE
TRACE("p: %s\r\n", _sdaiGetPart21Description(p));
#endif
            }
         else { // pdr == sdaiNULL
            // rockwell kludge, but rockwell could be correct!
            // rockwell coded to the mapping table but it was wrong.
            // it appears that the pdr is reversed.
            pdr = getNamedProductDefinitionRelationship(AP210Model, pp, "used package", pdr_ing);
#ifdef VERBOSE
TRACE("ROCKWELL\r\npdr 3: %s\r\n", _sdaiGetPart21Description(pdr));
#endif
            sdaiGetAttr(pdr, pdr_ed, sdaiINSTANCE, &p);
#ifdef VERBOSE
TRACE("p: %s\r\n", _sdaiGetPart21Description(p));
#endif
             }             
         }
      }
   else {
      TRACE("ERROR: %s is not a packaged_component\n",
            _sdaiGetPart21Description(pc));
      }
   if (p == sdaiNULL) {
      TRACE("ERROR: %s has no package\n", _sdaiGetPart21Description(pc));
      }
   return(p);
   }
SdaiAppInstance getPackagedPartPackage(SdaiModel AP210Model, SdaiAppInstance pp)
   {
   static SdaiEntity packaged_component = sdaiGetEntity(AP210Model, "packaged_component");

   static SdaiEntity pdr_entity = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr pdr_ed = sdaiGetAttrDefinition(pdr_entity,
                                                  "related_product_definition");
   static SdaiAttr pdr_ing = sdaiGetAttrDefinition(pdr_entity,
                                                   "relating_product_definition");

   SdaiAppInstance obj = sdaiNULL; // scratch object
   SdaiAppInstance pdr; // product_definition_relationship 
   SdaiAppInstance p = sdaiNULL;   // package 

#ifdef VERBOSE
TRACE0("In getPackagedComponentPackage()\r\n");
TRACE("pp: %s\r\n", _sdaiGetPart21Description(pp));
#endif
         pdr = getNamedProductDefinitionRelationship(AP210Model, pp, "used package", pdr_ed);
#ifdef VERBOSE
TRACE("pdr 2: %s\r\n", _sdaiGetPart21Description(pdr));
#endif
         if (pdr != sdaiNULL) {
            sdaiGetAttr(pdr, pdr_ing, sdaiINSTANCE, &p);
#ifdef VERBOSE
TRACE("p: %s\r\n", _sdaiGetPart21Description(p));
#endif
            }
         else { // pdr == sdaiNULL
            // rockwell kludge, but rockwell could be correct!
            // rockwell coded to the mapping table but it was wrong.
            // it appears that the pdr is reversed.
            pdr = getNamedProductDefinitionRelationship(AP210Model, pp, "used package", pdr_ing);
#ifdef VERBOSE
TRACE("ROCKWELL\r\npdr 3: %s\r\n", _sdaiGetPart21Description(pdr));
#endif
            sdaiGetAttr(pdr, pdr_ed, sdaiINSTANCE, &p);
#ifdef VERBOSE
TRACE("p: %s\r\n", _sdaiGetPart21Description(p));
#endif
             }             
   if (p == sdaiNULL) {
      TRACE("ERROR: %s has no package\n", _sdaiGetPart21Description(pp));
      }
   return(p);
   }
SdaiAppInstance getNamedProductDefinitionRelationship(SdaiModel AP210Model,
                                                      SdaiAppInstance obj,
                                                      SdaiString pdrName,
                                                      SdaiAttr attribute) {
   SdaiAppInstance pdr = sdaiNULL;
   SdaiIterator itor;

   SdaiNPL uppdrlist = sdaiCreateNPL(); // "used package" product_definition_relationship list
   getNamedProductDefinitionRelationships(AP210Model, obj, pdrName, attribute, uppdrlist);

   if (sdaiGetMemberCount(uppdrlist) == 1) {
      itor = sdaiCreateIterator(uppdrlist);
      sdaiNext(itor);
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &pdr); 
      sdaiDeleteIterator(itor);
      }
   sdaiDeleteNPL(uppdrlist);

   return(pdr);
   }
SdaiNPL getNamedProductDefinitionRelationships(SdaiModel AP210Model, 
                                               SdaiAppInstance obj,
                                               SdaiString pdrName,
                                               SdaiAttr attribute,
                                               SdaiNPL uppdrlist) {
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL pdrlist = sdaiCreateNPL(); // product_definition_relationship list
   static SdaiEntity pdr_entity = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr name = sdaiGetAttrDefinition(pdr_entity, "name");

   sdaiFindInstanceUsedIn(obj, attribute, domain, pdrlist);

#ifdef VERBOSE
TRACE("In getNamedProductDefinitionRelationships(%s)\r\n", pdrName);
TRACE("obj: %s\r\n", _sdaiGetPart21Description(obj));
TRACE("UsedIn Count: %d\n", sdaiGetMemberCount(pdrlist));

SdaiIterator nplitor = sdaiCreateIterator(pdrlist);
SdaiAppInstance pdr;
while (sdaiNext(nplitor)) {
   sdaiGetAggrByIterator(nplitor, sdaiINSTANCE, &pdr);
   TRACE("pdr: %s\r\n", _sdaiGetPart21Description(pdr));
   }
sdaiDeleteIterator(nplitor);
#endif

   _sdaiInstanceAttributeValueQuery(pdrlist,
                                    name,
                                    sdaiSTRING,
                                    pdrName,
                                    uppdrlist);
#ifdef VERBOSE
TRACE("Query Count: %d\r\n", sdaiGetMemberCount(uppdrlist));
#endif
   
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(pdrlist);

   return(uppdrlist);
   }
#define LKSOFTEDGE
SdaiAppInstance getGraphicPropertiesShapeRep(SdaiModel AP210Model, SdaiAppInstance prop) {
   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "property_definition_representation");
   static SdaiAttr PDR_DEF = sdaiGetAttrDefinition(PDR, "definition");
   static SdaiAttr PDR_UR = sdaiGetAttrDefinition(PDR, "used_representation");
   SdaiAppInstance sr = sdaiNULL;
   SdaiAppInstance prop_dr;

#ifndef LKSOFTEDGE
   prop_dr = _sdaiFindSingleSubTypeInstanceUsedIn(prop, PDR, PDR_DEF);
#else
   prop_dr = _sdaiFindSingleSubTypeKindOfUsedIn(prop, PDR, PDR_DEF);
#endif
   if (prop_dr != sdaiNULL) {
      sdaiGetAttr(prop_dr, PDR_UR, sdaiINSTANCE, &sr);
      }
   return(sr);
   }
#undef LKSOFTEDGE
/*
 * Function getRepresentationLengthUnit
 *
 * Given a REPRESENTATION return its units.
 *
 * Part21 Example:
 *   #5327=COMPONENT_LOCATION('',(#5306,#5322,#5326),#5321);
 *   #5306=REPRESENTATION_ITEM('');
 *   #5315=REPRESENTATION_MAP(#5306,#5314);
 *   #5314=SHAPE_REPRESENTATION('planar projected shape',(#5307),#5313);
 *   #5313=(GEOMETRIC_REPRESENTATION_CONTEXT(3)
 *      GLOBAL_UNCERTAINTY_ASSIGNED_CONTEXT((#5311))GLOBAL_UNIT_ASSIGNED_CONTEXT(
 *      (#164,#3027))REPRESENTATION_CONTEXT('','3D'));
 *   #3027=(CONVERSION_BASED_UNIT('TEN-NANOMETRE',#3023)LENGTH_UNIT()NAMED_UNIT(
 *      #3022));
 */
SdaiAppInstance getRepresentationLengthUnit(SdaiModel AP210Model, SdaiAppInstance sr) {
   SdaiIterator itor;
   SdaiAppInstance len_unit = sdaiNULL;
   SdaiAppInstance rc; // representation_context 
   SdaiAppInstance ui; // unit instance 
   SdaiAggr units; // set of Unit
   static SdaiEntity length_unit = sdaiGetEntity(AP210Model, "length_unit");
   static SdaiAttr coi = sdaiGetAttrDefinitionBN(AP210,
                                                 "representation",
                                                 "context_of_items");
   static SdaiEntity GUAC  = sdaiGetEntity(AP210Model, "global_unit_assigned_context");
   static SdaiAttr unit = sdaiGetAttrDefinition(GUAC,
                                                "units");
   static SdaiEntity length_unitent = sdaiGetEntity(AP210Model, "length_unit");

#ifdef VERBOSE
TRACE("rep: %s\r\n", _sdaiGetPart21Description(sr));
#endif
   if (sr != sdaiNULL) {
      sdaiGetAttr(sr, coi, sdaiINSTANCE, &rc);
#ifdef VERBOSE
TRACE("rc: %s\r\n", _sdaiGetPart21Description(rc));
#endif

      if (rc != sdaiNULL) {
         // It's good to check the type, require for an early ITI beta.
         if (sdaiIsKindOf(rc, GUAC)) {      
            sdaiGetAttr(rc, unit, sdaiAGGR, &units);

            itor = sdaiCreateIterator(units);
            while (sdaiNext(itor)) {
               sdaiGetAggrByIterator(itor, sdaiINSTANCE, &ui); 
#ifdef VERBOSE
TRACE("ui: %s\r\n", _sdaiGetPart21Description(ui));
#endif

               // Using sdaiIsKindOf rather than sdaiIsInstanceOf because ui is a
               // complex instance of the type conversion_based_unit_and_<unit_type>_unit
               if (sdaiIsKindOf(ui, length_unitent)) {
                  len_unit = ui;
                  break;
                  }   
               }
            }
         }
      }
#ifdef VERBOSE
TRACE("len_unit: %s\r\n", _sdaiGetPart21Description(len_unit));
#endif
   return(len_unit);
   }
// Geometry Extraction routines.
SdaiNPL getGeometryFromShapeRep(SdaiModel AP210Model, SdaiAppInstance sr) {
   static SdaiEntity GCS = sdaiGetEntity(AP210Model, "geometric_curve_set");

   static SdaiAttr SR_I = sdaiGetAttrDefinitionBN(AP210,
                                                  "shape_representation",
                                                  "items");
   SdaiIterator itor;
   SdaiAggr items;
   SdaiAppInstance gri;
   SdaiNPL result = sdaiCreateNPL();
   SdaiIterator nplitor = sdaiCreateIterator(result);
#ifdef VERBOSE
TRACE0("In getGeometryFromShapeRep()\r\n");
TRACE("sr: %s\r\n", _sdaiGetPart21Description(sr));
#endif

   sdaiGetAttr(sr, SR_I, sdaiAGGR, &items);
   itor = sdaiCreateIterator(items);

   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &gri);
      
      // check for geometric_curve_set
      if (sdaiIsKindOf(gri, GCS)) {
#ifdef VERBOSE
TRACE("GCS Geometry Item: %s\r\n", _sdaiGetPart21Description(gri));
#endif
         getGeometryFromGeometricCurveSet(AP210Model, gri, nplitor);
         }
      else { // check for annotation_curve_occurrence latter.
         sdaiEnd(nplitor);
         sdaiInsertBefore(nplitor, sdaiINSTANCE, gri);
#ifdef VERBOSE
TRACE("Geometry Item: %s\r\n", _sdaiGetPart21Description(gri));
#endif
         }
      } 
   sdaiDeleteIterator(itor);
   sdaiDeleteIterator(nplitor);
   return(result);
   }
void getGeometryFromGeometricCurveSet(SdaiModel AP210Model, SdaiAppInstance gcs, SdaiIterator curveitor) {
   static SdaiEntity ACO = sdaiGetEntity(AP210Model,"annotation_curve_occurrence");
   static SdaiAttr ACO_S = sdaiGetAttrDefinition(ACO, "styles");
   static SdaiAttr ACO_I = sdaiGetAttrDefinition(ACO, "item");

   static SdaiEntity GCS = sdaiGetEntity(AP210Model, "geometric_curve_set");
   static SdaiAttr GCS_E = sdaiGetAttrDefinition(GCS, "elements");

   static SdaiEntity CC = sdaiGetEntity(AP210Model, "composite_curve");

   static SdaiEntity C = sdaiGetEntity(AP210Model, "circle");

   static SdaiEntity PL = sdaiGetEntity(AP210Model, "polyline");

   SdaiIterator itor;
   SdaiAggr elements;
   SdaiInstance gss;  // geometric_set_select
#ifdef VERBOSE
TRACE0("In GetGeometryFromGeometricCurveSet()\r\n");
#endif

   sdaiGetAttr(gcs, GCS_E, sdaiAGGR, &elements);
   itor = sdaiCreateIterator(elements);

   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &gss);
#ifdef VERBOSE
TRACE("geometric_set_select: %s\r\n", _sdaiGetPart21Description(gss));
#endif
      // check for composite_curve
      if (sdaiIsKindOf(gss, CC)) {
         getGeometryFromCompositeCurve(AP210Model, gss, curveitor);
         }
      else if (sdaiIsKindOf(gss, ACO)) {
         getGeometryFromAnnotationCurveOccurance(AP210Model, gss, curveitor);
         }
      else if (sdaiIsKindOf(gss, PL)) {
         sdaiEnd(curveitor);
         sdaiInsertBefore(curveitor, sdaiINSTANCE, gss);
         }
      else if (sdaiIsKindOf(gss, C)) {
         sdaiEnd(curveitor);
         sdaiInsertBefore(curveitor, sdaiINSTANCE, gss);
         }
      else {
         TRACE("WARNING: Unhandled geometry type %s\r\n", _sdaiGetPart21Description(gss));
         }
      }      
   }
void getGeometryFromAnnotationCurveOccurance(SdaiModel AP210Model, SdaiAppInstance aco, SdaiIterator curveitor) {
   static SdaiEntity ACO = sdaiGetEntity(AP210Model,"annotation_curve_occurrence");
   static SdaiAttr ACO_S = sdaiGetAttrDefinition(ACO, "styles");
   static SdaiAttr ACO_I = sdaiGetAttrDefinition(ACO, "item");

   static SdaiAttr PSA_S = sdaiGetAttrDefinitionBN(AP210,
                                                   "presentation_style_assignment",
                                                   "styles");
   SdaiAggr styles;
   SdaiIterator stylesitor;
   SdaiAppInstance psa;
   SdaiAggr psa_styles;
   SdaiIterator psa_stylesitor;
   SdaiAppInstance cs;
   SdaiAppInstance acoi;

   // get the annotation_curve_occurrence's
   // styles attributes presentation_style_assignment
   sdaiGetAttr(aco, ACO_S, sdaiAGGR, &styles);
   stylesitor = sdaiCreateIterator(styles);
   sdaiNext(stylesitor);
   sdaiGetAggrByIterator(stylesitor, sdaiINSTANCE, &psa);
   sdaiDeleteIterator(stylesitor);
#ifdef VERBOSE
TRACE("In getGeometryFromAnnotationCurveOccurance()\r\n");
TRACE("PSA: %s\r\n", _sdaiGetPart21Description(psa));
#endif
    // get the presentation_style_assignment's
    // styles attributes presentation_style_assignment
    sdaiGetAttr(psa, PSA_S, sdaiAGGR, &psa_styles);
    psa_stylesitor = sdaiCreateIterator(psa_styles);
    sdaiNext(psa_stylesitor);
    sdaiGetAggrByIterator(psa_stylesitor, sdaiINSTANCE, &cs);
    sdaiDeleteIterator(psa_stylesitor);
#ifdef VERBOSE
TRACE("CS: %s\r\n", _sdaiGetPart21Description(cs));
#endif
      
    sdaiGetAttr(aco, ACO_I, sdaiINSTANCE, &acoi);
#ifdef VERBOSE
TRACE("Item: %s\r\n", _sdaiGetPart21Description(acoi));
#endif
   sdaiEnd(curveitor);
   sdaiInsertBefore(curveitor, sdaiINSTANCE, acoi);
   }
void getGeometryFromCompositeCurve(SdaiModel AP210Model, SdaiAppInstance cc, SdaiIterator curveitor) {
   static SdaiEntity CC = sdaiGetEntity(AP210Model, "composite_curve");
   static SdaiAttr CC_S = sdaiGetAttrDefinition(CC, "segments");

   static SdaiEntity CCS = sdaiGetEntity(AP210Model, "composite_curve_segment");
   static SdaiAttr CCS_PC = sdaiGetAttrDefinition(CCS, "parent_curve");

   SdaiIterator itor;
   SdaiAggr elements;
   SdaiInstance css;  // composite_curve_segment
   SdaiAppInstance curve;   // curve
#ifdef VERBOSE
TRACE0("In GetGeometryFromCompositeCurve()\r\n");
#endif

   sdaiGetAttr(cc, CC_S, sdaiAGGR, &elements);
   itor = sdaiCreateIterator(elements);

   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &css);
#ifdef VERBOSE
TRACE("composite_curve_segment: %s\r\n", _sdaiGetPart21Description(css));
#endif

      sdaiGetAttr(css, CCS_PC, sdaiINSTANCE, &curve);
#ifdef VERBOSE
TRACE("curve: %s\r\n", _sdaiGetPart21Description(curve));
#endif
      sdaiEnd(curveitor);
      sdaiInsertBefore(curveitor, sdaiINSTANCE, curve);
      }      
   }

/*
 * Function getPackagedComponentLocation
 *
 * Given a NEXT_ASSEMBLY_USAGE_OCCURRENCE return its COMPONENT_LOCATION.
 * If the PRODUCT_DEFINITION_SHAPE can't be found for the 
 * NEXT_ASSEMBLY_USAGE_OCCURRENCE it indicates that the component
 * has not been placed. 
 *
 * Part21 Example:
 *   #4750=NEXT_ASSEMBLY_USAGE_OCCURRENCE('','','',#103,#4736,'C1');
 *   #4751=PRODUCT_DEFINITION_SHAPE('','',#4750);
 *   #4764=PROPERTY_DEFINITION_REPRESENTATION(#4751,#4761);
 *   #4761=COMPONENT_LOCATION('',(#4753,#4754,#4758,#4760),#4752);
 *
 */
SdaiAppInstance getPackagedComponentLocation(SdaiModel AP210Model, SdaiAppInstance pc) {
   static SdaiEntity NAUO = sdaiGetEntity(AP210Model, "next_assembly_usage_occurrence");
   static SdaiAttr NAUO_PD = sdaiGetAttrDefinition(NAUO, "related_product_definition");

   static SdaiEntity PDS = sdaiGetEntity(AP210Model, "product_definition_shape");
   static SdaiAttr PDS_DEF = sdaiGetAttrDefinition(PDS, "definition");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "property_definition_representation");
   static SdaiAttr PDR_DEF= sdaiGetAttrDefinition(PDR, "definition");
   static SdaiAttr PDR_USED_REP = sdaiGetAttrDefinition(PDR, "used_representation");

   SdaiAppInstance nauo;               // next_assembly_usage_occurrence
   SdaiAppInstance pds = sdaiNULL;     // product_definition_shape
   SdaiAppInstance pdr = sdaiNULL;     // property_definition_representation
   SdaiAppInstance A2P_LOC = sdaiNULL; // component_location

#ifdef VERBOSE
TRACE0("In getPackagedComponentLocation()\r\n");
#endif
   // get the pc's reference designator*/
   nauo = _sdaiFindSingleSubTypeInstanceUsedIn(pc, NAUO, NAUO_PD);
#ifdef VERBOSE
TRACE("nauo: %s\r\n", _sdaiGetPart21Description(nauo));
#endif
   if ((pds = _sdaiFindSingleSubTypeInstanceUsedIn(nauo, PDS, PDS_DEF)) 
           != sdaiNULL) {
#ifdef VERBOSE
TRACE("Found pds: %s \r\n", _sdaiGetPart21Description(pds));
#endif
      pdr = _sdaiFindSingleSubTypeInstanceUsedIn(pds, PDR, PDR_DEF);
#ifdef VERBOSE
TRACE("Found pdr: %s \r\n", _sdaiGetPart21Description(pdr));
#endif
      sdaiGetAttr(pdr, PDR_USED_REP, sdaiINSTANCE, &A2P_LOC);
#ifdef VERBOSE
TRACE("Found A2P_LOC: %s \r\n", _sdaiGetPart21Description(A2P_LOC));
#endif
      }
   return(A2P_LOC);
   }
/*
 * Function getPackagedComponentShapeRepresentation
 *
 * Given a packaged_component return the geometry
 * for it's package. 
 * In the future Going through the package
 * would allow caching of the geometry.
 * 
 * Really the input to this function is a component_definition.
 * packaged_component just happens to be a subtype of that.
 *
 * Part21 Example:
 *   #329=COMPONENT_DEFINITION('','interconnect module edge',#228,#15);
 *   #328=PRODUCT_DEFINITION_SHAPE('','',#329);
 *   #499=SHAPE_DEFINITION_REPRESENTATION(#328,#395);
 *   #395=GEOMETRICALLY_BOUNDED_2D_WIREFRAME_REPRESENTATION(
 *      'planar projected shape',(#398,#774),#175);  
 */
SdaiAppInstance getComponentDefinitionShapeRepresentation(SdaiModel AP210Model, SdaiAppInstance pc) {
   static SdaiEntity PDS = sdaiGetEntity(AP210Model,
                                         "product_definition_shape");
   static SdaiAttr PDS_DEF = sdaiGetAttrDefinition(PDS,
                                                   "definition");

   static SdaiEntity SDR = sdaiGetEntity(AP210Model,
                                         "shape_definition_representation");
   static SdaiAttr SDR_DEF= sdaiGetAttrDefinition(SDR,
                                                  "definition");
   static SdaiAttr SDR_USED_REP = sdaiGetAttrDefinition(SDR,
                                                        "used_representation");
   SdaiAppInstance pds = sdaiNULL;
   SdaiAppInstance sdr = sdaiNULL;
   SdaiAppInstance sr  = sdaiNULL;

   pds = _sdaiFindSingleSubTypeInstanceUsedIn(pc, PDS, PDS_DEF);
#ifdef VERBOSE
TRACE("In getPackagedComponentShapeRepresentation()\r\n");
TRACE("Found pds: %s \n", _sdaiGetPart21Description(pds));
#endif
   sdr = _sdaiFindSingleSubTypeInstanceUsedIn(pds, SDR, SDR_DEF);
#ifdef VERBOSE
TRACE("Found sdr: %s \n", _sdaiGetPart21Description(sdr));
#endif
   sdaiGetAttr(sdr, SDR_USED_REP, sdaiINSTANCE, &sr);
#ifdef VERBOSE
TRACE("Found sr: %s \n", _sdaiGetPart21Description(sr));
#endif
   return(sr);
   }
/*
 * Function getPackageShapeRepresentation
 */
SdaiAppInstance getPackageShapeRepresentation(SdaiModel AP210Model, SdaiAppInstance p) {
   static SdaiEntity PDS = sdaiGetEntity(AP210Model, "product_definition_shape");
   static SdaiAttr PDS_DEF = sdaiGetAttrDefinition(PDS, "definition");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "property_definition_representation");
   static SdaiAttr PDR_DEF= sdaiGetAttrDefinition(PDR, "definition");
   static SdaiAttr PDR_UR = sdaiGetAttrDefinition(PDR, "used_representation");
   SdaiAppInstance pds = sdaiNULL;
   SdaiAppInstance pdr = sdaiNULL;
   SdaiAppInstance sr  = sdaiNULL;

#ifdef VERBOSE
TRACE("In getPackageShapeRepresentation()\r\n");
TRACE("  package: %s \n", _sdaiGetPart21Description(p));
#endif
   pds = _sdaiFindSingleSubTypeInstanceUsedIn(p, PDS, PDS_DEF);
#ifdef VERBOSE
TRACE("Found pds: %s \n", _sdaiGetPart21Description(pds));
#endif
   pdr = _sdaiFindSingleSubTypeInstanceUsedIn(pds, PDR, PDR_DEF);
#ifdef VERBOSE
TRACE("Found pdr: %s \n", _sdaiGetPart21Description(pdr));
#endif
   sdaiGetAttr(pdr, PDR_UR, sdaiINSTANCE, &sr);
#ifdef VERBOSE
TRACE("Found sr: %s \n", _sdaiGetPart21Description(sr));
#endif
   return(sr);
   }
/*
 * Function getPhysicalUnitsProduct
 *
 * Given a physical_unit return its product.
 *
 * Part21 Example:
 */
SdaiAppInstance getPhysicalUnitsProduct(SdaiModel AP210Model, SdaiAppInstance pu)
   {
   static SdaiEntity PU = sdaiGetEntity(AP210Model, "physical_unit");
   static SdaiAttr PU_F = sdaiGetAttrDefinition(PU, "formation");

   static SdaiAttr PDF_OP = sdaiGetAttrDefinitionBN(AP210,
                                 "product_definition_formation",
                                 "of_product");
   SdaiAppInstance pdf = sdaiNULL; // product_definition_formation 
   SdaiAppInstance p = sdaiNULL;   // product 

   if (sdaiIsKindOf(pu, PU)) {
      sdaiGetAttr(pu, PU_F, sdaiINSTANCE, &pdf);

      if (pdf != sdaiNULL) {
         sdaiGetAttr(pdf, PDF_OP, sdaiINSTANCE, &p);
         }
      }
   else {
      TRACE("ERROR: %s is not a physical_unit\n",
              _sdaiGetPart21Description(pu));
      }
   if (p == sdaiNULL) {
      TRACE("ERROR: %s has no product\n",
              _sdaiGetPart21Description(pu));
      }
   return(p);
   }
/*
 * Function getPhysicalUnitsPartNumber
 *
 * Given a physical_unit return its part number.
 *
 * Part21 Example:
 */
SdaiString getPhysicalUnitsPartNumber(SdaiModel AP210Model, SdaiAppInstance p) {
   static SdaiAttr P_ID = sdaiGetAttrDefinitionBN(AP210, "product", "id");
   SdaiString partnumber = sdaiNULL;
   SdaiAppInstance product = getPhysicalUnitsProduct(AP210Model, p);

   if (product != sdaiNULL) {
      sdaiGetAttr(product, P_ID, sdaiSTRING, &partnumber);
      }
   return partnumber;
   }
/*
 * Function getPackagedPartProduct
 *
 * Given a packaged_part return its product.
 *
 * Part21 Example:
 *   #19523=PACKAGED_PART('so_16','',#19521,#19522);
 *   #19521=PRODUCT_DEFINITION_FORMATION_WITH_SPECIFIED_SOURCE('','',
 *      #19519, .BOUGHT.);
 *   #19519=PRODUCT('900-12471-621','','',(#4));
 */
SdaiAppInstance getPackagedPartProduct(SdaiModel AP210Model, SdaiAppInstance pp)
   {
   static SdaiEntity PP = sdaiGetEntity(AP210Model, "packaged_part");
   static SdaiAttr PP_F = sdaiGetAttrDefinition(PP, "formation");

   static SdaiAttr PDF_OP = sdaiGetAttrDefinitionBN(AP210,
                                 "product_definition_formation",
                                 "of_product");
   SdaiAppInstance obj = sdaiNULL; // scratch object
   SdaiAppInstance pdf = sdaiNULL; // product_definition_formation 
   SdaiAppInstance p = sdaiNULL;   // product 

   if (sdaiIsInstanceOf(pp, PP)) {

      sdaiGetAttr(pp, PP_F, sdaiINSTANCE, &pdf);

      if (pdf != sdaiNULL) {
         sdaiGetAttr(pdf, PDF_OP, sdaiINSTANCE, &p);
         }
      }
   else {
      TRACE("ERROR: %s is not a packaged_part\n",
              _sdaiGetPart21Description(pp));
      }
   if (p == sdaiNULL) {
      TRACE("ERROR: %s has no product\n",
              _sdaiGetPart21Description(pp));
      }
   return(p);
   }
/*
 * Function getPackagedPartPartNumber
 *
 * Given a packaged_part return its part number.
 *
 * Part21 Example:
 *   #19523=PACKAGED_PART('so_16','',#19521,#19522);
 *   #19521=PRODUCT_DEFINITION_FORMATION_WITH_SPECIFIED_SOURCE('','',
 *      #19519, .BOUGHT.);
 *   #19519=PRODUCT('900-12471-621','','',(#4));
 */
SdaiString getPackagedPartPartNumber(SdaiModel AP210Model, SdaiAppInstance pp) {
   static SdaiAttr P_ID = sdaiGetAttrDefinitionBN(AP210, "product", "id");
   SdaiString partnumber = sdaiNULL;
   SdaiAppInstance product = getPackagedPartProduct(AP210Model, pp);

   if (product != sdaiNULL) {
      sdaiGetAttr(product, P_ID, sdaiSTRING, &partnumber);
      }
   return partnumber;
   }
/*
 * Function getPackagedComponentProduct
 *
 * Given a packaged_component return its product.
 *
 * Part21 Example:
 *   #19535=PACKAGED_COMPONENT('U2','',#19533,#19534);
 *   #19536=PRODUCT_DEFINITION_RELATIONSHIP('','instantiated part','',
 *      #19523,#19535);
 *   #19523=PACKAGED_PART('so_16','',#19521,#19522);
 *   #19521=PRODUCT_DEFINITION_FORMATION_WITH_SPECIFIED_SOURCE('','',
 *      #19519, .BOUGHT.);
 *   #19519=PRODUCT('900-12471-621','','',(#4));
 */
SdaiAppInstance getPackagedComponentProduct(SdaiModel AP210Model, SdaiAppInstance pc)
   {
   static SdaiEntity PC = sdaiGetEntity(AP210Model, "packaged_component");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr PDR_ED = sdaiGetAttrDefinition(PDR, "related_product_definition");
   static SdaiAttr PDR_ING = sdaiGetAttrDefinition(PDR,"relating_product_definition");

   static SdaiAttr pp_formation = sdaiGetAttrDefinitionBN(AP210,
                                 "packaged_part",
                                 "formation");
   static SdaiAttr pdf_of_product = sdaiGetAttrDefinitionBN(AP210,
                                 "product_definition_formation",
                                 "of_product");
   SdaiAppInstance obj = sdaiNULL; // scratch object
   SdaiAppInstance pdr; // product_definition_relationship 
   SdaiAppInstance pp;  // packaged_part 
   SdaiAppInstance pdf; // product_definition_formation 
   SdaiAppInstance p;   // product 

   if (sdaiIsInstanceOf(pc, PC)) {

      pdr = getNamedProductDefinitionRelationship(AP210Model, pc, "instantiated part", PDR_ED);

      if (pdr != sdaiNULL) {
         sdaiGetAttr(pdr, PDR_ING, sdaiINSTANCE, &pp);

         sdaiGetAttr(pp, pp_formation, sdaiINSTANCE, &pdf);

         if (pdf != sdaiNULL) {
            sdaiGetAttr(pdf, pdf_of_product, sdaiINSTANCE, &p);
            }
         }
      }
   else {
      TRACE("ERROR: %s is not a packaged_component\n",
              _sdaiGetPart21Description(pc));
      }
   if (p == sdaiNULL) {
      TRACE("ERROR: %s has no product\n",
              _sdaiGetPart21Description(pc));
      }
   return(p);
   }
/*
 * Function getPackagedComponentPackagedPart
 *
 * Given a packaged_component return its packaged_part.
 *
 * Part21 Example:
 *   #19535=PACKAGED_COMPONENT('U2','',#19533,#19534);
 *   #19536=PRODUCT_DEFINITION_RELATIONSHIP('','instantiated part','',
 *      #19523,#19535);
 *   #19523=PACKAGED_PART('so_16','',#19521,#19522);
 */
SdaiAppInstance getPackagedComponentPackagedPart(SdaiModel AP210Model, SdaiAppInstance pc)
   {
   static SdaiEntity PC = sdaiGetEntity(AP210Model, "packaged_component");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr PDR_ED = sdaiGetAttrDefinition(PDR, "related_product_definition");
   static SdaiAttr PDR_ING = sdaiGetAttrDefinition(PDR, "relating_product_definition");

   SdaiAppInstance pdr; // product_definition_relationship 
   SdaiAppInstance pp;  // packaged_part 

   if (sdaiIsInstanceOf(pc, PC)) {

      pdr = getNamedProductDefinitionRelationship(AP210Model, pc, "instantiated part", PDR_ED);

      if (pdr != sdaiNULL) {
         sdaiGetAttr(pdr, PDR_ING, sdaiINSTANCE, &pp);
         }
      }
   else {
      TRACE("ERROR: %s is not a packaged_component\n",
              _sdaiGetPart21Description(pc));
      }
   if (pp == sdaiNULL) {
      TRACE("ERROR: %s has no packaged_part\n",
              _sdaiGetPart21Description(pc));
      }
   return(pp);
   }
/*
 * Function getPackagedComponentPartNumber
 *
 * Given a packaged_component return its part number.
 *
 * Part21 Example:
 *   #19535=PACKAGED_COMPONENT('U2','',#19533,#19534);
 *   #19536=PRODUCT_DEFINITION_RELATIONSHIP('','instantiated part','',
 *      #19523,#19535);
 *   #19523=PACKAGED_PART('so_16','',#19521,#19522);
 *   #19521=PRODUCT_DEFINITION_FORMATION_WITH_SPECIFIED_SOURCE('','',
 *      #19519, .BOUGHT.);
 *   #19519=PRODUCT('900-12471-621','','',(#4));
 */
SdaiString getPackagedComponentPartNumber(SdaiModel AP210Model, SdaiAppInstance pc) {
   static SdaiAttr product_id = sdaiGetAttrDefinitionBN(AP210, "product", "id");
   SdaiString partnumber = sdaiNULL;
   SdaiAppInstance product = getPackagedComponentProduct(AP210Model, pc);

   if (product != sdaiNULL) {
      sdaiGetAttr(product, product_id, sdaiSTRING, &partnumber);
      }
   return partnumber;
   }
void getCartesianLocation(SdaiModel AP210Model, SdaiAppInstance A2P_LOC, double *DeltaX, double *DeltaY, double *angle) {
   // assuming that A2P_LOC.context_of_items.coordinate_space_dimension is 2.
   static SdaiEntity cro_2d_entity = sdaiGetEntity(AP210Model,
                                                   "cartesian_transformation_operator_2d");
   static SdaiAttr role = sdaiGetAttrDefinition(cro_2d_entity, "local_origin");
   static SdaiAttr axis1attr = sdaiGetAttrDefinition(cro_2d_entity, "axis1");

   static SdaiAttr coordinates = sdaiGetAttrDefinitionBN(AP210,
                                                        "cartesian_point",
                                                        "coordinates");
   static SdaiAttr direction_ratios = sdaiGetAttrDefinitionBN(AP210,
                                                              "direction",
                                                              "direction_ratios");
   SdaiAppInstance unit = sdaiNULL;
   SdaiAppInstance cro_2d;
   SdaiAppInstance offset;
   SdaiAggr coords;
   SdaiAppInstance axis1;
   SdaiAggr ratios;
   double factor = 1.0;
   double CosTheta;

   cro_2d = _sdaiGetSingleRepresentationItemOfType(A2P_LOC, cro_2d_entity);

   if (cro_2d != sdaiNULL) {
      sdaiGetAttr(cro_2d, role, sdaiINSTANCE, &offset);

      // Get the coordinates LIST
      sdaiGetAttr(offset, coordinates, sdaiAGGR, &coords);

      sdaiGetAggrByIndex(coords, 0, sdaiREAL, DeltaX);
      sdaiGetAggrByIndex(coords, 1, sdaiREAL, DeltaY);

      *DeltaX = (*DeltaX) * factor;
      *DeltaY = (*DeltaY) * factor;

      // Get the rotation LIST
      sdaiGetAttr(cro_2d, axis1attr, sdaiINSTANCE, &axis1);
      sdaiGetAttr(axis1, direction_ratios, sdaiAGGR, &ratios);

      sdaiGetAggrByIndex(ratios, 0, sdaiREAL, &CosTheta);
      *angle = acos(CosTheta) * 180.0/acos(-1.0);
      }
   else {
      TRACE("WARNING: No cartesian_transformation_operator_2d found for:\r\n         ");
      TRACE(_sdaiGetPart21Description(A2P_LOC));
      TRACE(".\r\n");
      }
   }
/*
 * Function getPackagedComponentHeight 
 *
 * Given a packaged_component return it's height above the seating plane.

 */
double getPackagedComponentHeight(SdaiModel AP210Model, SdaiAppInstance pc) {
   static SdaiAttr description = sdaiGetAttrDefinitionBN(AP210,
                                                         "property_definition",
                                                         "description");
   SdaiReal height = 0.0;
   SdaiReal temp = 0.0;
   SdaiAppInstance p = sdaiNULL;    // package

#ifdef VERBOSE
TRACE0("In getPackagedComponentHeight()\r\n");
TRACE("packaged_component: %s\r\n", _sdaiGetPart21Description(pc));
#endif
   p = getPackagedComponentPackage(AP210Model, pc);
#ifdef VERBOSE
TRACE("package: %s\r\n", _sdaiGetPart21Description(p));
#endif

   if (p != sdaiNULL) {
      height = getPackageHeight(AP210Model, p);
      }
   if (height == 0.0) {
      TRACE0("WARNING: Component Height of 0.0\n");
      }
#ifdef VERBOSE
   else {
      TRACE("Component Height %f\r\n", height);
      }
#endif
      
   return height;
   }
/*
 * Function getPackageHeight 
 *
 * Given a packaged return it's height above the seating plane.
 *
 * NOTE:
 *    The empilot and the ITI translator represent the component height differently.
 *    The empilot representation_item has a name of "maximum body clearance about seating plane".
 *    The ITI representation_item has a name of "maximum height about seating plane".
 *    The correct name is "maximum height about seating plane". (Confirm this).
 *    This function would not handle design that have both properly.
 *
 * EMpilot Part21 Example:
 *    #56=LIBRARY_DEFINED_PACKAGE('','package',#228,#58,IDENTIFIER('cc1210'),#57);
 *    #1140=PROPERTY_DEFINITION('','',#56);
 *    #1141=PROPERTY_DEFINITION_REPRESENTATION(#1140,#1142);
 *    #1142=REPRESENTATION('package mounting data',(#1139),#13);
 *    #1139=(
 *    LENGTH_MEASURE_WITH_UNIT()
 *    MEASURE_REPRESENTATION_ITEM()
 *    MEASURE_WITH_UNIT(LENGTH_MEASURE(67.),#177)
 *    REPRESENTATION_ITEM('maximum body height above seating plane')
 *    );
 *
 * ITI Part21 Example:
 *    #104=PACKAGE('','',#102,#103);
 *    #381=PROPERTY_DEFINITION('c1206','ComponentGeometry.Height',#104);
 *    #384=PROPERTY_DEFINITION_REPRESENTATION(#381,#383);
 *    #383=REPRESENTATION('package mounting data',(#380),#382);
 *    #380=(LENGTH_MEASURE_WITH_UNIT()MEASURE_REPRESENTATION_ITEM()
 *       MEASURE_WITH_UNIT(LENGTH_MEASURE(0.060000),#155)REPRESENTATION_ITEM(
 *       'maximum height above seating plane'));
 *    #155=(CONVERSION_BASED_UNIT('INCH',#151)LENGTH_UNIT()NAMED_UNIT(#150));
 *    #151=LENGTH_MEASURE_WITH_UNIT(LENGTH_MEASURE(2.540000),#149);
 *    #150=DIMENSIONAL_EXPONENTS(1.0,0.0,0.0,0.0,0.0,0.0,0.0);
 *    #149=(LENGTH_UNIT()NAMED_UNIT(*)SI_UNIT(.CENTI.,.METRE.));
 */
double getPackageHeight(SdaiModel AP210Model, SdaiAppInstance p) {
   static SdaiAttr description = sdaiGetAttrDefinitionBN(AP210,
                                                         "property_definition",
                                                         "description");
   SdaiReal height = 0.0;
   SdaiReal temp = 0.0;
   SdaiAppInstance rep;
   SdaiAppInstance rep_item;
#ifdef VERBOSE
TRACE("In getPackageHeight()\r\n");
TRACE("p: 0x%08x\r\n", p);
TRACE("p: %s\r\n", _sdaiGetPart21Description(p));
#endif
   if (p != sdaiNULL) {
      rep = getNamedRepresentation(AP210Model, p, "package mounting data");
#ifdef VERBOSE
TRACE("representation: %s\r\n", _sdaiGetPart21Description(rep));
#endif
      if (rep != sdaiNULL) {
         rep_item = getNamedRepresentationItem(AP210Model, rep, "maximum body height above seating plane");
#ifdef VERBOSE
TRACE("representation_item: %s\r\n", _sdaiGetPart21Description(rep_item));
#endif
         if (rep_item != sdaiNULL) {
            height = getLengthMeasureWithUnit(AP210Model, rep_item);
            }
         }
      }
   if (height == 0.0) {
      TRACE0("WARNING: Package Height of 0.0\n");
      }
#ifdef VERBOSE
   else {
      TRACE("Package Height %f\r\n", height);
      }
#endif
      
   return height;
   }
void setPackageHeight(SdaiModel AP210Model, SdaiAppInstance p, double height) {
   static SdaiAttr description = sdaiGetAttrDefinitionBN(AP210,
                                                         "property_definition",
                                                         "description");
   SdaiReal temp = 0.0;
   SdaiAppInstance rep;
   SdaiAppInstance rep_item;

   if (p != sdaiNULL) {
      rep = getNamedRepresentation(AP210Model, p, "package mounting data");
#ifdef VERBOSE
TRACE("representation: %s\r\n", _sdaiGetPart21Description(rep));
#endif
      if (rep != sdaiNULL) {
         rep_item = getNamedRepresentationItem(AP210Model, rep, "maximum body height above seating plane");
#ifdef VERBOSE
TRACE("representation_item: %s\r\n", _sdaiGetPart21Description(rep_item));
#endif
         if (rep_item != sdaiNULL) {
            setLengthMeasureWithUnit(AP210Model, rep_item, height);
            }
         }
      }
   }
/*
 * Function getnamedRepresentation
 *    Given a characterized_definition and a name return the representation.
 *
 * TBD:
 *    Check to see if cd is really a characterized_definition.
 *
 * Part21 Example:
 *    #56=LIBRARY_DEFINED_PACKAGE('','package',#228,#58,IDENTIFIER('cc1210'),#57);
 *    #1140=PROPERTY_DEFINITION('','',#56);
 *    #1141=PROPERTY_DEFINITION_REPRESENTATION(#1140,#1142);
 *    #1142=REPRESENTATION('package mounting data',(#1139),#13);
 *
 */
SdaiAppInstance getNamedRepresentation(SdaiModel AP210Model, SdaiAppInstance cd, SdaiString name) {
   static SdaiEntity PD = sdaiGetEntity(AP210Model, "property_definition");
   static SdaiAttr PD_NAME = sdaiGetAttrDefinition(PD, "name");
   static SdaiAttr PD_DEF = sdaiGetAttrDefinition(PD, "definition");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "property_definition_representation");
   static SdaiAttr PDR_DEF = sdaiGetAttrDefinition(PDR, "definition");
   static SdaiAttr PDR_UR = sdaiGetAttrDefinition(PDR, "used_representation");

   static SdaiEntity REP = sdaiGetEntity(AP210Model, "representation");
   static SdaiAttr REP_NAME = sdaiGetAttrDefinition(REP, "name");

   SdaiNPL domain = sdaiCreateNPL();

   SdaiInstance pd;   // property_definition
   SdaiNPL pd_resultList = sdaiCreateNPL();
   SdaiIterator pd_itor;

   SdaiInstance pdr;   // property_definition_representation
   SdaiNPL pdr_resultList;
   SdaiIterator pdr_itor;

   SdaiInstance rep = sdaiNULL;       // representation
   SdaiString rep_name;
   SdaiInstance test;
   
#ifdef VERBOSE
TRACE0("In getnamedRepresentation()\r\n");
TRACE("characterized_definition: %s\r\n", _sdaiGetPart21Description(cd));
#endif
   // Get property_definitions in which the physical_unit_datum 
   // has the role of definition.
   sdaiFindInstanceUsedIn(cd, PD_DEF, domain, pd_resultList);
   if (sdaiGetMemberCount(pd_resultList) > 0) {
      pd_itor = sdaiCreateIterator(pd_resultList);
      while ((rep == sdaiNULL) && sdaiNext(pd_itor)) {
         sdaiGetAggrByIterator(pd_itor, sdaiINSTANCE, &pd); 
         if (sdaiIsKindOf(pd, PD)) {
#ifdef VERBOSE
TRACE("  property_definition: %s\r\n", _sdaiGetPart21Description(pd));
#endif
            pdr_resultList = sdaiCreateNPL();
            sdaiFindInstanceUsedIn(pd, PDR_DEF, domain, pdr_resultList);
            if (sdaiGetMemberCount(pdr_resultList) > 0) {
               pdr_itor = sdaiCreateIterator(pdr_resultList);
               while (sdaiNext(pdr_itor)) {
                  sdaiGetAggrByIterator(pdr_itor, sdaiINSTANCE, &pdr);
#ifdef VERBOSE
TRACE("    property_definition_representation: %s\r\n", _sdaiGetPart21Description(pdr));
#endif
                  sdaiGetAttr(pdr, PDR_UR, sdaiINSTANCE, &test);
                  sdaiGetAttr(test, REP_NAME, sdaiSTRING, &rep_name);
#ifdef VERBOSE
TRACE("      rep_name: %s\r\n", rep_name);
TRACE("          name: %s\r\n", name);
#endif
                  if (!strcmp(name, rep_name)) {
                     rep = test;
                     break;
                     }
                  }
               sdaiDeleteNPL(pdr_resultList);
               sdaiDeleteIterator(pdr_itor);
               }
            }
         }
      sdaiDeleteNPL(pd_resultList);
      sdaiDeleteIterator(pd_itor);
      }
   return rep;
   }
/*
 * Function getLocatedInterconnectModuleThickness
 *
 * Given the physical_unit for a PCB get it's thickness product_definition.
 *
 * There are some navigation functions that could be
 * extracted from this function.
 * Such as:
 *      sdai AppInstance getPropertyDefinition()
 *         Given a characterized_definition and a name return the property_definition.
 *      sdai AppInstance getPropertyDefinitionRepresentation()
 *      sdai AppInstance getnamedRepresentation()
 *         Given a characterized_definition and a name return the representation.
 *
 * NOTE:
 *    Intent is to follow recomended practice.  The physical_unit
 *    should be the 'physical design usage' one.
 *
 * DIS Part21 Example:
 *    #146=PHYSICAL_UNIT('','interconnect module',#224,#58);
 *    #1185=PRODUCT_DEFINITION_SHAPE('','',#146);
 *    #183=PHYSICAL_UNIT_DATUM('','point',#1185,.F.);
 *    #185=PROPERTY_DEFINITION('located interconnect module thickness','',#183);
 *    #184=PROPERTY_DEFINITION_REPRESENTATION(#185,#187);
 *    #187=REPRESENTATION('',(#186,#188),#13); // THIS REPRESENTATION SHOULD HAVE A NAME! (all should!)
 *
 *    maximum thickness
 *
 *    #186=(
 *    LENGTH_MEASURE_WITH_UNIT()
 *    MEASURE_REPRESENTATION_ITEM()
 *    MEASURE_WITH_UNIT(LENGTH_MEASURE(62.),#177)
 *    REPRESENTATION_ITEM('maximum thickness')
 *    );
 *    #177=(
 *    CONVERSION_BASED_UNIT('mil',#179)
 *    LENGTH_UNIT()
 *    NAMED_UNIT(#178)
 *    #178=DIMENSIONAL_EXPONENTS(1.,0.,0.,0.,0.,0.,0.);
 *
 * IS Part21 Example:
 *    #195=PHYSICAL_UNIT('','interconnect module',#90,#213);
 *    #213=PRODUCT_DEFINITION_CONTEXT('physical design usage',#220, 'as designed');
 *    #103=PROPERTY_DEFINITION('located interconnect module thickness','',#195);
 *    #158=PRODUCT_DEFINITION_SHAPE('','',#195);
 *
 */
SdaiAppInstance getLocatedInterconnectModuleThickness(SdaiModel AP210Model, SdaiAppInstance pu) {
   static SdaiEntity PDS = sdaiGetEntity(AP210Model, "product_definition_shape");
   static SdaiAttr PDS_DEF = sdaiGetAttrDefinition(PDS, "definition");
   
   static SdaiEntity PUD = sdaiGetEntity(AP210Model, "physical_unit_datum");
   static SdaiAttr PUD_DES = sdaiGetAttrDefinition(PUD, "description");
   static SdaiAttr PUD_OS = sdaiGetAttrDefinition(PUD, "of_shape");

   static SdaiEntity PD = sdaiGetEntity(AP210Model, "property_definition");
   static SdaiAttr PD_NAME = sdaiGetAttrDefinition(PD, "name");
   static SdaiAttr PD_DEF = sdaiGetAttrDefinition(PD, "definition");

   SdaiNPL domain = sdaiCreateNPL();
   SdaiInstance pds;   // product_definition_shape
   SdaiNPL pds_resultList;
   SdaiIterator pds_itor;

   SdaiInstance pud;   // physical_unit_datum
   SdaiNPL pud_resultList;
   SdaiIterator pud_itor;
   SdaiString pud_des;

   SdaiInstance pd;   // property_definition
   SdaiNPL pd_resultList;
   SdaiIterator pd_itor;
   SdaiString pd_name;

#ifdef VERBOSE
TRACE0("In getLocatedInterconnectModuleThickness()\r\n");
tracePhysicalUnitView(AP210Model, pu);
#endif
   // Get product_definition_shape in which the physical_unit 
   // has the role of definition.
   pds_resultList = sdaiCreateNPL();
   // MIKE LOOK HERE
   // needs to be different PU for ITI 'physical design usage' rather than
   // 'physical design'.
   //
   sdaiFindInstanceUsedIn(pu, PDS_DEF, domain, pds_resultList);
   if (sdaiGetMemberCount(pds_resultList) > 0) {
      pds_itor = sdaiCreateIterator(pds_resultList);
      while (sdaiNext(pds_itor)) {
         sdaiGetAggrByIterator(pds_itor, sdaiINSTANCE, &pds); 
#ifdef VERBOSE
TRACE("product_definition_shape: %s\r\n", _sdaiGetPart21Description(pds));
#endif
         // IS Mapping
         if (sdaiIsInstanceOf(pds, PD)) {
            sdaiGetAttr(pds, PD_NAME, sdaiSTRING, &pd_name);
            // Get the property_definition with a name of
            // "located interconnect module thickness"
            if (!strcmp(pd_name, "located interconnect module thickness")) {
#ifdef VERBOSE
TRACE("located interconnect module thickness found.\r\n");
TRACE("    property_definition: %s\r\n", _sdaiGetPart21Description(pds));
#endif
                return pds;
                }
            }
         // DIS Mapping
         else {
            // Get physical_unit_datums in which the product_definition_shape 
            // has the role of of_shape.
            pud_resultList = sdaiCreateNPL();
            sdaiFindInstanceUsedIn(pds, PUD_OS, domain, pud_resultList);

            if (sdaiGetMemberCount(pud_resultList) > 0) {
               pud_itor = sdaiCreateIterator(pud_resultList);

               while (sdaiNext(pud_itor)) {
                  sdaiGetAggrByIterator(pud_itor, sdaiINSTANCE, &pud); 

                  if (sdaiIsKindOf(pud, PUD)) {
                     sdaiGetAttr(pud, PUD_DES, sdaiSTRING, &pud_des);
                     if (!strcmp(pud_des, "point")) {
#ifdef VERBOSE
TRACE("  physical_unit_datum: %s\r\n", _sdaiGetPart21Description(pud));
#endif
                        // Get property_definitions in which the physical_unit_datum 
                        // has the role of definition.
                        pd_resultList = sdaiCreateNPL();
                        sdaiFindInstanceUsedIn(pud, PD_DEF, domain, pd_resultList);
                        if (sdaiGetMemberCount(pd_resultList) > 0) {
                           pd_itor = sdaiCreateIterator(pd_resultList);
                           while (sdaiNext(pd_itor)) {
                              sdaiGetAggrByIterator(pd_itor, sdaiINSTANCE, &pd); 
                              if (sdaiIsKindOf(pd, PD)) {
                                 sdaiGetAttr(pd, PD_NAME, sdaiSTRING, &pd_name);
                                 // Get the property_definition with a name of
                                 // "located interconnect module thickness"
                                 if (!strcmp(pd_name, "located interconnect module thickness")) {
#ifdef VERBOSE
TRACE("located interconnect module thickness found.\r\n");
TRACE("    property_definition: %s\r\n", _sdaiGetPart21Description(pd));
#endif
                                    return pd;
                                    }
                                 }
                              }
                           sdaiDeleteIterator(pd_itor);
                           }
                        sdaiDeleteNPL(pd_resultList);
                        }
                     }
                  }
               sdaiDeleteIterator(pud_itor);
               }
            sdaiDeleteNPL(pud_resultList);
            }
         }
      sdaiDeleteIterator(pds_itor);
      }
   sdaiDeleteNPL(pds_resultList);
   sdaiDeleteNPL(domain);
#ifdef VERBOSE
TRACE("No located interconnect module thickness found.\r\n");
#endif
   return sdaiNULL;
   }
/*
 * Function getPCBThickness
 *
 * Given the physical_unit for a PCB get it's thickness.
 */
double getPCBThickness(SdaiModel AP210Model, SdaiAppInstance pu) {
   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "property_definition_representation");
   static SdaiAttr PDR_DEF = sdaiGetAttrDefinition(PDR, "definition");
   static SdaiAttr PDR_UR = sdaiGetAttrDefinition(PDR, "used_representation");

   double thickness = 0.0;
   SdaiNPL domain = sdaiCreateNPL();

   SdaiInstance pd;   // property_definition

   SdaiInstance pdr;   // property_definition_representation
   SdaiNPL pdr_resultList;
   SdaiIterator pdr_itor;

   SdaiInstance rep;     // representation
   SdaiInstance rep_item;

#ifdef VERBOSE
TRACE0("In getPCBThickness()\r\n");
tracePhysicalUnitView(AP210Model, pu);
#endif
   if ((pd = getLocatedInterconnectModuleThickness(AP210Model, pu)) != sdaiNULL) {
      // Get property_definition_representation in which the property_definition
      // has the role of definition.
      pdr_resultList = sdaiCreateNPL();
      sdaiFindInstanceUsedIn(pd, PDR_DEF, domain, pdr_resultList);

      if (sdaiGetMemberCount(pdr_resultList) > 0) {
         pdr_itor = sdaiCreateIterator(pdr_resultList);

         while (sdaiNext(pdr_itor)) {
            sdaiGetAggrByIterator(pdr_itor, sdaiINSTANCE, &pdr); 
#ifdef VERBOSE
TRACE("      property_definition_representation: %s\r\n", _sdaiGetPart21Description(pdr));
#endif
            sdaiGetAttr(pdr, PDR_UR, sdaiINSTANCE, &rep);
#ifdef VERBOSE
TRACE("        representation: %s\r\n", _sdaiGetPart21Description(rep));
#endif
            // Find the representation_item in the representations 
            // items with a name of "maximum thickness.
            if ((rep_item = getNamedRepresentationItem(AP210Model, rep,
                 "maximum thickness")) != sdaiNULL) {
#ifdef VERBOSE
TRACE("          representation_item: %s\r\n", _sdaiGetPart21Description(rep_item));
#endif
               thickness = getLengthMeasureWithUnit(AP210Model, rep_item);
               break;
               }
            }
         sdaiDeleteIterator(pdr_itor);
         }
      sdaiDeleteNPL(pdr_resultList);
      }
   sdaiDeleteNPL(domain);
#ifdef VERBOSE
TRACE("RC thickness: %f\r\n", thickness);
#endif
   return thickness;
   }
/*
 * Function setPCBThickness
 *
 * Given the physical_unit for a PCB and a thickness set it's thickness.
 */
void setPCBThickness(SdaiModel AP210Model, SdaiAppInstance pu, double thickness) {
   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "property_definition_representation");
   static SdaiAttr PDR_DEF = sdaiGetAttrDefinition(PDR, "definition");
   static SdaiAttr PDR_UR = sdaiGetAttrDefinition(PDR, "used_representation");

   SdaiNPL domain = sdaiCreateNPL();

   SdaiInstance pd;   // property_definition

   SdaiInstance pdr;   // property_definition_representation
   SdaiNPL pdr_resultList;
   SdaiIterator pdr_itor;

   SdaiInstance rep;     // representation
   SdaiInstance rep_item;

#ifdef VERBOSE
TRACE0("In getPCBThickness()\r\n");
tracePhysicalUnitView(AP210Model, pu);
#endif
   if ((pd = getLocatedInterconnectModuleThickness(AP210Model, pu)) != sdaiNULL) {
      // Get property_definition_representation in which the property_definition
      // has the role of definition.
      pdr_resultList = sdaiCreateNPL();
      sdaiFindInstanceUsedIn(pd, PDR_DEF, domain, pdr_resultList);

      if (sdaiGetMemberCount(pdr_resultList) > 0) {
         pdr_itor = sdaiCreateIterator(pdr_resultList);

         while (sdaiNext(pdr_itor)) {
            sdaiGetAggrByIterator(pdr_itor, sdaiINSTANCE, &pdr); 
#ifdef VERBOSE
TRACE("      property_definition_representation: %s\r\n", _sdaiGetPart21Description(pdr));
#endif
            sdaiGetAttr(pdr, PDR_UR, sdaiINSTANCE, &rep);
#ifdef VERBOSE
TRACE("        representation: %s\r\n", _sdaiGetPart21Description(rep));
#endif
            // Find the representation_item in the representations 
            // items with a name of "maximum thickness.
            if ((rep_item = getNamedRepresentationItem(AP210Model, rep,
                            "maximum thickness")) != sdaiNULL) {
#ifdef VERBOSE
TRACE("          representation_item: %s\r\n", _sdaiGetPart21Description(rep_item));
#endif
               setLengthMeasureWithUnit(AP210Model, rep_item, thickness);
               break;
               }
            }
         sdaiDeleteIterator(pdr_itor);
         }
      sdaiDeleteNPL(pdr_resultList);
      }
   else {
      TRACE("WARNING: No PCB thickness available on\r\n");
      TRACE("         %s\r\n", _sdaiGetPart21Description(pu));
      TRACE("         to set to %f\r\n", thickness);
      }
   sdaiDeleteNPL(domain);
   }
/*
 * Function getNamedRepresentationItem
 *
 * Given a representation and a name return a representation_item
 * from the representations item list if it exists otherwise 
 * return sdaiNULL.
 *
 * Part21 Example for "maximum thickness"
 *    #187=REPRESENTATION('',(#186,#188),#13);
 *    #186=(
 *    LENGTH_MEASURE_WITH_UNIT()
 *    MEASURE_REPRESENTATION_ITEM()
 *    MEASURE_WITH_UNIT(LENGTH_MEASURE(62.),#177)
 *    REPRESENTATION_ITEM('maximum thickness')
 *    );
 */
SdaiAppInstance getNamedRepresentationItem(SdaiModel AP210Model, SdaiAppInstance rep, SdaiString name) {
   static SdaiEntity REP = sdaiGetEntity(AP210Model, "representation");
   static SdaiAttr REP_ITEMS = sdaiGetAttrDefinition(REP, "items");

   static SdaiEntity REPITEM = sdaiGetEntity(AP210Model, "representation_item");
   static SdaiAttr REPITEM_NAME = sdaiGetAttrDefinition(REPITEM, "name");

   SdaiAggr rep_items;
   SdaiInstance item;
   SdaiInstance rep_item = sdaiNULL;
   SdaiIterator rep_itor;
   SdaiString rep_item_name;

#ifdef VERBOSE
TRACE("In getNamedRepresentationItem\r\nname: %s\r\n", name);
#endif
   sdaiGetAttr(rep, REP_ITEMS, sdaiAGGR, &rep_items);
   rep_itor = sdaiCreateIterator(rep_items);
   while (sdaiNext(rep_itor)) {
      sdaiGetAggrByIterator(rep_itor, sdaiINSTANCE, &item);
      sdaiGetAttr(item, REPITEM_NAME, sdaiSTRING, &rep_item_name);
                  
      if (!strcmp(rep_item_name, name)) {
#ifdef VERBOSE
TRACE("          representation_item: %s\r\n", _sdaiGetPart21Description(item));
TRACE("            representation_item.name: %s\r\n", rep_item_name);
#endif
         rep_item = item;
         break;
         }
      }
   sdaiDeleteNPL(rep_items);
   sdaiDeleteIterator(rep_itor);
   return rep_item;
   }
/*
 * Function getLengthMeasureWithUnit()
 *    Given a length_measure_with_return the length.
 *
 * Part21 Example:
 *    #186=(
 *    LENGTH_MEASURE_WITH_UNIT()
 *    MEASURE_REPRESENTATION_ITEM()
 *    MEASURE_WITH_UNIT(LENGTH_MEASURE(62.),#177)
 *    REPRESENTATION_ITEM('maximum thickness')
 *    );
 *    #177=(
 *    CONVERSION_BASED_UNIT('mil',#179)
 *    LENGTH_UNIT()
 *    NAMED_UNIT(#178)
 *    #178=DIMENSIONAL_EXPONENTS(1.,0.,0.,0.,0.,0.,0.);
 */
SdaiReal getLengthMeasureWithUnit(SdaiModel AP210Model, SdaiAppInstance length) {
//   static SdaiEntity LMWU = sdaiGetEntity(AP210Model, "length_measure_with_unit");

   static SdaiEntity MWU = sdaiGetEntity(AP210Model, "measure_with_unit");
   static SdaiAttr MWU_VC = sdaiGetAttrDefinition(MWU, "value_component");
   static SdaiAttr MWU_UC = sdaiGetAttrDefinition(MWU, "unit_component");

   SdaiReal value = 0.0;
   SdaiReal factor = 0.0;
   SdaiAppInstance unit;

// this makes sure it is a length but doesn't work for mechanical parts in the IDF translator
//   if (sdaiIsKindOf(length, length_measure_with_unit)) {
   if (sdaiIsKindOf(length, MWU)) {
      sdaiGetAttr(length, MWU_VC, sdaiREAL, &value);
      sdaiGetAttr(length, MWU_UC, sdaiINSTANCE, &unit);

      if (unit != sdaiNULL) {
         value = value * getUnitConversionFactor(AP210Model, unit, &factor); 
         }
      }
   return value;
   }
/*
    SdaiADB adb = sdaiCreateADB (sdaiREAL, 3.4);
    sdaiPutADBTypePath (adb, 1, typenames);
    sdaiPutAttrBN (inst, "value_component", sdaiADB, &adb);
*/
void setLengthMeasureWithUnit(SdaiModel AP210Model, SdaiAppInstance length, double value) {
//   static SdaiEntity LMWU = sdaiGetEntity(AP210Model, "length_measure_with_unit");

   static SdaiEntity MWU = sdaiGetEntity(AP210Model, "measure_with_unit");
   static SdaiAttr MWU_VC = sdaiGetAttrDefinition(MWU, "value_component");
   static SdaiAttr MWU_UC = sdaiGetAttrDefinition(MWU, "unit_component");

   SdaiReal factor = 0.0;
   SdaiAppInstance unit;
TRACE("In setLengthMeasureWithUnit()\r\n");
// this makes sure it is a length but doesn't work for mechanical parts in the IDF translator
//   if (sdaiIsKindOf(length, length_measure_with_unit)) {
   if (sdaiIsKindOf(length, MWU)) {
      sdaiGetAttr(length, MWU_UC, sdaiINSTANCE, &unit);

      if (unit != sdaiNULL) {
         value = value / getUnitConversionFactor(AP210Model, unit, &factor); 
         }
TRACE("Value: %f\r\n", value);
      SdaiADB value_adb = sdaiCreateADB (sdaiREAL, value);
      sdaiPutADBTypePath (value_adb, 1, LM_TYPENAMES);
      sdaiPutAttr(length, MWU_VC, sdaiADB, value_adb);
      }
   }
/*
 * Function getInterconnectModuleEdgeShapeRep
 *
 *   Given a interconnect modules physical_unit returns
 *   the shape_representation of the interconnect modules edge,
 *   per the mapping tables.

In getInterconnectModuleEdgeShapeRep()
pu: #973 a physical_unit  Value = 0-0 
NAUO count 12
nauo: #579 a assembly_component_usage  Value = 0-0 
  name: interconnect module stratum assembly relationship 
  description:  
  nauo_ed: #517 a stratum  Value = 0-0 
    component_definition.id: top 
    component_definition.description:  
ERROR: #517 a stratum  Value = 0-0 not used in entityName.attributeName
nauo: #580 a assembly_component_usage  Value = 0-0 
  name: interconnect module stratum assembly relationship 
  description:  
  nauo_ed: #518 a stratum  Value = 0-0 
    component_definition.id: bottom 
    component_definition.description:  
ERROR: #518 a stratum  Value = 0-0 not used in entityName.attributeName
nauo: #220 a next_assembly_usage_occurrence  Value = 0-0 
  name: assembly composition 
  description:  
  nauo_ed: #632 a component_definition  Value = 0-0 
    component_definition.id:  
    component_definition.description: interconnect module edge 
Found pds: #596 a product_definition_shape  Value = 0-0 
Found isf: #255 a inter_stratum_feature  Value = 0-0 
   isf.description: interconnect module edge 
FOUND interconnect module edge
nauo: #220 a next_assembly_usage_occurrence  Value = 0-0 
  description:  
  nauo_ed: #632 a component_definition  Value = 0-0 
sr: #671 a geometrically_bounded_2d_wireframe_representation  Value = 0-0 
Found Board Graphics!
Returning from getInterconnectModuleEdgeShapeRep()


 */
SdaiAppInstance getInterconnectModuleEdgeShapeRep(SdaiModel AP210Model, SdaiAppInstance pu) {
   static SdaiEntity NAUO = sdaiGetEntity(AP210Model, "next_assembly_usage_occurrence");
   static SdaiAttr NAUO_ED = sdaiGetAttrDefinition(NAUO, "related_product_definition");
   static SdaiAttr NAUO_ING = sdaiGetAttrDefinition(NAUO, "relating_product_definition");

   static SdaiEntity PDS = sdaiGetEntity(AP210Model, "product_definition_shape");
   static SdaiAttr PDS_DEF = sdaiGetAttrDefinition(PDS, "definition");
   SdaiAppInstance pds = sdaiNULL; // product_definition_shape

   static SdaiEntity ISF = sdaiGetEntity(AP210Model, "inter_stratum_feature");
   static SdaiAttr ISF_DESC = sdaiGetAttrDefinition(ISF, "description");
   static SdaiAttr ISF_OS = sdaiGetAttrDefinition(ISF, "of_shape");
   SdaiAppInstance isf = sdaiNULL;
   SdaiString isf_desc;

#ifdef VERBOSE
   static SdaiEntity CD = sdaiGetEntity(AP210Model, "component_definition");
   static SdaiAttr CD_DESC = sdaiGetAttrDefinition(CD, "description");

   SdaiString cd_desc;             // component_definition.description
   static SdaiAttr CD_ID = sdaiGetAttrDefinition(CD, "id");
   SdaiString cd_id;             // component_definition.id
   static SdaiAttr NAUO_NAME = sdaiGetAttrDefinition(NAUO, "name");
   SdaiString nauo_name;
   static SdaiAttr NAUO_DESC = sdaiGetAttrDefinition(NAUO, "description");
   SdaiString nauo_desc;
#endif
   SdaiAppInstance nauo;
   SdaiAppInstance nauo_ed; // component_definition
   SdaiIterator itor;
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL nauoList = sdaiCreateNPL();
   SdaiAppInstance sr = sdaiNULL; // shape_representation

   // Get entities in which the physical_unit is used in the relating_product_definition role.
   sdaiFindInstanceUsedIn(pu, NAUO_ING, domain, nauoList);

#ifdef VERBOSE
   TRACE("In getInterconnectModuleEdgeShapeRep()\n");
   TRACE("pu: %s \n", _sdaiGetPart21Description(pu));
#endif

#ifdef VERBOSE
   TRACE("NAUO count %d\n", sdaiGetMemberCount(nauoList));
#endif
   itor = sdaiCreateIterator(nauoList);

   if (sdaiGetMemberCount(nauoList) > 0) {
      while(sdaiNext(itor) && sr == sdaiNULL) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &nauo); 
         sdaiGetAttr(nauo, NAUO_ED, sdaiINSTANCE, &nauo_ed);
#ifdef VERBOSE
         TRACE("nauo: %s \n", _sdaiGetPart21Description(nauo));
         sdaiGetAttr(nauo, NAUO_NAME, sdaiSTRING, &nauo_name);
         TRACE("  name: %s \n", nauo_name);
         sdaiGetAttr(nauo, NAUO_DESC, sdaiSTRING, &nauo_desc);
         TRACE("  description: %s \n", nauo_desc);
         TRACE("  nauo_ed: %s \n", _sdaiGetPart21Description(nauo_ed));
         sdaiGetAttr(nauo_ed, CD_ID, sdaiSTRING, &cd_id);
         TRACE("    component_definition.id: %s \n", cd_id);
         sdaiGetAttr(nauo_ed, CD_DESC, sdaiSTRING, &cd_desc);
         TRACE("    component_definition.description: %s \n", cd_desc);
#endif
         pds = _sdaiFindSingleSubTypeInstanceUsedIn(nauo_ed, PDS, PDS_DEF);

         if (pds != sdaiNULL) {
#ifdef VERBOSE
           TRACE("Found pds: %s \n", _sdaiGetPart21Description(pds));
#endif
            isf = _sdaiFindSingleSubTypeInstanceUsedIn(pds, ISF, ISF_OS);
            if (isf != sdaiNULL) {
               sdaiGetAttr(isf, ISF_DESC, sdaiSTRING, &isf_desc);
#ifdef VERBOSE
               TRACE("Found isf: %s \n", _sdaiGetPart21Description(isf));
               TRACE("   isf.description: %s \n", isf_desc);
#endif

               if (!strcmp(isf_desc, "interconnect module edge")) {
#ifdef VERBOSE
                  TRACE("FOUND interconnect module edge\r\n");
                  TRACE("nauo: %s \n", _sdaiGetPart21Description(nauo));
                  TRACE("  description: %s \n", nauo_desc);
                  TRACE("  nauo_ed: %s \n", _sdaiGetPart21Description(nauo_ed));
#endif
                  // this function is probably miss named.
                  sr = getComponentDefinitionShapeRepresentation(AP210Model, nauo_ed); // might need replacing
#ifdef VERBOSE
                  TRACE("sr: %s \n", _sdaiGetPart21Description(sr));
#endif
                  }
               }
            }
         }
      }
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(nauoList);
   sdaiDeleteIterator(itor);
#ifdef VERBOSE
   if (sr != sdaiNULL) {
      TRACE("Found Board Graphics!\n");
      }
   else {
      TRACE("Didn't find Board Graphics!\n");
      }
   TRACE("Returning from getInterconnectModuleEdgeShapeRep()\n");
#endif
   return(sr);
   }
/*
 * Function getNamedProductDefinitionShapeAspect
 *
 *  MTK KLUDGE ALERT Really need to pass in the name!
 *
 *   Given a product and a shape_aspect name
 *   returns the named shape_aspect related to the
 *   product by a product_definition_shape.
 */
SdaiAppInstance getNamedProductDefinitionShapeAspect(SdaiModel AP210Model, SdaiAppInstance prod) {
   static SdaiEntity PDS = sdaiGetEntity(AP210Model, "product_definition_shape");
   static SdaiAttr PDS_DEF = sdaiGetAttrDefinition(PDS, "definition");

   static SdaiEntity SA = sdaiGetEntity(AP210Model, "shape_aspect");
   static SdaiAttr SA_DESC = sdaiGetAttrDefinition(SA, "description");
   static SdaiAttr SA_OS = sdaiGetAttrDefinition(SA, "of_shape");

   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL saList = sdaiCreateNPL();

   SdaiIterator itor;
   SdaiAppInstance test;           // test shape_aspect
   SdaiAppInstance sa = sdaiNULL;  // shape_aspect
   SdaiString sa_desc;
   SdaiAppInstance pds = sdaiNULL; // product_definition_shape
#ifdef VERBOSE
   TRACE("In getNamedProductDefinitionShapeAspect()\n");
   TRACE("prod: %s \n", _sdaiGetPart21Description(prod));
#endif
   pds = _sdaiFindSingleSubTypeInstanceUsedIn(prod, PDS, PDS_DEF);
#ifdef VERBOSE
   TRACE("pds: %s \n", _sdaiGetPart21Description(pds));
#endif
   // return a list of shape_aspects with pds as the of_shape
   sdaiFindInstanceUsedIn(pds, SA_OS, domain, saList);

   itor = sdaiCreateIterator(saList);

   if (sdaiGetMemberCount(saList) > 0) {
      while(sdaiNext(itor) && sa == sdaiNULL) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &test); 
         sdaiGetAttr(test, SA_DESC, sdaiSTRING, &sa_desc);
#ifdef VERBOSE
         TRACE("test: %s \n", _sdaiGetPart21Description(sa));
         TRACE("sa_desc: %s \n", sa_desc);
#endif
         if (!strcmp(sa_desc, "interconnect module edge surface")) {
            sa = test;
            }
         }
      }
#ifdef VERBOSE
   TRACE("sa: %s \n", _sdaiGetPart21Description(sa));
#endif
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(saList);
   return sa;
   }
/*
 * Function getInterconnectModuleEdgeSurfaceShapeRep
 *
 *   Given a interconnect modules physical_unit returns
 *   the shape_representation of the interconnect modules edge surface,
 *   per the mapping tables.
 */
#define VERBOSE
SdaiAppInstance getInterconnectModuleEdgeSurfaceShapeRep(SdaiModel AP210Model, SdaiAppInstance pu) {
   static SdaiEntity PD = sdaiGetEntity(AP210Model, "property_definition");
   static SdaiAttr PD_DEF = sdaiGetAttrDefinition(PD, "definition");

   SdaiAppInstance sa = sdaiNULL;  // shape_aspect
   SdaiAppInstance pd = sdaiNULL;  // property_definition
   SdaiAppInstance sr = sdaiNULL;  // shape_representation

#ifdef VERBOSE
   TRACE("In getInterconnectModuleEdgeSurfaceShapeRep()\n");
   TRACE("pu: %s \n", _sdaiGetPart21Description(pu));
#endif
   sa = getNamedProductDefinitionShapeAspect(AP210Model, pu);
#ifdef VERBOSE
   TRACE("sa: %s \n", _sdaiGetPart21Description(sa));
#endif
   pd = _sdaiFindSingleSubTypeInstanceUsedIn(sa, PD, PD_DEF);
#ifdef VERBOSE
   TRACE("pd: %s \n", _sdaiGetPart21Description(pd));
#endif
   sr = getGraphicPropertiesShapeRep(AP210Model, pd);
#ifdef VERBOSE
   TRACE("sr: %s \n", _sdaiGetPart21Description(sr));
#endif

#ifdef VERBOSE
   if (sr != sdaiNULL) {
      TRACE("Found Board Graphics!\n");
      }
   else {
      TRACE("Didn't find Board Graphics!\n");
      }
   TRACE("Returning from getInterconnectModuleEdgeSurfaceShapeRep()\n");
#endif
   return(sr);
   }
#undef VERBOSE
void tracePhysicalUnitView(SdaiModel AP210Model, SdaiAppInstance pu) {
   SdaiString Name;
   SdaiString ProductRelationship;

   static SdaiEntity PU = sdaiGetEntity(AP210Model, "physical_unit");
   static SdaiAttr PU_FOR = sdaiGetAttrDefinition(PU, "frame_of_reference");

   static SdaiEntity PDC = sdaiGetEntity(AP210Model, "product_definition_context");
   static SdaiAttr PDC_NAME = sdaiGetAttrDefinition(PDC, "name");

   static SdaiAttr PRPC_NAME = sdaiGetAttrDefinitionBN(AP210,
                                                      "product_related_product_category",
                                                      "name");

   SdaiAppInstance prpc; // product_related_product_catagory
   SdaiAppInstance pdc;  // physical_unit frame_of_reference
   prpc = getPhysicalUnitsProductRelatedProductCategory(pu);

   /* get the prpc's name */
   sdaiGetAttr(prpc, PRPC_NAME, sdaiSTRING, &Name);
   sdaiGetAttr(pu, PU_FOR, sdaiINSTANCE, &pdc);
   sdaiGetAttr(pdc, PDC_NAME, sdaiSTRING, &ProductRelationship);

   TRACE("physical_unit: %s\n", _sdaiGetPart21Description(pu));
   TRACE("pdc: %s\n", _sdaiGetPart21Description(pdc));
   TRACE("ProductRelationship: %s\n", ProductRelationship);
   TRACE("Name: %s\r\n", Name);
   }
/*
 * Function GetComponentDescriptiveRepresentationItemList
 *
 * Given a packaged_component return the list of
 * descriptive_representation_item.
 *
 * Part21 Example:
 *   #12857=PACKAGED_COMPONENT('C1','',#12855,#12856);
 *   #12899=REQUIREMENTS_PROPERTY('','',#12857);
 *   #12903=PROPERTY_DEFINITION_REPRESENTATION(#12899,#12902);
 *   #12902=COORDINATED_REPRESENTATION_ITEM('',(#12900),#12901,
 *       'planned characteristic');
 *   #12900=DESCRIPTIVE_REPRESENTATION_ITEM('POW_MAX','0.');
 */
SdaiNPL getComponentDescriptiveRepresentationItemList(SdaiModel AP210Model,
                                                      SdaiAppInstance pc) {
   static SdaiEntity DRI = sdaiGetEntity(AP210Model, "descriptive_representation_item");

   static SdaiAttr rp_def = sdaiGetAttrDefinitionBN(AP210,
                                                    "requirements_property",
                                                    "definition");

   static SdaiEntity pdr_entity= sdaiGetEntity(AP210Model, 
                                               "property_definition_representation");
   static SdaiAttr pdr_def = sdaiGetAttrDefinition(pdr_entity, "definition");
   static SdaiAttr pdr_used_rep = sdaiGetAttrDefinition(pdr_entity,
                                                        "used_representation");

   static SdaiAttr cri_items = sdaiGetAttrDefinitionBN(AP210,
                                                    "coordinated_representation_item",
                                                    "items");
//   SdaiIterator rp_itor;
//   SdaiIterator pdr_itor;
//   SdaiIterator items_itor;
   SdaiAppInstance dri = sdaiNULL;
   SdaiAppInstance test;
   SdaiAppInstance cri;
   SdaiAggr items; 
   SdaiAppInstance pdr;
   SdaiAppInstance rp; 
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL rps = sdaiCreateNPL();

   SdaiNPL resultList = sdaiCreateNPL(); // passed back
   SdaiIterator resultitor = sdaiCreateIterator(resultList);

#ifdef VERBOSE
TRACE("In getComponentDescriptiveRepresentationItemList()\r\n");
TRACE("pc: %s\r\n", _sdaiGetPart21Description(pc));
#endif

   // return a list of requirements_propertys pc as the definition
   sdaiFindInstanceUsedIn(pc, rp_def, domain, rps);
   if (sdaiGetMemberCount(rps) > 0) {
      SdaiIterator rp_itor = sdaiCreateIterator(rps);

      while (sdaiNext(rp_itor)) {
         sdaiGetAggrByIterator(rp_itor, sdaiINSTANCE, &rp); 
#ifdef VERBOSE
TRACE(" rp: %s\r\n", _sdaiGetPart21Description(rp));
#endif
         // return a list of property_definition_representations with rp as the definition
         SdaiNPL pdrs = sdaiCreateNPL();
         sdaiFindInstanceUsedIn(rp, pdr_def, domain, pdrs);

         if (sdaiGetMemberCount(pdrs) > 0) {
            SdaiIterator pdr_itor = sdaiCreateIterator(pdrs);

            while (sdaiNext(pdr_itor)) {
               sdaiGetAggrByIterator(pdr_itor, sdaiINSTANCE, &pdr); 
#ifdef VERBOSE
TRACE(" pdr: %s\r\n", _sdaiGetPart21Description(pdr));
#endif
               sdaiGetAttr(pdr, pdr_used_rep, sdaiINSTANCE, &cri);
#ifdef VERBOSE
TRACE(" cri: %s\r\n", _sdaiGetPart21Description(cri));
#endif
               sdaiGetAttr(cri, cri_items, sdaiAGGR, &items);
               SdaiIterator items_itor = sdaiCreateIterator(items);

               while (sdaiNext(items_itor)) {
                  sdaiGetAggrByIterator(items_itor, sdaiINSTANCE, &test); 
#ifdef VERBOSE
TRACE(" test: %s\r\n", _sdaiGetPart21Description(test));
#endif

                  if (sdaiIsInstanceOf(test, DRI)) {
#ifdef VERBOSE
TRACE("Found test: %s\r\n", _sdaiGetPart21Description(test));
#endif
                     // add to resultList
                     sdaiEnd(resultitor);
                     sdaiInsertBefore(resultitor, sdaiINSTANCE, test);
                     }
                  }
               // Delete iterator
               sdaiDeleteIterator(items_itor);

               if (dri != sdaiNULL) {
                  break;
                  }
               }
            // Delete iterator
            sdaiDeleteIterator(pdr_itor);

            if (dri != sdaiNULL) {
               break;
               }
            }
         sdaiDeleteNPL(pdrs);
         }
      // Delete iterator
      sdaiDeleteIterator(rp_itor);
      }

   // Delete SdaiNPLs
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(rps);

   return resultList;
   }
/*
 * Function getProductDefinitionProduct
 *
 * Given a product_definition return its product.
 *
 * Part21 Example:
 * #1660=COMPONENT_DEFINITION('','',#1397,#1736);
 * #1042=PRODUCT_DEFINITION_RELATIONSHIP('','instantiated part','',#1541,#1660);
 * #1541=PHYSICAL_UNIT('','',#1397,#1739);
 * #1397=PRODUCT_DEFINITION_FORMATION('','',#1378);
 * #1378=PRODUCT('pn-extractor','','',(#1746));


 * #1746=PRODUCT_CONTEXT('',#1749,'mechanical');
 */
SdaiAppInstance getProductDefinitionProduct(SdaiModel AP210Model, SdaiAppInstance pd)
   {
   static SdaiEntity PD = sdaiGetEntity(AP210Model, "product_definition");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr PDR_ED = sdaiGetAttrDefinition(PDR, "related_product_definition");
   static SdaiAttr PDR_ING = sdaiGetAttrDefinition(PDR,"relating_product_definition");

   static SdaiAttr PP_F = sdaiGetAttrDefinitionBN(AP210,
                                 "packaged_part",
                                 "formation");
   static SdaiAttr PDF_O = sdaiGetAttrDefinitionBN(AP210,
                                 "product_definition_formation",
                                 "of_product");
   SdaiAppInstance obj = sdaiNULL; // scratch object
   SdaiAppInstance pdr; // product_definition_relationship 
   SdaiAppInstance pp;  // packaged_part 
   SdaiAppInstance pdf; // product_definition_formation 
   SdaiAppInstance p;   // product 

   if (sdaiIsKindOf(pd, PD)) {

      pdr = getNamedProductDefinitionRelationship(AP210Model, pd, "instantiated part", PDR_ED);

      if (pdr != sdaiNULL) {
         sdaiGetAttr(pdr, PDR_ING, sdaiINSTANCE, &pp);

         sdaiGetAttr(pp, PP_F, sdaiINSTANCE, &pdf);

         if (pdf != sdaiNULL) {
            sdaiGetAttr(pdf, PDF_O, sdaiINSTANCE, &p);
            }
         }
      }
   else {
      TRACE("ERROR: %s is not a product_definition\n",
              _sdaiGetPart21Description(pd));
      }
   if (p == sdaiNULL) {
      TRACE("ERROR: %s has no product\n",
              _sdaiGetPart21Description(pd));
      }
   return(p);
   }
/*
 * Function getProductDefinitionPhysicalUnit
 *
 * Given a product_definition return its physical_unit.
 *
 * Part21 Example:
 * #1660=COMPONENT_DEFINITION('','',#1397,#1736);
 * #1042=PRODUCT_DEFINITION_RELATIONSHIP('','instantiated part','',#1541,#1660);
 * #1541=PHYSICAL_UNIT('','',#1397,#1739);

#1579=PRODUCT_DEFINITION_SHAPE('','',#1541);

 */
SdaiAppInstance getProductDefinitionPhysicalUnit(SdaiModel AP210Model, SdaiAppInstance pd)
   {
   static SdaiEntity PD = sdaiGetEntity(AP210Model, "product_definition");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr PDR_ED = sdaiGetAttrDefinition(PDR, "related_product_definition");
   static SdaiAttr PDR_ING = sdaiGetAttrDefinition(PDR, "relating_product_definition");

   SdaiAppInstance pdr; // product_definition_relationship 
   SdaiAppInstance pp;  // packaged_part 

   if (sdaiIsKindOf(pd, PD)) {

      pdr = getNamedProductDefinitionRelationship(AP210Model, pd, "instantiated part", PDR_ED);

      if (pdr != sdaiNULL) {
         sdaiGetAttr(pdr, PDR_ING, sdaiINSTANCE, &pp);
         }
      }
   else {
      TRACE("ERROR: %s is not a product_definition\n",
              _sdaiGetPart21Description(pd));
      }
   if (pp == sdaiNULL) {
      TRACE("ERROR: %s has no packaged_part\n",
              _sdaiGetPart21Description(pd));
      }
   return(pp);
   }
double getPhysicalUnitsHeight(SdaiModel AP210Model, SdaiAppInstance p) {
   static SdaiAttr description = sdaiGetAttrDefinitionBN(AP210,
                                                         "property_definition",
                                                         "description");
   SdaiReal height = 0.0;
   SdaiReal temp = 0.0;
   SdaiAppInstance rep;
   SdaiAppInstance rep_item;
#ifdef VERBOSE
TRACE("In getPhysicalUnitsHeight()\r\n");
TRACE("p: 0x%08x\r\n", p);
TRACE("p: %s\r\n", _sdaiGetPart21Description(p));
#endif
   if (p != sdaiNULL) {
      // bad form to have an empty name.
      rep = getNamedRepresentation(AP210Model, p, "");
#ifdef VERBOSE
TRACE("representation: %s\r\n", _sdaiGetPart21Description(rep));
#endif
      if (rep != sdaiNULL) {
         rep_item = getNamedRepresentationItem(AP210Model, rep, "");
#ifdef VERBOSE
TRACE("representation_item: %s\r\n", _sdaiGetPart21Description(rep_item));
#endif
         // an empilot design, this is incorrect below.
         if (rep_item == sdaiNULL) {
            rep_item = getNamedRepresentationItem(AP210Model, rep, "component height");
#ifdef VERBOSE
TRACE("representation_item: %s\r\n", _sdaiGetPart21Description(rep_item));
#endif
            }
         if (rep_item != sdaiNULL) {
            height = getLengthMeasureWithUnit(AP210Model, rep_item);
            }
         }
      }
   if (height == 0.0) {
      TRACE0("WARNING: Physical Unit Height of 0.0\n");
      }
#ifdef VERBOSE
   else {
      TRACE("Package Height %f\r\n", height);
      }
#endif
      
   return height;
   }
void setPhysicalUnitsHeight(SdaiModel AP210Model, SdaiAppInstance p, double height) {
   static SdaiAttr description = sdaiGetAttrDefinitionBN(AP210,
                                                         "property_definition",
                                                         "description");
   SdaiReal temp = 0.0;
   SdaiAppInstance rep;
   SdaiAppInstance rep_item;

   if (p != sdaiNULL) {
      // bad form to have an empty name.
      rep = getNamedRepresentation(AP210Model, p, "");
#ifdef VERBOSE
TRACE("representation: %s\r\n", _sdaiGetPart21Description(rep));
#endif
      if (rep != sdaiNULL) {
         rep_item = getNamedRepresentationItem(AP210Model, rep, "component height");
#ifdef VERBOSE
TRACE("representation_item: %s\r\n", _sdaiGetPart21Description(rep_item));
#endif
         if (rep_item != sdaiNULL) {
            setLengthMeasureWithUnit(AP210Model, rep_item, height);
            }
         }
      }
   }
/*
 * getInterconnectModuleComponentDefintion()
 *
 * Given the "physical design usage" physical_unit for 
 * an interconnect module return its component_definition.
 *
 * Note: Assuming only one PDR with a description of "instantiated part"
 *       and it is for the interconnect modules component_definition.
 *       If this turns out to not be the case we can get a lost of PDRs
 *       and look for the description of "interconnect module" in the
 *       PDR_ED.
 *
 * Part21 Example:
 *  #956=PHYSICAL_UNIT('','interconnect module',#832,#1011);
 *  #631=PRODUCT_DEFINITION_RELATIONSHIP('','instantiated part','',#956,#617);
 *  #617=COMPONENT_DEFINITION('','interconnect module',#832,#1008);
 */
SdaiAppInstance getInterconnectModuleComponentDefinition(SdaiModel AP210Model, SdaiAppInstance pu) {
   static SdaiEntity PU = sdaiGetEntity(AP210Model, "physical_unit");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr PDR_ED = sdaiGetAttrDefinition(PDR, "related_product_definition");
   static SdaiAttr PDR_ING = sdaiGetAttrDefinition(PDR,"relating_product_definition");

   SdaiAppInstance cd = sdaiNULL;
   SdaiAppInstance pdr; // product_definition_relationship 

   if (sdaiIsInstanceOf(pu, PU)) {
      pdr = getNamedProductDefinitionRelationship(AP210Model, pu, "instantiated part", PDR_ING);
#ifdef VERBOSE
TRACE("pdr: %s\n", _sdaiGetPart21Description(pdr));
#endif
     if (pdr != sdaiNULL) {
        sdaiGetAttr(pdr, PDR_ED, sdaiINSTANCE, &cd);
        }
     }
   else {
      TRACE("ERROR: %s is not a physical_unit\n",
              _sdaiGetPart21Description(pu));
      }
   if (cd == sdaiNULL) {
      TRACE("ERROR: %s has no component_definition\n",
              _sdaiGetPart21Description(pu));
      }

   return cd;
   }
/*
 * getMountingRestrictionAreas()
 *
 * Given a component_definition for a interconnect_module
 * Return in the provided sdaiNPL a list of all the
 * mounting_restriction_areas.
 *
 * Part21 Example:
 *  #617=COMPONENT_DEFINITION('','interconnect module',#832,#1008);
 *  // Example 1
 *  #609=PRODUCT_DEFINITION_SHAPE('','',#617);
 *  #552=MOUNTING_RESTRICTION_AREA('','',#609,.F.);
 *  // Example 2
 *  #610=PRODUCT_DEFINITION_SHAPE('','',#617);
 *  #553=MOUNTING_RESTRICTION_AREA('','',#610,.F.);
 */
SdaiNPL getMountingRestrictionAreas(SdaiModel AP210Model, SdaiNPL resultList, SdaiAppInstance cd) {
   static SdaiEntity PDS = sdaiGetEntity(AP210Model, "product_definition_shape");
   static SdaiAttr PDS_DEF = sdaiGetAttrDefinition(PDS, "definition");

   static SdaiEntity MRA = sdaiGetEntity(AP210Model, "mounting_restriction_area");
   static SdaiAttr MRA_OS = sdaiGetAttrDefinition(MRA, "of_shape");

   SdaiIterator nplitor = sdaiCreateIterator(resultList);
   SdaiNPL domain = sdaiCreateNPL();
   SdaiInstance pds;   // product_definition_shape
   SdaiNPL pds_resultList = sdaiCreateNPL();
   SdaiIterator pds_itor;

#ifdef VERBOSE
TRACE("In getMountingRestrictionAreas\r\n");
#endif

   sdaiFindInstanceUsedIn(cd, PDS_DEF, domain, pds_resultList);

   if (sdaiGetMemberCount(pds_resultList) > 0) {
      pds_itor = sdaiCreateIterator(pds_resultList);

      while (sdaiNext(pds_itor)) {
         sdaiGetAggrByIterator(pds_itor, sdaiINSTANCE, &pds); 
#ifdef VERBOSE
TRACE("product_definition_shape: %s\r\n", _sdaiGetPart21Description(pds));
#endif
         _sdaiFindSubTypeInstanceUsedIn(pds, MRA, MRA_OS, resultList);
         }
      sdaiDeleteIterator(pds_itor);
      }
   sdaiDeleteNPL(pds_resultList);
   sdaiDeleteNPL(domain);

   sdaiDeleteIterator(nplitor);
   return resultList;
   }
/*
 * getNamedRepresentationRelationship()
 *
 * Part21 Example:
 *  #877=REPRESENTATION('component placement restriction assignment',(#964), #1015);
 *  #283=REPRESENTATION_RELATIONSHIP('','',#877,#885);
 *  #885=REPRESENTATION('maximum positive component height',(#300,#1000),#1015);
 */
SdaiAppInstance getNamedRepresentationRelationship(SdaiModel AP210Model, 
                                                   SdaiAppInstance obj,
                                                   SdaiAttr rr_rep,
                                                   char *name)
   {
   static SdaiEntity RR = sdaiGetEntity(AP210Model, "representation_relationship");
   static SdaiAttr RR_REP1 = sdaiGetAttrDefinition(RR, "rep_1");
   static SdaiAttr RR_REP2 = sdaiGetAttrDefinition(RR, "rep_2");

   static SdaiEntity REP = sdaiGetEntity(AP210Model, "representation");
   static SdaiAttr REP_NAME = sdaiGetAttrDefinition(REP, "name");

   SdaiIterator itor;
   SdaiString test;
   SdaiAppInstance rr = sdaiNULL;
   SdaiAppInstance rep1 = sdaiNULL;
   SdaiAppInstance rep2 = sdaiNULL;
   SdaiAppInstance rep = sdaiNULL;

   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL rr_rep1_resultList = sdaiCreateNPL();

#ifdef VERBOSE
   TRACE("In getNamedRepresentationRelationship()\r\n");
   TRACE("%s\n   %s\n", _sdaiGetPart21Description(obj), name);
#endif
   sdaiFindInstanceUsedIn(obj, RR_REP1, domain, rr_rep1_resultList);
#ifdef REALLYVERBOSE
      TRACE("rr_rep1_resultList: %d\n", sdaiGetMemberCount(rr_rep1_resultList));
#endif
   if (sdaiGetMemberCount(rr_rep1_resultList) > 0) {
      itor = sdaiCreateIterator(rr_rep1_resultList);

      while (sdaiNext(itor) && (rep == sdaiNULL)) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &rr); 
#ifdef REALLYVERBOSE
         TRACE("rr: %s\n", _sdaiGetPart21Description(rr));
#endif
         if (sdaiIsInstanceOf(rr, RR)) {
            sdaiGetAttr(rr, RR_REP2, sdaiINSTANCE, &rep2);
#ifdef REALLYVERBOSE
            TRACE("rep2: %s\n", _sdaiGetPart21Description(rep2));
#endif
            sdaiGetAttr(rep2, REP_NAME, sdaiSTRING, &test);
#ifdef REALLYVERBOSE
            TRACE("test name: %s, name: %s\n", test, name);
#endif
            if (!strcmp(test, name)) {
               rep = rep2;
#ifdef VERBOSE
               TRACE("Found It: %s\n", test);
               TRACE("rep: %s\n", _sdaiGetPart21Description(rep));
               TRACE("rr: %s\n", _sdaiGetPart21Description(rr));
#endif
               }
            }
         }
      sdaiDeleteIterator(itor);
      }

   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(rr_rep1_resultList);

#ifdef VERBOSE
   if (rep == sdaiNULL) {
      TRACE("WARNING: %s has no representation relationship\n",
                         _sdaiGetPart21Description(obj));
      TRACE("         with a %s of \"%s\"\n", "attributeName value", name);
      }
#endif
   return(rep);
   }