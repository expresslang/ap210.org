#ifndef COMPONENT_EXTERNAL_REFERENCE_H
#define COMPONENT_EXTERNAL_REFERENCE_H

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

class AP210ARM_API component_external_reference:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 281};

   private:
      // Required attributes
      STR _design_owner;
      STR _part_number;
      STR _revision_code;
      STR _product_definition_id;
      STR _reference_designation;

      // Optional attributes

   protected:
      component_external_reference();

   public:
      ~component_external_reference();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_external_reference *InstanceOf(ARMObject *);
      static component_external_reference *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_external_reference *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
