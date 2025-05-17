#ifndef AXIS_PLACEMENT_H
#define AXIS_PLACEMENT_H

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

class AP210ARM_API axis_placement:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 103};

   private:
      // Required attributes
      class orientation *_device_orientation;
      class cartesian_point *_translation;

      // Optional attributes

   protected:
      axis_placement();

   public:
      ~axis_placement();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static axis_placement *InstanceOf(ARMObject *);
      static axis_placement *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static axis_placement *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
