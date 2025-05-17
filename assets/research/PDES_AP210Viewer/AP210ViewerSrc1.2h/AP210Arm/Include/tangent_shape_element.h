#ifndef TANGENT_SHAPE_ELEMENT_H
#define TANGENT_SHAPE_ELEMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <derived_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API tangent_shape_element:
public derived_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 139};

   private:
      // Required attributes

      // Optional attributes

   protected:
      tangent_shape_element();

   public:
      ~tangent_shape_element();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tangent_shape_element *InstanceOf(ARMObject *);
      static tangent_shape_element *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tangent_shape_element *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
