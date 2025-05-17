/*
 * $Id: boardfile.c,v 1.3 1998/03/03 22:25:12 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sdai.h"
#include "../Sdai/SdaiUtility.h"
#include "IDF.h"

void PrintIDFBoardFile(FILE *fp, SdaiInstance board_data)
{
	SdaiInstance board_header;
	SdaiInstance board_outline;
	SdaiAggr other_outline;
	SdaiAggr route_outline;
	SdaiAggr place_outline;
	SdaiAggr route_keepout;
	SdaiAggr via_keepout;
	SdaiAggr place_keepout;
	SdaiAggr place_region;
	SdaiAggr drilled_holes;
	SdaiAggr placement;

	/* Print the Board Header */
	sdaiGetAttrBN(board_data, "board_board_header", sdaiINSTANCE, &board_header);
    PrintIDFBoardHeader(fp, board_header);

	/* Print the Board Outline */
	sdaiGetAttrBN(board_data, "board_board_outline", sdaiINSTANCE, &board_outline);
    PrintIDFBoardOutline(fp, board_outline);

	/* Print the Board Other Outline. */
   if (sdaiTestAttrBN(board_data, "board_other_outline") == sdaiTRUE)
       {
	   sdaiGetAttrBN(board_data, "board_other_outline", sdaiAGGR, &other_outline);
	   PrintIDFBoardOtherOutline(fp, other_outline);
       }

   /* Print the Board Route Outline. */
   if (sdaiTestAttrBN(board_data, "board_route_outline") == sdaiTRUE)
       {
	   sdaiGetAttrBN(board_data, "board_route_outline", sdaiAGGR, &route_outline);
	   PrintIDFBoardRouteOutline(fp, route_outline);
       }
  /* Print the Board Place Outline. */
   if (sdaiTestAttrBN(board_data, "board_place_outline") == sdaiTRUE)
       {
	   sdaiGetAttrBN(board_data, "board_place_outline", sdaiAGGR, &place_outline);
	   PrintIDFBoardPlaceOutline(fp, place_outline);
       }
 /* Print the Board Route Keepout. */
   if (sdaiTestAttrBN(board_data, "board_route_keepout") == sdaiTRUE)
       {
	   sdaiGetAttrBN(board_data, "board_route_keepout", sdaiAGGR, &route_keepout);
	   PrintIDFBoardRouteKeepout(fp, route_keepout);
       }
 /* Print the Board Via Keepout. */
   if (sdaiTestAttrBN(board_data, "board_via_keepout") == sdaiTRUE)
       {
	   sdaiGetAttrBN(board_data, "board_via_keepout", sdaiAGGR, &via_keepout);
	   PrintIDFBoardViaKeepout(fp, via_keepout);
       }
 /* Print the Board Place Keepout. */
   if (sdaiTestAttrBN(board_data, "board_place_keepout") == sdaiTRUE)
       {
	   sdaiGetAttrBN(board_data, "board_place_keepout", sdaiAGGR, &place_keepout);
	   PrintIDFBoardPlaceKeepout(fp, place_keepout);
       }
 /* Print the Board Place Region. */
   if (sdaiTestAttrBN(board_data, "board_place_region") == sdaiTRUE)
       {
	   sdaiGetAttrBN(board_data, "board_place_region", sdaiAGGR, &place_region);
	   PrintIDFBoardPlaceRegion(fp, place_region);
       }
 /* Print the Board Drilled Holes. */
   if (sdaiTestAttrBN(board_data, "board_drilled_holes") == sdaiTRUE)
       {
	   sdaiGetAttrBN(board_data, "board_drilled_holes", sdaiAGGR, &drilled_holes);
	   PrintIDFBoardDrilledHoles(fp, drilled_holes);
       }
 /* Print the Board Drilled Holes. */
   if (sdaiTestAttrBN(board_data, "board_placement") == sdaiTRUE)
       {
	   sdaiGetAttrBN(board_data, "board_placement", sdaiAGGR, &placement);
	   PrintIDFBoardPlacement(fp, placement);
       }
}
/*
 * Print Board Header
 */
