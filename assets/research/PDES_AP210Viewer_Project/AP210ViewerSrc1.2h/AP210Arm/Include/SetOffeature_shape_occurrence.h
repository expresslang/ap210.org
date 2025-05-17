#ifndef SETOFFEATURE_SHAPE_OCCURRENCE_H
#define SETOFFEATURE_SHAPE_OCCURRENCE_H

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

class AP210ARM_API SetOffeature_shape_occurrence:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 75};

   private:
      // Required attributes
      class feature_shape_occurrence *_feature_shape_occurrence;

      // Optional attributes

   protected:
      SetOffeature_shape_occurrence();

   public:
      ~SetOffeature_shape_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOffeature_shape_occurrence *InstanceOf(ARMObject *);
      static SetOffeature_shape_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOffeature_shape_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
