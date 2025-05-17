// IDFToSdai.cpp: implementation of the IDFToSdai class.
//
////////////////////////////////////
#define MTKFIX

#include "stdafx.h"
#include "IDFToSdai.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// Static Variable Declarations
int IDFToSdai::yyleng;
char * IDFToSdai::yytext;
FILE * IDFToSdai::yyout;
int IDFToSdai::yychar;
int IDFToSdai::yynerrs;
int IDFToSdai::yydebug;
char * IDFToSdai::OriginatingSystem;
FILE * IDFToSdai::yyin;
char * IDFToSdai::second_file;
char * IDFToSdai::current_file;
SdaiModel IDFToSdai::myModel;

////////////////////////////////////
// Construction/Destruction
////////////////////////////////////

IDFToSdai::IDFToSdai()
{

}

IDFToSdai::~IDFToSdai()
{

}

int IDFToSdai::parseIDF(char * designname, SdaiModel IDFModel)
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
// All the stuff below is from map.cpp, it should be 
// replaced with code automagically transformed from
// the bison output.


/*  A Bison parser, made from map.y
 by  GNU Bison version 1.25
  */
#define YYBISON 1  /* Identify Bison output.  */

#define	STRING	258
#define	RAWREAL	259
#define	RAWINTEGER	260
#define	START_HEADER	261
#define	END_HEADER	262
#define	BOARD_FILE	263
#define	MM	264
#define	TNM	265
#define	THOU	266
#define	TOP	267
#define	BOTTOM	268
#define	BOTH	269
#define	ALL	270
#define	PTH	271
#define	NPTH	272
#define	BOARD	273
#define	NOREFDES	274
#define	FIXED	275
#define	UNPLACED	276
#define	PLACED	277
#define	START_BOARD_OUTLINE	278
#define	END_BOARD_OUTLINE	279
#define	START_OTHER_OUTLINE	280
#define	END_OTHER_OUTLINE	281
#define	START_ROUTE_OUTLINE	282
#define	END_ROUTE_OUTLINE	283
#define	START_PLACE_OUTLINE	284
#define	END_PLACE_OUTLINE	285
#define	START_ROUTE_KEEPOUT	286
#define	END_ROUTE_KEEPOUT	287
#define	START_VIA_KEEPOUT	288
#define	END_VIA_KEEPOUT	289
#define	START_PLACE_KEEPOUT	290
#define	END_PLACE_KEEPOUT	291
#define	START_PLACE_REGION	292
#define	END_PLACE_REGION	293
#define	START_DRILLED_HOLES	294
#define	END_DRILLED_HOLES	295
#define	START_PLACEMENT	296
#define	END_PLACEMENT	297
#define	LIBRARY_FILE	298
#define	START_ELECTRICAL	299
#define	END_ELECTRICAL	300
#define	START_MECHANICAL	301
#define	END_MECHANICAL	302

#define YYSTYPE IDFYYSTYPE

//#line 4 "map.y"
typedef union
{
char charval;
char *SdaiString;
char *SdaiEnumeration;
double SdaiReal;
int SdaiInteger;
struct Sdai_Id* SdaiInstance;
struct InstanceList *List;
struct OutlineAndCutouts *OutlineAndCutouts;
} YYSTYPE;
//#line 16 "map.y"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/* This is useful for a developer but confusing for a end user.
#define YYERROR_VERBOSE
*/
#include <sdai.h>

extern SdaiModel myModel;
extern char *OriginatingSystem;

#ifdef MTKFIX
void yyerror(char *error);
#endif
int yylex (void );

struct InstanceList
   {
   SdaiInstance instance;
   struct InstanceList *next;
   };
struct OutlineAndCutouts
   {
   int current_loop_label;
   SdaiInstance current_loop;
   SdaiInstance outline;
   struct InstanceList *cutouts;
   };

#define alloca
void MTKsdaiInsertAfterBN(SdaiInstance instance,
                          char *attribute_name,
                          SdaiPrimitiveType type,
                          SdaiInstance attribute);


#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		164
#define	YYFLAG		-32768
#define	YYNTBASE	51

#define YYTRANSLATE(x) ((unsigned)(x) <= 302 ? yytranslate[x] : 94)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,    44,    43,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    46,    47,    48,
    49,    50
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     7,    10,    12,    15,    18,    21,    24,
    27,    30,    33,    36,    39,    42,    52,    54,    56,    58,
    60,    62,    64,    66,    68,    70,    72,    74,    76,    78,
    80,    82,    84,    86,    88,    90,    92,    94,    96,    98,
   103,   105,   111,   113,   117,   121,   126,   128,   130,   132,
   134,   138,   144,   146,   148,   150,   157,   159,   161,   164,
   168,   170,   174,   176,   178,   181,   184,   187,   193,   195,
   197,   199,   201,   203,   206,   209,   212,   215,   224,   232,
   234,   236,   238,   240,   242,   244,   246,   248,   251,   254,
   262,   270,   278,   280,   282
};

static const short yyrhs[] = {    52,
     0,    51,    52,     0,    87,     0,    51,    87,     0,    53,
     0,    52,    61,     0,    52,    63,     0,    52,    65,     0,
    52,    66,     0,    52,    67,     0,    52,    69,     0,    52,
    72,     0,    52,    70,     0,    52,    78,     0,    52,    82,
     0,     6,     8,    54,    55,    56,    57,    58,    60,     7,
     0,     4,     0,    59,     0,     3,     0,    92,     0,    59,
     0,     3,     0,     9,     0,    10,     0,    11,     0,    12,
     0,    13,     0,    14,     0,    15,     0,    16,     0,    17,
     0,    18,     0,    19,     0,    20,     0,    21,     0,    22,
     0,     9,     0,    10,     0,    11,     0,    23,    62,    74,
    24,     0,    93,     0,    25,    59,    64,    74,    26,     0,
    93,     0,    27,    74,    28,     0,    29,    74,    30,     0,
    31,    68,    74,    32,     0,    12,     0,    13,     0,    14,
     0,    15,     0,    33,    74,    34,     0,    37,    71,    59,
    74,    38,     0,    12,     0,    13,     0,    14,     0,    35,
    71,    73,    73,    74,    36,     0,    93,     0,    92,     0,
    75,    76,     0,    74,    75,    76,     0,    92,     0,    93,
    93,    77,     0,    93,     0,    92,     0,    39,    79,     0,
    78,    79,     0,    78,    40,     0,    93,    93,    93,    80,
    81,     0,    16,     0,    17,     0,    18,     0,    19,     0,
    59,     0,    41,    83,     0,    41,    42,     0,    82,    83,
     0,    82,    42,     0,    59,    59,    84,    93,    93,    93,
    85,    86,     0,    59,    59,    84,    93,    93,    93,    85,
     0,    59,     0,    19,     0,    12,     0,    13,     0,    20,
     0,    21,     0,    22,     0,    90,     0,    87,    88,     0,
    87,    89,     0,    47,    59,    59,    60,    93,    74,    48,
     0,    49,    59,    59,    60,    93,    74,    50,     0,     6,
    46,    54,    55,    56,    91,     7,     0,    92,     0,     5,
     0,     4,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   193,   198,   203,   208,   214,   219,   224,   229,   234,   239,
   244,   249,   254,   259,   270,   282,   304,   307,   311,   314,
   317,   321,   323,   325,   327,   329,   331,   333,   335,   337,
   339,   341,   343,   345,   347,   349,   353,   355,   357,   360,
   379,   384,   405,   410,   416,   422,   429,   431,   433,   435,
   438,   444,   452,   454,   456,   459,   470,   472,   476,   487,
   522,   525,   535,   537,   543,   548,   562,   565,   575,   577,
   580,   582,   584,   587,   592,   596,   610,   613,   625,   637,
   639,   642,   644,   647,   649,   651,   654,   659,   664,   670,
   680,   690,   705,   710,   716
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","STRING",
"RAWREAL","RAWINTEGER","START_HEADER","END_HEADER","BOARD_FILE","MM","TNM","THOU",
"TOP","BOTTOM","BOTH","ALL","PTH","NPTH","BOARD","NOREFDES","FIXED","UNPLACED",
"PLACED","START_BOARD_OUTLINE","END_BOARD_OUTLINE","START_OTHER_OUTLINE","END_OTHER_OUTLINE",
"START_ROUTE_OUTLINE","END_ROUTE_OUTLINE","START_PLACE_OUTLINE","END_PLACE_OUTLINE",
"START_ROUTE_KEEPOUT","END_ROUTE_KEEPOUT","START_VIA_KEEPOUT","END_VIA_KEEPOUT",
"START_PLACE_KEEPOUT","END_PLACE_KEEPOUT","START_PLACE_REGION","END_PLACE_REGION",
"START_DRILLED_HOLES","END_DRILLED_HOLES","START_PLACEMENT","END_PLACEMENT",
"'/'","'.'","':'","LIBRARY_FILE","START_ELECTRICAL","END_ELECTRICAL","START_MECHANICAL",
"END_MECHANICAL","idf_data","board_data","board_header","idf_version_number",
"source_system_identification","date","board_file_version","board_name","any_string",
"units_definition_enumeration","board_outline","board_thickness","other_outline",
"extrude_thickness","route_outline","place_outline","route_keepout","inner_and_outer_layer_enumeration",
"via_keepout","place_region","outer_layers_enumeration","place_keepout","comp_height",
"loop","loop_label","arc","angle","board_drilled_holes","drilled_holes","hole_type_enumeration",
"associated_part_string","board_placement","placement","reference_designator",
"top_or_bottom_enumeration","placement_status_enumeration","library_data","electrical",
"mechanical","library_header","library_file_version","integer","real", NULL
};
#endif

static const short yyr1[] = {     0,
    51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
    52,    52,    52,    52,    52,    53,    54,    55,    56,    57,
    58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    59,    59,    59,    59,    60,    60,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    68,    68,    68,
    69,    70,    71,    71,    71,    72,    73,    73,    74,    74,
    75,    76,    77,    77,    78,    78,    78,    79,    80,    80,
    81,    81,    81,    82,    82,    82,    82,    83,    83,    84,
    84,    85,    85,    86,    86,    86,    87,    87,    87,    88,
    89,    90,    91,    92,    93
};

static const short yyr2[] = {     0,
     1,     2,     1,     2,     1,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     9,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
     1,     5,     1,     3,     3,     4,     1,     1,     1,     1,
     3,     5,     1,     1,     1,     6,     1,     1,     2,     3,
     1,     3,     1,     1,     2,     2,     2,     5,     1,     1,
     1,     1,     1,     2,     2,     2,     2,     8,     7,     1,
     1,     1,     1,     1,     1,     1,     1,     2,     2,     7,
     7,     7,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     1,     5,     3,    87,     0,     0,     2,     4,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     6,     7,     8,     9,    10,    11,    13,    12,    14,    15,
     0,     0,    88,    89,    17,     0,     0,    95,     0,    41,
    22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
    32,    33,    34,    35,    36,     0,    94,     0,     0,    61,
     0,    47,    48,    49,    50,     0,     0,    53,    54,    55,
     0,     0,    65,     0,    75,     0,    74,    67,    66,    77,
    76,     0,     0,     0,    18,     0,     0,     0,    43,    44,
     0,    59,     0,    45,     0,    51,     0,    58,    57,     0,
     0,     0,     0,     0,    19,     0,     0,    40,     0,    60,
     0,    46,     0,     0,     0,    33,    80,     0,    37,    38,
    39,     0,     0,     0,    20,     0,    93,    42,    62,    64,
    63,     0,    52,    69,    70,     0,     0,     0,     0,     0,
    21,    92,    56,    32,    33,    73,    68,     0,     0,     0,
     0,     0,    90,    91,    16,    82,    83,    79,    84,    85,
    86,    78,     0,     0
};

static const short yydefgoto[] = {     2,
     3,     4,    36,    84,   106,   124,   140,    76,   122,    21,
    39,    22,    88,    23,    24,    25,    66,    26,    27,    71,
    28,    97,    58,    59,    92,   129,    29,    73,   136,   147,
    30,    77,   118,   158,   162,     5,    33,    34,     6,   126,
    60,    74
};

