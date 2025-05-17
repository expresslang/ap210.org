/*
 * $Id: libraryfile.c,v 1.3 1998/03/03 22:25:12 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <stdio.h>

#include "sdai.h"
#include "../Sdai/SdaiUtility.h"
#include "IDF.h"


void PrintIDFLibraryFile(FILE *fp, SdaiInstance library_data)
{
	SdaiInstance library_header;
	SdaiAggr library_electrical;
	SdaiAggr library_mechanical;

	/* Print the Library Header */
	sdaiGetAttrBN(library_data, "library_library_header", sdaiINSTANCE, &library_header);
    PrintIDFLibraryHeader(fp, library_header);
 
	/* Print the Electrical data. */
   if (sdaiTestAttrBN(library_data, "library_electrical") == sdaiTRUE)
       {
	   sdaiGetAttrBN(library_data, "library_electrical", sdaiAGGR, &library_electrical);
	   PrintIDFLibraryElectrical(fp, library_electrical);
       }
 
	/* Print the Mechanical data. */
   if (sdaiTestAttrBN(library_data, "library_mechanical") == sdaiTRUE)
       {
	   sdaiGetAttrBN(library_data, "library_mechanical", sdaiAGGR, &library_mechanical);
	   PrintIDFLibraryMechanical(fp, library_mechanical);
       }
}

void PrintIDFLibraryHeader(FILE *fp, SdaiInstance library_header)
{
	SdaiString idf_version_number;
	SdaiString source_system_identification;
	SdaiString date;
	SdaiInteger library_file_version;

	/* Get the Library Header attributes */
	sdaiGetAttrBN(library_header, "idf_version_number", sdaiSTRING, &idf_version_number);
	_sdaiGetStringAttrWithQuotesBN(library_header, "source_system_identification", &source_system_identification);
	_sdaiGetStringAttrWithQuotesBN(library_header, "date", &date);
	sdaiGetAttrBN(library_header, "library_file_version", sdaiINTEGER, &library_file_version);

	/* Get and Print the Library Header record */
	fputs(".HEADER\n", fp);
	fprintf(fp, "LIBRARY_FILE %s %s %s %d\n",
		idf_version_number,
		source_system_identification,
		date,
		library_file_version);

	fputs(".END_HEADER\n", fp);
}
void PrintIDFLibraryElectrical(FILE *fp, SdaiAggr library_electrical)
{
	SdaiInstance electrical;
	SdaiIterator itor;

	itor = sdaiCreateIterator(library_electrical);
	
	while (sdaiNext(itor))
	{
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &electrical);
		PrintIDFElectrical(fp, electrical);

	}
}

void PrintIDFElectrical(FILE *fp, SdaiInstance electrical)
{
	SdaiString geometry_name;
	SdaiString part_number;
	SdaiEnum units_definition;
	SdaiReal component_height;
	SdaiInstance outline;

	/* Get the Electrial attributes */
	_sdaiGetStringAttrWithQuotesBN(electrical, "geometry_name", &geometry_name);
	_sdaiGetStringAttrWithQuotesBN(electrical, "part_number", &part_number);
	sdaiGetAttrBN(electrical, "units_definition", sdaiENUM, &units_definition);
	sdaiGetAttrBN(electrical, "component_height", sdaiREAL, &component_height);
	sdaiGetAttrBN(electrical, "outline", sdaiINSTANCE, &outline);

	fputs(".ELECTRICAL\n", fp);
	fprintf(fp, "%s %s %s %f\n", geometry_name, part_number, units_definition, component_height);
	PrintIDFLoop(fp, outline);
	fputs(".END_ELECTRICAL\n", fp);

}
void PrintIDFLibraryMechanical(FILE *fp, SdaiAggr library_mechanical)
{
	SdaiInstance mechanical;
	SdaiIterator itor;

	itor = sdaiCreateIterator(library_mechanical);
	
	while (sdaiNext(itor))
	{
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &mechanical);
		PrintIDFMechanical(fp, mechanical);

	}
}

void PrintIDFMechanical(FILE *fp, SdaiInstance mechanical)
{
	SdaiString geometry_name;
	SdaiString part_number;
	SdaiEnum units_definition;
	SdaiReal component_height;
	SdaiInstance outline;

	/* Get the Mechanical attributes */
	_sdaiGetStringAttrWithQuotesBN(mechanical, "geometry_name", &geometry_name);
	_sdaiGetStringAttrWithQuotesBN(mechanical, "part_number", &part_number);
	sdaiGetAttrBN(mechanical, "units_definition", sdaiENUM, &units_definition);
	sdaiGetAttrBN(mechanical, "component_height", sdaiREAL, &component_height);
	sdaiGetAttrBN(mechanical, "outline", sdaiINSTANCE, &outline);

	fputs(".MECHANICAL\n", fp);
	fprintf(fp, "%s %s %s %f\n", geometry_name, part_number, units_definition, component_height);
	PrintIDFLoop(fp, outline);
	fputs(".END_MECHANICAL\n", fp);

}
void PrintIDFLoop(FILE *fp, SdaiInstance loop)
{
	SdaiInteger loop_label;
	SdaiAggr closed_curve;
	SdaiIterator itor;
	SdaiInstance arc;
	SdaiReal x_coord;
	SdaiReal y_coord;
	SdaiReal included_angle;

	/* Get the Loop attributes */
	sdaiGetAttrBN(loop, "loop_label", sdaiINTEGER, &loop_label);

	/* Print the Closed Curve data. */
   if (sdaiTestAttrBN(loop, "closed_curve") == sdaiTRUE)
   {
	   sdaiGetAttrBN(loop, "closed_curve", sdaiAGGR, &closed_curve);
	   itor = sdaiCreateIterator(closed_curve);
	   
	   while (sdaiNext(itor))
	   {
		   sdaiGetAggrByIterator (itor, sdaiINSTANCE, &arc);
		   
		   /* Get the Arc attributes */
		   sdaiGetAttrBN(arc, "x_coord", sdaiREAL, &x_coord);
		   sdaiGetAttrBN(arc, "y_coord", sdaiREAL, &y_coord);
		   sdaiGetAttrBN(arc, "included_angle", sdaiREAL, &included_angle);

		   /* Print Arc Record */
		   fprintf(fp, "%d %f %f %f\n", loop_label, x_coord, y_coord, included_angle);
	   }
   }
}
void PrintIDFLoopList(FILE *fp, SdaiAggr loops)
{
	SdaiIterator itor;
	SdaiInstance loop;

	itor = sdaiCreateIterator(loops);
	
	while (sdaiNext(itor))
	{
		/* Get the loop */
		sdaiGetAggrByIterator (itor, sdaiINSTANCE, &loop);
		
		/* Print the Loop */
		PrintIDFLoop(fp, loop);
	}
}
