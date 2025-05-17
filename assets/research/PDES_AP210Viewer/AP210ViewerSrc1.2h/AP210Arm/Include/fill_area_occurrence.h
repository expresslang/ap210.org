#ifndef FILL_AREA_OCCURRENCE_H
#define FILL_AREA_OCCURRENCE_H

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

class AP210ARM_API fill_area_occurrence:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 465};

   private:
      // Required attributes
      class fill_area_style *_style[2000];
      class fill_area *_filled_area;
      class cartesian_point *_fill_style_target;
      class curve_style *_boundary_style;

      // Optional attributes

   protected:
      fill_area_occurrence();

   public:
      ~fill_area_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fill_area_occurrence *InstanceOf(ARMObject *);
      static fill_area_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fill_area_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
