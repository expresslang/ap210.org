/*
 * $Id: map.y,v 1.5 1998/10/23 20:27:21 keenan Exp $
*/
%union
{
char charval;
char *SdaiString;
char *SdaiEnumeration;
double SdaiReal;
int SdaiInteger;
struct Sdai_Id* SdaiInstance;
struct InstanceList *List;
struct OutlineAndCutouts *OutlineAndCutouts;
}

%{
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/* This is useful for a developer but confusing for a end user.
#define YYERROR_VERBOSE
*/
#include <sdai.h>

extern SdaiModel myModel;
extern char *OriginatingSystem;

void yyerror(char *error);
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


%}
%token <SdaiString> STRING
%type <SdaiReal> real
%token <SdaiString> RAWREAL 
%type <SdaiInteger> integer 
%token <SdaiString> RAWINTEGER 
%token START_HEADER
%token END_HEADER

%token BOARD_FILE

/* all of these keywords need to be rolled back into a string 
   since they are not reserved keywords */
/* units */
%token <SdaiEnumeration> MM
%token <SdaiEnumeration> TNM
%token <SdaiEnumeration> THOU

/* layers */
%token <SdaiEnumeration> TOP
%token <SdaiEnumeration> BOTTOM
%token <SdaiEnumeration> BOTH
%token <SdaiEnumeration> ALL

/* hole type */
%token <SdaiEnumeration> PTH
%token <SdaiEnumeration> NPTH

/* associated part */
%token <SdaiEnumeration> BOARD
%token <SdaiEnumeration> NOREFDES

/* placement status */
%token <SdaiEnumeration> FIXED
%token <SdaiEnumeration> UNPLACED
%token <SdaiEnumeration> PLACED

%token START_BOARD_OUTLINE
%token END_BOARD_OUTLINE

%token START_OTHER_OUTLINE
%token END_OTHER_OUTLINE

%token START_ROUTE_OUTLINE
%token END_ROUTE_OUTLINE

%token START_PLACE_OUTLINE
%token END_PLACE_OUTLINE

%token START_ROUTE_KEEPOUT
%token END_ROUTE_KEEPOUT

%token START_VIA_KEEPOUT
%token END_VIA_KEEPOUT

%token START_PLACE_KEEPOUT
%token END_PLACE_KEEPOUT

%token START_PLACE_REGION
%token END_PLACE_REGION

%token START_DRILLED_HOLES
%token END_DRILLED_HOLES

%token START_PLACEMENT
%token END_PLACEMENT

%token '/'
%token '.'
%token ':'

%token LIBRARY_FILE 

%token START_ELECTRICAL
%token END_ELECTRICAL

%token START_MECHANICAL
%token END_MECHANICAL

%type <SdaiString> any_string

%type <SdaiInstance> idf_data

%type <SdaiInstance> board_data

%type <SdaiInstance> board_header
%type <SdaiString> idf_version_number
%type <SdaiString> source_system_identification
%type <SdaiString> date
%type <SdaiInteger> board_file_version
%type <SdaiString> board_name

%type <SdaiEnumeration> units_definition_enumeration
%type <SdaiEnumeration> placement_status_enumeration
%type <SdaiEnumeration> top_or_bottom_enumeration
%type <SdaiEnumeration> outer_layers_enumeration
%type <SdaiEnumeration> inner_and_outer_layer_enumeration

%type <SdaiInstance> board_outline
%type <SdaiReal> board_thickness

%type <SdaiInstance> other_outline
%type <SdaiReal> extrude_thickness

%type <SdaiInstance> route_outline

%type <SdaiInstance> place_outline

%type <SdaiInstance> route_keepout

%type <SdaiInstance> via_keepout

%type <SdaiInstance> place_keepout
%type <SdaiReal> comp_height

%type <SdaiInstance> place_region

%type <List> board_drilled_holes
%type <SdaiInstance> drilled_holes
%type <SdaiEnumeration> hole_type_enumeration
%type <SdaiString> associated_part_string

%type <List> board_placement
%type <SdaiInstance> placement
%type <SdaiString> reference_designator


%type <SdaiInstance> library_data

%type <SdaiInstance> library_header
%type <SdaiInteger>  library_file_version
%type <SdaiInstance> electrical
%type <SdaiInstance> mechanical

%type <OutlineAndCutouts> loop
%type<SdaiInteger> loop_label

%type <SdaiInstance> arc
%type <SdaiReal> angle

