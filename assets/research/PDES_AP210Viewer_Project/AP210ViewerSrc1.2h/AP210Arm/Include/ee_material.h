#ifndef EE_MATERIAL_H
#define EE_MATERIAL_H

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
#include <material_conductivity_classification.h>
#include <material_conductivity_classification.h>
#include <material_conductivity_classification.h>

class AP210ARM_API ee_material:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 30};

   private:
      // Required attributes
      STR _material_name;
      class ee_document *_registration_document;

      // Optional attributes
      STR _material_description[2000];
      class coordinated_characteristic *_coordinated_material_property[2000];
      material_conductivity_classification::material_conductivity_classification _electrical_conductivity_classification;
      material_conductivity_classification::material_conductivity_classification _optical_conductivity_classification;
      material_conductivity_classification::material_conductivity_classification _thermal_conductivity_classification;

   protected:
      ee_material();

   public:
      ~ee_material();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_material *InstanceOf(ARMObject *);
      static ee_material *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_material *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
