#ifndef FILL_AREA_STYLE_TILE_SHAPE_SELECT_H
#define FILL_AREA_STYLE_TILE_SHAPE_SELECT_H

// Enumerations
union fill_area_style_tile_shape_select {
   class externally_defined_tile *ST_externally_defined_tile;
   class fill_area_style_tile_symbol_with_style *ST_fill_area_style_tile_symbol_with_style;
   class fill_area_style_tile_solid_region *ST_fill_area_style_tile_solid_region;
   class fill_area_style_tile_curve_with_style *ST_fill_area_style_tile_curve_with_style;
   };

#endif