static const short yypact[] = {     3,
    -6,    27,   238,-32768,   -15,-32768,    14,    14,   238,   -15,
    31,   197,    20,    20,    57,    20,     8,     8,    31,   129,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,     4,   163,
   197,   197,-32768,-32768,-32768,   197,   197,-32768,    20,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    31,-32768,    26,    31,-32768,
     7,-32768,-32768,-32768,-32768,    20,     9,-32768,-32768,-32768,
    88,   197,-32768,    31,-32768,   197,-32768,-32768,-32768,-32768,
-32768,   197,   197,    56,-32768,    56,    53,    20,-32768,-32768,
    31,-32768,    31,-32768,    21,-32768,    88,-32768,-32768,    20,
    31,   217,    78,    78,-32768,    20,    20,-32768,    12,-32768,
    88,-32768,    20,    -2,    82,-32768,-32768,    31,-32768,-32768,
-32768,    31,    31,   197,-32768,    49,-32768,-32768,-32768,-32768,
-32768,     6,-32768,-32768,-32768,   237,    31,    20,    20,    78,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    31,     1,    -4,
    55,    93,-32768,-32768,-32768,-32768,-32768,    75,-32768,-32768,
-32768,-32768,    65,-32768
};

static const short yypgoto[] = {-32768,
    71,-32768,    59,    39,    -5,-32768,-32768,    -8,   -88,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    60,
-32768,   -14,    -9,   -48,    17,-32768,-32768,    74,-32768,-32768,
-32768,    79,-32768,-32768,-32768,    83,-32768,-32768,-32768,-32768,
   -56,   -11
};


#define	YYLAST		279


static const short yytable[] = {    40,
    57,     7,    57,    56,    61,    57,    67,    38,     1,    91,
    57,    57,    91,    57,    98,   123,    57,    35,    91,    68,
    69,    70,    82,    83,    57,    57,   163,    85,    85,    87,
    57,    31,     1,    32,    38,   133,    94,   128,    91,     8,
    98,   143,    96,    78,    89,   154,    91,    93,   153,   125,
   127,   151,   112,    90,   130,   142,    95,    57,   105,    99,
    91,   155,   101,   100,   164,    91,    37,   102,    62,    63,
    64,    65,     9,   103,   104,    86,   108,    72,   109,    93,
   107,   111,   113,    91,    10,    99,   119,   120,   121,   115,
   114,    38,    57,   117,   159,   160,   161,   134,   135,   131,
    91,    91,    79,   132,   156,   157,   137,   110,    81,     0,
   138,   139,     0,     0,     0,   141,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   148,     0,   146,   149,   150,
     0,    41,     0,     0,     0,     0,   152,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
    75,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
     0,     0,     0,     0,    80,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    41,
     0,     0,     0,     0,     0,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,   116,    53,    54,    55,    41,
     0,     0,     0,     0,     0,    42,    43,    44,    45,    46,
    47,    48,    49,    50,   144,   145,    53,    54,    55,     0,
    11,     0,    12,     0,    13,     0,    14,     0,    15,     0,
    16,     0,    17,     0,    18,     0,    19,     0,    20
};

static const short yycheck[] = {    11,
     5,     8,     5,    12,    14,     5,    16,     4,     6,    58,
     5,     5,    61,     5,    71,   104,     5,     4,    67,    12,
    13,    14,    31,    32,     5,     5,     0,    36,    37,    39,
     5,    47,     6,    49,     4,    38,    30,    26,    87,    46,
    97,    36,    34,    40,    56,    50,    95,    59,    48,   106,
   107,   140,    32,    28,   111,     7,    66,     5,     3,    71,
   109,     7,    74,    72,     0,   114,     8,    76,    12,    13,
    14,    15,     2,    82,    83,    37,    24,    18,    88,    91,
    86,    93,    97,   132,     2,    97,     9,    10,    11,   101,
   100,     4,     5,   102,    20,    21,    22,    16,    17,   111,
   149,   150,    29,   113,    12,    13,   118,    91,    30,    -1,
   122,   123,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   137,    -1,   136,   138,   139,
    -1,     3,    -1,    -1,    -1,    -1,   148,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
    42,     9,    10,    11,    12,    13,    14,    15,    16,    17,
    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
    -1,    -1,    -1,    -1,    42,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    22,     3,
    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    22,     3,
    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
    23,    -1,    25,    -1,    27,    -1,    29,    -1,    31,    -1,
    33,    -1,    35,    -1,    37,    -1,    39,    -1,    41
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
//#line 3 "/depot/gnu/arch/share/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

#ifdef MTKFIX
int	yychar;			/*  the lookahead symbol		*/
#endif
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

#ifdef MTKFIX
int yynerrs;			/*  number of parse errors so far       */
#endif
#endif  /* not YYPURE */

#if YYDEBUG != 0
#ifdef MTKFIX
int yydebug;			/*  nonzero means print parse trace	*/
#endif
						/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

//#line 196 "/depot/gnu/arch/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

int
IDFToSdai::yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    TRACE("Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	TRACE("Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    TRACE("Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	TRACE("Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	TRACE("Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  TRACE("Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  TRACE(")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    TRACE("Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      TRACE("Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	TRACE("%s ", yytname[yyrhs[i]]);
      TRACE(" -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
//#line 194 "map.y"
{ 
           yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "idf_data");
           sdaiPutAttrBN (yyval.SdaiInstance, "board_file", sdaiINSTANCE, yyvsp[0].SdaiInstance);
           ;
    break;}
case 2:
//#line 199 "map.y"
{ 
           yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
           sdaiPutAttrBN (yyval.SdaiInstance, "board_file", sdaiINSTANCE, yyvsp[0].SdaiInstance);
           ;
    break;}
case 3:
//#line 204 "map.y"
{ 
           yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "idf_data");
           sdaiPutAttrBN (yyval.SdaiInstance, "library_file", sdaiINSTANCE, yyvsp[0].SdaiInstance);
           ;
    break;}
case 4:
//#line 209 "map.y"
{ 
           yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
           sdaiPutAttrBN (yyval.SdaiInstance, "library_file", sdaiINSTANCE, yyvsp[0].SdaiInstance);
           ;
    break;}
case 5:
//#line 215 "map.y"
{ 
             yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "board_data");
             sdaiPutAttrBN (yyval.SdaiInstance, "board_board_header", sdaiINSTANCE, yyvsp[0].SdaiInstance);
             ;
    break;}
case 6:
//#line 220 "map.y"
{ 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
             sdaiPutAttrBN (yyval.SdaiInstance, "board_board_outline", sdaiINSTANCE, yyvsp[0].SdaiInstance);
             ;
    break;}
case 7:
//#line 225 "map.y"
{ 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
             MTKsdaiInsertAfterBN(yyval.SdaiInstance, "board_other_outline", sdaiINSTANCE, yyvsp[0].SdaiInstance);
             ;
    break;}
case 8:
//#line 230 "map.y"
{ 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
             MTKsdaiInsertAfterBN(yyval.SdaiInstance, "board_route_outline", sdaiINSTANCE, yyvsp[0].SdaiInstance);
             ;
    break;}
case 9:
//#line 235 "map.y"
{ 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
             MTKsdaiInsertAfterBN(yyval.SdaiInstance, "board_place_outline", sdaiINSTANCE, yyvsp[0].SdaiInstance);
             ;
    break;}
case 10:
//#line 240 "map.y"
{ 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
             MTKsdaiInsertAfterBN(yyval.SdaiInstance, "board_route_keepout", sdaiINSTANCE, yyvsp[0].SdaiInstance);
             ;
    break;}
case 11:
//#line 245 "map.y"
{ 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
             MTKsdaiInsertAfterBN(yyval.SdaiInstance, "board_via_keepout", sdaiINSTANCE, yyvsp[0].SdaiInstance);
             ;
    break;}
case 12:
//#line 250 "map.y"
{ 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
             MTKsdaiInsertAfterBN(yyval.SdaiInstance, "board_place_keepout", sdaiINSTANCE, yyvsp[0].SdaiInstance);
             ;
    break;}
case 13:
//#line 255 "map.y"
{ 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
             MTKsdaiInsertAfterBN(yyval.SdaiInstance, "board_place_region", sdaiINSTANCE, yyvsp[0].SdaiInstance);
             ;
    break;}
case 14:
//#line 260 "map.y"
{
             struct InstanceList *list = yyvsp[0].List; 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;

             while(list != NULL)
                {
                MTKsdaiInsertAfterBN(yyval.SdaiInstance, "board_drilled_holes", sdaiINSTANCE, list->instance);
                list = list->next;
                }
             ;
    break;}
case 15:
//#line 271 "map.y"
{ 
             struct InstanceList *list = yyvsp[0].List; 
             yyval.SdaiInstance = yyvsp[-1].SdaiInstance;

             while(list != NULL)
                {
                MTKsdaiInsertAfterBN(yyval.SdaiInstance, "board_placement", sdaiINSTANCE, list->instance);
                list = list->next;
                }
             ;
    break;}
case 16:
//#line 291 "map.y"
{
               yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "board_header");
               sdaiPutAttrBN (yyval.SdaiInstance, "idf_version_number", sdaiSTRING, yyvsp[-6].SdaiString);
               sdaiPutAttrBN (yyval.SdaiInstance, "source_system_identification", sdaiSTRING, yyvsp[-5].SdaiString);
               OriginatingSystem = (char *)strdup(yyvsp[-5].SdaiString);

               sdaiPutAttrBN (yyval.SdaiInstance, "date", sdaiSTRING, yyvsp[-4].SdaiString);

               sdaiPutAttrBN (yyval.SdaiInstance, "board_file_version", sdaiINTEGER, yyvsp[-3].SdaiInteger);
               sdaiPutAttrBN (yyval.SdaiInstance, "board_name", sdaiSTRING, yyvsp[-2].SdaiString);
               sdaiPutAttrBN (yyval.SdaiInstance, "units_definition", sdaiENUM, yyvsp[-1].SdaiEnumeration);
               ;
    break;}
case 17:
//#line 305 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiString; ;
    break;}
case 18:
//#line 308 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiString; ;
    break;}
case 19:
//#line 312 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiString; ;
    break;}
case 20:
//#line 315 "map.y"
{ yyval.SdaiInteger = yyvsp[0].SdaiInteger; ;
    break;}
case 21:
//#line 318 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiString; ;
    break;}
case 22:
//#line 322 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiString; ;
    break;}
case 23:
//#line 324 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 24:
//#line 326 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 25:
//#line 328 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 26:
//#line 330 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 27:
//#line 332 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 28:
//#line 334 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 29:
//#line 336 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 30:
//#line 338 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 31:
//#line 340 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 32:
//#line 342 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 33:
//#line 344 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 34:
//#line 346 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 35:
//#line 348 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 36:
//#line 350 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 37:
//#line 354 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 38:
//#line 356 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 39:
//#line 358 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 40:
//#line 361 "map.y"
{ 
                yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "board_outline");
                sdaiPutAttrBN(yyval.SdaiInstance, "board_thickness", sdaiREAL, yyvsp[-2].SdaiReal);
                sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);                

                /* Add cutouts if present */
                if (yyvsp[-1].OutlineAndCutouts->cutouts != NULL)
                   {
                   struct InstanceList *list = yyvsp[-1].OutlineAndCutouts->cutouts; 

                   while(list != NULL)
                      {
                      MTKsdaiInsertAfterBN(yyval.SdaiInstance, "cutouts", sdaiINSTANCE, list->instance);
                      list = list->next;
                      }
                  }
               ;
    break;}
case 41:
//#line 380 "map.y"
{ /* must be positive */
                  yyval.SdaiReal = yyvsp[0].SdaiReal;
                  ;
    break;}
case 42:
//#line 385 "map.y"
{ 
                yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "other_outline");
                sdaiPutAttrBN(yyval.SdaiInstance, "outline_identifier", sdaiSTRING, yyvsp[-3].SdaiString);
                sdaiPutAttrBN(yyval.SdaiInstance, "extrude_thickness", sdaiREAL, yyvsp[-2].SdaiReal);
                sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);                

                /* Add cutouts if present */
                if (yyvsp[-1].OutlineAndCutouts->cutouts != NULL)
                   {
                   struct InstanceList *list = yyvsp[-1].OutlineAndCutouts->cutouts; 

                   while(list != NULL)
                      {
                      MTKsdaiInsertAfterBN(yyval.SdaiInstance, "cutouts", sdaiINSTANCE, list->instance);
                      list = list->next;
                      }
                  }

                ;
    break;}
case 43:
//#line 406 "map.y"
{ /* must be positive */
                    yyval.SdaiReal = yyvsp[0].SdaiReal;
                    ;
    break;}
