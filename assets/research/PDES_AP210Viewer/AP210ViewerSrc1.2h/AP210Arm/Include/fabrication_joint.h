#ifndef FABRICATION_JOINT_H
#define FABRICATION_JOINT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API fabrication_joint:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 449};

   private:
      // Required attributes
      union fabricated_feature_select *_fabrication_features[2000];

      // Optional attributes
      class stratum_feature_template_component *_auxiliary_joint_material;

   protected:
      fabrication_joint();

   public:
      ~fabrication_joint();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fabrication_joint *InstanceOf(ARMObject *);
      static fabrication_joint *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fabrication_joint *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
