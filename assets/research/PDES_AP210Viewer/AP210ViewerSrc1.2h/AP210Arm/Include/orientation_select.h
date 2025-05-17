#ifndef ORIENTATION_SELECT_H
#define ORIENTATION_SELECT_H

// Enumerations
union orientation_select {
   class datum_axis_related_orientation *ST_datum_axis_related_orientation;
   class viewing_plane_based_orientation *ST_viewing_plane_based_orientation;
   class datum_based_vector_orientation *ST_datum_based_vector_orientation;
   };

#endif
