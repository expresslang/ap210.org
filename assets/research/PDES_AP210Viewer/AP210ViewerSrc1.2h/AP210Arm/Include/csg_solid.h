#ifndef CSG_SOLID_H
#define CSG_SOLID_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <bound_volume_shape.h>

// Unions

// Enumerations

class AP210ARM_API csg_solid:
public bound_volume_shape
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 403};

   private:
      // Required attributes

      // Optional attributes

   protected:
      csg_solid();

   public:
      ~csg_solid();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static csg_solid *InstanceOf(ARMObject *);
      static csg_solid *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static csg_solid *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
