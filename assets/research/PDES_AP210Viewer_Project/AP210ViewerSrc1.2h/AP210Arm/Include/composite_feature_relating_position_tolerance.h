#ifndef COMPOSITE_FEATURE_RELATING_POSITION_TOLERANCE_H
#define COMPOSITE_FEATURE_RELATING_POSITION_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <position_tolerance.h>

// Unions
#include <locating_or_relating_position_tolerance.h>

// Enumerations

class AP210ARM_API composite_feature_relating_position_tolerance:
public position_tolerance
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 347};

   private:
      // Required attributes
      union locating_or_relating_position_tolerance *_refined_control;

      // Optional attributes

   protected:
      composite_feature_relating_position_tolerance();

   public:
      ~composite_feature_relating_position_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static composite_feature_relating_position_tolerance *InstanceOf(ARMObject *);
      static composite_feature_relating_position_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static composite_feature_relating_position_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
