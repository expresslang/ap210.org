#ifndef PHYSICAL_CONNECTIVITY_DEFINITION_RELATIONSHIP_H
#define PHYSICAL_CONNECTIVITY_DEFINITION_RELATIONSHIP_H

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

class AP210ARM_API physical_connectivity_definition_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 691};

   private:
      // Required attributes
      class ee_requirement_occurrence *_requirement;
      class physical_connectivity_definition *_previous_definition;
      class physical_connectivity_definition *_current_definition;

      // Optional attributes

   protected:
      physical_connectivity_definition_relationship();

   public:
      ~physical_connectivity_definition_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_connectivity_definition_relationship *InstanceOf(ARMObject *);
      static physical_connectivity_definition_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_connectivity_definition_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
