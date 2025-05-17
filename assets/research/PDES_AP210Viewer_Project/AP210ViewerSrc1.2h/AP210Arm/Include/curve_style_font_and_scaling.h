#ifndef CURVE_STYLE_FONT_AND_SCALING_H
#define CURVE_STYLE_FONT_AND_SCALING_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <curve_style_font_select.h>

// Enumerations

class AP210ARM_API curve_style_font_and_scaling:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 374};

   private:
      // Required attributes
      union curve_style_font_select *_curve_font;
      STR _name;
      class positive_ratio_measure *_curve_font_scaling;

      // Optional attributes

   protected:
      curve_style_font_and_scaling();

   public:
      ~curve_style_font_and_scaling();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static curve_style_font_and_scaling *InstanceOf(ARMObject *);
      static curve_style_font_and_scaling *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static curve_style_font_and_scaling *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
