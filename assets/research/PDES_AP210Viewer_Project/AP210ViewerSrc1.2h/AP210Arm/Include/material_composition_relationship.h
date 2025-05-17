#ifndef MATERIAL_COMPOSITION_RELATIONSHIP_H
#define MATERIAL_COMPOSITION_RELATIONSHIP_H

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

class AP210ARM_API material_composition_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 647};

   private:
      // Required attributes
      STR _composition_basis;
      class ee_text *_determination_method;
      STR _composition_class;
      class data_element *_constituent_amount;
      class ee_material *_related_product;
      class ee_material *_relating_product;

      // Optional attributes

   protected:
      material_composition_relationship();

   public:
      ~material_composition_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static material_composition_relationship *InstanceOf(ARMObject *);
      static material_composition_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static material_composition_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
