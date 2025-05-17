#ifndef DEVICE_TERMINAL_MAP_RELATIONSHIP_H
#define DEVICE_TERMINAL_MAP_RELATIONSHIP_H

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

class AP210ARM_API device_terminal_map_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 491};

   private:
      // Required attributes
      class device_terminal_map *_related_device_terminal_map;
      class device_terminal_map *_relating_device_terminal_map;

      // Optional attributes

   protected:
      device_terminal_map_relationship();

   public:
      ~device_terminal_map_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static device_terminal_map_relationship *InstanceOf(ARMObject *);
      static device_terminal_map_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static device_terminal_map_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
