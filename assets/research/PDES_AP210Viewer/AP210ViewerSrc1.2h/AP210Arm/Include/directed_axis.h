#ifndef DIRECTED_AXIS_H
#define DIRECTED_AXIS_H

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

class AP210ARM_API directed_axis:
public non_feature_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 509};

   private:
      // Required attributes
      class centre_axis *_axis_to_be_oriented;
      class shape_element *_start_shape_element;
      class shape_element *_end_shape_element;

      // Optional attributes

   protected:
      directed_axis();

   public:
      ~directed_axis();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static directed_axis *InstanceOf(ARMObject *);
      static directed_axis *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static directed_axis *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
