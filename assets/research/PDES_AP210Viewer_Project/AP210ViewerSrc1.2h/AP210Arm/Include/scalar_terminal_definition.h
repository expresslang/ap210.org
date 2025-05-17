#ifndef SCALAR_TERMINAL_DEFINITION_H
#define SCALAR_TERMINAL_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <functional_unit_usage_view_terminal_definition.h>

// Unions

// Enumerations

class AP210ARM_API scalar_terminal_definition:
public functional_unit_usage_view_terminal_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 93};

   private:
      // Required attributes

      // Optional attributes

   protected:
      scalar_terminal_definition();

   public:
      ~scalar_terminal_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static scalar_terminal_definition *InstanceOf(ARMObject *);
      static scalar_terminal_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static scalar_terminal_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
