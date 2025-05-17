#ifndef PACKAGED_OR_PRINTED_TERMINAL_H
#define PACKAGED_OR_PRINTED_TERMINAL_H

// Enumerations
union packaged_or_printed_terminal {
   class packaged_part_terminal *ST_packaged_part_terminal;
   class printed_part_template_terminal *ST_printed_part_template_terminal;
   };

#endif