case 44:
//#line 411 "map.y"
{ 
                yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "route_outline");
                sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);                
                ;
    break;}
case 45:
//#line 417 "map.y"
{ 
                yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "place_outline");
                sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);                
                ;
    break;}
case 46:
//#line 423 "map.y"
{ 
                yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "route_keepout");
                sdaiPutAttrBN(yyval.SdaiInstance, "routing_layers", sdaiENUM, yyvsp[-2].SdaiEnumeration);                
                sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);                
                ;
    break;}
case 47:
//#line 430 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 48:
//#line 432 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 49:
//#line 434 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 50:
//#line 436 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 51:
//#line 439 "map.y"
{ 
                yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "via_keepout");
                sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);                
                ;
    break;}
case 52:
//#line 445 "map.y"
{
               yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "place_region");
               sdaiPutAttrBN(yyval.SdaiInstance, "board_side", sdaiENUM, yyvsp[-3].SdaiEnumeration);
               sdaiPutAttrBN(yyval.SdaiInstance, "component_group_name", sdaiSTRING, yyvsp[-2].SdaiString);
               sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);                
               ;
    break;}
case 53:
//#line 453 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 54:
//#line 455 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 55:
//#line 457 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 56:
//#line 460 "map.y"
{ 
                yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "place_keepout");

                sdaiPutAttrBN(yyval.SdaiInstance, "board_side", sdaiENUM, yyvsp[-4].SdaiEnumeration);
                sdaiPutAttrBN(yyval.SdaiInstance, "maximum_height", sdaiREAL, yyvsp[-3].SdaiReal);
                sdaiPutAttrBN(yyval.SdaiInstance, "minimum_height", sdaiREAL, yyvsp[-2].SdaiReal);
                sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);                
                ;
    break;}
case 57:
//#line 471 "map.y"
{ yyval.SdaiReal = yyvsp[0].SdaiReal; ;
    break;}
case 58:
//#line 473 "map.y"
{ yyval.SdaiReal = yyvsp[0].SdaiInteger; ;
    break;}
case 59:
//#line 477 "map.y"
{ 
       /* create a loop here */
       yyval.OutlineAndCutouts = (struct OutlineAndCutouts *)calloc(1, sizeof(struct OutlineAndCutouts));
       yyval.OutlineAndCutouts->current_loop_label = yyvsp[-1].SdaiInteger;
       yyval.OutlineAndCutouts->outline = sdaiCreateInstanceBN (myModel, "loop");
       yyval.OutlineAndCutouts->current_loop = yyval.OutlineAndCutouts->outline;

       sdaiPutAttrBN (yyval.OutlineAndCutouts->current_loop, "loop_label", sdaiINTEGER, yyvsp[-1].SdaiInteger);
       MTKsdaiInsertAfterBN(yyval.OutlineAndCutouts->current_loop, "closed_curve", sdaiINSTANCE, yyvsp[0].SdaiInstance);
       ;
    break;}
case 60:
//#line 488 "map.y"
{ 
       if (yyval.OutlineAndCutouts->current_loop_label == yyvsp[-1].SdaiInteger)
          {
          yyval.OutlineAndCutouts = yyvsp[-2].OutlineAndCutouts;
          MTKsdaiInsertAfterBN(yyval.OutlineAndCutouts->current_loop, "closed_curve", sdaiINSTANCE, yyvsp[0].SdaiInstance);
          }
       else
          {
          /* create a loop here */
          yyval.OutlineAndCutouts->current_loop_label = yyvsp[-1].SdaiInteger; 
          yyval.OutlineAndCutouts->current_loop = sdaiCreateInstanceBN (myModel, "loop");
          sdaiPutAttrBN (yyval.OutlineAndCutouts->current_loop, "loop_label", sdaiINTEGER, yyvsp[-1].SdaiInteger);
          MTKsdaiInsertAfterBN(yyval.OutlineAndCutouts->current_loop, "closed_curve", sdaiINSTANCE, yyvsp[0].SdaiInstance);
          if (yyval.OutlineAndCutouts->cutouts == NULL)
             {
             yyval.OutlineAndCutouts->cutouts = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
             yyval.OutlineAndCutouts->cutouts->instance = yyval.OutlineAndCutouts->current_loop;
             }
          else
             {
             struct InstanceList *last;
             last = yyval.OutlineAndCutouts->cutouts;

             while(last->next != NULL)
                 {
                 last = last->next;
                 }
             last->next = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
             last = last->next;
             last->instance = yyval.OutlineAndCutouts->current_loop;
             }
          } 
       ;
    break;}
case 61:
//#line 523 "map.y"
{ yyval.SdaiInteger = yyvsp[0].SdaiInteger; ;
    break;}
case 62:
//#line 526 "map.y"
{
      yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "arc");

      sdaiPutAttrBN (yyval.SdaiInstance, "x_coord", sdaiREAL, yyvsp[-2].SdaiReal);
      sdaiPutAttrBN (yyval.SdaiInstance, "y_coord", sdaiREAL, yyvsp[-1].SdaiReal);
      sdaiPutAttrBN (yyval.SdaiInstance, "included_angle", sdaiREAL, yyvsp[0].SdaiReal);
      ;
    break;}
case 63:
//#line 536 "map.y"
{ yyval.SdaiReal = yyvsp[0].SdaiReal; ;
    break;}
case 64:
//#line 538 "map.y"
{ yyval.SdaiReal = yyvsp[0].SdaiInteger; ;
    break;}
case 65:
//#line 544 "map.y"
{
                      yyval.List = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
                      yyval.List->instance = yyvsp[0].SdaiInstance;
                      ;
    break;}
case 66:
//#line 549 "map.y"
{
                      struct InstanceList *last;
                      yyval.List = yyvsp[-1].List;
                      last = yyval.List;

                      while(last->next != NULL)
                         {
                         last = last->next;
                         }
                      last->next = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
                      last = last->next;
                      last->instance = yyvsp[0].SdaiInstance;
                      ;
    break;}
case 67:
//#line 563 "map.y"
{ yyval.List = yyvsp[-1].List; ;
    break;}
case 68:
//#line 566 "map.y"
{ 
                yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "drilled_holes");
                sdaiPutAttrBN (yyval.SdaiInstance, "hole_diameter", sdaiREAL, yyvsp[-4].SdaiReal);
                sdaiPutAttrBN (yyval.SdaiInstance, "x_coord", sdaiREAL, yyvsp[-3].SdaiReal);
                sdaiPutAttrBN (yyval.SdaiInstance, "y_coord", sdaiREAL, yyvsp[-2].SdaiReal);
                sdaiPutAttrBN(yyval.SdaiInstance, "hole_type", sdaiENUM, yyvsp[-1].SdaiEnumeration);
                sdaiPutAttrBN (yyval.SdaiInstance, "associated_part_string", sdaiSTRING, yyvsp[0].SdaiString);
                ;
    break;}
case 69:
//#line 576 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 70:
//#line 578 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 71:
//#line 581 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 72:
//#line 583 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 73:
//#line 585 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiString; ;
    break;}
case 74:
//#line 588 "map.y"
{ 
                  yyval.List = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
                  yyval.List->instance = yyvsp[0].SdaiInstance;
                  ;
    break;}
case 75:
//#line 593 "map.y"
{
                  yyval.List = NULL;
                  ;
    break;}
case 76:
//#line 597 "map.y"
{
                  struct InstanceList *last;
                  yyval.List = yyvsp[-1].List;
                  last = yyval.List;

                  while(last->next != NULL)
                      {
                      last = last->next;
                      }
                  last->next = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
                  last = last->next;
                  last->instance = yyvsp[0].SdaiInstance;
                  ;
    break;}
case 77:
//#line 611 "map.y"
{ yyval.List = yyvsp[-1].List; ;
    break;}
case 78:
//#line 614 "map.y"
{ 
            yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "placement");
            sdaiPutAttrBN (yyval.SdaiInstance, "package_name", sdaiSTRING, yyvsp[-7].SdaiString);
            sdaiPutAttrBN (yyval.SdaiInstance, "part_number", sdaiSTRING, yyvsp[-6].SdaiString);
            sdaiPutAttrBN (yyval.SdaiInstance, "reference_designator", sdaiSTRING, yyvsp[-5].SdaiString);
            sdaiPutAttrBN (yyval.SdaiInstance, "x_coord", sdaiREAL, yyvsp[-4].SdaiReal);
            sdaiPutAttrBN (yyval.SdaiInstance, "y_coord", sdaiREAL, yyvsp[-3].SdaiReal);
            sdaiPutAttrBN (yyval.SdaiInstance, "rotation_angle", sdaiREAL, yyvsp[-2].SdaiReal);
            sdaiPutAttrBN (yyval.SdaiInstance, "side_of_board", sdaiENUM, yyvsp[-1].SdaiEnumeration);
            sdaiPutAttrBN (yyval.SdaiInstance, "placement_status", sdaiENUM, yyvsp[0].SdaiEnumeration);
            ;
    break;}
case 79:
//#line 626 "map.y"
{ 
            yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "placement");
            sdaiPutAttrBN (yyval.SdaiInstance, "package_name", sdaiSTRING, yyvsp[-6].SdaiString);
            sdaiPutAttrBN (yyval.SdaiInstance, "part_number", sdaiSTRING, yyvsp[-5].SdaiString);
            sdaiPutAttrBN (yyval.SdaiInstance, "reference_designator", sdaiSTRING, yyvsp[-4].SdaiString);
            sdaiPutAttrBN (yyval.SdaiInstance, "x_coord", sdaiREAL, yyvsp[-3].SdaiReal);
            sdaiPutAttrBN (yyval.SdaiInstance, "y_coord", sdaiREAL, yyvsp[-2].SdaiReal);
            sdaiPutAttrBN (yyval.SdaiInstance, "rotation_angle", sdaiREAL, yyvsp[-1].SdaiReal);
            sdaiPutAttrBN (yyval.SdaiInstance, "side_of_board", sdaiENUM, yyvsp[0].SdaiEnumeration);
            ;
    break;}
case 80:
//#line 638 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiString; ;
    break;}
case 81:
//#line 640 "map.y"
{ yyval.SdaiString = yyvsp[0].SdaiEnumeration; ;
    break;}
case 82:
//#line 643 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 83:
//#line 645 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 84:
//#line 648 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 85:
//#line 650 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 86:
//#line 652 "map.y"
{ yyval.SdaiEnumeration = yyvsp[0].SdaiEnumeration; ;
    break;}
case 87:
//#line 655 "map.y"
{ 
               yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "library_data");
               sdaiPutAttrBN (yyval.SdaiInstance, "library_library_header", sdaiINSTANCE, yyvsp[0].SdaiInstance);
               ;
    break;}
case 88:
//#line 660 "map.y"
{ 
               yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
               MTKsdaiInsertAfterBN(yyval.SdaiInstance, "library_electrical", sdaiINSTANCE, yyvsp[0].SdaiInstance);
               ;
    break;}
case 89:
//#line 665 "map.y"
{ 
               yyval.SdaiInstance = yyvsp[-1].SdaiInstance;
               MTKsdaiInsertAfterBN(yyval.SdaiInstance, "library_mechanical", sdaiINSTANCE, yyvsp[0].SdaiInstance);
               ;
    break;}
case 90:
//#line 671 "map.y"
{
             yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "electrical");
             sdaiPutAttrBN (yyval.SdaiInstance, "geometry_name", sdaiSTRING, yyvsp[-5].SdaiString);
             sdaiPutAttrBN (yyval.SdaiInstance, "part_number", sdaiSTRING, yyvsp[-4].SdaiString);
             sdaiPutAttrBN (yyval.SdaiInstance, "units_definition", sdaiENUM, yyvsp[-3].SdaiEnumeration);
             sdaiPutAttrBN (yyval.SdaiInstance, "component_height", sdaiREAL, yyvsp[-2].SdaiReal);
             sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);
             ;
    break;}
case 91:
//#line 681 "map.y"
{ 
             yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "mechanical");
             sdaiPutAttrBN (yyval.SdaiInstance, "geometry_name", sdaiSTRING, yyvsp[-5].SdaiString);
             sdaiPutAttrBN (yyval.SdaiInstance, "part_number", sdaiSTRING, yyvsp[-4].SdaiString);
             sdaiPutAttrBN (yyval.SdaiInstance, "units_definition", sdaiENUM, yyvsp[-3].SdaiEnumeration);
             sdaiPutAttrBN (yyval.SdaiInstance, "component_height", sdaiREAL, yyvsp[-2].SdaiReal);
             sdaiPutAttrBN(yyval.SdaiInstance, "outline", sdaiINSTANCE, yyvsp[-1].OutlineAndCutouts->outline);
             ;
    break;}
