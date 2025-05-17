#ifndef PACKAGE_OR_PACKAGE_EXTERNAL_REFERENCE_H
#define PACKAGE_OR_PACKAGE_EXTERNAL_REFERENCE_H

// Enumerations
union package_or_package_external_reference {
   class package *ST_package;
   class package_external_reference *ST_package_external_reference;
   };

#endif
