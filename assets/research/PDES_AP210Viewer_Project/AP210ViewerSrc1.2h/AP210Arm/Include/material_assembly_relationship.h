#ifndef MATERIAL_ASSEMBLY_RELATIONSHIP_H
#define MATERIAL_ASSEMBLY_RELATIONSHIP_H

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

class AP210ARM_API material_assembly_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 85};

   private:
      // Required attributes
      class ee_material *_component;
      class ee_material *_assembly;
      STR _component_identifier;

      // Optional attributes

   protected:
      material_assembly_relationship();

   public:
      ~material_assembly_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static material_assembly_relationship *InstanceOf(ARMObject *);
      static material_assembly_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static material_assembly_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