%start idf_data 
%%
idf_data : board_data
           { 
           $$ = sdaiCreateInstanceBN (myModel, "idf_data");
           sdaiPutAttrBN ($$, "board_file", sdaiINSTANCE, $1);
           } 
         | idf_data board_data
           { 
           $$ = $1;
           sdaiPutAttrBN ($$, "board_file", sdaiINSTANCE, $2);
           } 
         | library_data
           { 
           $$ = sdaiCreateInstanceBN (myModel, "idf_data");
           sdaiPutAttrBN ($$, "library_file", sdaiINSTANCE, $1);
           } 
         | idf_data library_data
           { 
           $$ = $1;
           sdaiPutAttrBN ($$, "library_file", sdaiINSTANCE, $2);
           }

board_data : board_header
             { 
             $$ = sdaiCreateInstanceBN (myModel, "board_data");
             sdaiPutAttrBN ($$, "board_board_header", sdaiINSTANCE, $1);
             }
           | board_data board_outline
             { 
             $$ = $1;
             sdaiPutAttrBN ($$, "board_board_outline", sdaiINSTANCE, $2);
             }
           | board_data other_outline
             { 
             $$ = $1;
             MTKsdaiInsertAfterBN($$, "board_other_outline", sdaiINSTANCE, $2);
             }
           | board_data route_outline
             { 
             $$ = $1;
             MTKsdaiInsertAfterBN($$, "board_route_outline", sdaiINSTANCE, $2);
             }
           | board_data place_outline 
             { 
             $$ = $1;
             MTKsdaiInsertAfterBN($$, "board_place_outline", sdaiINSTANCE, $2);
             }
           | board_data route_keepout
             { 
             $$ = $1;
             MTKsdaiInsertAfterBN($$, "board_route_keepout", sdaiINSTANCE, $2);
             }
           | board_data via_keepout
             { 
             $$ = $1;
             MTKsdaiInsertAfterBN($$, "board_via_keepout", sdaiINSTANCE, $2);
             }
            | board_data place_keepout
             { 
             $$ = $1;
             MTKsdaiInsertAfterBN($$, "board_place_keepout", sdaiINSTANCE, $2);
             }
          | board_data place_region
             { 
             $$ = $1;
             MTKsdaiInsertAfterBN($$, "board_place_region", sdaiINSTANCE, $2);
             }
           | board_data board_drilled_holes 
             {
             struct InstanceList *list = $2; 
             $$ = $1;

             while(list != NULL)
                {
                MTKsdaiInsertAfterBN($$, "board_drilled_holes", sdaiINSTANCE, list->instance);
                list = list->next;
                }
             }
           | board_data board_placement 
             { 
             struct InstanceList *list = $2; 
             $$ = $1;

             while(list != NULL)
                {
                MTKsdaiInsertAfterBN($$, "board_placement", sdaiINSTANCE, list->instance);
                list = list->next;
                }
             }

board_header : START_HEADER 
               BOARD_FILE 
               idf_version_number 
               source_system_identification 
               date 
               board_file_version
               board_name
               units_definition_enumeration
               END_HEADER
               {
               $$ = sdaiCreateInstanceBN (myModel, "board_header");
               sdaiPutAttrBN ($$, "idf_version_number", sdaiSTRING, $3);
               sdaiPutAttrBN ($$, "source_system_identification", sdaiSTRING, $4);
               OriginatingSystem = (char *)strdup($4);

               sdaiPutAttrBN ($$, "date", sdaiSTRING, $5);

               sdaiPutAttrBN ($$, "board_file_version", sdaiINTEGER, $6);
               sdaiPutAttrBN ($$, "board_name", sdaiSTRING, $7);
               sdaiPutAttrBN ($$, "units_definition", sdaiENUM, $8);
               } 

idf_version_number : RAWREAL 
                     { $$ = $1; } 

source_system_identification : any_string
                               { $$ = $1; }

/* use STRING for date since non of the "pseduo keywords" are a valid date. */
date : STRING 
       { $$ = $1; }

board_file_version : integer 
                     { $$ = $1; }

board_name : any_string
             { $$ = $1; }

/* required because IDF doesn't reserved keywords */
any_string : STRING
             { $$ = $1; }
           | MM
             { $$ = $1; }
           | TNM
             { $$ = $1; }
           | THOU
             { $$ = $1; }
           | TOP
             { $$ = $1; }
           | BOTTOM
             { $$ = $1; }
           | BOTH
             { $$ = $1; }
           | ALL
             { $$ = $1; }
           | PTH
             { $$ = $1; }
           | NPTH
             { $$ = $1; }
           | BOARD
             { $$ = $1; }
           | NOREFDES
             { $$ = $1; }
           | FIXED
             { $$ = $1; }
           | UNPLACED
             { $$ = $1; }
           | PLACED
             { $$ = $1; }


