#ifndef ASSEMBLY_MATERIAL_COMPOSITION_RELATIONSHIP_H
#define ASSEMBLY_MATERIAL_COMPOSITION_RELATIONSHIP_H

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

class AP210ARM_API assembly_material_composition_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 197};

   private:
      // Required attributes
      class physical_unit_design_view *_assembly;
      class ee_material *_component_material;
      class security_classification *_security_code;
      RoseLogical _as_required;

      // Optional attributes
      class data_element *_quantity;

   protected:
      assembly_material_composition_relationship();

   public:
      ~assembly_material_composition_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_material_composition_relationship *InstanceOf(ARMObject *);
      static assembly_material_composition_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_material_composition_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