case 92:
//#line 697 "map.y"
{
                 yyval.SdaiInstance = sdaiCreateInstanceBN (myModel, "library_header");
                 sdaiPutAttrBN (yyval.SdaiInstance, "idf_version_number", sdaiSTRING, yyvsp[-4].SdaiString);
                 sdaiPutAttrBN (yyval.SdaiInstance, "source_system_identification", sdaiSTRING, yyvsp[-3].SdaiString);
                 sdaiPutAttrBN (yyval.SdaiInstance, "date", sdaiSTRING, yyvsp[-2].SdaiString);
                 sdaiPutAttrBN (yyval.SdaiInstance, "library_file_version", sdaiINTEGER, yyvsp[-1].SdaiInteger);
                 ;
    break;}
case 93:
//#line 706 "map.y"
{ yyval.SdaiInteger = yyvsp[0].SdaiInteger; ;
    break;}
case 94:
//#line 711 "map.y"
{
          yyval.SdaiInteger = atoi(yyvsp[0].SdaiString);
          free(yyvsp[0].SdaiString);
          ;
    break;}
case 95:
//#line 717 "map.y"
{
       yyval.SdaiReal = atof(yyvsp[0].SdaiString);
       free(yyvsp[0].SdaiString);
       ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
//#line 498 "/depot/gnu/arch/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      TRACE("state stack now");
      while (ssp1 != yyssp)
	TRACE(" %d", *++ssp1);
      TRACE("\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	TRACE("Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      TRACE("Error: state stack now");
      while (ssp1 != yyssp)
	TRACE(" %d", *++ssp1);
      TRACE("\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    TRACE("Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
//#line 721 "map.y"

void IDFToSdai::MTKsdaiInsertAfterBN(SdaiInstance instance,
                          char *attribute_name,
                          SdaiPrimitiveType type,
                          SdaiInstance attribute)
   {
   /* need to make this a function for adding SdaiInstance types to list */
   SdaiAggr ag;
   SdaiIterator itor;

   /* Need to check to see if the attribute has been created. */
   if (sdaiTestAttrBN(instance, attribute_name) == sdaiFALSE)
       {
       /* Has not been created so create it. */
       ag = sdaiCreateAggrBN(instance, attribute_name);
       }
    sdaiGetAttrBN(instance, attribute_name, sdaiAGGR, &ag);
    itor = sdaiCreateIterator(ag);
    sdaiEnd(itor);
    sdaiPrevious(itor);
    sdaiInsertAfter(itor, type, attribute);
}

// This stuff came from map.yy.c
/* A lexical scanner generated by flex */

/* Scanner skeleton version:
 * $Header: /home/daffy/u0/vern/flex/RCS/flex.skl,v 2.91 96/09/10 16:58:48 vern Exp $
 */
#define YY_NEVER_INTERACTIVE 1

#define FLEX_SCANNER
#define YY_FLEX_MAJOR_VERSION 2
#define YY_FLEX_MINOR_VERSION 5

#include <stdio.h>


/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif


#ifdef __cplusplus

#include <stdlib.h>
//#include <unistd.h>

/* Use prototypes in function declarations. */
#define YY_USE_PROTOS

/* The "const" storage-class-modifier is valid. */
#define YY_USE_CONST

#else	/* ! __cplusplus */

#if __STDC__

#define YY_USE_PROTOS
#define YY_USE_CONST

#endif	/* __STDC__ */
#endif	/* ! __cplusplus */

#ifdef __TURBOC__
 #pragma warn -rch
 #pragma warn -use
#include <io.h>
#include <stdlib.h>
#define YY_USE_CONST
#define YY_USE_PROTOS
#endif

#ifdef MTKFIX
#ifdef YY_USE_CONST
#define yyconst const
#else
#define yyconst
#endif
#endif

#ifdef YY_USE_PROTOS
#define YY_PROTO(proto) proto
#else
#define YY_PROTO(proto) ()
#endif

/* Returned upon end-of-file. */
#define YY_NULL 0

/* Promotes a possibly negative, possibly signed char to an unsigned
 * integer for use as an array index.  If the signed char is negative,
 * we want to instead treat it as an 8-bit unsigned char, hence the
 * double cast.
 */
#define YY_SC_TO_UI(c) ((unsigned int) (unsigned char) c)

/* Enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN.
 */
#define BEGIN yy_start = 1 + 2 *

/* Translate the current start state into a value that can be later handed
 * to BEGIN to return to the state.  The YYSTATE alias is for lex
 * compatibility.
 */
#define YY_START ((yy_start - 1) / 2)
#define YYSTATE YY_START

/* Action number for EOF rule of a given start state. */
#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)

/* Special action meaning "start processing a new file". */
#define YY_NEW_FILE yyrestart( yyin )

#define YY_END_OF_BUFFER_CHAR 0

/* Size of default input buffer. */
#define YY_BUF_SIZE 16384

#ifdef MTKFIX
typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern int yyleng;
extern FILE *yyin, *yyout;
#endif

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* The funky do-while in the following #define is used to turn the definition
 * int a single C statement (which needs a semi-colon terminator).  This
 * avoids problems with code like:
 *
 * 	if ( condition_holds )
 *		yyless( 5 );
 *	else
 *		do_something_else();
 *
 * Prior to using the do-while the compiler would get upset at the
 * "else" because it interpreted the "if" statement as being all
 * done when it reached the ';' after the yyless() call.
 */

/* Return all but the first 'n' matched characters back to the input stream. */

#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		*yy_cp = yy_hold_char; \
		YY_RESTORE_YY_MORE_OFFSET \
		yy_c_buf_p = yy_cp = yy_bp + n - YY_MORE_ADJ; \
		YY_DO_BEFORE_ACTION; /* set up yytext again */ \
		} \
	while ( 0 )

#define unput(c) yyunput( c, yytext_ptr )

/* The following is because we cannot portably get our hands on size_t
 * (without autoconf's help, which isn't available because we want
 * flex-generated scanners to compile on their own).
 */
#ifdef MTKFIX
typedef unsigned int yy_size_t;
#endif

struct yy_buffer_state
	{
	FILE *yy_input_file;

	char *yy_ch_buf;		/* input buffer */
	char *yy_buf_pos;		/* current position in input buffer */

	/* Size of input buffer in bytes, not including room for EOB
	 * characters.
	 */
	yy_size_t yy_buf_size;

	/* Number of characters read into yy_ch_buf, not including EOB
	 * characters.
	 */
	int yy_n_chars;

	/* Whether we "own" the buffer - i.e., we know we created it,
	 * and can realloc() it to grow it, and should free() it to
	 * delete it.
	 */
	int yy_is_our_buffer;

	/* Whether this is an "interactive" input source; if so, and
	 * if we're using stdio for input, then we want to use getc()
	 * instead of fread(), to make sure we stop fetching input after
	 * each newline.
	 */
	int yy_is_interactive;

	/* Whether we're considered to be at the beginning of a line.
	 * If so, '^' rules will be active on the next match, otherwise
	 * not.
	 */
	int yy_at_bol;

	/* Whether to try to fill the input buffer when we reach the
	 * end of it.
	 */
	int yy_fill_buffer;

	int yy_buffer_status;
#define YY_BUFFER_NEW 0
#define YY_BUFFER_NORMAL 1
	/* When an EOF's been seen but there's still some text to process
	 * then we mark the buffer as YY_EOF_PENDING, to indicate that we
	 * shouldn't try reading from the input source any more.  We might
	 * still have a bunch of tokens to match, though, because of
	 * possible backing-up.
	 *
	 * When we actually see the EOF, we change the status to "new"
	 * (via yyrestart()), so that the user can continue scanning by
	 * just pointing yyin at a new input file.
	 */
#define YY_BUFFER_EOF_PENDING 2
	};

static YY_BUFFER_STATE yy_current_buffer = 0;

/* We provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state".
 */
#define YY_CURRENT_BUFFER yy_current_buffer


/* yy_hold_char holds the character lost when yytext is formed. */
static char yy_hold_char;

static int yy_n_chars;		/* number of characters read into yy_ch_buf */

#ifdef MTKFIX
int yyleng;
#endif

/* Points to current character in buffer. */
static char *yy_c_buf_p = (char *) 0;
static int yy_init = 1;		/* whether we need to initialize */
static int yy_start = 0;	/* start state number */

/* Flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh yyin.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;

void yyrestart YY_PROTO(( FILE *input_file ));

#ifdef MTKFIX
void yy_switch_to_buffer YY_PROTO(( YY_BUFFER_STATE new_buffer ));
#endif
void yy_load_buffer_state YY_PROTO(( void ));
#ifdef MTKFIX
YY_BUFFER_STATE yy_create_buffer YY_PROTO(( FILE *file, int size ));
void yy_delete_buffer YY_PROTO(( YY_BUFFER_STATE b ));
void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));
void yy_flush_buffer YY_PROTO(( YY_BUFFER_STATE b ));
#endif
#define YY_FLUSH_BUFFER yy_flush_buffer( yy_current_buffer )

YY_BUFFER_STATE yy_scan_buffer YY_PROTO(( char *base, yy_size_t size ));
#ifdef MTKFIX
YY_BUFFER_STATE yy_scan_string YY_PROTO(( yyconst char *yy_str ));
#endif
YY_BUFFER_STATE yy_scan_bytes YY_PROTO(( yyconst char *bytes, int len ));

static void *yy_flex_alloc YY_PROTO(( yy_size_t ));
static void *yy_flex_realloc YY_PROTO(( void *, yy_size_t ));
static void yy_flex_free YY_PROTO(( void * ));

#define yy_new_buffer yy_create_buffer

#define yy_set_interactive(is_interactive) \
	{ \
	if ( ! yy_current_buffer ) \
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
	yy_current_buffer->yy_is_interactive = is_interactive; \
	}

#define yy_set_bol(at_bol) \
	{ \
	if ( ! yy_current_buffer ) \
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
	yy_current_buffer->yy_at_bol = at_bol; \
	}

#define YY_AT_BOL() (yy_current_buffer->yy_at_bol)

typedef unsigned char YY_CHAR;
#ifdef MTKFIX
FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
#endif
#ifdef MTKFIX
typedef int yy_state_type;
extern char *yytext;
#endif
#define yytext_ptr yytext

static yy_state_type yy_get_previous_state YY_PROTO(( void ));
static yy_state_type yy_try_NUL_trans YY_PROTO(( yy_state_type current_state ));
static int yy_get_next_buffer YY_PROTO(( void ));
static void yy_fatal_error YY_PROTO(( yyconst char msg[] ));

/* Done after the current pattern has been matched and before the
 * corresponding action - sets up yytext.
 */
#define YY_DO_BEFORE_ACTION \
	yytext_ptr = yy_bp; \
	yyleng = (int) (yy_cp - yy_bp); \
	yy_hold_char = *yy_cp; \
	*yy_cp = '\0'; \
	yy_c_buf_p = yy_cp;

#define YY_NUM_RULES 56
#define YY_END_OF_BUFFER 57
static yyconst short int yy_accept[354] =
    {   0,
        0,    0,   57,   55,   54,   55,   55,   52,   51,   47,
       53,   55,   55,   55,   55,   55,   55,   55,   55,   55,
       55,   55,    0,   48,   46,    0,    0,    0,    0,    0,
        0,    0,    0,    0,   50,   50,   47,   50,   50,   50,
       50,    2,   50,   50,   50,   50,   50,   50,   50,   50,
        0,   49,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,   45,    8,   50,   50,   50,   50,   50,
       50,   50,    9,   50,    3,    5,   50,    1,   44,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,   50,
        7,   50,   50,   50,   50,   10,   50,    4,   50,    0,

        0,    0,    0,    0,    0,    0,    0,    0,    0,   11,
       50,   13,   50,   50,   50,   50,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,   50,    6,   50,   50,   15,   50,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,   16,    0,    0,    0,    0,    0,    0,   50,
       50,   50,   50,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,   50,   50,   12,   14,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,

        0,    0,    0,    0,    0,    0,    0,    0,    0,   50,
       50,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,   37,    0,
        0,    0,   18,   50,    0,    0,   40,    0,    0,    0,
       17,    0,    0,    0,    0,    0,    0,   42,    0,    0,
        0,    0,    0,    0,    0,   50,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,   29,   39,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,   31,    0,    0,   19,   35,

        0,    0,    0,    0,    0,    0,    0,    0,   38,    0,
        0,    0,   21,   33,   25,   27,   23,    0,    0,   41,
       43,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,   30,    0,    0,    0,
        0,    0,   32,    0,    0,   20,   36,   22,   34,   26,
       28,   24,    0
    } ;

static yyconst int yy_ec[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    2,    1,    4,    5,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    6,    7,    8,    9,    9,    9,
        9,    9,    9,    9,    9,    9,    9,   10,    1,    1,
        1,    1,    1,    1,   12,   13,   14,   15,   16,   17,
       18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
       21,   28,   29,   30,   31,   32,   21,   33,   34,   21,
        1,    1,    1,    1,   11,    1,   12,   13,   14,   15,

       16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
       26,   27,   21,   28,   29,   30,   31,   32,   21,   33,
       34,   21,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1
    } ;

static yyconst int yy_meta[35] =
    {   0,
        1,    2,    3,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1
    } ;

static yyconst short int yy_base[357] =
    {   0,
        0,  369,  373,  375,  375,  368,  362,   22,  375,   33,
      375,  347,  343,    0,  348,  347,  342,   17,   22,   32,
      340,    0,  360,  375,   46,  337,  334,   36,  345,  344,
      329,  335,  331,  336,    0,  346,   53,  331,   35,  320,
      339,    0,  323,  320,  337,  329,  321,  322,  318,  317,
      340,  375,  333,  329,  320,  323,  323,  325,  322,  316,
      322,  302,  320,  322,    0,  302,   37,  313,  300,  311,
      307,  311,    0,  293,    0,    0,  300,  375,  313,  293,
      297,  305,  307,  302,  297,  299,  300,  283,  301,  296,
        0,  284,  294,  296,  290,    0,  290,    0,  293,  289,

      280,  272,   55,  285,  288,  271,  282,  281,  274,  284,
      270,    0,  265,  277,  276,  276,  278,  272,  259,  260,
      257,  261,  267,  266,  251,  257,  253,  258,  249,  251,
      264,   52,  263,  257,  255,    0,  237,  254,    0,  253,
      242,  252,  246,  253,  244,  247,  250,  247,  241,  247,
      227,  245,  375,  236,  229,   47,  238,   58,  237,  232,
      240,  221,  234,  217,  236,  232,  217,  221,  229,  227,
      222,  224,  225,  208,  226,  222,  204,  218,  202,  216,
      206,  214,  198,  201,  204,  209,    0,    0,  195,  205,
      211,  207,  198,  190,  203,  206,  189,  200,  199,  192,

      201,  182,  195,  180,  191,  178,  191,  176,  179,  188,
      183,  179,  175,  177,  188,  182,  169,  168,  170,  183,
       53,  182,  176,  168,  167,  162,  165,  167,  375,  159,
      162,  153,    0,  160,  162,  158,  375,  154,  164,  158,
      375,  157,  150,   63,  159,   64,  158,  375,  153,  146,
      151,  144,  143,  148,  137,  150,  140,  148,  132,  151,
      147,  146,  128,  142,  126,  140,  130,  138,  122,  125,
      126,  119,  124,  123,  116,  121,  375,    0,  129,  115,
      113,  123,  129,  128,  109,  122,  107,  118,  105,  118,
      103,  106,  115,  100,  113,  375,   98,  111,  375,  375,

      103,   99,  101,  100,   99,   94,   97,   99,  375,   91,
       94,   85,  375,  375,  375,  375,  375,   95,   91,  375,
      375,   93,   86,   91,   84,   83,   88,   77,   81,   89,
       79,   72,   77,   76,   69,   74,  375,   82,   68,   72,
       48,   56,  375,   36,   23,  375,  375,  375,  375,  375,
      375,  375,  375,   91,   35,   94
    } ;

static yyconst short int yy_def[357] =
    {   0,
      353,    1,  353,  353,  353,  354,  353,  353,  353,  355,
      353,  355,  355,  355,  355,  355,  355,  355,  355,  355,
      355,  356,  354,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  355,  355,  355,  355,  355,  355,
      355,  355,  355,  355,  355,  355,  355,  355,  355,  355,
      356,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  355,  355,  355,  355,  355,  355,  355,
      355,  355,  355,  355,  355,  355,  355,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  355,
      355,  355,  355,  355,  355,  355,  355,  355,  355,  353,

      353,  353,  353,  353,  353,  353,  353,  353,  353,  355,
      355,  355,  355,  355,  355,  355,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  355,  355,  355,  355,  355,  355,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  355,
      355,  355,  355,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  355,  355,  355,  355,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,

      353,  353,  353,  353,  353,  353,  353,  353,  353,  355,
      355,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  355,  355,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  355,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  355,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,

      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,    0,  353,  353,  353
    } ;

static yyconst short int yy_nxt[410] =
    {   0,
        4,    4,    5,    6,    4,    7,    8,    9,   10,   11,
        4,   12,   13,   14,   14,   14,   15,   14,   14,   14,
       14,   14,   16,   17,   18,   14,   19,   14,   14,   20,
       21,   14,   14,   14,   26,   35,   27,   28,  352,   36,
       29,   37,   43,   44,   45,   30,   66,   31,   32,   33,
       47,   46,   53,   34,   25,   91,   48,   49,   56,   36,
       57,   37,  156,  244,   67,  351,   92,  120,  178,  121,
      122,  350,  179,  123,  180,  157,  245,  349,  124,  182,
      125,  126,  127,  183,  264,  268,  128,  348,  265,  269,
      266,   23,   23,   23,   51,   51,  347,  346,  345,  344,

      343,  342,  341,  340,  339,  338,  337,  336,  335,  334,
      333,  332,  331,  330,  329,  328,  327,  326,  325,  324,
      323,  322,  321,  320,  319,  318,  317,  316,  315,  314,
      313,  312,  311,  310,  309,  308,  307,  306,  305,  304,
      303,  302,  301,  300,  299,  298,  297,  296,  295,  294,
      293,  292,  291,  290,  289,  288,  287,  286,  285,  284,
      283,  282,  281,  280,  279,  278,  277,  276,  275,  274,
      273,  272,  271,  270,  267,  263,  262,  261,  260,  259,
      258,  257,  256,  255,  254,  253,  252,  251,  250,  249,
      248,  247,  246,  243,  242,  241,  240,  239,  238,  237,

      236,  235,  234,  233,  232,  231,  230,  229,  228,  227,
      226,  225,  224,  223,  222,  221,  220,  219,  218,  217,
      216,  215,  214,  213,  212,  211,  210,  209,  208,  207,
      206,  205,  204,  203,  202,  201,  200,  199,  198,  197,
      196,  195,  194,  193,  192,  191,  190,  189,  188,  187,
      186,  185,  184,  181,  177,  176,  175,  174,  173,  172,
      171,  170,  169,  168,  167,  166,  165,  164,  163,  162,
      161,  160,  159,  158,  155,  154,  153,  152,  151,  150,
      149,  148,  147,  146,  145,  144,  143,  142,  141,  140,
      139,  138,  137,  136,  135,  134,  133,  132,  131,  130,

      129,  119,  118,  117,  116,  115,  114,  113,  112,  111,
      110,  109,  108,  107,  106,  105,  104,  103,  102,  101,
      100,   79,   99,   98,   97,   96,   95,   94,   93,   90,
       64,   89,   88,   87,   86,   85,   84,   83,   82,   81,
       80,   79,   78,   77,   76,   75,   74,   73,   72,   71,
       70,   69,   68,   65,   64,   63,   62,   61,   60,   59,
       58,   55,   54,   52,   50,   42,   41,   40,   39,   38,
       25,   24,  353,   22,    3,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,

      353,  353,  353,  353,  353,  353,  353,  353,  353
    } ;

static yyconst short int yy_chk[410] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    8,  355,    8,    8,  345,   10,
        8,   10,   18,   18,   19,    8,   39,    8,    8,    8,
       20,   19,   25,    8,   25,   67,   20,   20,   28,   37,
       28,   37,  132,  221,   39,  344,   67,  103,  156,  103,
      103,  342,  156,  103,  156,  132,  221,  341,  103,  158,
      103,  103,  103,  158,  244,  246,  103,  340,  244,  246,
      244,  354,  354,  354,  356,  356,  339,  338,  336,  335,

      334,  333,  332,  331,  330,  329,  328,  327,  326,  325,
      324,  323,  322,  319,  318,  312,  311,  310,  308,  307,
      306,  305,  304,  303,  302,  301,  298,  297,  295,  294,
      293,  292,  291,  290,  289,  288,  287,  286,  285,  284,
      283,  282,  281,  280,  279,  276,  275,  274,  273,  272,
      271,  270,  269,  268,  267,  266,  265,  264,  263,  262,
      261,  260,  259,  258,  257,  256,  255,  254,  253,  252,
      251,  250,  249,  247,  245,  243,  242,  240,  239,  238,
      236,  235,  234,  232,  231,  230,  228,  227,  226,  225,
      224,  223,  222,  220,  219,  218,  217,  216,  215,  214,

      213,  212,  211,  210,  209,  208,  207,  206,  205,  204,
      203,  202,  201,  200,  199,  198,  197,  196,  195,  194,
      193,  192,  191,  190,  189,  186,  185,  184,  183,  182,
      181,  180,  179,  178,  177,  176,  175,  174,  173,  172,
      171,  170,  169,  168,  167,  166,  165,  164,  163,  162,
      161,  160,  159,  157,  155,  154,  152,  151,  150,  149,
      148,  147,  146,  145,  144,  143,  142,  141,  140,  138,
      137,  135,  134,  133,  131,  130,  129,  128,  127,  126,
      125,  124,  123,  122,  121,  120,  119,  118,  117,  116,
      115,  114,  113,  111,  110,  109,  108,  107,  106,  105,

      104,  102,  101,  100,   99,   97,   95,   94,   93,   92,
       90,   89,   88,   87,   86,   85,   84,   83,   82,   81,
       80,   79,   77,   74,   72,   71,   70,   69,   68,   66,
       64,   63,   62,   61,   60,   59,   58,   57,   56,   55,
       54,   53,   51,   50,   49,   48,   47,   46,   45,   44,
       43,   41,   40,   38,   36,   34,   33,   32,   31,   30,
       29,   27,   26,   23,   21,   17,   16,   15,   13,   12,
        7,    6,    3,    2,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
      353,  353,  353,  353,  353,  353,  353,  353,  353,  353,

      353,  353,  353,  353,  353,  353,  353,  353,  353
    } ;

static yy_state_type yy_last_accepting_state;
static char *yy_last_accepting_cpos;

/* The intent behind this definition is that it'll catch
 * any uses of REJECT which flex missed.
 */
#define REJECT reject_used_but_not_detected
#define yymore() yymore_used_but_not_detected
#define YY_MORE_ADJ 0
#define YY_RESTORE_YY_MORE_OFFSET
#ifdef MTKFIX
char *yytext;
#endif
//#line 1 "map.yy.l"
#define INITIAL 0
//#line 2 "map.yy.l"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "map_tab.h"

int linecount = 1;
char *current_file;
char *second_file;

char *StripQuotes(char *str);
/*
ALPHANUM [/\-_\.0-9a-zA-Z]
*/
//#line 583 "lex.yy.c"

/* Macros after this point can all be overridden by user definitions in
 * section 1.
 */

#ifndef YY_SKIP_YYWRAP
#ifdef __cplusplus
extern "C" int yywrap YY_PROTO(( void ));
#else
extern int yywrap YY_PROTO(( void ));
#endif
#endif

#ifndef YY_NO_UNPUT
static void yyunput YY_PROTO(( int c, char *buf_ptr ));
#endif

#ifndef yytext_ptr
static void yy_flex_strncpy YY_PROTO(( char *, yyconst char *, int ));
#endif

#ifdef YY_NEED_STRLEN
static int yy_flex_strlen YY_PROTO(( yyconst char * ));
#endif

#ifndef YY_NO_INPUT
#ifdef __cplusplus
static int yyinput YY_PROTO(( void ));
#else
static int input YY_PROTO(( void ));
#endif
#endif

#if YY_STACK_USED
static int yy_start_stack_ptr = 0;
static int yy_start_stack_depth = 0;
static int *yy_start_stack = 0;
#ifndef YY_NO_PUSH_STATE
static void yy_push_state YY_PROTO(( int new_state ));
#endif
#ifndef YY_NO_POP_STATE
static void yy_pop_state YY_PROTO(( void ));
#endif
#ifndef YY_NO_TOP_STATE
static int yy_top_state YY_PROTO(( void ));
#endif

#else
#define YY_NO_PUSH_STATE 1
#define YY_NO_POP_STATE 1
#define YY_NO_TOP_STATE 1
#endif

#ifdef YY_MALLOC_DECL
YY_MALLOC_DECL
#else
#if __STDC__
#ifndef __cplusplus
#include <stdlib.h>
#endif
#else
/* Just try to get by without declaring the routines.  This will fail
 * miserably on non-ANSI systems for which sizeof(size_t) != sizeof(int)
 * or sizeof(void*) != sizeof(int).
 */
#endif
#endif

/* Amount of stuff to slurp up with each read. */
#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif

/* Copy whatever the last rule matched to the standard output. */

#ifndef ECHO
/* This used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite().
 */
#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )
#endif

/* Gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#ifndef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( yy_current_buffer->yy_is_interactive ) \
		{ \
		int c = '*', n; \
		for ( n = 0; n < max_size && \
			     (c = getc( yyin )) != EOF && c != '\n'; ++n ) \
			buf[n] = (char) c; \
		if ( c == '\n' ) \
			buf[n++] = (char) c; \
		if ( c == EOF && ferror( yyin ) ) \
			YY_FATAL_ERROR( "input in flex scanner failed" ); \
		result = n; \
		} \
	else if ( ((result = fread( buf, 1, max_size, yyin )) == 0) \
		  && ferror( yyin ) ) \
		YY_FATAL_ERROR( "input in flex scanner failed" );
#endif

/* No semi-colon after return; correct usage is to write "yyterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */
#ifndef yyterminate
#define yyterminate() return YY_NULL
#endif

/* Number of entries by which start-condition stack grows. */
#ifndef YY_START_STACK_INCR
#define YY_START_STACK_INCR 25
#endif

/* Report a fatal error. */
#ifndef YY_FATAL_ERROR
#define YY_FATAL_ERROR(msg) yy_fatal_error( msg )
#endif

/* Default declaration of generated scanner - a define so the user can
 * easily add parameters.
 */
#ifndef YY_DECL
#define YY_DECL int IDFToSdai::yylex YY_PROTO(( void ))
#endif

/* Code executed at the beginning of each rule, after yytext and yyleng
 * have been set up.
 */
#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

/* Code executed at the end of each rule. */
#ifndef YY_BREAK
#define YY_BREAK break;
#endif

#define YY_RULE_SETUP \
	if ( yyleng > 0 ) \
		yy_current_buffer->yy_at_bol = \
				(yytext[yyleng - 1] == '\n'); \
	YY_USER_ACTION

YY_DECL
	{
	register yy_state_type yy_current_state;
	register char *yy_cp, *yy_bp;
	register int yy_act;

//#line 21 "map.yy.l"

//#line 739 "lex.yy.c"

	if ( yy_init )
		{
		yy_init = 0;

#ifdef YY_USER_INIT
		YY_USER_INIT;
#endif

		if ( ! yy_start )
			yy_start = 1;	/* first start state */

		if ( ! yyin )
			yyin = stdin;

		if ( ! yyout )
			yyout = stdout;

		if ( ! yy_current_buffer )
			yy_current_buffer =
				yy_create_buffer( yyin, YY_BUF_SIZE );

		yy_load_buffer_state();
		}

	while ( 1 )		/* loops until end-of-file is reached */
		{
		yy_cp = yy_c_buf_p;

		/* Support of yytext. */
		*yy_cp = yy_hold_char;

		/* yy_bp points to the position in yy_ch_buf of the start of
		 * the current run.
		 */
		yy_bp = yy_cp;

		yy_current_state = yy_start;
		yy_current_state += YY_AT_BOL();
yy_match:
		do
			{
			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
			if ( yy_accept[yy_current_state] )
				{
				yy_last_accepting_state = yy_current_state;
				yy_last_accepting_cpos = yy_cp;
				}
			while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
				{
				yy_current_state = (int) yy_def[yy_current_state];
				if ( yy_current_state >= 354 )
					yy_c = yy_meta[(unsigned int) yy_c];
				}
			yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
			++yy_cp;
			}
		while ( yy_base[yy_current_state] != 375 );

yy_find_action:
		yy_act = yy_accept[yy_current_state];
		if ( yy_act == 0 )
			{ /* have to back up */
			yy_cp = yy_last_accepting_cpos;
			yy_current_state = yy_last_accepting_state;
			yy_act = yy_accept[yy_current_state];
			}

		YY_DO_BEFORE_ACTION;


do_action:	/* This label is used only to access EOF actions. */


		switch ( yy_act )
	{ /* beginning of action switch */
			case 0: /* must back up */
			/* undo the effects of YY_DO_BEFORE_ACTION */
			*yy_cp = yy_hold_char;
			yy_cp = yy_last_accepting_cpos;
			yy_current_state = yy_last_accepting_state;
			goto yy_find_action;

case 1:
YY_RULE_SETUP
//#line 22 "map.yy.l"
{linecount++;}
	YY_BREAK
case 2:
YY_RULE_SETUP
//#line 23 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(MM);}
	YY_BREAK
case 3:
YY_RULE_SETUP
//#line 24 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(TNM);}
	YY_BREAK
case 4:
YY_RULE_SETUP
//#line 25 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(THOU);}
	YY_BREAK
case 5:
YY_RULE_SETUP
//#line 26 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(TOP);}
	YY_BREAK
case 6:
YY_RULE_SETUP
//#line 27 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(BOTTOM);}
	YY_BREAK
case 7:
YY_RULE_SETUP
//#line 28 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(BOTH);}
	YY_BREAK
case 8:
YY_RULE_SETUP
//#line 29 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(ALL);}
	YY_BREAK
case 9:
YY_RULE_SETUP
//#line 30 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(PTH);}
	YY_BREAK
case 10:
YY_RULE_SETUP
//#line 31 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(NPTH);}
	YY_BREAK
case 11:
YY_RULE_SETUP
//#line 32 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(BOARD);}
	YY_BREAK
case 12:
YY_RULE_SETUP
//#line 33 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(NOREFDES);}
	YY_BREAK
case 13:
YY_RULE_SETUP
//#line 34 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup("PLACEMENT_FIXED");return(FIXED);}
	YY_BREAK
case 14:
YY_RULE_SETUP
//#line 35 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(UNPLACED);}
	YY_BREAK
case 15:
YY_RULE_SETUP
//#line 36 "map.yy.l"
{yylval.SdaiEnumeration = (char *)strdup(yytext);return(PLACED);}
	YY_BREAK
case 16:
YY_RULE_SETUP
//#line 38 "map.yy.l"
{return(START_HEADER);}    
	YY_BREAK
case 17:
YY_RULE_SETUP
//#line 39 "map.yy.l"
{return(END_HEADER);}    
	YY_BREAK
case 18:
YY_RULE_SETUP
//#line 41 "map.yy.l"
{return(BOARD_FILE);}
	YY_BREAK
case 19:
YY_RULE_SETUP
//#line 43 "map.yy.l"
{return(START_BOARD_OUTLINE);}    
	YY_BREAK
case 20:
YY_RULE_SETUP
//#line 44 "map.yy.l"
{return(END_BOARD_OUTLINE);}    
	YY_BREAK
case 21:
YY_RULE_SETUP
//#line 46 "map.yy.l"
{return(START_OTHER_OUTLINE);}    
	YY_BREAK
case 22:
YY_RULE_SETUP
//#line 47 "map.yy.l"
{return(END_OTHER_OUTLINE);}    
	YY_BREAK
case 23:
YY_RULE_SETUP
//#line 49 "map.yy.l"
{return(START_ROUTE_OUTLINE);}    
	YY_BREAK
case 24:
YY_RULE_SETUP
//#line 50 "map.yy.l"
{return(END_ROUTE_OUTLINE);}    
	YY_BREAK
case 25:
YY_RULE_SETUP
//#line 52 "map.yy.l"
{return(START_PLACE_OUTLINE);}    
	YY_BREAK
case 26:
YY_RULE_SETUP
//#line 53 "map.yy.l"
{return(END_PLACE_OUTLINE);}    
	YY_BREAK
case 27:
YY_RULE_SETUP
//#line 55 "map.yy.l"
{return(START_ROUTE_KEEPOUT);}    
	YY_BREAK
case 28:
YY_RULE_SETUP
//#line 56 "map.yy.l"
{return(END_ROUTE_KEEPOUT);}    
	YY_BREAK
case 29:
YY_RULE_SETUP
//#line 58 "map.yy.l"
{return(START_VIA_KEEPOUT);}    
	YY_BREAK
case 30:
YY_RULE_SETUP
//#line 59 "map.yy.l"
{return(END_VIA_KEEPOUT);}    
	YY_BREAK
case 31:
YY_RULE_SETUP
//#line 61 "map.yy.l"
{return(START_PLACE_REGION);}    
	YY_BREAK
case 32:
YY_RULE_SETUP
//#line 62 "map.yy.l"
{return(END_PLACE_REGION);}    
	YY_BREAK
case 33:
YY_RULE_SETUP
//#line 64 "map.yy.l"
{return(START_PLACE_KEEPOUT);}    
	YY_BREAK
case 34:
YY_RULE_SETUP
//#line 65 "map.yy.l"
{return(END_PLACE_KEEPOUT);}    
	YY_BREAK
case 35:
YY_RULE_SETUP
//#line 67 "map.yy.l"
{return(START_DRILLED_HOLES);}    
	YY_BREAK
case 36:
YY_RULE_SETUP
//#line 68 "map.yy.l"
{return(END_DRILLED_HOLES);}    
	YY_BREAK
case 37:
YY_RULE_SETUP
//#line 70 "map.yy.l"
{return(START_PLACEMENT);}    
	YY_BREAK
case 38:
YY_RULE_SETUP
//#line 71 "map.yy.l"
{return(END_PLACEMENT);}    
	YY_BREAK
case 39:
YY_RULE_SETUP
//#line 73 "map.yy.l"
{return(LIBRARY_FILE);}
	YY_BREAK
case 40:
YY_RULE_SETUP
//#line 75 "map.yy.l"
{return(START_ELECTRICAL);}    
	YY_BREAK
case 41:
YY_RULE_SETUP
//#line 76 "map.yy.l"
{return(END_ELECTRICAL);}    
	YY_BREAK
case 42:
YY_RULE_SETUP
//#line 78 "map.yy.l"
{return(START_MECHANICAL);}    
	YY_BREAK
case 43:
YY_RULE_SETUP
//#line 79 "map.yy.l"
{return(END_MECHANICAL);}    
	YY_BREAK
case 44:
YY_RULE_SETUP
//#line 81 "map.yy.l"
{yylval.SdaiString = strdup(yytext);return(RAWREAL);}
	YY_BREAK
case 45:
YY_RULE_SETUP
//#line 82 "map.yy.l"
{yylval.SdaiString = strdup(yytext);return(RAWREAL);}
	YY_BREAK
case 46:
YY_RULE_SETUP
//#line 83 "map.yy.l"
{yylval.SdaiString = strdup(yytext);return(RAWINTEGER);}
	YY_BREAK
case 47:
YY_RULE_SETUP
//#line 84 "map.yy.l"
{yylval.SdaiString = strdup(yytext);return(RAWINTEGER);}
	YY_BREAK
case 48:
YY_RULE_SETUP
//#line 86 "map.yy.l"
{yylval.SdaiString = "";return(STRING);}
	YY_BREAK
case 49:
YY_RULE_SETUP
//#line 87 "map.yy.l"
{yylval.SdaiString = StripQuotes(yytext);return(STRING);}
	YY_BREAK
case 50:
YY_RULE_SETUP
//#line 88 "map.yy.l"
{yylval.SdaiString = (char *)strdup(yytext);return(STRING);}
	YY_BREAK
case 51:
YY_RULE_SETUP
//#line 90 "map.yy.l"
{return(*yytext);}
	YY_BREAK
case 52:
YY_RULE_SETUP
//#line 91 "map.yy.l"
{return(*yytext);}
	YY_BREAK
case 53:
YY_RULE_SETUP
//#line 92 "map.yy.l"
{return(*yytext);}
	YY_BREAK
case 54:
YY_RULE_SETUP
//#line 93 "map.yy.l"
{linecount++;}
	YY_BREAK
case 55:
YY_RULE_SETUP
//#line 94 "map.yy.l"
{/* printf("Missed: '%s': %d on line %d.\n", yytext, *yytext,linecount);*/}
	YY_BREAK
case 56:
YY_RULE_SETUP
//#line 95 "map.yy.l"
ECHO;
	YY_BREAK
//#line 1103 "lex.yy.c"
case YY_STATE_EOF(INITIAL):
	yyterminate();

	case YY_END_OF_BUFFER:
		{
		/* Amount of text matched not including the EOB char. */
		int yy_amount_of_matched_text = (int) (yy_cp - yytext_ptr) - 1;

		/* Undo the effects of YY_DO_BEFORE_ACTION. */
		*yy_cp = yy_hold_char;
		YY_RESTORE_YY_MORE_OFFSET

		if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_NEW )
			{
			/* We're scanning a new file or input source.  It's
			 * possible that this happened because the user
			 * just pointed yyin at a new source and called
			 * yylex().  If so, then we have to assure
			 * consistency between yy_current_buffer and our
			 * globals.  Here is the right place to do so, because
			 * this is the first action (other than possibly a
			 * back-up) that will match for the new input source.
			 */
			yy_n_chars = yy_current_buffer->yy_n_chars;
			yy_current_buffer->yy_input_file = yyin;
			yy_current_buffer->yy_buffer_status = YY_BUFFER_NORMAL;
			}

		/* Note that here we test for yy_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since yy_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the
		 * end-of-buffer state).  Contrast this with the test
		 * in input().
		 */
		if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )
			{ /* This was really a NUL. */
			yy_state_type yy_next_state;

			yy_c_buf_p = yytext_ptr + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state();

			/* Okay, we're now positioned to make the NUL
			 * transition.  We couldn't have
			 * yy_get_previous_state() go ahead and do it
			 * for us because it doesn't know how to deal
			 * with the possibility of jamming (and we don't
			 * want to build jamming into it because then it
			 * will run more slowly).
			 */

			yy_next_state = yy_try_NUL_trans( yy_current_state );

			yy_bp = yytext_ptr + YY_MORE_ADJ;

			if ( yy_next_state )
				{
				/* Consume the NUL. */
				yy_cp = ++yy_c_buf_p;
				yy_current_state = yy_next_state;
				goto yy_match;
				}

			else
				{
				yy_cp = yy_c_buf_p;
				goto yy_find_action;
				}
			}

		else switch ( yy_get_next_buffer() )
			{
			case EOB_ACT_END_OF_FILE:
				{
				yy_did_buffer_switch_on_eof = 0;

				if ( yywrap() )
					{
					/* Note: because we've taken care in
					 * yy_get_next_buffer() to have set up
					 * yytext, we can now set up
					 * yy_c_buf_p so that if some total
					 * hoser (like flex itself) wants to
					 * call the scanner after we return the
					 * YY_NULL, it'll still work - another
					 * YY_NULL will get returned.
					 */
					yy_c_buf_p = yytext_ptr + YY_MORE_ADJ;

					yy_act = YY_STATE_EOF(YY_START);
					goto do_action;
					}

				else
					{
					if ( ! yy_did_buffer_switch_on_eof )
						YY_NEW_FILE;
					}
				break;
				}

			case EOB_ACT_CONTINUE_SCAN:
				yy_c_buf_p =
					yytext_ptr + yy_amount_of_matched_text;

				yy_current_state = yy_get_previous_state();

				yy_cp = yy_c_buf_p;
				yy_bp = yytext_ptr + YY_MORE_ADJ;
				goto yy_match;

			case EOB_ACT_LAST_MATCH:
				yy_c_buf_p =
				&yy_current_buffer->yy_ch_buf[yy_n_chars];

				yy_current_state = yy_get_previous_state();

				yy_cp = yy_c_buf_p;
				yy_bp = yytext_ptr + YY_MORE_ADJ;
				goto yy_find_action;
			}
		break;
		}

	default:
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	} /* end of action switch */
		} /* end of scanning one token */
	} /* end of yylex */


