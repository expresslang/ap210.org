#ifndef FUNCTIONAL_USAGE_VIEW_TO_PRINTED_PART_TEMPLATE_TERMINAL_ASSIGNMENT_H
#define FUNCTIONAL_USAGE_VIEW_TO_PRINTED_PART_TEMPLATE_TERMINAL_ASSIGNMENT_H

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

class AP210ARM_API functional_usage_view_to_printed_part_template_terminal_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 569};

   private:
      // Required attributes
      class printed_part_template_terminal *_physical_usage_view_terminal;
      class scalar_terminal_definition *_functional_usage_view_terminal;

      // Optional attributes

   protected:
      functional_usage_view_to_printed_part_template_terminal_assignment();

   public:
      ~functional_usage_view_to_printed_part_template_terminal_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_usage_view_to_printed_part_template_terminal_assignment *InstanceOf(ARMObject *);
      static functional_usage_view_to_printed_part_template_terminal_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_usage_view_to_printed_part_template_terminal_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
