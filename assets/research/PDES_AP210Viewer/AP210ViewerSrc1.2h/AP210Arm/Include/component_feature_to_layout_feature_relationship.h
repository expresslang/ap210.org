#ifndef COMPONENT_FEATURE_TO_LAYOUT_FEATURE_RELATIONSHIP_H
#define COMPONENT_FEATURE_TO_LAYOUT_FEATURE_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <stratum_concept.h>
#include <component_or_component_feature.h>

// Enumerations

class AP210ARM_API component_feature_to_layout_feature_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 302};

   private:
      // Required attributes
      union stratum_concept *_related_stratum_concept;
      union component_or_component_feature *_relating_feature;

      // Optional attributes
      class ee_requirement_occurrence *_requirement;

   protected:
      component_feature_to_layout_feature_relationship();

   public:
      ~component_feature_to_layout_feature_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_feature_to_layout_feature_relationship *InstanceOf(ARMObject *);
      static component_feature_to_layout_feature_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_feature_to_layout_feature_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
