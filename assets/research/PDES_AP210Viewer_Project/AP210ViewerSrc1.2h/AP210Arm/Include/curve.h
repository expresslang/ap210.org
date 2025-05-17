#ifndef CURVE_H
#define CURVE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <feature_shape_definition.h>

// Unions

// Enumerations

class AP210ARM_API curve:
public feature_shape_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 252};

   private:
      // Required attributes

      // Optional attributes

   protected:
      curve();

   public:
      ~curve();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static curve *InstanceOf(ARMObject *);
      static curve *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static curve *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
