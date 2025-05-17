#ifndef TOLERANCE_ZONE_AND_VIEWING_PLANE_ORIENTING_RELATIONSHIP_H
#define TOLERANCE_ZONE_AND_VIEWING_PLANE_ORIENTING_RELATIONSHIP_H

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

class AP210ARM_API tolerance_zone_and_viewing_plane_orienting_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 838};

   private:
      // Required attributes
      class viewing_plane *_orienting_viewing_plane;
      class tolerance_zone *_oriented_tolerance_zone;

      // Optional attributes

   protected:
      tolerance_zone_and_viewing_plane_orienting_relationship();

   public:
      ~tolerance_zone_and_viewing_plane_orienting_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_zone_and_viewing_plane_orienting_relationship *InstanceOf(ARMObject *);
      static tolerance_zone_and_viewing_plane_orienting_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_zone_and_viewing_plane_orienting_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
