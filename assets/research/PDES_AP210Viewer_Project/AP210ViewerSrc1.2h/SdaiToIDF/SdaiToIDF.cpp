/*
 * $Id: sdaiidf.c,v 1.7 1998/03/03 22:25:12 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

#include "sdai.h"
#include "../IOAP210.h"
#include "IDF.h"

int WriteIDF(SdaiModel myModel, char *dir, char *name)    {
   FILE *bfp, *lfp;
   SdaiAggr all_objects;
   SdaiAppInstance obj;
   SdaiInstance board_data;
   SdaiInstance library_data;
   SdaiIterator itor;
   char *boardfile;
   char *libraryfile;

   /* set the model format to output a STEP Part21 file */
   _sdaiSetModelFormat(myModel, "step");

   /* get a list of all instances */
   sdaiGetAttrBN ((SdaiAppInstance) myModel, "contents", 
		       sdaiINSTANCE, &obj);

   sdaiGetAttrBN (obj, "instances", sdaiAGGR, &all_objects);
	
   /* Print IDF board and library files */
   itor = sdaiCreateIterator (all_objects);

   while (sdaiNext(itor))
      {
      sdaiGetAggrByIterator (itor, sdaiINSTANCE, &obj);

      if (sdaiIsInstanceOfBN (obj, "idf_data"))
         {
         /* Print the IDF Board File */
         if (sdaiTestAttrBN(obj, "board_file") == sdaiTRUE) {
         sdaiGetAttrBN(obj, "board_file", sdaiINSTANCE, &board_data);
         boardfile = (char *)calloc(1, strlen(dir)+strlen(name)+strlen(IDFBRDEXT)+3);
         strcpy(boardfile, dir);
         strcat(boardfile, "\\");
         strcat(boardfile, name);
         strcat(boardfile, ".");
         strcat(boardfile, IDFBRDEXT);
         bfp = fopen(boardfile, "w");
         PrintIDFBoardFile(bfp, board_data);
         fclose(bfp);
         free(boardfile);
            }
         else {
            fprintf(stderr, "WARNING: %s.stp contains no Board data.\n", name);
            }
         /* Print the IDF Library File */
         if (sdaiTestAttrBN(obj, "library_file") == sdaiTRUE) {
            sdaiGetAttrBN(obj, "library_file", sdaiINSTANCE, &library_data);
           
            libraryfile = (char *)calloc(1, strlen(dir)+strlen(name)+strlen(IDFLIBEXT)+3);
            strcpy(libraryfile, dir);
            strcat(libraryfile, "\\");
            strcat(libraryfile, name);
            strcat(libraryfile, ".");
            strcat(libraryfile, IDFLIBEXT);
            lfp = fopen(libraryfile, "w");
            PrintIDFLibraryFile(lfp, library_data);   
            fclose(lfp);
            free(libraryfile);
            }
         else {
            fprintf(stderr, "WARNING: %s.stp contains no Library data.\n", name);
            }
         }
      }
   return(0);
   }
