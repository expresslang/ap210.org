#ifndef CONNECTIVITY_COMPONENT_H
#define CONNECTIVITY_COMPONENT_H

// Enumerations
union connectivity_component {
   class connectivity_sub_structure *ST_connectivity_sub_structure;
   union termination_or_junction *ST_termination_or_junction;
   };

#endif