units_definition_enumeration : MM 
                   { $$ = $1; }
                 | TNM
                   { $$ = $1; }
                 | THOU
                   { $$ = $1; }

board_outline : START_BOARD_OUTLINE board_thickness loop END_BOARD_OUTLINE
                { 
                $$ = sdaiCreateInstanceBN (myModel, "board_outline");
                sdaiPutAttrBN($$, "board_thickness", sdaiREAL, $2);
                sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $3->outline);                

                /* Add cutouts if present */
                if ($3->cutouts != NULL)
                   {
                   struct InstanceList *list = $3->cutouts; 

                   while(list != NULL)
                      {
                      MTKsdaiInsertAfterBN($$, "cutouts", sdaiINSTANCE, list->instance);
                      list = list->next;
                      }
                  }
               }

board_thickness : real 
                  { /* must be positive */
                  $$ = $1;
                  }

other_outline : START_OTHER_OUTLINE any_string extrude_thickness loop END_OTHER_OUTLINE
                { 
                $$ = sdaiCreateInstanceBN (myModel, "other_outline");
                sdaiPutAttrBN($$, "outline_identifier", sdaiSTRING, $2);
                sdaiPutAttrBN($$, "extrude_thickness", sdaiREAL, $3);
                sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $4->outline);                

                /* Add cutouts if present */
                if ($4->cutouts != NULL)
                   {
                   struct InstanceList *list = $4->cutouts; 

                   while(list != NULL)
                      {
                      MTKsdaiInsertAfterBN($$, "cutouts", sdaiINSTANCE, list->instance);
                      list = list->next;
                      }
                  }

                }
         
extrude_thickness : real 
                    { /* must be positive */
                    $$ = $1;
                    }

route_outline : START_ROUTE_OUTLINE loop END_ROUTE_OUTLINE
                { 
                $$ = sdaiCreateInstanceBN (myModel, "route_outline");
                sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $2->outline);                
                }
         
place_outline : START_PLACE_OUTLINE loop END_PLACE_OUTLINE
                { 
                $$ = sdaiCreateInstanceBN (myModel, "place_outline");
                sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $2->outline);                
                }
         
route_keepout : START_ROUTE_KEEPOUT inner_and_outer_layer_enumeration loop END_ROUTE_KEEPOUT
                { 
                $$ = sdaiCreateInstanceBN (myModel, "route_keepout");
                sdaiPutAttrBN($$, "routing_layers", sdaiENUM, $2);                
                sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $3->outline);                
                }
         
inner_and_outer_layer_enumeration : TOP
                                    { $$ = $1; }
                                  | BOTTOM
                                    { $$ = $1; }
                                  | BOTH
                                    { $$ = $1; }
                                  | ALL
                                    { $$ = $1; }

via_keepout : START_VIA_KEEPOUT loop END_VIA_KEEPOUT
                { 
                $$ = sdaiCreateInstanceBN (myModel, "via_keepout");
                sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $2->outline);                
                }
         
place_region : START_PLACE_REGION outer_layers_enumeration any_string loop END_PLACE_REGION
               {
               $$ = sdaiCreateInstanceBN (myModel, "place_region");
               sdaiPutAttrBN($$, "board_side", sdaiENUM, $2);
               sdaiPutAttrBN($$, "component_group_name", sdaiSTRING, $3);
               sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $4->outline);                
               }

outer_layers_enumeration : TOP
                           { $$ = $1; }
                         | BOTTOM
                           { $$ = $1; }
                         | BOTH
                           { $$ = $1; }

place_keepout : START_PLACE_KEEPOUT outer_layers_enumeration comp_height comp_height loop END_PLACE_KEEPOUT
                { 
                $$ = sdaiCreateInstanceBN (myModel, "place_keepout");

                sdaiPutAttrBN($$, "board_side", sdaiENUM, $2);
                sdaiPutAttrBN($$, "maximum_height", sdaiREAL, $3);
                sdaiPutAttrBN($$, "minimum_height", sdaiREAL, $4);
                sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $5->outline);                
                }

/* only real according to specification but integers in example */
comp_height : real
              { $$ = $1; }
            | integer
              { $$ = $1; }
         
