#ifndef RIGHT_CIRCULAR_CYLINDER_H
#define RIGHT_CIRCULAR_CYLINDER_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <csg_primitive.h>

// Unions

// Enumerations

class AP210ARM_API right_circular_cylinder:
public csg_primitive
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 752};

   private:
      // Required attributes

      // Optional attributes

   protected:
      right_circular_cylinder();

   public:
      ~right_circular_cylinder();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static right_circular_cylinder *InstanceOf(ARMObject *);
      static right_circular_cylinder *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static right_circular_cylinder *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
