#ifndef SCALAR_OR_COORDINATED_CHARACTERISTICS_H
#define SCALAR_OR_COORDINATED_CHARACTERISTICS_H

// Enumerations
union scalar_or_coordinated_characteristics {
   class coordinated_characteristic *ST_coordinated_characteristic;
   class characteristic *ST_characteristic;
   };

#endif