/* the express collapses all the arcs in a given loop into one structure */
loop : loop_label arc
       { 
       /* create a loop here */
       $$ = (struct OutlineAndCutouts *)calloc(1, sizeof(struct OutlineAndCutouts));
       $$->current_loop_label = $1;
       $$->outline = sdaiCreateInstanceBN (myModel, "loop");
       $$->current_loop = $$->outline;

       sdaiPutAttrBN ($$->current_loop, "loop_label", sdaiINTEGER, $1);
       MTKsdaiInsertAfterBN($$->current_loop, "closed_curve", sdaiINSTANCE, $2);
       }
     | loop loop_label arc 
       { 
       if ($$->current_loop_label == $2)
          {
          $$ = $1;
          MTKsdaiInsertAfterBN($$->current_loop, "closed_curve", sdaiINSTANCE, $3);
          }
       else
          {
          /* create a loop here */
          $$->current_loop_label = $2; 
          $$->current_loop = sdaiCreateInstanceBN (myModel, "loop");
          sdaiPutAttrBN ($$->current_loop, "loop_label", sdaiINTEGER, $2);
          MTKsdaiInsertAfterBN($$->current_loop, "closed_curve", sdaiINSTANCE, $3);
          if ($$->cutouts == NULL)
             {
             $$->cutouts = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
             $$->cutouts->instance = $$->current_loop;
             }
          else
             {
             struct InstanceList *last;
             last = $$->cutouts;

             while(last->next != NULL)
                 {
                 last = last->next;
                 }
             last->next = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
             last = last->next;
             last->instance = $$->current_loop;
             }
          } 
       }
/* must be positive? */
loop_label : integer
             { $$ = $1; }

arc : real real angle 
      {
      $$ = sdaiCreateInstanceBN (myModel, "arc");

      sdaiPutAttrBN ($$, "x_coord", sdaiREAL, $1);
      sdaiPutAttrBN ($$, "y_coord", sdaiREAL, $2);
      sdaiPutAttrBN ($$, "included_angle", sdaiREAL, $3);
      }

/* only real according to specification but integers in library example */
angle : real
        { $$ = $1; }
      | integer
        { $$ = $1; }
/* Since many drilled holes are defined between the
   START_DRILLED_HOLES and END_DRILL_HOLES keywords a list
   is required to hold them until board_drilled_holes fires a rule
   in board_data. */
board_drilled_holes : START_DRILLED_HOLES drilled_holes
                      {
                      $$ = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
                      $$->instance = $2;
                      }
                    | board_drilled_holes drilled_holes
                      {
                      struct InstanceList *last;
                      $$ = $1;
                      last = $$;

                      while(last->next != NULL)
                         {
                         last = last->next;
                         }
                      last->next = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
                      last = last->next;
                      last->instance = $2;
                      }
                    | board_drilled_holes END_DRILLED_HOLES
                      { $$ = $1; }

drilled_holes : real real real hole_type_enumeration associated_part_string
                { 
                $$ = sdaiCreateInstanceBN (myModel, "drilled_holes");
                sdaiPutAttrBN ($$, "hole_diameter", sdaiREAL, $1);
                sdaiPutAttrBN ($$, "x_coord", sdaiREAL, $2);
                sdaiPutAttrBN ($$, "y_coord", sdaiREAL, $3);
                sdaiPutAttrBN($$, "hole_type", sdaiENUM, $4);
                sdaiPutAttrBN ($$, "associated_part_string", sdaiSTRING, $5);
                }

hole_type_enumeration : PTH
                        { $$ = $1; }
                      | NPTH
                        { $$ = $1; }

associated_part_string : BOARD  /* hopefully BOARD and NOREDES will be picked up */
                         { $$ = $1; }
                       | NOREFDES
                         { $$ = $1; }
                       | any_string 
                         { $$ = $1; }

board_placement : START_PLACEMENT placement
                  { 
                  $$ = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
                  $$->instance = $2;
                  }
                | START_PLACEMENT END_PLACEMENT
                  {
                  $$ = NULL;
                  }
                | board_placement placement
                  {
                  struct InstanceList *last;
                  $$ = $1;
                  last = $$;

                  while(last->next != NULL)
                      {
                      last = last->next;
                      }
                  last->next = (struct InstanceList *)calloc(1, sizeof(struct InstanceList));
                  last = last->next;
                  last->instance = $2;
                  }
                | board_placement END_PLACEMENT
                  { $$ = $1; }

