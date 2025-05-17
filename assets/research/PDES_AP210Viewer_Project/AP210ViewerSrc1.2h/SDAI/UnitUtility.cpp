/*
 * $Id: UnitUtility.cpp,v 1.2 1999/07/17 19:00:22 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"
// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdio.h>
#include <string.h>
#include <sdai.h>

#include "SIUnits.h"
#include "SdaiUtility.h"
#include "UnitUtility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

double getPrefixConversionFactor(char *prefix);

/* 
 * Given a conversion_based_unit or si_unit return a conversion factor to 
 * convert to inches.
 *
 * From the input information the conversion to meters can be made
 * this is then converted to inches.
 *
 * This routine handles the both of the following conditions:
 *   A conversion based unit
 *   #1317=(CONVERSION_BASED_UNIT('INCH',#1313)LENGTH_UNIT()NAMED_UNIT(#1312));
 *   #1313=LENGTH_MEASURE_WITH_UNIT(LENGTH_MEASURE(2.540000),#1311);
 *   #1311=(LENGTH_UNIT()NAMED_UNIT(*)SI_UNIT(.CENTI.,.METRE.));
 *
 *   An SI based unit
 *   #46006=(LENGTH_UNIT()NAMED_UNIT(*)SI_UNIT(.MILLI.,.METRE.));
 */
double getUnitConversionFactor(SdaiModel AP210Model, SdaiAppInstance unit, double *factor) {
   static SdaiEntity CBU = sdaiGetEntity(AP210Model, "conversion_based_unit");
   static SdaiAttr CBU_NM = sdaiGetAttrDefinition(CBU, "name");
   static SdaiAttr CBU_CF = sdaiGetAttrDefinition(CBU, "conversion_factor");

   static SdaiEntity MWU = sdaiGetEntity(AP210Model, "measure_with_unit");
   static SdaiAttr MWU_VC = sdaiGetAttrDefinition(MWU, "value_component");
   static SdaiAttr MWU_UC = sdaiGetAttrDefinition(MWU, "unit_component");

   static SdaiEntity SU = sdaiGetEntity(AP210Model, "si_unit");
   static SdaiAttr SU_P = sdaiGetAttrDefinition(SU, "prefix");
   static SdaiAttr SU_NM = sdaiGetAttrDefinition(SU, "name");

   SdaiEnum sinm;
   SdaiEnum pre;

   SdaiString nm;
   SdaiAppInstance cf;
   SdaiAppInstance uc = sdaiNULL;
   if (unit != sdaiNULL) {
      if (sdaiIsKindOf(unit, CBU)) {
         sdaiGetAttr(unit, CBU_NM, sdaiSTRING, &nm);
         sdaiGetAttr(unit, CBU_CF, sdaiINSTANCE, &cf);

         if (cf != sdaiNULL) {
            // get the factor specifed for the specified prefix and the si unit metre
            sdaiGetAttr(cf, MWU_VC, sdaiREAL, factor);
            sdaiGetAttr(cf, MWU_UC, sdaiINSTANCE, &uc);
            }
         }
      else if (sdaiIsKindOf(unit, SU)) {
         uc = unit;
         *factor = 1.0;
         }
      else {
         TRACE("ERROR: Unexpected unit type %s\r\n", _sdaiGetPart21Description(unit));
         }
      if (uc != sdaiNULL) {
         sdaiGetAttr(uc, SU_P, sdaiENUM, &pre);
         sdaiGetAttr(uc, SU_NM, sdaiENUM, &sinm);
         if (strcmp(sinm, "metre")) {
            TRACE("ERROR: Unexpected SI length unit of '%s' expected 'metre'\n", sinm);
            }
         // get the conversion factor for the specified prefix 
         // and apply it to the metre value. 
         *factor = *factor * getPrefixConversionFactor(pre);
         }
      else {
         TRACE("ERROR no unit found %s\n", _sdaiGetPart21Description(unit));
	      }
      }
   else {
      TRACE("ERROR no unit defined\r\n");
      }
   // Convert meters to inches.
   *factor = *factor * 39.370;

   // A value of zero for the factor is unrealistic make it one.
   if (*factor == 0.0) {
      *factor = 1.0;
      }
   return *factor;
   }
double getPrefixConversionFactor(char *prefix) {
   double factor = 1.0;

   // An attempt has been made to order these such that the 
   // most frequent appear first.

   if (!strcmp(prefix, "centi")) {
      factor = 1.0E-2;
      } 
   else if (!strcmp(prefix, "nano")) {
      factor = 1.0E-9;
      } 
   else if (!strcmp(prefix, "milli")) {
      factor = 1.0E-3;
      } 
   else if (!strcmp(prefix, "kilo")) {
      factor = 1.0E3;
      } 
   else if (!strcmp(prefix, "exa")) {
      factor = 1.0E18;
      } 
   else if (!strcmp(prefix, "peta")) {
      factor = 1.0E15;
      } 
   else if (!strcmp(prefix, "tera")) {
      factor = 1.0E12;
      } 
   else if (!strcmp(prefix, "giga")) {
      factor = 1.0E9;
      } 
   else if (!strcmp(prefix, "mega")) {
      factor = 1.0E6;
      } 
   else if (!strcmp(prefix, "hecto")) {
      factor = 1.0E2;
      } 
   else if (!strcmp(prefix, "deka")) {
      factor = 10.0;
      } 
   else if (!strcmp(prefix, "deci")) {
      factor = 1.0E-1;
      } 
   else if (!strcmp(prefix, "micro")) {
      factor = 1.0E-6;
      } 
   else if (!strcmp(prefix, "pico")) {
      factor = 1.0E-12;
      } 
   else if (!strcmp(prefix, "femto")) {
      factor = 1.0E-15;
      } 
   else if (!strcmp(prefix, "atto")) {
      factor = 1.0E-18;
      } 
   else {
      TRACE("ERROR: Unknown Unit Prefix '%s'\n", prefix);
      } 
#ifdef VERBOSE
TRACE("prefix: %s, factor: %f\r\n", prefix, factor);
#endif
   return factor;
   }

