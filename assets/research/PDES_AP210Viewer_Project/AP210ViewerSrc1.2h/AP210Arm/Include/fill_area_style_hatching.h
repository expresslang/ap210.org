#ifndef FILL_AREA_STYLE_HATCHING_H
#define FILL_AREA_STYLE_HATCHING_H

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

class AP210ARM_API fill_area_style_hatching:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 478};

   private:
      // Required attributes
      class curve_style *_hatch_line_appearance;
      class vector *_start_of_next_hatch_line;
      class cartesian_point *_point_of_reference_hatch_line;
      class cartesian_point *_pattern_start;
      class angle_data_element *_hatch_line_angle;

      // Optional attributes

   protected:
      fill_area_style_hatching();

   public:
      ~fill_area_style_hatching();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fill_area_style_hatching *InstanceOf(ARMObject *);
      static fill_area_style_hatching *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fill_area_style_hatching *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
