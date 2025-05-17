#ifndef PLANNED_EFFECTIVITY_H
#define PLANNED_EFFECTIVITY_H

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

class AP210ARM_API planned_effectivity:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 706};

   private:
      // Required attributes
      class assembly_composition_relationship *_effective_assembly;
      class ee_approval *_effectivity_approval;
      class ee_product_configuration *_configuration;

      // Optional attributes
      class data_element *_component_quantity;

   protected:
      planned_effectivity();

   public:
      ~planned_effectivity();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static planned_effectivity *InstanceOf(ARMObject *);
      static planned_effectivity *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static planned_effectivity *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
