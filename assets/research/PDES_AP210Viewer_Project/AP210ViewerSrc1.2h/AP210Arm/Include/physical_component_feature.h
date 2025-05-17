#ifndef PHYSICAL_COMPONENT_FEATURE_H
#define PHYSICAL_COMPONENT_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <component_feature.h>
#include <physical_feature_or_part_template.h>

// Unions

// Enumerations

class AP210ARM_API physical_component_feature:
public component_feature,
public physical_feature_or_part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 689};

   private:
      // Required attributes

      // Optional attributes

   protected:
      physical_component_feature();

   public:
      ~physical_component_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_component_feature *InstanceOf(ARMObject *);
      static physical_component_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_component_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
