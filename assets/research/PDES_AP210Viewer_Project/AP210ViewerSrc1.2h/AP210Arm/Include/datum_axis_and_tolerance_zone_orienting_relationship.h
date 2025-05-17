#ifndef DATUM_AXIS_AND_TOLERANCE_ZONE_ORIENTING_RELATIONSHIP_H
#define DATUM_AXIS_AND_TOLERANCE_ZONE_ORIENTING_RELATIONSHIP_H

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

class AP210ARM_API datum_axis_and_tolerance_zone_orienting_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 411};

   private:
      // Required attributes
      class tolerance_zone *_oriented_tolerance_zone;
      class datum_axis *_orienting_datum_axis;

      // Optional attributes

   protected:
      datum_axis_and_tolerance_zone_orienting_relationship();

   public:
      ~datum_axis_and_tolerance_zone_orienting_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_axis_and_tolerance_zone_orienting_relationship *InstanceOf(ARMObject *);
      static datum_axis_and_tolerance_zone_orienting_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_axis_and_tolerance_zone_orienting_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
