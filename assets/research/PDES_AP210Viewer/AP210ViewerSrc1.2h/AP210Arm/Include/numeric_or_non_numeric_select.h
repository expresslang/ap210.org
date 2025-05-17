#ifndef NUMERIC_OR_NON_NUMERIC_SELECT_H
#define NUMERIC_OR_NON_NUMERIC_SELECT_H

// Enumerations
union numeric_or_non_numeric_select {
   union non_numeric_property_type *ST_non_numeric_property_type;
   class external_definition *ST_external_definition;
   class data_element *ST_data_element;
   };

#endif
