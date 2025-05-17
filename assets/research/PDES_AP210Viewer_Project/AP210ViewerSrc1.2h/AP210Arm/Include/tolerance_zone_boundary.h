#ifndef TOLERANCE_ZONE_BOUNDARY_H
#define TOLERANCE_ZONE_BOUNDARY_H

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

class AP210ARM_API tolerance_zone_boundary:
public non_feature_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 118};

   private:
      // Required attributes

      // Optional attributes

   protected:
      tolerance_zone_boundary();

   public:
      ~tolerance_zone_boundary();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone_boundary *InstanceOf(ARMObject *);
      static tolerance_zone_boundary *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone_boundary *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
