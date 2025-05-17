#ifndef CARTESIAN_POINT_H
#define CARTESIAN_POINT_H

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

class AP210ARM_API cartesian_point:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 77};

   private:
      // Required attributes

      // Optional attributes

   protected:
      cartesian_point();

   public:
      ~cartesian_point();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static cartesian_point *InstanceOf(ARMObject *);
      static cartesian_point *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static cartesian_point *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