void PrintIDFBoardHeader(FILE *fp, SdaiInstance board_header)
{
	SdaiString idf_version_number;
	SdaiString source_system_identification;
	SdaiString date;
	SdaiInteger board_file_version;
	SdaiString board_name;
	SdaiEnum units_definition;

	/* Get the Board Header attributes */
	sdaiGetAttrBN(board_header, "idf_version_number", sdaiSTRING, &idf_version_number);
	_sdaiGetStringAttrWithQuotesBN(board_header, "source_system_identification", &source_system_identification);
	_sdaiGetStringAttrWithQuotesBN(board_header, "date", &date);
	sdaiGetAttrBN(board_header, "board_file_version", sdaiINTEGER, &board_file_version);
	_sdaiGetStringAttrWithQuotesBN(board_header, "board_name", &board_name);
	sdaiGetAttrBN(board_header, "units_definition", sdaiENUM, &units_definition);

	/* Print the Board Header record */
	fputs(".HEADER\n", fp);
	fprintf(fp, "BOARD_FILE %s %s %s %d\n",
		idf_version_number,
		source_system_identification,
		date,
		board_file_version);
	fprintf(fp, "%s %s\n", board_name, units_definition);
	fputs(".END_HEADER\n", fp);
}
/*
 * Print Board Other Outlines
 */
void PrintIDFBoardOutline(FILE *fp, SdaiInstance board_outline)
{
	SdaiReal board_thickness;
	SdaiInstance outline;
	SdaiAggr cutouts;

	/* Get Board Outline attributes */
	sdaiGetAttrBN(board_outline, "board_thickness", sdaiREAL, &board_thickness);
	sdaiGetAttrBN(board_outline, "outline", sdaiINSTANCE, &outline);

	/* Print Board Outline */
	fputs(".BOARD_OUTLINE\n", fp);
	fprintf(fp, "%f\n", board_thickness);
    PrintIDFLoop(fp, outline);

	/* Print the Cutout data. */
   if (sdaiTestAttrBN(board_outline, "cutouts") == sdaiTRUE)
   {
	   sdaiGetAttrBN(board_outline, "cutouts", sdaiAGGR, &cutouts);

	   PrintIDFLoopList(fp, cutouts);
   }
	fputs(".END_BOARD_OUTLINE\n", fp);
}
/*
 * Print Board Other Outlines
 */
void PrintIDFBoardOtherOutline(FILE *fp, SdaiAggr board_other_outline)
{
	SdaiIterator itor;
	SdaiInstance other_outline;

	itor = sdaiCreateIterator(board_other_outline);
	
	while (sdaiNext(itor))
	{
		/* Get the Other Outline */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &other_outline);
		
		/* Print the Other Outline */
		PrintIDFOtherOutline(fp, other_outline);
	}
}
void PrintIDFOtherOutline(FILE *fp, SdaiInstance other_outline)
{
	SdaiString outline_identifier;
	SdaiReal extrude_thickness;
	SdaiInstance outline;
	SdaiAggr cutouts;

	/* Get Other Outline attributes */
	_sdaiGetStringAttrWithQuotesBN(other_outline, "outline_identifier", &outline_identifier);
	sdaiGetAttrBN(other_outline, "extrude_thickness", sdaiREAL, &extrude_thickness);
	sdaiGetAttrBN(other_outline, "outline", sdaiINSTANCE, &outline);

	/* Print Other Outline */
	fputs(".OTHER_OUTLINE\n", fp);
	fprintf(fp, "%s %f\n", outline_identifier, extrude_thickness);
   PrintIDFLoop(fp, outline);

	/* Print the Cutout data. */
   if (sdaiTestAttrBN(other_outline, "cutouts") == sdaiTRUE)
   {
	   sdaiGetAttrBN(other_outline, "cutouts", sdaiAGGR, &cutouts);

	   PrintIDFLoopList(fp, cutouts);
   }
	fputs(".END_OTHER_OUTLINE\n", fp);
}
/*
 * Print Board Route Outlines
 */
