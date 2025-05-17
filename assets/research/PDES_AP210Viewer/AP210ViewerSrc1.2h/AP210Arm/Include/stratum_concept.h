#ifndef STRATUM_CONCEPT_H
#define STRATUM_CONCEPT_H

// Enumerations
union stratum_concept {
   class laminate_component *ST_laminate_component;
   class inter_stratum_feature *ST_inter_stratum_feature;
   class stratum_feature *ST_stratum_feature;
   class stratum *ST_stratum;
   class stratum_surface *ST_stratum_surface;
   };

#endif
