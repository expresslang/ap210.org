#ifndef TOLERANCE_ZONE_H
#define TOLERANCE_ZONE_H

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

class AP210ARM_API tolerance_zone:
public non_feature_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 117};

   private:
      // Required attributes
      class tolerance_zone_boundary *_zone_boundary;

      // Optional attributes

   protected:
      tolerance_zone();

   public:
      ~tolerance_zone();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone *InstanceOf(ARMObject *);
      static tolerance_zone *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
