#ifndef COMPONENT_FEATURE_H
#define COMPONENT_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <part_feature_or_template_feature.h>

// Enumerations

class AP210ARM_API component_feature:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 162};

   private:
      // Required attributes
      class assembly_component *_associated_component;

      // Optional attributes
      union part_feature_or_template_feature *_definition;

   protected:
      component_feature();

   public:
      ~component_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_feature *InstanceOf(ARMObject *);
      static component_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
