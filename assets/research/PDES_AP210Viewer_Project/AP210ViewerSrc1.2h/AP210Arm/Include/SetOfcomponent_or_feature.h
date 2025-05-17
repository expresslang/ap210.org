#ifndef SETOFCOMPONENT_OR_FEATURE_H
#define SETOFCOMPONENT_OR_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <component_or_feature.h>

// Enumerations

class AP210ARM_API SetOfcomponent_or_feature:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 211};

   private:
      // Required attributes
      union component_or_feature *_component_or_feature;

      // Optional attributes

   protected:
      SetOfcomponent_or_feature();

   public:
      ~SetOfcomponent_or_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfcomponent_or_feature *InstanceOf(ARMObject *);
      static SetOfcomponent_or_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfcomponent_or_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
