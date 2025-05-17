#ifndef CONNECTION_ZONE_INTERFACE_PLANE_RELATIONSHIP_H
#define CONNECTION_ZONE_INTERFACE_PLANE_RELATIONSHIP_H

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

class AP210ARM_API connection_zone_interface_plane_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 388};

   private:
      // Required attributes
      class seating_plane *_interface_plane;
      class connection_zone *_mating_zone;
      STR _name;

      // Optional attributes

   protected:
      connection_zone_interface_plane_relationship();

   public:
      ~connection_zone_interface_plane_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static connection_zone_interface_plane_relationship *InstanceOf(ARMObject *);
      static connection_zone_interface_plane_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static connection_zone_interface_plane_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
