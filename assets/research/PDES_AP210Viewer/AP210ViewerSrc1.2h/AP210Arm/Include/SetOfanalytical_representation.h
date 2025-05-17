#ifndef SETOFANALYTICAL_REPRESENTATION_H
#define SETOFANALYTICAL_REPRESENTATION_H

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

class AP210ARM_API SetOfanalytical_representation:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 48};

   private:
      // Required attributes
      class analytical_representation *_analytical_representation;

      // Optional attributes

   protected:
      SetOfanalytical_representation();

   public:
      ~SetOfanalytical_representation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfanalytical_representation *InstanceOf(ARMObject *);
      static SetOfanalytical_representation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfanalytical_representation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
