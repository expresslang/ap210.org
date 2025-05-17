#ifndef DATUM_DIFFERENCE_FUNCTIONAL_UNIT_USAGE_VIEW_TERMINAL_ASSIGNMENT_H
#define DATUM_DIFFERENCE_FUNCTIONAL_UNIT_USAGE_VIEW_TERMINAL_ASSIGNMENT_H

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

class AP210ARM_API datum_difference_functional_unit_usage_view_terminal_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 418};

   private:
      // Required attributes
      class functional_unit_usage_view_terminal_definition *_assigned_functional_terminal_definition;
      class datum_difference *_assigned_datum_difference;

      // Optional attributes

   protected:
      datum_difference_functional_unit_usage_view_terminal_assignment();

   public:
      ~datum_difference_functional_unit_usage_view_terminal_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_difference_functional_unit_usage_view_terminal_assignment *InstanceOf(ARMObject *);
      static datum_difference_functional_unit_usage_view_terminal_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_difference_functional_unit_usage_view_terminal_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
