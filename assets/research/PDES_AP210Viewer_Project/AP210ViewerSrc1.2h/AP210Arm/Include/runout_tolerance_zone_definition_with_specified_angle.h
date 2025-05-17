#ifndef RUNOUT_TOLERANCE_ZONE_DEFINITION_WITH_SPECIFIED_ANGLE_H
#define RUNOUT_TOLERANCE_ZONE_DEFINITION_WITH_SPECIFIED_ANGLE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <tolerance_zone_definition.h>

// Unions

// Enumerations

class AP210ARM_API runout_tolerance_zone_definition_with_specified_angle:
public tolerance_zone_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 772};

   private:
      // Required attributes
      class runout_zone_orientation *_runout_orientation;

      // Optional attributes

   protected:
      runout_tolerance_zone_definition_with_specified_angle();

   public:
      ~runout_tolerance_zone_definition_with_specified_angle();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static runout_tolerance_zone_definition_with_specified_angle *InstanceOf(ARMObject *);
      static runout_tolerance_zone_definition_with_specified_angle *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static runout_tolerance_zone_definition_with_specified_angle *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
