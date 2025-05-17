/*
 * $Id: SdaiUtility.cpp,v 1.4 1999/08/22 05:26:06 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <rose.h>
#include <sdai.h>

#include "AP210SdaiModel.h"
#include "SdaiUtility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static char buf[1024]; // a SdaiString 
static char buf2[1024]; // a SdaiString 

const char *_sdaiGetPart21Description(SdaiAppInstance obj)
   {
   if (obj != sdaiNULL) {
      sprintf(buf2, "#%ld a %s",
              _sdaiGetPart21Id(obj),
              sdaiGetDescription(obj, buf));
      }
   else {
      strcpy(buf2, "sdaiNULL");
      }
   return(buf2);
   }

unsigned long _sdaiGetPart21Id(SdaiAppInstance obj) {
  unsigned long result;
  RoseStructure *structure;

  structure = _sdaiGetRoseStructure(obj);
  result =  structure->entity_id();

  return result;
}

void _sdaiDisplayNPL(SdaiNPL npl)
   {
   SdaiAppInstance obj;
   SdaiIterator itor = sdaiCreateIterator(npl);
   
   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &obj);

      _sdaiDisplay(obj);
      }
   sdaiDeleteIterator(itor);
   }
SdaiNPL _sdaiInstanceAttributeValueQuery(SdaiNPL inputList,
                                         SdaiAttr attribute,   
                                         SdaiPrimitiveType valueType,
                                         void *value,
                                         SdaiNPL resultList)
   {
   void *objvalue;
   SdaiAppInstance obj;
   SdaiIterator itor = sdaiCreateIterator(inputList);
   SdaiIterator nplitor = sdaiCreateIterator(resultList);
#ifdef VERBOSE
TRACE("In _sdaiInstanceAttributeValueQuery(\"%s\")\r\n", value);
#endif

   while(sdaiNext(itor)) {
       
      if (sdaiGetAggrByIterator(itor, sdaiINSTANCE, &obj) != sdaiNULL) {
    
         if (sdaiGetAttr(obj, attribute, valueType, &objvalue) != sdaiNULL) {
            // Making the major assumption that the valueType is sdaiSTRING
            // Need to write or find a compare function that is type aware.
#ifdef VERBOSE
TRACE("\r\nent: %s\r\n", _sdaiGetPart21Description(obj));
TRACE("String: %s\r\n", (SdaiString)objvalue);
#endif
            if (!strcmp((SdaiString)value, (SdaiString)objvalue)) {
               sdaiEnd(nplitor);
               sdaiInsertBefore(nplitor, sdaiINSTANCE, obj);
               } 
            }
         }
      }
   sdaiDeleteIterator(itor);
   sdaiDeleteIterator(nplitor);
   return(resultList);
   }
/*
 * _sdaiFindSubTypeInstanceUsedIn
 * 
 * Return a single instance that uses the given
 * object in the given entity and role, even if the role
 * is defined in a super type. If more than one instance
 * uses it return sdaiNULL and issue an error message.
 */
SdaiAppInstance _sdaiFindSingleSubTypeInstanceUsedIn(SdaiAppInstance obj,
                                                     SdaiEntity entity,
                                                     SdaiAttr role)
   {
   SdaiInteger count;
   SdaiIterator itor;
   SdaiAppInstance inst;
   SdaiAppInstance result = sdaiNULL;
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL rawresultList = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();
   SdaiIterator nplitor = sdaiCreateIterator(resultList);
#ifdef VERBOSE
TRACE0("In _sdaiFindSingleSubTypeInstanceUsedIn()\r\n");
TRACE("obj: %s\r\n", _sdaiGetPart21Description(obj));
#endif
   // Get entities in which obj is used in the defined role.
   sdaiFindInstanceUsedIn(obj, role, domain, rawresultList);
   if (sdaiGetMemberCount(rawresultList) > 0) {
#ifdef VERBOSE
TRACE("%d instance in rawresultList\r\n", sdaiGetMemberCount(rawresultList));
#endif

      // filter the result list for the entity, seems like a lot of work
      itor = sdaiCreateIterator(rawresultList);

      while(sdaiNext(itor)) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &inst); 
#ifdef VERBOSE
TRACE("inst: %s\r\n", _sdaiGetPart21Description(inst));
#endif

         if (sdaiIsInstanceOf(inst, entity)) {
#ifdef VERBOSE
TRACE0("Insert\r\n");
#endif
            sdaiEnd(nplitor);
            sdaiInsertBefore(nplitor, sdaiINSTANCE, inst);
            }
         }
      sdaiDeleteIterator(itor);
