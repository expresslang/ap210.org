#ifndef DESCRIPTIVE_OR_GEOMETRIC_ORIENTATION_H
#define DESCRIPTIVE_OR_GEOMETRIC_ORIENTATION_H

// Enumerations
#include <measure_orientation.h>
union descriptive_or_geometric_orientation {
   measure_orientation::measure_orientation ST_measure_orientation;
   class orientation *ST_orientation;
   };

#endif
