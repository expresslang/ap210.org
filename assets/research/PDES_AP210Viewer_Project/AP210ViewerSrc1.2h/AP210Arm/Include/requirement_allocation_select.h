#ifndef REQUIREMENT_ALLOCATION_SELECT_H
#define REQUIREMENT_ALLOCATION_SELECT_H

// Enumerations
union requirement_allocation_select {
   class assembly_requirement_allocation *ST_assembly_requirement_allocation;
   class requirement_allocation *ST_requirement_allocation;
   class functional_unit_requirement_allocation *ST_functional_unit_requirement_allocation;
   };

#endif
