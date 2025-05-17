#ifndef RUNOUT_TOLERANCE_ZONE_ORIENTING_RELATIONSHIP_H
#define RUNOUT_TOLERANCE_ZONE_ORIENTING_RELATIONSHIP_H

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

class AP210ARM_API runout_tolerance_zone_orienting_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 774};

   private:
      // Required attributes
      class tolerance_zone *_oriented_zone;
      class directed_axis *_orienting_axis;

      // Optional attributes

   protected:
      runout_tolerance_zone_orienting_relationship();

   public:
      ~runout_tolerance_zone_orienting_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static runout_tolerance_zone_orienting_relationship *InstanceOf(ARMObject *);
      static runout_tolerance_zone_orienting_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static runout_tolerance_zone_orienting_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
