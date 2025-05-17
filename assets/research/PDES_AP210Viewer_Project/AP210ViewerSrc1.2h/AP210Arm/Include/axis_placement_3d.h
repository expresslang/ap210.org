#ifndef AXIS_PLACEMENT_3D_H
#define AXIS_PLACEMENT_3D_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <axis_placement.h>

// Unions

// Enumerations

class AP210ARM_API axis_placement_3d:
public axis_placement
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 214};

   private:
      // Required attributes

      // Optional attributes

   protected:
      axis_placement_3d();

   public:
      ~axis_placement_3d();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static axis_placement_3d *InstanceOf(ARMObject *);
      static axis_placement_3d *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static axis_placement_3d *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
