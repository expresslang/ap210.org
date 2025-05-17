#ifndef SHIELDABLE_ITEM_H
#define SHIELDABLE_ITEM_H

// Enumerations
union shieldable_item {
   class assembly_component *ST_assembly_component;
   class component_feature *ST_component_feature;
   class physical_connectivity_definition *ST_physical_connectivity_definition;
   };

#endif
