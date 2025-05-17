#ifndef USAGE_CONCEPT_H
#define USAGE_CONCEPT_H

// Enumerations
union usage_concept {
   class part_template *ST_part_template;
   class physical_unit_usage_view *ST_physical_unit_usage_view;
   class land_template_terminal *ST_land_template_terminal;
   class component_termination_passage_template_terminal *ST_component_termination_passage_template_terminal;
   class via_template_terminal *ST_via_template_terminal;
   class part_feature *ST_part_feature;
   class printed_part_template_terminal *ST_printed_part_template_terminal;
   };

#endif