placement : any_string any_string reference_designator real real real top_or_bottom_enumeration placement_status_enumeration
            { 
            $$ = sdaiCreateInstanceBN (myModel, "placement");
            sdaiPutAttrBN ($$, "package_name", sdaiSTRING, $1);
            sdaiPutAttrBN ($$, "part_number", sdaiSTRING, $2);
            sdaiPutAttrBN ($$, "reference_designator", sdaiSTRING, $3);
            sdaiPutAttrBN ($$, "x_coord", sdaiREAL, $4);
            sdaiPutAttrBN ($$, "y_coord", sdaiREAL, $5);
            sdaiPutAttrBN ($$, "rotation_angle", sdaiREAL, $6);
            sdaiPutAttrBN ($$, "side_of_board", sdaiENUM, $7);
            sdaiPutAttrBN ($$, "placement_status", sdaiENUM, $8);
            }
          | any_string any_string reference_designator real real real top_or_bottom_enumeration 
            { 
            $$ = sdaiCreateInstanceBN (myModel, "placement");
            sdaiPutAttrBN ($$, "package_name", sdaiSTRING, $1);
            sdaiPutAttrBN ($$, "part_number", sdaiSTRING, $2);
            sdaiPutAttrBN ($$, "reference_designator", sdaiSTRING, $3);
            sdaiPutAttrBN ($$, "x_coord", sdaiREAL, $4);
            sdaiPutAttrBN ($$, "y_coord", sdaiREAL, $5);
            sdaiPutAttrBN ($$, "rotation_angle", sdaiREAL, $6);
            sdaiPutAttrBN ($$, "side_of_board", sdaiENUM, $7);
            }

reference_designator : any_string 
                       { $$ = $1; }
                     | NOREFDES
                       { $$ = $1; }

top_or_bottom_enumeration : TOP 
                            { $$ = $1; }
                          | BOTTOM
                            { $$ = $1; }

placement_status_enumeration : FIXED
                               { $$ = $1; }
                             | UNPLACED
                               { $$ = $1; }
                             | PLACED
                               { $$ = $1; }
         
library_data : library_header
               { 
               $$ = sdaiCreateInstanceBN (myModel, "library_data");
               sdaiPutAttrBN ($$, "library_library_header", sdaiINSTANCE, $1);
               }
             | library_data electrical
               { 
               $$ = $1;
               MTKsdaiInsertAfterBN($$, "library_electrical", sdaiINSTANCE, $2);
               }
             | library_data mechanical
               { 
               $$ = $1;
               MTKsdaiInsertAfterBN($$, "library_mechanical", sdaiINSTANCE, $2);
               }

electrical : START_ELECTRICAL any_string any_string units_definition_enumeration real loop END_ELECTRICAL
             {
             $$ = sdaiCreateInstanceBN (myModel, "electrical");
             sdaiPutAttrBN ($$, "geometry_name", sdaiSTRING, $2);
             sdaiPutAttrBN ($$, "part_number", sdaiSTRING, $3);
             sdaiPutAttrBN ($$, "units_definition", sdaiENUM, $4);
             sdaiPutAttrBN ($$, "component_height", sdaiREAL, $5);
             sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $6->outline);
             } 

mechanical : START_MECHANICAL any_string any_string units_definition_enumeration real loop END_MECHANICAL
             { 
             $$ = sdaiCreateInstanceBN (myModel, "mechanical");
             sdaiPutAttrBN ($$, "geometry_name", sdaiSTRING, $2);
             sdaiPutAttrBN ($$, "part_number", sdaiSTRING, $3);
             sdaiPutAttrBN ($$, "units_definition", sdaiENUM, $4);
             sdaiPutAttrBN ($$, "component_height", sdaiREAL, $5);
             sdaiPutAttrBN($$, "outline", sdaiINSTANCE, $6->outline);
             } 

library_header : START_HEADER 
                 LIBRARY_FILE 
                 idf_version_number
                 source_system_identification 
                 date 
                 library_file_version
                 END_HEADER
                 {
                 $$ = sdaiCreateInstanceBN (myModel, "library_header");
                 sdaiPutAttrBN ($$, "idf_version_number", sdaiSTRING, $3);
                 sdaiPutAttrBN ($$, "source_system_identification", sdaiSTRING, $4);
                 sdaiPutAttrBN ($$, "date", sdaiSTRING, $5);
                 sdaiPutAttrBN ($$, "library_file_version", sdaiINTEGER, $6);
                 }
/* must be positive */
library_file_version : integer 
                       { $$ = $1; }

/* utility rules */

integer : RAWINTEGER
          {
          $$ = atoi($1);
          free($1);
          }

real : RAWREAL
       {
       $$ = atof($1);
       free($1);
       }
%%
void MTKsdaiInsertAfterBN(SdaiInstance instance,
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
