#ifndef PRINTED_PART_TEMPLATE_MATERIAL_H
#define PRINTED_PART_TEMPLATE_MATERIAL_H

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

class AP210ARM_API printed_part_template_material:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 174};

   private:
      // Required attributes
      class length_data_element *_maximum_thickness;
      class ee_material *_required_material;
      class length_data_element *_minimum_thickness;

      // Optional attributes

   protected:
      printed_part_template_material();

   public:
      ~printed_part_template_material();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_part_template_material *InstanceOf(ARMObject *);
      static printed_part_template_material *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_part_template_material *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
