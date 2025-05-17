#ifndef BUS_STRUCTURAL_DEFINITION_OR_NODE_H
#define BUS_STRUCTURAL_DEFINITION_OR_NODE_H

// Enumerations
union bus_structural_definition_or_node {
   class functional_unit_network_node_definition *ST_functional_unit_network_node_definition;
   class bus_structural_definition *ST_bus_structural_definition;
   };

#endif
