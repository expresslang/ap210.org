#ifndef COMPONENT_OR_COMPONENT_FEATURE_H
#define COMPONENT_OR_COMPONENT_FEATURE_H

// Enumerations
union component_or_component_feature {
   class assembly_component *ST_assembly_component;
   class component_external_reference *ST_component_external_reference;
   class component_feature *ST_component_feature;
   class component_feature_external_reference *ST_component_feature_external_reference;
   };

#endif
