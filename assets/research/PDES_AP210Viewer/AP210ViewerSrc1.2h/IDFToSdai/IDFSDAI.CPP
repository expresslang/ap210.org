/*
 * $Id: idfsdai.c,v 1.10 1998/10/23 20:17:43 keenan Exp $
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <stdio.h>

#include "rose.h"
#include "sdai.h"

/* These variables are global because the are needed
 * in the grammer and the lexical analyser.
 */
extern int yydebug;
int yyparse (void);
extern char *current_file;
extern char *second_file;

/* input file for lexical analyser created by flex. */
extern FILE *yyin;
/*
 * myModel is defined externally because 
 * it is referenced in the Bison grammer.
 */
SdaiModel myModel;
char *OriginatingSystem;

int parseIDF(char *designname, SdaiModel IDFModel)
   {
   RoseDesign *design;
   char *first_file;

   /* enable parser debugging */
//    yydebug = 1;
   /* create a new model */
   myModel = IDFModel;

   sdaiAccessModel (myModel, sdaiRW);
   if(sdaiErrorQuery())  {
      TRACE("Cannot access model\n");
      return(1);
      }
   _sdaiSetModelFormat(myModel, "step");

   /* Parse IDF file */
   first_file = (char *)calloc(1, strlen(designname)+5);
   strcpy(first_file, designname);
   strcat(first_file, ".brd");
TRACE("first_file: %s\n", first_file);
   second_file = (char *)calloc(1, strlen(designname)+5);
   strcpy(second_file, designname);
   strcat(second_file, ".lib");
TRACE("second_file: %s\n", second_file);

   current_file = first_file;
   if ((yyin = fopen(current_file, "r")) == NULL)
      { 
      TRACE("ERROR: Can't open %s.\n", current_file);
      return(1);
      }

   TRACE("Parsing.\n");
   if (yyparse() == 0)
      {
      TRACE("Parsing complete.\n");

      /* Get the Rose Design object */
      design = _sdaiGetRoseDesign(myModel);

      /* build header */
      design->initialize_header();

      /* add file description information */
      design->header_description()->description()->add("IDF Part 21 file");
       
      /* add file name information */
      design->header_name()->author()->add("Software: Michael T. Keenan");
      design->header_name()->organization()->add("The Boeing Company");

      design->header_name()->author()->add("Data Schema: Brad L. Kicklighter");
      design->header_name()->organization()->add("Delphi Delco Electronics Systems");

      design->header_name()->organization()->add("PDES Inc. EMPilot");
      design->header_name()->originating_system("idfsdai 1.1");
#if 0
      /* save step  */
      sdaiSaveChanges (myModel);
      TRACE("Step file saved.\n");
#endif
      }
   /* return cleanly */
   free(first_file);
   free(second_file);
   fclose(yyin);
   free(OriginatingSystem);
   return(0);
   }
