#ifndef COMPONENT_FEATURE_EXTERNAL_REFERENCE_H
#define COMPONENT_FEATURE_EXTERNAL_REFERENCE_H

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

class AP210ARM_API component_feature_external_reference:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 282};

   private:
      // Required attributes
      class component_external_reference *_associated_component;
      STR _name;

      // Optional attributes

   protected:
      component_feature_external_reference();

   public:
      ~component_feature_external_reference();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_feature_external_reference *InstanceOf(ARMObject *);
      static component_feature_external_reference *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_feature_external_reference *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
