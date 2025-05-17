#ifndef SETOFMATING_CONNECTOR_TERMINATION_H
#define SETOFMATING_CONNECTOR_TERMINATION_H

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

class AP210ARM_API SetOfmating_connector_termination:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 826};

   private:
      // Required attributes
      class mating_connector_termination *_mating_connector_termination;

      // Optional attributes

   protected:
      SetOfmating_connector_termination();

   public:
      ~SetOfmating_connector_termination();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfmating_connector_termination *InstanceOf(ARMObject *);
      static SetOfmating_connector_termination *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfmating_connector_termination *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