/* yy_get_next_buffer - try to read in a new buffer
 *
 * Returns a code representing an action:
 *	EOB_ACT_LAST_MATCH -
 *	EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *	EOB_ACT_END_OF_FILE - end of file
 */

int IDFToSdai::yy_get_next_buffer()
	{
	register char *dest = yy_current_buffer->yy_ch_buf;
	register char *source = yytext_ptr;
	register int number_to_move, i;
	int ret_val;

	if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
		YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

	if ( yy_current_buffer->yy_fill_buffer == 0 )
		{ /* Don't try to fill the buffer, so this is an EOF. */
		if ( yy_c_buf_p - yytext_ptr - YY_MORE_ADJ == 1 )
			{
			/* We matched a single character, the EOB, so
			 * treat this as a final EOF.
			 */
			return EOB_ACT_END_OF_FILE;
			}

		else
			{
			/* We matched some text prior to the EOB, first
			 * process it.
			 */
			return EOB_ACT_LAST_MATCH;
			}
		}

	/* Try to read more data. */

	/* First move last chars to start of buffer. */
	number_to_move = (int) (yy_c_buf_p - yytext_ptr) - 1;

	for ( i = 0; i < number_to_move; ++i )
		*(dest++) = *(source++);

	if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_EOF_PENDING )
		/* don't do the read, it's not guaranteed to return an EOF,
		 * just force an EOF
		 */
		yy_current_buffer->yy_n_chars = yy_n_chars = 0;

	else
		{
		int num_to_read =
			yy_current_buffer->yy_buf_size - number_to_move - 1;

		while ( num_to_read <= 0 )
			{ /* Not enough room in the buffer - grow it. */
#ifdef YY_USES_REJECT
			YY_FATAL_ERROR(
"input buffer overflow, can't enlarge buffer because scanner uses REJECT" );
#else

			/* just a shorter name for the current buffer */
			YY_BUFFER_STATE b = yy_current_buffer;

			int yy_c_buf_p_offset =
				(int) (yy_c_buf_p - b->yy_ch_buf);

			if ( b->yy_is_our_buffer )
				{
				int new_size = b->yy_buf_size * 2;

				if ( new_size <= 0 )
					b->yy_buf_size += b->yy_buf_size / 8;
				else
					b->yy_buf_size *= 2;

				b->yy_ch_buf = (char *)
					/* Include room in for 2 EOB chars. */
					yy_flex_realloc( (void *) b->yy_ch_buf,
							 b->yy_buf_size + 2 );
				}
			else
				/* Can't grow it, we don't own it. */
				b->yy_ch_buf = 0;

			if ( ! b->yy_ch_buf )
				YY_FATAL_ERROR(
				"fatal error - scanner input buffer overflow" );

			yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];

			num_to_read = yy_current_buffer->yy_buf_size -
						number_to_move - 1;
#endif
			}

		if ( num_to_read > YY_READ_BUF_SIZE )
			num_to_read = YY_READ_BUF_SIZE;

		/* Read in more data. */
		YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),
			yy_n_chars, num_to_read );

		yy_current_buffer->yy_n_chars = yy_n_chars;
		}

	if ( yy_n_chars == 0 )
		{
		if ( number_to_move == YY_MORE_ADJ )
			{
			ret_val = EOB_ACT_END_OF_FILE;
			yyrestart( yyin );
			}

		else
			{
			ret_val = EOB_ACT_LAST_MATCH;
			yy_current_buffer->yy_buffer_status =
				YY_BUFFER_EOF_PENDING;
			}
		}

	else
		ret_val = EOB_ACT_CONTINUE_SCAN;

	yy_n_chars += number_to_move;
	yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;
	yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;

	yytext_ptr = &yy_current_buffer->yy_ch_buf[0];

	return ret_val;
	}


