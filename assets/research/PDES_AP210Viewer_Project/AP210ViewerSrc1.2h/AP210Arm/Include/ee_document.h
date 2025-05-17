#ifndef EE_DOCUMENT_H
#define EE_DOCUMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <person_organization.h>

// Enumerations

class AP210ARM_API ee_document:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 18};

   private:
      // Required attributes
      union person_organization *_publisher;
      class ee_document_identifier *_base_identifier;
      class date_and_time *_creation_date;
      STR _document_name;

      // Optional attributes
      class structured_text *_key_phrase[2000];
      class ee_approval *_document_approval;
      class date_and_time *_change_date[2000];
      class security_classification *_security_code;
      union plain_or_structured_text *_text_usage[2000];
      class person *_author[2000];
      STR _revision;

   protected:
      ee_document();

   public:
      ~ee_document();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_document *InstanceOf(ARMObject *);
      static ee_document *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_document *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
