#ifndef FUNCTIONAL_UNIT_NETWORK_TERMINAL_DEFINITION_BUS_ASSIGNMENT_H
#define FUNCTIONAL_UNIT_NETWORK_TERMINAL_DEFINITION_BUS_ASSIGNMENT_H

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

class AP210ARM_API functional_unit_network_terminal_definition_bus_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 563};

   private:
      // Required attributes
      class bus_structural_definition *_connected_bus;
      class functional_unit_usage_view_terminal_definition *_connected_terminal;

      // Optional attributes

   protected:
      functional_unit_network_terminal_definition_bus_assignment();

   public:
      ~functional_unit_network_terminal_definition_bus_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_unit_network_terminal_definition_bus_assignment *InstanceOf(ARMObject *);
      static functional_unit_network_terminal_definition_bus_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_unit_network_terminal_definition_bus_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