#ifdef VERBOSE
TRACE("Count: %d\r\n", sdaiGetMemberCount(resultList));
#endif
    
      if ((count = sdaiGetMemberCount(resultList)) == 1) {
         itor = sdaiCreateIterator(resultList);
         sdaiNext(itor);
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &result); 
         sdaiDeleteIterator(itor);
         }  
      else if (count == 0) {
         TRACE("ERROR: %s not used in %s.%s\r\n",
               _sdaiGetPart21Description(obj),
               "entityName", "attributeName"); 
         }
      else if (count > 1) {
         TRACE("ERROR: %s in more than one %s.%s\r\n",
               _sdaiGetPart21Description(obj),
               "entityName", "attributeName"); 
         }
      }
   else {
      TRACE("WARNING: %s not USEDIN this role!\r\n", _sdaiGetPart21Description(obj)); 
      }
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(rawresultList);
   sdaiDeleteNPL(resultList);
   sdaiDeleteIterator(nplitor);
#ifdef VERBOSE
TRACE("result: %s\r\n", _sdaiGetPart21Description(result));
#endif
   return(result);
   }
/*
 * _sdaiFindSingleSubTypeKindOfUsedIn
 *
 *
 * Not a good name, this could replace the function above.
 *
 * Return a single instance that uses the given
 * object in the given entity and role, even if the role
 * is defined in a super type. If more than one instance
 * uses it return sdaiNULL and issue an error message.
 */
#define VERBOSE
SdaiAppInstance _sdaiFindSingleSubTypeKindOfUsedIn(SdaiAppInstance obj,
                                                   SdaiEntity entity,
                                                   SdaiAttr role)
   {
   SdaiInteger count;
   SdaiIterator itor;
   SdaiAppInstance inst;
   SdaiAppInstance result = sdaiNULL;
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL rawresultList = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();
   SdaiIterator nplitor = sdaiCreateIterator(resultList);
#ifdef VERBOSE
TRACE0("In _sdaiFindSingleSubTypeInstanceUsedIn()\r\n");
TRACE("obj: %s\r\n", _sdaiGetPart21Description(obj));
#endif
   // Get entities in which obj is used in the defined role.
   sdaiFindInstanceUsedIn(obj, role, domain, rawresultList);
   if (sdaiGetMemberCount(rawresultList) > 0) {
#ifdef VERBOSE
TRACE("%d instance in rawresultList\r\n", sdaiGetMemberCount(rawresultList));
#endif

      // filter the result list for the entity, seems like a lot of work
      itor = sdaiCreateIterator(rawresultList);

      while(sdaiNext(itor)) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &inst); 
#ifdef VERBOSE
TRACE("inst: %s\r\n", _sdaiGetPart21Description(inst));
#endif

         if (sdaiIsKindOf(inst, entity)) {
#ifdef VERBOSE
TRACE0("Insert\r\n");
#endif
            sdaiEnd(nplitor);
            sdaiInsertBefore(nplitor, sdaiINSTANCE, inst);
            }
         }
      sdaiDeleteIterator(itor);
