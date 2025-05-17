#ifndef PRINTED_PART_CROSS_SECTION_TEMPLATE_H
#define PRINTED_PART_CROSS_SECTION_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <printed_part_template.h>

// Unions

// Enumerations

class AP210ARM_API printed_part_cross_section_template:
public printed_part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 175};

   private:
      // Required attributes
      class analytical_model *_transmission_line_model;
      class length_data_element *_maximum_width;
      class length_data_element *_minimum_width;

      // Optional attributes
      class analytical_representation *_maximum_transmission_line_characteristic[2000];
      class analytical_representation *_minimum_transmission_line_characteristic[2000];

   protected:
      printed_part_cross_section_template();

   public:
      ~printed_part_cross_section_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static printed_part_cross_section_template *InstanceOf(ARMObject *);
      static printed_part_cross_section_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static printed_part_cross_section_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
