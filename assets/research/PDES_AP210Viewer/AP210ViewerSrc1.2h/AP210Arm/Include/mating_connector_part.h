#ifndef MATING_CONNECTOR_PART_H
#define MATING_CONNECTOR_PART_H

// Enumerations
union mating_connector_part {
   class ee_specification *ST_ee_specification;
   class printed_connector_template *ST_printed_connector_template;
   class packaged_connector *ST_packaged_connector;
   };

#endif
