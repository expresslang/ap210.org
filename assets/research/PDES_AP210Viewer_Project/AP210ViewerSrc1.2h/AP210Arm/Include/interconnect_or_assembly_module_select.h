#ifndef INTERCONNECT_OR_ASSEMBLY_MODULE_SELECT_H
#define INTERCONNECT_OR_ASSEMBLY_MODULE_SELECT_H

// Enumerations
union interconnect_or_assembly_module_select {
   class component_termination_passage_interface_terminal *ST_component_termination_passage_interface_terminal;
   class printed_connector_component_interface_terminal *ST_printed_connector_component_interface_terminal;
   class non_functional_land_interface_terminal *ST_non_functional_land_interface_terminal;
   class land_interface_terminal *ST_land_interface_terminal;
   };

#endif
