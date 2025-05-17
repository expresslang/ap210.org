#ifndef ASSEMBLY_MODULE_USAGE_VIEW_CONNECTOR_RELATIONSHIP_H
#define ASSEMBLY_MODULE_USAGE_VIEW_CONNECTOR_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <usage_concept_usage_relationship.h>

// Unions

// Enumerations

class AP210ARM_API assembly_module_usage_view_connector_relationship:
public usage_concept_usage_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 205};

   private:
      // Required attributes
      STR _externally_visible_partial_reference_designation;

      // Optional attributes

   protected:
      assembly_module_usage_view_connector_relationship();

   public:
      ~assembly_module_usage_view_connector_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_module_usage_view_connector_relationship *InstanceOf(ARMObject *);
      static assembly_module_usage_view_connector_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_module_usage_view_connector_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
