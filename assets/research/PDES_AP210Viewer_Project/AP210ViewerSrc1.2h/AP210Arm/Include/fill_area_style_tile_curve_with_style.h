#ifndef FILL_AREA_STYLE_TILE_CURVE_WITH_STYLE_H
#define FILL_AREA_STYLE_TILE_CURVE_WITH_STYLE_H

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

class AP210ARM_API fill_area_style_tile_curve_with_style:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 475};

   private:
      // Required attributes

      // Optional attributes

   protected:
      fill_area_style_tile_curve_with_style();

   public:
      ~fill_area_style_tile_curve_with_style();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fill_area_style_tile_curve_with_style *InstanceOf(ARMObject *);
      static fill_area_style_tile_curve_with_style *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fill_area_style_tile_curve_with_style *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
