#ifndef CURVE_FONT_OR_SCALED_CURVE_FONT_SELECT_H
#define CURVE_FONT_OR_SCALED_CURVE_FONT_SELECT_H

// Enumerations
union curve_font_or_scaled_curve_font_select {
   class curve_style_font_and_scaling *ST_curve_style_font_and_scaling;
   union curve_style_font_select *ST_curve_style_font_select;
   };

#endif
