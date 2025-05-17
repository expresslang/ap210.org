#ifndef VIEWING_PLANE_BASED_ORIENTATION_H
#define VIEWING_PLANE_BASED_ORIENTATION_H

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

class AP210ARM_API viewing_plane_based_orientation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 844};

   private:
      // Required attributes
      class tolerance_zone_and_viewing_plane_orienting_relationship *_orienting_relationship;
      class viewing_plane_definition *_viewing_plane_specification;

      // Optional attributes

   protected:
      viewing_plane_based_orientation();

   public:
      ~viewing_plane_based_orientation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static viewing_plane_based_orientation *InstanceOf(ARMObject *);
      static viewing_plane_based_orientation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static viewing_plane_based_orientation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
