#ifndef SETOFPARAMETER_ASSIGNMENT_H
#define SETOFPARAMETER_ASSIGNMENT_H

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

class AP210ARM_API SetOfparameter_assignment:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 50};

   private:
      // Required attributes
      class parameter_assignment *_parameter_assignment;

      // Optional attributes

   protected:
      SetOfparameter_assignment();

   public:
      ~SetOfparameter_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfparameter_assignment *InstanceOf(ARMObject *);
      static SetOfparameter_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfparameter_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
