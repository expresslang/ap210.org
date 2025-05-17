#ifndef RIGHT_ANGULAR_WEDGE_H
#define RIGHT_ANGULAR_WEDGE_H

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

class AP210ARM_API right_angular_wedge:
public csg_primitive
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 751};

   private:
      // Required attributes

      // Optional attributes

   protected:
      right_angular_wedge();

   public:
      ~right_angular_wedge();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static right_angular_wedge *InstanceOf(ARMObject *);
      static right_angular_wedge *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static right_angular_wedge *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
