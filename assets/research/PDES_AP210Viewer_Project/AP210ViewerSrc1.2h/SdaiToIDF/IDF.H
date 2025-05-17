/* Functions in LibraryFile.c */
void PrintIDFLibraryFile(FILE *fp, SdaiInstance library_data);
void PrintIDFLibraryHeader(FILE *fp, SdaiInstance library_header);
void PrintIDFLibraryElectrical(FILE *fp, SdaiAggr library_electrical);
void PrintIDFElectrical(FILE *fp, SdaiInstance electrical);
void PrintIDFLibraryMechanical(FILE *fp, SdaiAggr library_mechanical);
void PrintIDFMechanical(FILE *fp, SdaiInstance mechanical);
void PrintIDFLoop(FILE *fp, SdaiInstance loop);
void PrintIDFLoopList(FILE *fp, SdaiAggr loops);

/* Functions in BoardFile.c */
void PrintIDFBoardFile(FILE *fp, SdaiInstance board_data);
void PrintIDFBoardHeader(FILE *fp, SdaiInstance board_header);
void PrintIDFBoardOutline(FILE *fp, SdaiInstance board_outline);

void PrintIDFBoardOtherOutline(FILE *fp, SdaiAggr board_other_outline);
void PrintIDFOtherOutline(FILE *fp, SdaiInstance other_outline);

void PrintIDFBoardRouteOutline(FILE *fp, SdaiAggr board_route_outline);
void PrintIDFRouteOutline(FILE *fp, SdaiInstance route_outline);

void PrintIDFBoardPlaceOutline(FILE *fp, SdaiAggr board_place_outline);
void PrintIDFPlaceOutline(FILE *fp, SdaiInstance place_outline);

void PrintIDFBoardRouteKeepout(FILE *fp, SdaiAggr board_route_keepout);
void PrintIDFRouteKeepout(FILE *fp, SdaiInstance route_keepout);

void PrintIDFBoardViaKeepout(FILE *fp, SdaiAggr board_via_keepout);
void PrintIDFViaKeepout(FILE *fp, SdaiInstance via_keepout);

void PrintIDFBoardPlaceKeepout(FILE *fp, SdaiAggr board_place_keepout);
void PrintIDFPlaceKeepout(FILE *fp, SdaiInstance place_keepout);

void PrintIDFBoardPlaceRegion(FILE *fp, SdaiAggr board_place_region);
void PrintIDFPlaceRegion(FILE *fp, SdaiInstance place_region);

void PrintIDFBoardDrilledHoles(FILE *fp, SdaiAggr board_drilled_holes);
void PrintIDFDrilledHoles(FILE *fp, SdaiInstance drilled_holes);

void PrintIDFBoardPlacement(FILE *fp, SdaiAggr board_placement);
void PrintIDFPlacement(FILE *fp, SdaiInstance placement);

