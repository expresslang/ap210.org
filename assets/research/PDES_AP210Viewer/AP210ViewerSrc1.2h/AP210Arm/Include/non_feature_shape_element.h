#ifndef NON_FEATURE_SHAPE_ELEMENT_H
#define NON_FEATURE_SHAPE_ELEMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <shape_element.h>

// Unions

// Enumerations

class AP210ARM_API non_feature_shape_element:
public shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 73};

   private:
      // Required attributes

      // Optional attributes
      class feature_shape_occurrence *_element_shape[2000];

   protected:
      non_feature_shape_element();

   public:
      ~non_feature_shape_element();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static non_feature_shape_element *InstanceOf(ARMObject *);
      static non_feature_shape_element *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static non_feature_shape_element *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
