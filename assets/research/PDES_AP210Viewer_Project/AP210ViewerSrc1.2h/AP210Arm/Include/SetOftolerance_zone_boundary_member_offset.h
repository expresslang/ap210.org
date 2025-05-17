#ifndef SETOFTOLERANCE_ZONE_BOUNDARY_MEMBER_OFFSET_H
#define SETOFTOLERANCE_ZONE_BOUNDARY_MEMBER_OFFSET_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOftolerance_zone_boundary_member_offset:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 737};

   private:
      // Required attributes
      class tolerance_zone_boundary_member_offset *_tolerance_zone_boundary_member_offset;

      // Optional attributes

   protected:
      SetOftolerance_zone_boundary_member_offset();

   public:
      ~SetOftolerance_zone_boundary_member_offset();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOftolerance_zone_boundary_member_offset *InstanceOf(ARMObject *);
      static SetOftolerance_zone_boundary_member_offset *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOftolerance_zone_boundary_member_offset *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
