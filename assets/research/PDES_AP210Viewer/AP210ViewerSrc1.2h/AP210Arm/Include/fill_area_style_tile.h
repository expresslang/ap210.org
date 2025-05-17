#ifndef FILL_AREA_STYLE_TILE_H
#define FILL_AREA_STYLE_TILE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <fill_area_style_tile_shape_select.h>

// Enumerations

class AP210ARM_API fill_area_style_tile:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 469};

   private:
      // Required attributes
      class vector *_tiling_pattern[2000];
      union fill_area_style_tile_shape_select *_tile;
      class positive_ratio_measure *_tiling_scale;

      // Optional attributes

   protected:
      fill_area_style_tile();

   public:
      ~fill_area_style_tile();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fill_area_style_tile *InstanceOf(ARMObject *);
      static fill_area_style_tile *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fill_area_style_tile *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
