#ifndef GEOMETRIC_TOLERANCE_H
#define GEOMETRIC_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <constraining_element_definitions.h>
#include <toleranceable_shape_element.h>

// Enumerations

class AP210ARM_API geometric_tolerance:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 115};

   private:
      // Required attributes
      union constraining_element_definitions *_tolerance_zone_or_boundary_definition;
      union toleranceable_shape_element *_toleranced_shape_element;

      // Optional attributes

   protected:
      geometric_tolerance();

   public:
      ~geometric_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static geometric_tolerance *InstanceOf(ARMObject *);
      static geometric_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static geometric_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