/* yy_get_previous_state - get the state just before the EOB char was reached */

yy_state_type IDFToSdai::yy_get_previous_state()
	{
	register yy_state_type yy_current_state;
	register char *yy_cp;

	yy_current_state = yy_start;
	yy_current_state += YY_AT_BOL();

	for ( yy_cp = yytext_ptr + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )
		{
		register YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
		if ( yy_accept[yy_current_state] )
			{
			yy_last_accepting_state = yy_current_state;
			yy_last_accepting_cpos = yy_cp;
			}
		while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
			{
			yy_current_state = (int) yy_def[yy_current_state];
			if ( yy_current_state >= 354 )
				yy_c = yy_meta[(unsigned int) yy_c];
			}
		yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
		}

	return yy_current_state;
	}


/* yy_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *	next_state = yy_try_NUL_trans( current_state );
 */

#ifdef YY_USE_PROTOS
static yy_state_type yy_try_NUL_trans( yy_state_type yy_current_state )
#else
static yy_state_type yy_try_NUL_trans( yy_current_state )
yy_state_type yy_current_state;
#endif
	{
	register int yy_is_jam;
	register char *yy_cp = yy_c_buf_p;

	register YY_CHAR yy_c = 1;
	if ( yy_accept[yy_current_state] )
		{
		yy_last_accepting_state = yy_current_state;
		yy_last_accepting_cpos = yy_cp;
		}
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = (int) yy_def[yy_current_state];
		if ( yy_current_state >= 354 )
			yy_c = yy_meta[(unsigned int) yy_c];
		}
	yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
	yy_is_jam = (yy_current_state == 353);

	return yy_is_jam ? 0 : yy_current_state;
	}


