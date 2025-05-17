#ifndef SHAPE_ELEMENT_BOUNDARY_RELATIONSHIP_H
#define SHAPE_ELEMENT_BOUNDARY_RELATIONSHIP_H

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

class AP210ARM_API shape_element_boundary_relationship:
public shape_element_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 778};

   private:
      // Required attributes

      // Optional attributes

   protected:
      shape_element_boundary_relationship();

   public:
      ~shape_element_boundary_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static shape_element_boundary_relationship *InstanceOf(ARMObject *);
      static shape_element_boundary_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static shape_element_boundary_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
