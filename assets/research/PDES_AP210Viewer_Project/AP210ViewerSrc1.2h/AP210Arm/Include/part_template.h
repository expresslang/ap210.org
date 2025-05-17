#ifndef PART_TEMPLATE_H
#define PART_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <library_item.h>
#include <physical_feature_or_part_template.h>

// Unions

// Enumerations

class AP210ARM_API part_template:
public library_item,
public physical_feature_or_part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 154};

   private:
      // Required attributes

      // Optional attributes
      class analytical_model *_part_template_analytical_model;
      union correlated_or_independent *_physical_characteristic[2000];
      class analytical_representation *_analytical_part_template_representation[2000];

   protected:
      part_template();

   public:
      ~part_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_template *InstanceOf(ARMObject *);
      static part_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
