#ifndef ASSEMBLY_JOINT_H
#define ASSEMBLY_JOINT_H

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

class AP210ARM_API assembly_joint:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 158};

   private:
      // Required attributes
      union assembled_feature_select *_assembly_features[2000];

      // Optional attributes
      STR _description;
      STR _name;

   protected:
      assembly_joint();

   public:
      ~assembly_joint();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_joint *InstanceOf(ARMObject *);
      static assembly_joint *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_joint *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
