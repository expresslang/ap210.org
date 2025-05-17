#ifndef COMPOSITE_CURVE_H
#define COMPOSITE_CURVE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <curve.h>

// Unions

// Enumerations

class AP210ARM_API composite_curve:
public curve
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 343};

   private:
      // Required attributes
      class composite_curve_segment *_curve_segment[2000];

      // Optional attributes

   protected:
      composite_curve();

   public:
      ~composite_curve();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static composite_curve *InstanceOf(ARMObject *);
      static composite_curve *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static composite_curve *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
