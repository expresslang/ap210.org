#ifndef DERIVED_SHAPE_ELEMENT_H
#define DERIVED_SHAPE_ELEMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <non_feature_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API derived_shape_element:
public non_feature_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 135};

   private:
      // Required attributes

      // Optional attributes

   protected:
      derived_shape_element();

   public:
      ~derived_shape_element();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static derived_shape_element *InstanceOf(ARMObject *);
      static derived_shape_element *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static derived_shape_element *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
