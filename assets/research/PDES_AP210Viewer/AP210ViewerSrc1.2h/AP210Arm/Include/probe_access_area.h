#ifndef PROBE_ACCESS_AREA_H
#define PROBE_ACCESS_AREA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <laminate_component.h>

// Unions

// Enumerations

class AP210ARM_API probe_access_area:
public laminate_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 616};

   private:
      // Required attributes
      class stratum_feature *_probed_layout_item;
      class connection_zone *_probe_contact_zone;

      // Optional attributes

   protected:
      probe_access_area();

   public:
      ~probe_access_area();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static probe_access_area *InstanceOf(ARMObject *);
      static probe_access_area *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static probe_access_area *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
