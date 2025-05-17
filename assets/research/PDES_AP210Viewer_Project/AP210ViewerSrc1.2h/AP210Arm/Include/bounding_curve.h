#ifndef BOUNDING_CURVE_H
#define BOUNDING_CURVE_H

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

class AP210ARM_API bounding_curve:
public curve
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 251};

   private:
      // Required attributes
      class external_definition *_mapping_function;
      class trimmed_line *_basis_curve;

      // Optional attributes

   protected:
      bounding_curve();

   public:
      ~bounding_curve();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static bounding_curve *InstanceOf(ARMObject *);
      static bounding_curve *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static bounding_curve *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
