#ifndef ASSEMBLY_OR_INTERCONNECT_DESIGN_OBJECT_SELECT_H
#define ASSEMBLY_OR_INTERCONNECT_DESIGN_OBJECT_SELECT_H

// Enumerations
union assembly_or_interconnect_design_object_select {
   class assembly_component *ST_assembly_component;
   class component_feature *ST_component_feature;
   union interconnect_module_design_object_select *ST_interconnect_module_design_object_select;
   };

#endif
