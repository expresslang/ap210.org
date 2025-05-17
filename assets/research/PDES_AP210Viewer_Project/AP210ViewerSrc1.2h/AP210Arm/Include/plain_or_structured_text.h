#ifndef PLAIN_OR_STRUCTURED_TEXT_H
#define PLAIN_OR_STRUCTURED_TEXT_H

// Enumerations
union plain_or_structured_text {
   class structured_text *ST_structured_text;
   class ee_text *ST_ee_text;
   };

#endif
