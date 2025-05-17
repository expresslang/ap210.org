#ifndef EE_PRODUCT_DEFINITION_H
#define EE_PRODUCT_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API ee_product_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 3};

   private:
      // Required attributes
      union person_organization *_creator[2000];
      STR _product_definition_id;
      class security_classification *_security_code;
      class ee_text *_context_description;
      class ee_product_version *_version;
      class ee_approval *_product_definition_approval;
      class date_and_time *_creation_date;
      STR _discipline_id;

      // Optional attributes
      class ee_document *_documentation[2000];
      STR _cad_filename;

   protected:
      ee_product_definition();

   public:
      ~ee_product_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_product_definition *InstanceOf(ARMObject *);
      static ee_product_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_product_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
