#ifndef MOUNTING_RESTRICTION_AREA_H
#define MOUNTING_RESTRICTION_AREA_H

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

class AP210ARM_API mounting_restriction_area:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 319};

   private:
      // Required attributes
      class feature_shape_occurrence *_area;
      class interconnect_module_component_surface_feature *_mounting_surface;
      class interconnect_module_component *_scope;

      // Optional attributes

   protected:
      mounting_restriction_area();

   public:
      ~mounting_restriction_area();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static mounting_restriction_area *InstanceOf(ARMObject *);
      static mounting_restriction_area *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static mounting_restriction_area *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
