#ifndef CENTRE_POINT_H
#define CENTRE_POINT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <centre_of_symmetry.h>

// Unions

// Enumerations

class AP210ARM_API centre_point:
public centre_of_symmetry
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 137};

   private:
      // Required attributes

      // Optional attributes

   protected:
      centre_point();

   public:
      ~centre_point();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static centre_point *InstanceOf(ARMObject *);
      static centre_point *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static centre_point *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
