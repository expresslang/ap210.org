#ifndef DATUM_SYSTEM_DEFINING_CONDITIONS_H
#define DATUM_SYSTEM_DEFINING_CONDITIONS_H

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

class AP210ARM_API datum_system_defining_conditions:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 140};

   private:
      // Required attributes
      class datum_system *_conditions_of;
      class datum_precedence_assignment *_assigned_datum_precedences[2000];

      // Optional attributes

   protected:
      datum_system_defining_conditions();

   public:
      ~datum_system_defining_conditions();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_system_defining_conditions *InstanceOf(ARMObject *);
      static datum_system_defining_conditions *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_system_defining_conditions *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
