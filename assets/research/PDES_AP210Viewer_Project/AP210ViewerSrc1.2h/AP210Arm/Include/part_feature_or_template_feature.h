#ifndef PART_FEATURE_OR_TEMPLATE_FEATURE_H
#define PART_FEATURE_OR_TEMPLATE_FEATURE_H

// Enumerations
union part_feature_or_template_feature {
   class land_template_terminal *ST_land_template_terminal;
   class component_termination_passage_template_terminal *ST_component_termination_passage_template_terminal;
   class part_feature *ST_part_feature;
   class printed_part_template_terminal *ST_printed_part_template_terminal;
   class part_terminal_external_reference *ST_part_terminal_external_reference;
   class via_template_terminal *ST_via_template_terminal;
   };

#endif
