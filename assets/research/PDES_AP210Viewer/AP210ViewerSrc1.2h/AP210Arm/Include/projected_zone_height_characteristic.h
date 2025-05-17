#ifndef PROJECTED_ZONE_HEIGHT_CHARACTERISTIC_H
#define PROJECTED_ZONE_HEIGHT_CHARACTERISTIC_H

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

class AP210ARM_API projected_zone_height_characteristic:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 742};

   private:
      // Required attributes
      class projected_zone_and_base_relationship *_defined_height_of;
      class length_data_element *_projected_height_value;

      // Optional attributes

   protected:
      projected_zone_height_characteristic();

   public:
      ~projected_zone_height_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static projected_zone_height_characteristic *InstanceOf(ARMObject *);
      static projected_zone_height_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static projected_zone_height_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
