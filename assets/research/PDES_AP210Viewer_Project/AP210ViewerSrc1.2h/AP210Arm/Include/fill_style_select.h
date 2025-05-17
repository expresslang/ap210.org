#ifndef FILL_STYLE_SELECT_H
#define FILL_STYLE_SELECT_H

// Enumerations
union fill_style_select {
   class solid_fill_style *ST_solid_fill_style;
   class fill_area_style_tile *ST_fill_area_style_tile;
   class externally_defined_tile_style *ST_externally_defined_tile_style;
   class externally_defined_hatch_style *ST_externally_defined_hatch_style;
   class fill_area_style_hatching *ST_fill_area_style_hatching;
   };

#endif
