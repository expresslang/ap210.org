#ifndef PART_FEATURE_H
#define PART_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_feature_or_part_template.h>

// Unions

// Enumerations

class AP210ARM_API part_feature:
public physical_feature_or_part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 80};

   private:
      // Required attributes
      class physical_unit_usage_view *_associated_definition;

      // Optional attributes
      class feature_shape_occurrence *_feature_shape[2000];
      class part_feature *_precedent_feature;

   protected:
      part_feature();

   public:
      ~part_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_feature *InstanceOf(ARMObject *);
      static part_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