#ifndef YY_NO_UNPUT
#ifdef YY_USE_PROTOS
void IDFToSdai::yyunput( int c, register char *yy_bp )
#else
static void yyunput( c, yy_bp )
int c;
register char *yy_bp;
#endif
	{
	register char *yy_cp = yy_c_buf_p;

	/* undo effects of setting up yytext */
	*yy_cp = yy_hold_char;

	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
		{ /* need to shift things up to make room */
		/* +2 for EOB chars. */
		register int number_to_move = yy_n_chars + 2;
		register char *dest = &yy_current_buffer->yy_ch_buf[
					yy_current_buffer->yy_buf_size + 2];
		register char *source =
				&yy_current_buffer->yy_ch_buf[number_to_move];

		while ( source > yy_current_buffer->yy_ch_buf )
			*--dest = *--source;

		yy_cp += (int) (dest - source);
		yy_bp += (int) (dest - source);
		yy_current_buffer->yy_n_chars =
			yy_n_chars = yy_current_buffer->yy_buf_size;

		if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
			YY_FATAL_ERROR( "flex scanner push-back overflow" );
		}

	*--yy_cp = (char) c;


	yytext_ptr = yy_bp;
	yy_hold_char = *yy_cp;
	yy_c_buf_p = yy_cp;
	}
#endif	/* ifndef YY_NO_UNPUT */


#ifdef __cplusplus
int IDFToSdai::yyinput()
#else
static int input()
#endif
	{
	int c;

	*yy_c_buf_p = yy_hold_char;

	if ( *yy_c_buf_p == YY_END_OF_BUFFER_CHAR )
		{
		/* yy_c_buf_p now points to the character we want to return.
		 * If this occurs *before* the EOB characters, then it's a
		 * valid NUL; if not, then we've hit the end of the buffer.
		 */
		if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )
			/* This was really a NUL. */
			*yy_c_buf_p = '\0';

		else
			{ /* need more input */
			int offset = yy_c_buf_p - yytext_ptr;
			++yy_c_buf_p;

			switch ( yy_get_next_buffer() )
				{
				case EOB_ACT_LAST_MATCH:
					/* This happens because yy_g_n_b()
					 * sees that we've accumulated a
					 * token and flags that we need to
					 * try matching the token before
					 * proceeding.  But for input(),
					 * there's no matching to consider.
					 * So convert the EOB_ACT_LAST_MATCH
					 * to EOB_ACT_END_OF_FILE.
					 */

					/* Reset buffer status. */
					yyrestart( yyin );

					/* fall through */

				case EOB_ACT_END_OF_FILE:
					{
					if ( yywrap() )
						return EOF;

					if ( ! yy_did_buffer_switch_on_eof )
						YY_NEW_FILE;
#ifdef __cplusplus
					return yyinput();
#else
					return input();
#endif
					}

				case EOB_ACT_CONTINUE_SCAN:
					yy_c_buf_p = yytext_ptr + offset;
					break;
				}
			}
		}

	c = *(unsigned char *) yy_c_buf_p;	/* cast for 8-bit char's */
	*yy_c_buf_p = '\0';	/* preserve yytext */
	yy_hold_char = *++yy_c_buf_p;

	yy_current_buffer->yy_at_bol = (c == '\n');

	return c;
	}


