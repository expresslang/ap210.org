%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "map_tab.h"

int linecount = 1;
char *current_file;
char *second_file;

char *StripQuotes(char *str);
/*
ALPHANUM [/\-_\.0-9a-zA-Z]
*/
%}
ALPHANUM [^ \n\t]
ALPHA [0-9a-zA-Z]
NUM [0-9]

%%
^#.+\n        {linecount++;}
MM            {yylval.SdaiEnumeration = (char *)strdup(yytext);return(MM);}
TNM           {yylval.SdaiEnumeration = (char *)strdup(yytext);return(TNM);}
THOU          {yylval.SdaiEnumeration = (char *)strdup(yytext);return(THOU);}
TOP           {yylval.SdaiEnumeration = (char *)strdup(yytext);return(TOP);}
BOTTOM        {yylval.SdaiEnumeration = (char *)strdup(yytext);return(BOTTOM);}
BOTH          {yylval.SdaiEnumeration = (char *)strdup(yytext);return(BOTH);}
ALL           {yylval.SdaiEnumeration = (char *)strdup(yytext);return(ALL);}
PTH           {yylval.SdaiEnumeration = (char *)strdup(yytext);return(PTH);}
NPTH          {yylval.SdaiEnumeration = (char *)strdup(yytext);return(NPTH);}
BOARD         {yylval.SdaiEnumeration = (char *)strdup(yytext);return(BOARD);}
NOREFDES      {yylval.SdaiEnumeration = (char *)strdup(yytext);return(NOREFDES);}
FIXED         {yylval.SdaiEnumeration = (char *)strdup("PLACEMENT_FIXED");return(FIXED);}
UNPLACED      {yylval.SdaiEnumeration = (char *)strdup(yytext);return(UNPLACED);}
PLACED        {yylval.SdaiEnumeration = (char *)strdup(yytext);return(PLACED);}

".HEADER"       {return(START_HEADER);}    
".END_HEADER"   {return(END_HEADER);}    

BOARD_FILE    {return(BOARD_FILE);}

".BOARD_OUTLINE" {return(START_BOARD_OUTLINE);}    
".END_BOARD_OUTLINE" {return(END_BOARD_OUTLINE);}    

".OTHER_OUTLINE" {return(START_OTHER_OUTLINE);}    
".END_OTHER_OUTLINE" {return(END_OTHER_OUTLINE);}    

".ROUTE_OUTLINE" {return(START_ROUTE_OUTLINE);}    
".END_ROUTE_OUTLINE" {return(END_ROUTE_OUTLINE);}    

".PLACE_OUTLINE" {return(START_PLACE_OUTLINE);}    
".END_PLACE_OUTLINE" {return(END_PLACE_OUTLINE);}    

".ROUTE_KEEPOUT" {return(START_ROUTE_KEEPOUT);}    
".END_ROUTE_KEEPOUT" {return(END_ROUTE_KEEPOUT);}    

".VIA_KEEPOUT" {return(START_VIA_KEEPOUT);}    
".END_VIA_KEEPOUT" {return(END_VIA_KEEPOUT);}    

".PLACE_REGION" {return(START_PLACE_REGION);}    
".END_PLACE_REGION" {return(END_PLACE_REGION);}    

".PLACE_KEEPOUT" {return(START_PLACE_KEEPOUT);}    
".END_PLACE_KEEPOUT" {return(END_PLACE_KEEPOUT);}    

".DRILLED_HOLES" {return(START_DRILLED_HOLES);}    
".END_DRILLED_HOLES" {return(END_DRILLED_HOLES);}    

".PLACEMENT" {return(START_PLACEMENT);}    
".END_PLACEMENT" {return(END_PLACEMENT);}    

LIBRARY_FILE       {return(LIBRARY_FILE);}

".ELECTRICAL"      {return(START_ELECTRICAL);}    
".END_ELECTRICAL"  {return(END_ELECTRICAL);}    

".MECHANICAL"      {return(START_MECHANICAL);}    
".END_MECHANICAL"  {return(END_MECHANICAL);}    

-{NUM}+"."{NUM}+   {yylval.SdaiString = strdup(yytext);return(RAWREAL);}
{NUM}+"."{NUM}+    {yylval.SdaiString = strdup(yytext);return(RAWREAL);}
-{NUM}+            {yylval.SdaiString = strdup(yytext);return(RAWINTEGER);}
{NUM}+             {yylval.SdaiString = strdup(yytext);return(RAWINTEGER);}

\"\"               {yylval.SdaiString = "";return(STRING);}
\"[^"]+\"          {yylval.SdaiString = StripQuotes(yytext);return(STRING);}
{ALPHA}{ALPHANUM}+ {yylval.SdaiString = (char *)strdup(yytext);return(STRING);}

"/"                {return(*yytext);}
"."                {return(*yytext);}
":"                {return(*yytext);}
\n                 {linecount++;}
.	             {/* printf("Missed: '%s': %d on line %d.\n", yytext, *yytext,linecount);*/}
%%

char *StripQuotes(char *str)
   {
   char *result;

   /* remove quotes */
   result = (char *)strdup(&str[1]);
   result[strlen(result)-1] = '\0';

   return(result);
   }

int yywrap()
   {
   static FILE *temp = NULL;

   /* this prevents an infinite loop */
   if (temp == yyin)
      {
      return 1;
      }
   /* load the library file */
   if ((temp = fopen(second_file, "r")) == NULL)
      { 
      fprintf(stderr, "ERROR: Can't open %s.\n", second_file);
      return 1;
      }
   current_file = second_file;
   fclose(yyin);
   yyin = temp;
   linecount = 1;
   return 0;
   }
/* provide a yyerror that gives the line number of the error. */
void yyerror(char *error)
   {
   int count = 1;
   char c;
   fputs(error, stderr);
   fprintf(stderr, " near line %d of %s\n", linecount, current_file);
   rewind(yyin);

   while(count <= linecount+1)
      {
      c = fgetc(yyin);
      if (count >= linecount-1 && count <= linecount)
         {
         fputc(c, stderr);
         }
      if (c == '\n')
         {
         count++;

         if (count >= linecount-1 && count <= linecount)
            {
            fprintf(stderr, "%d: ", count);
            }
         }
      }
   }
