#ifndef CURVE_STYLE_FONT_SELECT_H
#define CURVE_STYLE_FONT_SELECT_H

// Enumerations
union curve_style_font_select {
   class solid_curve *ST_solid_curve;
   class externally_defined_curve_font *ST_externally_defined_curve_font;
   class curve_style_font *ST_curve_style_font;
   };

#endif
