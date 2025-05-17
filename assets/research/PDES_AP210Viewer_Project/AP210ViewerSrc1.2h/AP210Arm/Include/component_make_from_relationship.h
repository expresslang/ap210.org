#ifndef COMPONENT_MAKE_FROM_RELATIONSHIP_H
#define COMPONENT_MAKE_FROM_RELATIONSHIP_H

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

class AP210ARM_API component_make_from_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 309};

   private:
      // Required attributes
      class assembly_composition_relationship *_reusable_component;
      class assembly_composition_relationship *_resultant_component;

      // Optional attributes

   protected:
      component_make_from_relationship();

   public:
      ~component_make_from_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_make_from_relationship *InstanceOf(ARMObject *);
      static component_make_from_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_make_from_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
