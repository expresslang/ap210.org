#ifndef SETOFVECTOR_H
#define SETOFVECTOR_H

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

class AP210ARM_API SetOfvector:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 470};

   private:
      // Required attributes
      class vector *_vector;

      // Optional attributes

   protected:
      SetOfvector();

   public:
      ~SetOfvector();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfvector *InstanceOf(ARMObject *);
      static SetOfvector *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfvector *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
