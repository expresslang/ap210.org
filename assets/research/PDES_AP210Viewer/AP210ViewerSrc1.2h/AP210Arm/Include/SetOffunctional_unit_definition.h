#ifndef SETOFFUNCTIONAL_UNIT_DEFINITION_H
#define SETOFFUNCTIONAL_UNIT_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOffunctional_unit_definition:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 538};

   private:
      // Required attributes
      class functional_unit_definition *_functional_unit_definition;

      // Optional attributes

   protected:
      SetOffunctional_unit_definition();

   public:
      ~SetOffunctional_unit_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOffunctional_unit_definition *InstanceOf(ARMObject *);
      static SetOffunctional_unit_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOffunctional_unit_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
