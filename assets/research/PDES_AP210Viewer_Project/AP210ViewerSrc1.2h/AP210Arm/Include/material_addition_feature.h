#ifndef MATERIAL_ADDITION_FEATURE_H
#define MATERIAL_ADDITION_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <design_intent_modification.h>

// Unions

// Enumerations

class AP210ARM_API material_addition_feature:
public design_intent_modification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 645};

   private:
      // Required attributes

      // Optional attributes

   protected:
      material_addition_feature();

   public:
      ~material_addition_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static material_addition_feature *InstanceOf(ARMObject *);
      static material_addition_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static material_addition_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
