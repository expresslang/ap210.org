#ifndef DIMENSION_ALONG_CURVE_H
#define DIMENSION_ALONG_CURVE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <dimensional_location.h>

// Unions

// Enumerations

class AP210ARM_API dimension_along_curve:
public dimensional_location
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 497};

   private:
      // Required attributes
      class shape_element *_path;

      // Optional attributes

   protected:
      dimension_along_curve();

   public:
      ~dimension_along_curve();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimension_along_curve *InstanceOf(ARMObject *);
      static dimension_along_curve *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimension_along_curve *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