#ifdef VERBOSE
TRACE("Count: %d\r\n", sdaiGetMemberCount(resultList));
#endif
    
      if ((count = sdaiGetMemberCount(resultList)) == 1) {
         itor = sdaiCreateIterator(resultList);
         sdaiNext(itor);
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &result); 
         sdaiDeleteIterator(itor);
         }  
      else if (count == 0) {
         TRACE("ERROR: %s not used in %s.%s\r\n",
               _sdaiGetPart21Description(obj),
               "entityName", "attributeName"); 
         }
      else if (count > 1) {
         TRACE("ERROR: %s in more than one %s.%s\r\n",
               _sdaiGetPart21Description(obj),
               "entityName", "attributeName"); 
         }
      }
   else {
      TRACE("WARNING: %s not USEDIN this role!\r\n", _sdaiGetPart21Description(obj)); 
      }
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(rawresultList);
   sdaiDeleteNPL(resultList);
   sdaiDeleteIterator(nplitor);
#ifdef VERBOSE
TRACE("result: %s\r\n", _sdaiGetPart21Description(result));
#endif
   return(result);
   }
#undef VERBOSE
/*
 * _sdaiFindSubTypeInstanceUsedIn
 * 
 * Return a list of the instances that use the given
 * object in the given entity and role, even if the role
 * is defined in a super type.
 *
 * Note this could be optimized by check to see if the
 * role is defined in the given entity then the rawresultList
 * could be return.
 */
SdaiNPL _sdaiFindSubTypeInstanceUsedIn(SdaiAppInstance obj,
                                       SdaiEntity entity,
                                       SdaiAttr role,
                                       SdaiNPL resultList)
   {
   SdaiIterator itor;
   SdaiAppInstance inst;
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL rawresultList = sdaiCreateNPL();
   SdaiIterator nplitor = sdaiCreateIterator(resultList);
#ifdef VERBOSE
TRACE0("In _sdaiFindSingleSubTypeInstanceUsedIn()\r\n");
TRACE("obj: %s\r\n", _sdaiGetPart21Description(obj));
#endif
   // Get entities in which obj is used in the defined role.
   sdaiFindInstanceUsedIn(obj, role, domain, rawresultList);

   if (sdaiGetMemberCount(rawresultList) > 0) {
#ifdef VERBOSE
TRACE("%d instance in rawresultList\r\n", sdaiGetMemberCount(rawresultList));
#endif
      // filter the result list for the entity, seems like a lot of work
      itor = sdaiCreateIterator(rawresultList);

      while(sdaiNext(itor)) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &inst); 
#ifdef VERBOSE
TRACE("inst: %s\r\n", _sdaiGetPart21Description(inst));
#endif

         if (sdaiIsInstanceOf(inst, entity)) {
#ifdef VERBOSE
TRACE0("Insert\r\n");
#endif
            sdaiEnd(nplitor);
            sdaiInsertBefore(nplitor, sdaiINSTANCE, inst);
            }
         }
      sdaiDeleteIterator(itor);
      }
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(rawresultList);
   sdaiDeleteIterator(nplitor);

   return(resultList);
   }
/*
 * _sdaiGetStringAttrWithQuotesBN()
 *
 *  Adds quotes as nessesary.
 * 
 */
SdaiString _sdaiGetStringAttrWithQuotesBN(SdaiInstance instance, 
                                          SdaiString attributeName, 
                                          SdaiString *value
                                          ) {
	SdaiString s;
	SdaiString getvalue;

	sdaiGetAttrBN(instance, attributeName, sdaiSTRING, &getvalue);
    
	*value = (char *)calloc(1, strlen(getvalue)+3);
	strcpy(*value, getvalue);
	s = getvalue;

        /* make null sting */
        if (*s == '\0') {
           strcpy(*value, "\"\"");
           }
        else {

	/* look for a space in the string */
    while (*s != '\0')
	{
		if (*s == ' ')
		{
			/* add quotes */
            sprintf(*value, "\"%s\"", getvalue);
			break;
		}
		s++;
	   }
	}
	return(*value);
}
