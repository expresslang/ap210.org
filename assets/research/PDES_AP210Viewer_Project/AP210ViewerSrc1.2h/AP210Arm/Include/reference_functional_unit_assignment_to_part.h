#ifndef REFERENCE_FUNCTIONAL_UNIT_ASSIGNMENT_TO_PART_H
#define REFERENCE_FUNCTIONAL_UNIT_ASSIGNMENT_TO_PART_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <physical_unit_or_part_template.h>

// Enumerations

class AP210ARM_API reference_functional_unit_assignment_to_part:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 748};

   private:
      // Required attributes
      class reference_composition_path *_functional_design_definition_path;
      union physical_unit_or_part_template *_implementation;
      STR _path_alias;

      // Optional attributes
      class coordinated_characteristic *_of_property[2000];
      STR _swap_code;

   protected:
      reference_functional_unit_assignment_to_part();

   public:
      ~reference_functional_unit_assignment_to_part();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static reference_functional_unit_assignment_to_part *InstanceOf(ARMObject *);
      static reference_functional_unit_assignment_to_part *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static reference_functional_unit_assignment_to_part *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
