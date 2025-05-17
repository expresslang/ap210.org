#ifndef PARALLEL_SHAPE_ELEMENT_RELATIONSHIP_H
#define PARALLEL_SHAPE_ELEMENT_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <shape_element_relationship.h>

// Unions

// Enumerations

class AP210ARM_API parallel_shape_element_relationship:
public shape_element_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 672};

   private:
      // Required attributes

      // Optional attributes

   protected:
      parallel_shape_element_relationship();

   public:
      ~parallel_shape_element_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static parallel_shape_element_relationship *InstanceOf(ARMObject *);
      static parallel_shape_element_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static parallel_shape_element_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
