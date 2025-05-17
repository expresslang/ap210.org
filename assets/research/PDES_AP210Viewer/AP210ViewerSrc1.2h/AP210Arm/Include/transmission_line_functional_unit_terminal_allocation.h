#ifndef TRANSMISSION_LINE_FUNCTIONAL_UNIT_TERMINAL_ALLOCATION_H
#define TRANSMISSION_LINE_FUNCTIONAL_UNIT_TERMINAL_ALLOCATION_H

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

class AP210ARM_API transmission_line_functional_unit_terminal_allocation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 850};

   private:
      // Required attributes
      class printed_component_join_terminal *_implementation;
      class functional_unit_terminal *_transmission_line_functional_unit_terminal;
      class transmission_line_functional_unit_to_routed_printed_component_allocation *_functional_unit_design_path;

      // Optional attributes

   protected:
      transmission_line_functional_unit_terminal_allocation();

   public:
      ~transmission_line_functional_unit_terminal_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static transmission_line_functional_unit_terminal_allocation *InstanceOf(ARMObject *);
      static transmission_line_functional_unit_terminal_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static transmission_line_functional_unit_terminal_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
