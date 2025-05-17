#ifndef LAND_PHYSICAL_TEMPLATE_H
#define LAND_PHYSICAL_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <stratum_feature_template.h>

// Unions

// Enumerations

class AP210ARM_API land_physical_template:
public stratum_feature_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 164};

   private:
      // Required attributes

      // Optional attributes
      class external_definition *_pre_defined_classification_code;

   protected:
      land_physical_template();

   public:
      ~land_physical_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static land_physical_template *InstanceOf(ARMObject *);
      static land_physical_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static land_physical_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
