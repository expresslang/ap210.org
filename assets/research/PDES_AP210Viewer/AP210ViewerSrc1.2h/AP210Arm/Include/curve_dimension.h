#ifndef CURVE_DIMENSION_H
#define CURVE_DIMENSION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <single_boundary_dimension.h>

// Unions

// Enumerations

class AP210ARM_API curve_dimension:
public single_boundary_dimension
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 404};

   private:
      // Required attributes

      // Optional attributes

   protected:
      curve_dimension();

   public:
      ~curve_dimension();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static curve_dimension *InstanceOf(ARMObject *);
      static curve_dimension *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static curve_dimension *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
