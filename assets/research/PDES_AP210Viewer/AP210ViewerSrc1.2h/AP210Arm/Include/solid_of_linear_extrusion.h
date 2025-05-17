#ifndef SOLID_OF_LINEAR_EXTRUSION_H
#define SOLID_OF_LINEAR_EXTRUSION_H

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

class AP210ARM_API solid_of_linear_extrusion:
public bound_volume_shape
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 789};

   private:
      // Required attributes

      // Optional attributes

   protected:
      solid_of_linear_extrusion();

   public:
      ~solid_of_linear_extrusion();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static solid_of_linear_extrusion *InstanceOf(ARMObject *);
      static solid_of_linear_extrusion *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static solid_of_linear_extrusion *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
