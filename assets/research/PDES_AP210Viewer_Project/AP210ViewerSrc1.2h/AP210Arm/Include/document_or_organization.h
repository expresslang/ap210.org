#ifndef DOCUMENT_OR_ORGANIZATION_H
#define DOCUMENT_OR_ORGANIZATION_H

// Enumerations
union document_or_organization {
   class ee_document *ST_ee_document;
   class organization *ST_organization;
   };

#endif
