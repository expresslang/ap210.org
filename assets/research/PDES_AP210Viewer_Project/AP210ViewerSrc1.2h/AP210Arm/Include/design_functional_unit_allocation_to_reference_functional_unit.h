#ifndef DESIGN_FUNCTIONAL_UNIT_ALLOCATION_TO_REFERENCE_FUNCTIONAL_UNIT_H
#define DESIGN_FUNCTIONAL_UNIT_ALLOCATION_TO_REFERENCE_FUNCTIONAL_UNIT_H

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

class AP210ARM_API design_functional_unit_allocation_to_reference_functional_unit:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 455};

   private:
      // Required attributes
      class reference_composition_path *_reference_definition_path;
      class design_composition_path *_design_definition_path;

      // Optional attributes

   protected:
      design_functional_unit_allocation_to_reference_functional_unit();

   public:
      ~design_functional_unit_allocation_to_reference_functional_unit();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static design_functional_unit_allocation_to_reference_functional_unit *InstanceOf(ARMObject *);
      static design_functional_unit_allocation_to_reference_functional_unit *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static design_functional_unit_allocation_to_reference_functional_unit *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
