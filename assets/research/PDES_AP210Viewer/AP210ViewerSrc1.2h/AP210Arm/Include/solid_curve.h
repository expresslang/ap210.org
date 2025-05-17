#ifndef SOLID_CURVE_H
#define SOLID_CURVE_H

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

class AP210ARM_API solid_curve:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 375};

   private:
      // Required attributes

      // Optional attributes

   protected:
      solid_curve();

   public:
      ~solid_curve();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static solid_curve *InstanceOf(ARMObject *);
      static solid_curve *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static solid_curve *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
