#ifndef FILL_AREA_STYLE_TILE_SOLID_REGION_H
#define FILL_AREA_STYLE_TILE_SOLID_REGION_H

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

class AP210ARM_API fill_area_style_tile_solid_region:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 474};

   private:
      // Required attributes

      // Optional attributes

   protected:
      fill_area_style_tile_solid_region();

   public:
      ~fill_area_style_tile_solid_region();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fill_area_style_tile_solid_region *InstanceOf(ARMObject *);
      static fill_area_style_tile_solid_region *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fill_area_style_tile_solid_region *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
