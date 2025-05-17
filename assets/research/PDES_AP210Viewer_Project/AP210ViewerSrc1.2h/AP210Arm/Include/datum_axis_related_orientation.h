#ifndef DATUM_AXIS_RELATED_ORIENTATION_H
#define DATUM_AXIS_RELATED_ORIENTATION_H

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
#include <centre_type.h>

class AP210ARM_API datum_axis_related_orientation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 412};

   private:
      // Required attributes
      class datum_axis_and_tolerance_zone_orienting_relationship *_orienting_relationship;
      centre_type::centre_type _orientation_type;

      // Optional attributes

   protected:
      datum_axis_related_orientation();

   public:
      ~datum_axis_related_orientation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_axis_related_orientation *InstanceOf(ARMObject *);
      static datum_axis_related_orientation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_axis_related_orientation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
