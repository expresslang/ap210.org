#ifndef STRATUM_INTERCONNECT_MODULE_3D_POSITION_H
#define STRATUM_INTERCONNECT_MODULE_3D_POSITION_H

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

class AP210ARM_API stratum_interconnect_module_3d_position:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 812};

   private:
      // Required attributes
      class interconnect_module_stratum_assembly_relationship *_stratum_component;
      class stratum_3d_shape *_stratum_shape;
      class physical_unit_3d_shape *_interconnect_module_shape;
      class axis_placement_3d *_transformation;

      // Optional attributes

   protected:
      stratum_interconnect_module_3d_position();

   public:
      ~stratum_interconnect_module_3d_position();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_interconnect_module_3d_position *InstanceOf(ARMObject *);
      static stratum_interconnect_module_3d_position *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_interconnect_module_3d_position *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
