#ifndef USAGE_CONCEPT_USAGE_RELATIONSHIP_H
#define USAGE_CONCEPT_USAGE_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <usage_concept.h>
#include <usage_concept.h>

// Enumerations

class AP210ARM_API usage_concept_usage_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 206};

   private:
      // Required attributes
      union usage_concept *_associating_usage;
      union usage_concept *_associated_usage;
      class axis_placement *_associated_usage_placement;

      // Optional attributes

   protected:
      usage_concept_usage_relationship();

   public:
      ~usage_concept_usage_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static usage_concept_usage_relationship *InstanceOf(ARMObject *);
      static usage_concept_usage_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static usage_concept_usage_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
