#ifndef MATERIAL_ADDITION_FEATURE_TEMPLATE_H
#define MATERIAL_ADDITION_FEATURE_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_template.h>

// Unions

// Enumerations

class AP210ARM_API material_addition_feature_template:
public part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 646};

   private:
      // Required attributes

      // Optional attributes

   protected:
      material_addition_feature_template();

   public:
      ~material_addition_feature_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static material_addition_feature_template *InstanceOf(ARMObject *);
      static material_addition_feature_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static material_addition_feature_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
