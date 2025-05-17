#ifndef ASSEMBLED_FEATURE_SELECT_H
#define ASSEMBLED_FEATURE_SELECT_H

// Enumerations
union assembled_feature_select {
   class interconnect_component_join_terminal *ST_interconnect_component_join_terminal;
   class interconnect_component_interface_terminal *ST_interconnect_component_interface_terminal;
   class packaged_connector_component_interface_terminal *ST_packaged_connector_component_interface_terminal;
   class package_terminal_occurrence *ST_package_terminal_occurrence;
   class bare_die_component_terminal *ST_bare_die_component_terminal;
   class packaged_component_join_terminal *ST_packaged_component_join_terminal;
   class assembly_module_component_terminal *ST_assembly_module_component_terminal;
   class interconnect_module_component_terminal *ST_interconnect_module_component_terminal;
   class component_feature *ST_component_feature;
   };

#endif
