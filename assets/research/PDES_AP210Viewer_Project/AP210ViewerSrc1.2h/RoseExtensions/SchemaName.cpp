#include "stdafx.h"

#include <rose.h>
#include <RoseP21Parser.h>

#include "SchemaName.h"

//typedef RoseErrorCode (*RoseP21AddSchemaFn) (
//        RoseDesign * design, char * name);
    
RoseErrorCode my_add_schema_fn(
RoseDesign * design, char * schemaname) {
char *suffix;
   RoseErrorCode result = ROSE_GENERAL;
#ifdef VERBOSE
TRACE("In add_schema_fn %s\r\n", schemaname);
#endif
   if ((suffix = strrchr(schemaname, '{')) != NULL) {
      *suffix = '\0';
      }
   design->addSchema(schemaname);
   result = ROSE_OK;
#ifdef VERBOSE
TRACE("In add_schema_fn %s\r\n", schemaname);
#endif
   return result;
   }
void set_schema_fn() {
RoseP21Parser::add_schema_fn = my_add_schema_fn;
}