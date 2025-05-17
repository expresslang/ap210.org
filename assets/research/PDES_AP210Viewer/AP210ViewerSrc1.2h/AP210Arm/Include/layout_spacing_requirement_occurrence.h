#ifndef LAYOUT_SPACING_REQUIREMENT_OCCURRENCE_H
#define LAYOUT_SPACING_REQUIREMENT_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_requirement_occurrence.h>

// Unions

// Enumerations
#include <pca_product_design_object_category.h>
#include <pca_product_design_object_category.h>

class AP210ARM_API layout_spacing_requirement_occurrence:
public ee_requirement_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 629};

   private:
      // Required attributes
      pca_product_design_object_category::pca_product_design_object_category _reference_design_object_category;
      pca_product_design_object_category::pca_product_design_object_category _dependent_design_object_category;

      // Optional attributes

   protected:
      layout_spacing_requirement_occurrence();

   public:
      ~layout_spacing_requirement_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static layout_spacing_requirement_occurrence *InstanceOf(ARMObject *);
      static layout_spacing_requirement_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static layout_spacing_requirement_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
