#ifndef TOLERANCEABLE_SHAPE_ELEMENT_H
#define TOLERANCEABLE_SHAPE_ELEMENT_H

// Enumerations
union toleranceable_shape_element {
   class centre_axis *ST_centre_axis;
   class centre_plane *ST_centre_plane;
   class centre_point *ST_centre_point;
   class tangent_plane *ST_tangent_plane;
   class physical_feature_or_part_template *ST_physical_feature_or_part_template;
   };

#endif
