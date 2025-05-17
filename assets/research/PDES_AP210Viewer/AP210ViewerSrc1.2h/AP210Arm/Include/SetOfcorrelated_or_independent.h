#ifndef SETOFCORRELATED_OR_INDEPENDENT_H
#define SETOFCORRELATED_OR_INDEPENDENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <correlated_or_independent.h>

// Enumerations

class AP210ARM_API SetOfcorrelated_or_independent:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 156};

   private:
      // Required attributes
      union correlated_or_independent *_correlated_or_independent;

      // Optional attributes

   protected:
      SetOfcorrelated_or_independent();

   public:
      ~SetOfcorrelated_or_independent();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfcorrelated_or_independent *InstanceOf(ARMObject *);
      static SetOfcorrelated_or_independent *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfcorrelated_or_independent *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
