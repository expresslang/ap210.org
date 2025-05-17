#ifndef TOLERANCE_ZONE_BOUNDARY_MEMBER_OFFSET_H
#define TOLERANCE_ZONE_BOUNDARY_MEMBER_OFFSET_H

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
#include <offset_types.h>

class AP210ARM_API tolerance_zone_boundary_member_offset:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 738};

   private:
      // Required attributes
      class tolerance_zone_boundary_member *_offset_tolerance_zone_boundary_member;
      class length_data_element *_offset_value;
      offset_types::offset_types _type_of_offset;

      // Optional attributes

   protected:
      tolerance_zone_boundary_member_offset();

   public:
      ~tolerance_zone_boundary_member_offset();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone_boundary_member_offset *InstanceOf(ARMObject *);
      static tolerance_zone_boundary_member_offset *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone_boundary_member_offset *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
