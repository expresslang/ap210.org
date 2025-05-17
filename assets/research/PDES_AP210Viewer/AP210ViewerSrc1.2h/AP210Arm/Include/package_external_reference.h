#ifndef PACKAGE_EXTERNAL_REFERENCE_H
#define PACKAGE_EXTERNAL_REFERENCE_H

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

class AP210ARM_API package_external_reference:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 88};

   private:
      // Required attributes
      STR _design_owner;
      STR _part_number;
      STR _revision_code;
      STR _product_definition_id;

      // Optional attributes

   protected:
      package_external_reference();

   public:
      ~package_external_reference();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static package_external_reference *InstanceOf(ARMObject *);
      static package_external_reference *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static package_external_reference *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
