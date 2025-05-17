#ifndef TERMINATION_OR_JUNCTION_H
#define TERMINATION_OR_JUNCTION_H

// Enumerations
union termination_or_junction {
   class component_terminal *ST_component_terminal;
   class topological_junction *ST_topological_junction;
   };

#endif
