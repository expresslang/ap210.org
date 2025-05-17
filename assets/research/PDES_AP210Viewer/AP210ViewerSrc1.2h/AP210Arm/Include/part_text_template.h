#ifndef PART_TEXT_TEMPLATE_H
#define PART_TEXT_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_template.h>

// Unions
#include <font_select.h>

// Enumerations

class AP210ARM_API part_text_template:
public part_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 681};

   private:
      // Required attributes
      union font_select *_font;
      class length_data_element *_maximum_font_horizontal_extent;
      class length_data_element *_maximum_font_vertical_extent;
      class angle_data_element *_slant_angle;
      class length_data_element *_stroke_width;

      // Optional attributes

   protected:
      part_text_template();

   public:
      ~part_text_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_text_template *InstanceOf(ARMObject *);
      static part_text_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_text_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