#ifdef YY_USE_PROTOS
void IDFToSdai::yyrestart( FILE *input_file )
#else
void yyrestart( input_file )
FILE *input_file;
#endif
	{
	if ( ! yy_current_buffer )
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE );

	yy_init_buffer( yy_current_buffer, input_file );
	yy_load_buffer_state();
	}


#ifdef YY_USE_PROTOS
void IDFToSdai::yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )
#else
void yy_switch_to_buffer( new_buffer )
YY_BUFFER_STATE new_buffer;
#endif
	{
	if ( yy_current_buffer == new_buffer )
		return;

	if ( yy_current_buffer )
		{
		/* Flush out information for old buffer. */
		*yy_c_buf_p = yy_hold_char;
		yy_current_buffer->yy_buf_pos = yy_c_buf_p;
		yy_current_buffer->yy_n_chars = yy_n_chars;
		}

	yy_current_buffer = new_buffer;
	yy_load_buffer_state();

	/* We don't actually know whether we did this switch during
	 * EOF (yywrap()) processing, but the only time this flag
	 * is looked at is after yywrap() is called, so it's safe
	 * to go ahead and always set it.
	 */
	yy_did_buffer_switch_on_eof = 1;
	}


#ifdef YY_USE_PROTOS
void IDFToSdai::yy_load_buffer_state( void )
#else
void yy_load_buffer_state()
#endif
	{
	yy_n_chars = yy_current_buffer->yy_n_chars;
	yytext_ptr = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
	yyin = yy_current_buffer->yy_input_file;
	yy_hold_char = *yy_c_buf_p;
	}


#ifdef YY_USE_PROTOS
YY_BUFFER_STATE IDFToSdai::yy_create_buffer( FILE *file, int size )
#else
YY_BUFFER_STATE yy_create_buffer( file, size )
FILE *file;
int size;
#endif
	{
	YY_BUFFER_STATE b;

	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );
	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_buf_size = size;

	/* yy_ch_buf has to be 2 characters longer than the size given because
	 * we need to put in 2 end-of-buffer characters.
	 */
	b->yy_ch_buf = (char *) yy_flex_alloc( b->yy_buf_size + 2 );
	if ( ! b->yy_ch_buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_is_our_buffer = 1;

	yy_init_buffer( b, file );

	return b;
	}


#ifdef YY_USE_PROTOS
void IDFToSdai::yy_delete_buffer( YY_BUFFER_STATE b )
#else
void yy_delete_buffer( b )
YY_BUFFER_STATE b;
#endif
	{
	if ( ! b )
		return;

	if ( b == yy_current_buffer )
		yy_current_buffer = (YY_BUFFER_STATE) 0;

	if ( b->yy_is_our_buffer )
		yy_flex_free( (void *) b->yy_ch_buf );

	yy_flex_free( (void *) b );
	}


#ifndef YY_ALWAYS_INTERACTIVE
#ifndef YY_NEVER_INTERACTIVE
extern int isatty YY_PROTO(( int ));
#endif
#endif

#ifdef YY_USE_PROTOS
void IDFToSdai::yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
#else
void yy_init_buffer( b, file )
YY_BUFFER_STATE b;
FILE *file;
#endif


	{
	yy_flush_buffer( b );

	b->yy_input_file = file;
	b->yy_fill_buffer = 1;

#if YY_ALWAYS_INTERACTIVE
	b->yy_is_interactive = 1;
#else
#if YY_NEVER_INTERACTIVE
	b->yy_is_interactive = 0;
#else
	b->yy_is_interactive = file ? (isatty( fileno(file) ) > 0) : 0;
#endif
#endif
	}


#ifdef YY_USE_PROTOS
void IDFToSdai::yy_flush_buffer( YY_BUFFER_STATE b )
#else
void yy_flush_buffer( b )
YY_BUFFER_STATE b;
#endif

	{
	if ( ! b )
		return;

	b->yy_n_chars = 0;

	/* We always need two end-of-buffer characters.  The first causes
	 * a transition to the end-of-buffer state.  The second causes
	 * a jam in that state.
	 */
	b->yy_ch_buf[0] = YY_END_OF_BUFFER_CHAR;
	b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;

	b->yy_buf_pos = &b->yy_ch_buf[0];

	b->yy_at_bol = 1;
	b->yy_buffer_status = YY_BUFFER_NEW;

	if ( b == yy_current_buffer )
		yy_load_buffer_state();
	}


#ifndef YY_NO_SCAN_BUFFER
#ifdef YY_USE_PROTOS
YY_BUFFER_STATE IDFToSdai::yy_scan_buffer( char *base, yy_size_t size )
#else
YY_BUFFER_STATE yy_scan_buffer( base, size )
char *base;
yy_size_t size;
#endif
	{
	YY_BUFFER_STATE b;

	if ( size < 2 ||
	     base[size-2] != YY_END_OF_BUFFER_CHAR ||
	     base[size-1] != YY_END_OF_BUFFER_CHAR )
		/* They forgot to leave room for the EOB's. */
		return 0;

	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );
	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_scan_buffer()" );

	b->yy_buf_size = size - 2;	/* "- 2" to take care of EOB's */
	b->yy_buf_pos = b->yy_ch_buf = base;
	b->yy_is_our_buffer = 0;
	b->yy_input_file = 0;
	b->yy_n_chars = b->yy_buf_size;
	b->yy_is_interactive = 0;
	b->yy_at_bol = 1;
	b->yy_fill_buffer = 0;
	b->yy_buffer_status = YY_BUFFER_NEW;

	yy_switch_to_buffer( b );

	return b;
	}
#endif


#ifndef YY_NO_SCAN_STRING
#ifdef YY_USE_PROTOS
YY_BUFFER_STATE IDFToSdai::yy_scan_string( yyconst char *yy_str )
#else
YY_BUFFER_STATE yy_scan_string( yy_str )
yyconst char *yy_str;
#endif
	{
	int len;
	for ( len = 0; yy_str[len]; ++len )
		;

	return yy_scan_bytes( yy_str, len );
	}
#endif


#ifndef YY_NO_SCAN_BYTES
#ifdef YY_USE_PROTOS
YY_BUFFER_STATE yy_scan_bytes( yyconst char *bytes, int len )
#else
YY_BUFFER_STATE yy_scan_bytes( bytes, len )
yyconst char *bytes;
int len;
#endif
	{
	YY_BUFFER_STATE b;
	char *buf;
	yy_size_t n;
	int i;

	/* Get memory for full buffer, including space for trailing EOB's. */
	n = len + 2;
	buf = (char *) yy_flex_alloc( n );
	if ( ! buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_scan_bytes()" );

	for ( i = 0; i < len; ++i )
		buf[i] = bytes[i];

	buf[len] = buf[len+1] = YY_END_OF_BUFFER_CHAR;

	b = yy_scan_buffer( buf, n );
	if ( ! b )
		YY_FATAL_ERROR( "bad buffer in yy_scan_bytes()" );

	/* It's okay to grow etc. this buffer, and we should throw it
	 * away when we're done.
	 */
	b->yy_is_our_buffer = 1;

	return b;
	}
#endif


#ifndef YY_NO_PUSH_STATE
#ifdef YY_USE_PROTOS
static void yy_push_state( int new_state )
#else
static void yy_push_state( new_state )
int new_state;
#endif
	{
	if ( yy_start_stack_ptr >= yy_start_stack_depth )
		{
		yy_size_t new_size;

		yy_start_stack_depth += YY_START_STACK_INCR;
		new_size = yy_start_stack_depth * sizeof( int );

		if ( ! yy_start_stack )
			yy_start_stack = (int *) yy_flex_alloc( new_size );

		else
			yy_start_stack = (int *) yy_flex_realloc(
					(void *) yy_start_stack, new_size );

		if ( ! yy_start_stack )
			YY_FATAL_ERROR(
			"out of memory expanding start-condition stack" );
		}

	yy_start_stack[yy_start_stack_ptr++] = YY_START;

	BEGIN(new_state);
	}
#endif


#ifndef YY_NO_POP_STATE
static void yy_pop_state()
	{
	if ( --yy_start_stack_ptr < 0 )
		YY_FATAL_ERROR( "start-condition stack underflow" );

	BEGIN(yy_start_stack[yy_start_stack_ptr]);
	}
#endif


#ifndef YY_NO_TOP_STATE
static int yy_top_state()
	{
	return yy_start_stack[yy_start_stack_ptr - 1];
	}
#endif

#ifndef YY_EXIT_FAILURE
#define YY_EXIT_FAILURE 2
#endif

#ifdef YY_USE_PROTOS
static void yy_fatal_error( yyconst char msg[] )
#else
static void yy_fatal_error( msg )
char msg[];
#endif
	{
//	(void) TRACE("%s\n", msg );
	TRACE("%s\n", msg );
	exit( YY_EXIT_FAILURE );
	}



/* Redefine yyless() so it works in section 3 code. */

#undef yyless
#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		yytext[yyleng] = yy_hold_char; \
		yy_c_buf_p = yytext + n; \
		yy_hold_char = *yy_c_buf_p; \
		*yy_c_buf_p = '\0'; \
		yyleng = n; \
		} \
	while ( 0 )


/* Internal utility routines. */

#ifndef yytext_ptr
#ifdef YY_USE_PROTOS
static void yy_flex_strncpy( char *s1, yyconst char *s2, int n )
#else
static void yy_flex_strncpy( s1, s2, n )
char *s1;
yyconst char *s2;
int n;
#endif
	{
	register int i;
	for ( i = 0; i < n; ++i )
		s1[i] = s2[i];
	}
#endif

#ifdef YY_NEED_STRLEN
#ifdef YY_USE_PROTOS
static int yy_flex_strlen( yyconst char *s )
#else
static int yy_flex_strlen( s )
yyconst char *s;
#endif
	{
	register int n;
	for ( n = 0; s[n]; ++n )
		;

	return n;
	}
#endif


#ifdef YY_USE_PROTOS
static void *yy_flex_alloc( yy_size_t size )
#else
static void *yy_flex_alloc( size )
yy_size_t size;
#endif
	{
	return (void *) malloc( size );
	}

#ifdef YY_USE_PROTOS
static void *yy_flex_realloc( void *ptr, yy_size_t size )
#else
static void *yy_flex_realloc( ptr, size )
void *ptr;
yy_size_t size;
#endif
	{
	/* The cast to (char *) in the following accommodates both
	 * implementations that use char* generic pointers, and those
	 * that use void* generic pointers.  It works with the latter
	 * because both ANSI C and C++ allow castless assignment from
	 * any pointer type to void*, and deal with argument conversions
	 * as though doing an assignment.
	 */
	return (void *) realloc( (char *) ptr, size );
	}

#ifdef YY_USE_PROTOS
static void yy_flex_free( void *ptr )
#else
static void yy_flex_free( ptr )
void *ptr;
#endif
	{
	free( ptr );
	}

#if YY_MAIN
int main()
	{
	yylex();
	return 0;
	}
#endif
//#line 95 "map.yy.l"


char *StripQuotes(char *str)
   {
   char *result;

   /* remove quotes */
   result = (char *)strdup(&str[1]);
   result[strlen(result)-1] = '\0';

   return(result);
   }

int IDFToSdai::yywrap()
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
      TRACE("ERROR: Can't open %s.\n", second_file);
      return 1;
      }
   current_file = second_file;
   fclose(yyin);
   yyin = temp;
   linecount = 1;
   return 0;
   }
/* provide a yyerror that gives the line number of the error. */
void IDFToSdai::yyerror(char *error)
   {
   char s[1024];
   int count = 1;
   char c;
   TRACE(error);
   TRACE(" near line %d of %s.\n", linecount, current_file);
   rewind(yyin);
   sprintf(s, "%s near line %d of %s.", error, linecount, current_file);
   AfxMessageBox(s,  MB_OK | MB_ICONSTOP | MB_APPLMODAL);

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
            TRACE("%d: ", count);
            }
         }
      }
   }

