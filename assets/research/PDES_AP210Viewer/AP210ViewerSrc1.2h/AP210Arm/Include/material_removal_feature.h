#ifndef MATERIAL_REMOVAL_FEATURE_H
#define MATERIAL_REMOVAL_FEATURE_H

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

class AP210ARM_API material_removal_feature:
public design_intent_modification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 528};

   private:
      // Required attributes
      class material_removal_feature_template *_material_removal_shape;

      // Optional attributes

   protected:
      material_removal_feature();

   public:
      ~material_removal_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static material_removal_feature *InstanceOf(ARMObject *);
      static material_removal_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static material_removal_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
