#ifndef DIMENSIONAL_LOCATION_OR_DIMENSIONAL_SIZE_H
#define DIMENSIONAL_LOCATION_OR_DIMENSIONAL_SIZE_H

// Enumerations
union dimensional_location_or_dimensional_size {
   class dimensional_size *ST_dimensional_size;
   class dimensional_location *ST_dimensional_location;
   };

#endif
