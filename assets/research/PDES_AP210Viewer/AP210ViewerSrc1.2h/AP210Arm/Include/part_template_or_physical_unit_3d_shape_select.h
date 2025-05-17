#ifndef PART_TEMPLATE_OR_PHYSICAL_UNIT_3D_SHAPE_SELECT_H
#define PART_TEMPLATE_OR_PHYSICAL_UNIT_3D_SHAPE_SELECT_H

// Enumerations
union part_template_or_physical_unit_3d_shape_select {
   class part_template_3d_shape *ST_part_template_3d_shape;
   class part_template_non_planar_2d_shape *ST_part_template_non_planar_2d_shape;
   class physical_unit_3d_shape *ST_physical_unit_3d_shape;
   };

#endif
