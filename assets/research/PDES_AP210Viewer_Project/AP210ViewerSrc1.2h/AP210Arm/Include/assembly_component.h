#ifndef ASSEMBLY_COMPONENT_H
#define ASSEMBLY_COMPONENT_H

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

class AP210ARM_API assembly_component:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 153};

   private:
      // Required attributes

      // Optional attributes
      union physical_unit_or_part_template *_usage_definition;

   protected:
      assembly_component();

   public:
      ~assembly_component();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_component *InstanceOf(ARMObject *);
      static assembly_component *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_component *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
