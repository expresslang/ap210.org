#ifndef TRIMMED_OR_BOUNDING_CURVE_H
#define TRIMMED_OR_BOUNDING_CURVE_H

// Enumerations
union trimmed_or_bounding_curve {
   class bounding_curve *ST_bounding_curve;
   class trimmed_line *ST_trimmed_line;
   };

#endif
