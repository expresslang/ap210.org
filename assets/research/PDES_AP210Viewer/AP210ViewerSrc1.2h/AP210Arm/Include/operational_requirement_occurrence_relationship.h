#ifndef OPERATIONAL_REQUIREMENT_OCCURRENCE_RELATIONSHIP_H
#define OPERATIONAL_REQUIREMENT_OCCURRENCE_RELATIONSHIP_H

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
#include <relationship_operation.h>

class AP210ARM_API operational_requirement_occurrence_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 662};

   private:
      // Required attributes
      relationship_operation::relationship_operation _relationship_type;
      class ee_requirement_occurrence *_relating_requirement_occurrence;
      class ee_requirement_occurrence *_related_requirement_occurrence;

      // Optional attributes

   protected:
      operational_requirement_occurrence_relationship();

   public:
      ~operational_requirement_occurrence_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static operational_requirement_occurrence_relationship *InstanceOf(ARMObject *);
      static operational_requirement_occurrence_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static operational_requirement_occurrence_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
