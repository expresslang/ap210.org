#ifndef INTERCONNECT_MODULE_DESIGN_OBJECT_SELECT_H
#define INTERCONNECT_MODULE_DESIGN_OBJECT_SELECT_H

// Enumerations
union interconnect_module_design_object_select {
   class via *ST_via;
   class cutout *ST_cutout;
   class component_termination_passage *ST_component_termination_passage;
   class land *ST_land;
   class conductor *ST_conductor;
   class conductive_filled_area *ST_conductive_filled_area;
   class stratum_feature *ST_stratum_feature;
   class laminate_component *ST_laminate_component;
   class inter_stratum_feature *ST_inter_stratum_feature;
   class non_functional_land *ST_non_functional_land;
   };

#endif