void PrintIDFBoardRouteOutline(FILE *fp, SdaiAggr board_route_outline)
{
	SdaiIterator itor;
	SdaiInstance route_outline;

	itor = sdaiCreateIterator(board_route_outline);
	
	while (sdaiNext(itor))
	{
		/* Get the Route Outline */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &route_outline);
		
		/* Print the Route Outline */
		PrintIDFRouteOutline(fp, route_outline);
	}
}


void PrintIDFRouteOutline(FILE *fp, SdaiInstance route_outline)
{
	SdaiInstance outline;
#ifdef DERIVED_ATTRIBUTES
	SdaiEnum routing_layers;
#endif

	/* Get Route Outline attributes */
#ifdef DERIVED_ATTRIBUTES
	sdaiGetAttrBN(route_outline, "routing_layers", sdaiENUM, &routing_layers);
#endif
	sdaiGetAttrBN(route_outline, "outline", sdaiINSTANCE, &outline);

	/* Print Route Outline */
	fputs(".ROUTE_OUTLINE\n", fp);
#ifdef DERIVED_ATTRIBUTES
	fprintf(fp, "#%s\n", routing_layers);
#endif
    PrintIDFLoop(fp, outline);

	fputs(".END_ROUTE_OUTLINE\n", fp);
}
/*
 * Print Board Placement Outlines
 */
void PrintIDFBoardPlaceOutline(FILE *fp, SdaiAggr board_place_outline)
{
	SdaiIterator itor;
	SdaiInstance place_outline;

	itor = sdaiCreateIterator(board_place_outline);
	
	while (sdaiNext(itor))
	{
		/* Get the Place Outline */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &place_outline);
		
		/* Print the Place Outline */
		PrintIDFPlaceOutline(fp, place_outline);
	}
}
void PrintIDFPlaceOutline(FILE *fp, SdaiInstance place_outline)
{
	SdaiInstance outline;
#ifdef DERIVED_ATTRIBUTES
	SdaiEnum place_layers;
#endif

	/* Get Place Outline attributes */
#ifdef DERIVED_ATTRIBUTES
	sdaiGetAttrBN(place_outline, "place_layers", sdaiENUM, &place_layers);
#endif
	sdaiGetAttrBN(place_outline, "outline", sdaiINSTANCE, &outline);

	/* Print Place Outline */
	fputs(".PLACE_OUTLINE\n", fp);
#ifdef DERIVED_ATTRIBUTES
	fprintf(fp, "#%s\n", place_layers);
#endif
    PrintIDFLoop(fp, outline);

	fputs(".END_PLACE_OUTLINE\n", fp);
}
/*
 * Print Board Route Keepouts
 */
void PrintIDFBoardRouteKeepout(FILE *fp, SdaiAggr board_route_keepout)
{
	SdaiIterator itor;
	SdaiInstance route_keepout;

	itor = sdaiCreateIterator(board_route_keepout);
	
	while (sdaiNext(itor))
	{
		/* Get the Route Keepout */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &route_keepout);
		
		/* Print the Route Keepout */
		PrintIDFRouteKeepout(fp, route_keepout);
	}
}
void PrintIDFRouteKeepout(FILE *fp, SdaiInstance route_keepout)
{
	SdaiInstance outline;
	SdaiEnum routing_layers;

	/* Get Place Outline attributes */
	sdaiGetAttrBN(route_keepout, "routing_layers", sdaiENUM, &routing_layers);
	sdaiGetAttrBN(route_keepout, "outline", sdaiINSTANCE, &outline);

	/* Print Place Outline */
	fputs(".ROUTE_KEEPOUT\n", fp);
	fprintf(fp, "%s\n", routing_layers);
    PrintIDFLoop(fp, outline);

	fputs(".END_ROUTE_KEEPOUT\n", fp);
}
/*
 * Print Board Via Keepouts
 */
