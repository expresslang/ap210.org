#ifndef INTERFACE_COMPONENT_ALLOCATION_H
#define INTERFACE_COMPONENT_ALLOCATION_H

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

class AP210ARM_API interface_component_allocation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 604};

   private:
      // Required attributes
      class interface_component *_mating_solution;
      class mating_connector_component *_mating_requirement;

      // Optional attributes

   protected:
      interface_component_allocation();

   public:
      ~interface_component_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interface_component_allocation *InstanceOf(ARMObject *);
      static interface_component_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interface_component_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
