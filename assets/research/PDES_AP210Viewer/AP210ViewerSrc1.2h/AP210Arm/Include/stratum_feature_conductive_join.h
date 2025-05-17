#ifndef STRATUM_FEATURE_CONDUCTIVE_JOIN_H
#define STRATUM_FEATURE_CONDUCTIVE_JOIN_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <stratum_concept_relationship.h>

// Unions

// Enumerations

class AP210ARM_API stratum_feature_conductive_join:
public stratum_concept_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 238};

   private:
      // Required attributes
      class stratum_feature_template_component *_related_concept;
      class stratum_feature_template_component *_relating_concept;

      // Optional attributes

   protected:
      stratum_feature_conductive_join();

   public:
      ~stratum_feature_conductive_join();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_feature_conductive_join *InstanceOf(ARMObject *);
      static stratum_feature_conductive_join *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_feature_conductive_join *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