void PrintIDFBoardViaKeepout(FILE *fp, SdaiAggr board_via_keepout)
{
	SdaiIterator itor;
	SdaiInstance via_keepout;

	itor = sdaiCreateIterator(board_via_keepout);
	
	while (sdaiNext(itor))
	{
		/* Get the Via Keepout */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &via_keepout);
		
		/* Print the Via Keepout */
		PrintIDFViaKeepout(fp, via_keepout);
	}
}
void PrintIDFViaKeepout(FILE *fp, SdaiInstance via_keepout)
{
	SdaiInstance outline;
#ifdef DERIVED_ATTRIBUTES
	SdaiEnum keepout_layers;
#endif

	/* Get Place Outline attributes */
#ifdef DERIVED_ATTRIBUTES
	sdaiGetAttrBN(via_keepout, "keepout_layers", sdaiENUM, &keepout_layers);
#endif
	sdaiGetAttrBN(via_keepout, "outline", sdaiINSTANCE, &outline);

	/* Print Place Outline */
	fputs(".VIA_KEEPOUT\n", fp);
#ifdef DERIVED_ATTRIBUTES
	fprintf(fp, "#%s\n", keepout_layers);
#endif
    PrintIDFLoop(fp, outline);

	fputs(".END_VIA_KEEPOUT\n", fp);
}
/*
 * Print Board Placement Keepout
 */
void PrintIDFBoardPlaceKeepout(FILE *fp, SdaiAggr board_place_keepout)
{
	SdaiIterator itor;
	SdaiInstance place_keepout;

	itor = sdaiCreateIterator(board_place_keepout);
	
	while (sdaiNext(itor))
	{
		/* Get the Place Keepout */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &place_keepout);
		
		/* Print the Place Keepout */
		PrintIDFPlaceKeepout(fp, place_keepout);
	}
}
void PrintIDFPlaceKeepout(FILE *fp, SdaiInstance place_keepout)
{
	SdaiInstance outline;
	SdaiEnum board_side;
	SdaiReal maximum_height;
	SdaiReal minimum_height;

	/* Get Place Keepout attributes */
	sdaiGetAttrBN(place_keepout, "board_side", sdaiENUM, &board_side);
	sdaiGetAttrBN(place_keepout, "maximum_height", sdaiREAL, &maximum_height);
	sdaiGetAttrBN(place_keepout, "minimum_height", sdaiREAL, &minimum_height);
	sdaiGetAttrBN(place_keepout, "outline", sdaiINSTANCE, &outline);

	/* Print Place Keepout */
	fputs(".PLACE_KEEPOUT\n", fp);
	fprintf(fp, "%s %f %f\n", board_side, maximum_height, minimum_height);
    PrintIDFLoop(fp, outline);

	fputs(".END_PLACE_KEEPOUT\n", fp);
}
/*
 * Print Board Placement Regions
 */
void PrintIDFBoardPlaceRegion(FILE *fp, SdaiAggr board_place_region)
{
	SdaiIterator itor;
	SdaiInstance place_region;

	itor = sdaiCreateIterator(board_place_region);
	
	while (sdaiNext(itor))
	{
		/* Get the Place Region */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &place_region);
		
		/* Print the Place Region */
		PrintIDFPlaceRegion(fp, place_region);
	}
}
void PrintIDFPlaceRegion(FILE *fp, SdaiInstance place_region) {
	SdaiInstance outline;
	SdaiEnum board_side;
	SdaiString component_group_name;

	/* Get Place Region attributes */
	sdaiGetAttrBN(place_region, "board_side", sdaiENUM, &board_side);
	_sdaiGetStringAttrWithQuotesBN(place_region, "component_group_name", &component_group_name);
	sdaiGetAttrBN(place_region, "outline", sdaiINSTANCE, &outline);

	/* Print Place Region */
	fputs(".PLACE_REGION\n", fp);
	fprintf(fp, "%s %s\n", board_side, component_group_name);
   PrintIDFLoop(fp, outline);

	fputs(".END_PLACE_REGION\n", fp);
   }
/*
 * Print Board Drilled Holes
 */
