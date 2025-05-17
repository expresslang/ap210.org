#ifndef RESTRICTION_BASIS_ITEM_H
#define RESTRICTION_BASIS_ITEM_H

// Enumerations
union restriction_basis_item {
   union stratum_concept *ST_stratum_concept;
   class ee_requirement_occurrence *ST_ee_requirement_occurrence;
   class part_feature *ST_part_feature;
   class stratum *ST_stratum;
   union component_or_component_feature *ST_component_or_component_feature;
   };

#endif
