#ifndef CURVE_STYLE_H
#define CURVE_STYLE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <curve_font_or_scaled_curve_font_select.h>

// Enumerations
#include <extend_or_chord_2_extend_or_truncate_or_round.h>
#include <extend_or_truncate.h>
#include <square_or_round.h>

class AP210ARM_API curve_style:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 373};

   private:
      // Required attributes
      STR _name;
      extend_or_chord_2_extend_or_truncate_or_round::extend_or_chord_2_extend_or_truncate_or_round _corner_style;
      class length_data_element *_curve_width;
      extend_or_truncate::extend_or_truncate _end_extension;
      square_or_round::square_or_round _end_style;

      // Optional attributes
      union curve_font_or_scaled_curve_font_select *_curve_font;

   protected:
      curve_style();

   public:
      ~curve_style();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static curve_style *InstanceOf(ARMObject *);
      static curve_style *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static curve_style *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
