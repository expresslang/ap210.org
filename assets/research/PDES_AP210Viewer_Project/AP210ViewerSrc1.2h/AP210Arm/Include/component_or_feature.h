#ifndef COMPONENT_OR_FEATURE_H
#define COMPONENT_OR_FEATURE_H

// Enumerations
union component_or_feature {
   class assembly_component *ST_assembly_component;
   class component_feature *ST_component_feature;
   };

#endif
