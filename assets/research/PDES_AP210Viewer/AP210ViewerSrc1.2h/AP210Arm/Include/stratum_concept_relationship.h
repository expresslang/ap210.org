#ifndef STRATUM_CONCEPT_RELATIONSHIP_H
#define STRATUM_CONCEPT_RELATIONSHIP_H

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

class AP210ARM_API stratum_concept_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 239};

   private:
      // Required attributes
      class ee_requirement_occurrence *_technology_requirement[2000];

      // Optional attributes
      class feature_shape_definition *_resulting_shape;

   protected:
      stratum_concept_relationship();

   public:
      ~stratum_concept_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_concept_relationship *InstanceOf(ARMObject *);
      static stratum_concept_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_concept_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
