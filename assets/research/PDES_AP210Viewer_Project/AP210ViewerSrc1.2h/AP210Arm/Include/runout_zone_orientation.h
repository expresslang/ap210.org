#ifndef RUNOUT_ZONE_ORIENTATION_H
#define RUNOUT_ZONE_ORIENTATION_H

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

class AP210ARM_API runout_zone_orientation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 773};

   private:
      // Required attributes
      class runout_tolerance_zone_orienting_relationship *_oriented_relationship;
      class angle_data_element *_semi_angle_value;

      // Optional attributes

   protected:
      runout_zone_orientation();

   public:
      ~runout_zone_orientation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static runout_zone_orientation *InstanceOf(ARMObject *);
      static runout_zone_orientation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static runout_zone_orientation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
