#ifndef TRUE_PROFILE_REPRESENTATIONS_H
#define TRUE_PROFILE_REPRESENTATIONS_H

// Enumerations
union true_profile_representations {
   class dimension_set *ST_dimension_set;
   class ee_document *ST_ee_document;
   class ee_rule_function *ST_ee_rule_function;
   class bound_volume_shape *ST_bound_volume_shape;
   };

#endif
