#ifndef COMPONENT_TERMINAL_TO_INTERCONNECT_MODULE_TERMINAL_ASSIGNMENT_H
#define COMPONENT_TERMINAL_TO_INTERCONNECT_MODULE_TERMINAL_ASSIGNMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <interconnect_or_assembly_module_select.h>

// Enumerations

class AP210ARM_API component_terminal_to_interconnect_module_terminal_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 324};

   private:
      // Required attributes
      class interconnect_module_terminal *_usage_view_terminal;
      union interconnect_or_assembly_module_select *_assigned_terminal;

      // Optional attributes

   protected:
      component_terminal_to_interconnect_module_terminal_assignment();

   public:
      ~component_terminal_to_interconnect_module_terminal_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_terminal_to_interconnect_module_terminal_assignment *InstanceOf(ARMObject *);
      static component_terminal_to_interconnect_module_terminal_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_terminal_to_interconnect_module_terminal_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
