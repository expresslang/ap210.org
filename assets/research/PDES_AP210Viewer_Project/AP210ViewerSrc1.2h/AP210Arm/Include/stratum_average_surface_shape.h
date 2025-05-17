#ifndef STRATUM_AVERAGE_SURFACE_SHAPE_H
#define STRATUM_AVERAGE_SURFACE_SHAPE_H

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

class AP210ARM_API stratum_average_surface_shape:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 800};

   private:
      // Required attributes
      class stratum_average_surface *_of_surface;

      // Optional attributes

   protected:
      stratum_average_surface_shape();

   public:
      ~stratum_average_surface_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_average_surface_shape *InstanceOf(ARMObject *);
      static stratum_average_surface_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_average_surface_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