void PrintIDFBoardDrilledHoles(FILE *fp, SdaiAggr board_drilled_holes)
{
	SdaiIterator itor;
	SdaiInstance drilled_holes;

	itor = sdaiCreateIterator(board_drilled_holes);
	
	fputs(".DRILLED_HOLES\n", fp);
	while (sdaiNext(itor))
	{
		/* Get the Drilled Holes */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &drilled_holes);
		
		/* Print the Drilled Holes */
		PrintIDFDrilledHoles(fp, drilled_holes);
	}
	fputs(".END_DRILLED_HOLES\n", fp);
}
void PrintIDFDrilledHoles(FILE *fp, SdaiInstance drilled_holes) {
	SdaiReal hole_diameter;
	SdaiReal x_coord;
	SdaiReal y_coord;
	SdaiEnum hole_type;
	SdaiString associated_part_string;

	/* Get Drilled Holes attributes */
	sdaiGetAttrBN(drilled_holes, "hole_diameter", sdaiREAL, &hole_diameter);
	sdaiGetAttrBN(drilled_holes, "x_coord", sdaiREAL, &x_coord);
	sdaiGetAttrBN(drilled_holes, "y_coord", sdaiREAL, &y_coord);
	sdaiGetAttrBN(drilled_holes, "hole_type", sdaiENUM, &hole_type);
	_sdaiGetStringAttrWithQuotesBN(drilled_holes, "associated_part_string", &associated_part_string);

	/* Print Drilled Holes */
	fprintf(fp, "%f %f %f %s %s\n", hole_diameter, x_coord, y_coord, hole_type, associated_part_string);
   }
/*
 * Print Board Placement
 */
void PrintIDFBoardPlacement(FILE *fp, SdaiAggr board_placement)
{
	SdaiIterator itor;
	SdaiInstance placement;

	itor = sdaiCreateIterator(board_placement);
	
	fputs(".PLACEMENT\n", fp);
	while (sdaiNext(itor))
	{
		/* Get the Drilled Holes */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &placement);
		
		/* Print the Drilled Holes */
		PrintIDFPlacement(fp, placement);
	}
	fputs(".END_PLACEMENT\n", fp);
}
void PrintIDFPlacement(FILE *fp, SdaiInstance placement)
{
	SdaiString package_name;
	SdaiString part_number;
	SdaiString reference_designator;
	SdaiReal x_coord;
	SdaiReal y_coord;
	SdaiReal rotation_angle;
	SdaiEnum side_of_board;
	SdaiEnum placement_status;

	/* Get Drilled Holes attributes */
	_sdaiGetStringAttrWithQuotesBN(placement, "package_name", &package_name);
	_sdaiGetStringAttrWithQuotesBN(placement, "part_number", &part_number);
	_sdaiGetStringAttrWithQuotesBN(placement, "reference_designator", &reference_designator);
	sdaiGetAttrBN(placement, "x_coord", sdaiREAL, &x_coord);
	sdaiGetAttrBN(placement, "y_coord", sdaiREAL, &y_coord);
	sdaiGetAttrBN(placement, "rotation_angle", sdaiREAL, &rotation_angle);
	sdaiGetAttrBN(placement, "side_of_board", sdaiENUM, &side_of_board);
	sdaiGetAttrBN(placement, "placement_status", sdaiENUM, &placement_status);

	/* Print Drilled Holes */
	fprintf(fp, "%s %s %s\n", package_name, part_number, reference_designator);
	fprintf(fp, "%f %f %f %s ", x_coord, y_coord, rotation_angle, side_of_board);

	/* 
	 * Fixed is a keyword in Express and could not be used in the 
	 * placement status enumeration .PLACEMENT_FIXED. was used instead.
	 * This code is required to write out FIXED when .PLACEMENT_FIXED.
	 * is encountered.
	 */
	if (strcmp(placement_status, "PLACEMENT_FIXED"))
	{
		fputs(placement_status, fp);
	}
	else
	{
		fputs("FIXED", fp);
	}
	fputc('\n', fp);
}

