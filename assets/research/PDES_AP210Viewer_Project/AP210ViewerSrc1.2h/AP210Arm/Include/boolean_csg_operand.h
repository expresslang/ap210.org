#ifndef BOOLEAN_CSG_OPERAND_H
#define BOOLEAN_CSG_OPERAND_H

// Enumerations
union boolean_csg_operand {
   class csg_primitive *ST_csg_primitive;
   class bound_volume_shape *ST_bound_volume_shape;
   class boolean_csg_result *ST_boolean_csg_result;
   };

#endif
