#ifndef TRANSMISSION_LINE_FUNCTIONAL_UNIT_TO_ROUTED_PRINTED_COMPONENT_ALLOCATION_H
#define TRANSMISSION_LINE_FUNCTIONAL_UNIT_TO_ROUTED_PRINTED_COMPONENT_ALLOCATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <design_functional_unit_allocation_to_assembly_component.h>

// Unions

// Enumerations

class AP210ARM_API transmission_line_functional_unit_to_routed_printed_component_allocation:
public design_functional_unit_allocation_to_assembly_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 851};

   private:
      // Required attributes

      // Optional attributes

   protected:
      transmission_line_functional_unit_to_routed_printed_component_allocation();

   public:
      ~transmission_line_functional_unit_to_routed_printed_component_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static transmission_line_functional_unit_to_routed_printed_component_allocation *InstanceOf(ARMObject *);
      static transmission_line_functional_unit_to_routed_printed_component_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static transmission_line_functional_unit_to_routed_printed_component_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
