#ifndef ASSEMBLY_COMPOSITION_RELATIONSHIP_H
#define ASSEMBLY_COMPOSITION_RELATIONSHIP_H

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

class AP210ARM_API assembly_composition_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 196};

   private:
      // Required attributes
      class physical_unit_design_view *_assembly;
      class assembly_component *_component;
      class security_classification *_security_code;

      // Optional attributes
      class ee_material *_assembly_bonding_agent[2000];

   protected:
      assembly_composition_relationship();

   public:
      ~assembly_composition_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_composition_relationship *InstanceOf(ARMObject *);
      static assembly_composition_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_composition_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
