#ifndef SHAPE_ELEMENT_LOCATING_RELATIONSHIP_H
#define SHAPE_ELEMENT_LOCATING_RELATIONSHIP_H

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

class AP210ARM_API shape_element_locating_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 102};

   private:
      // Required attributes
      class shape_element *_locating_shape_element;
      class shape_element *_located_shape_element;

      // Optional attributes

   protected:
      shape_element_locating_relationship();

   public:
      ~shape_element_locating_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static shape_element_locating_relationship *InstanceOf(ARMObject *);
      static shape_element_locating_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static shape_element_locating_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
