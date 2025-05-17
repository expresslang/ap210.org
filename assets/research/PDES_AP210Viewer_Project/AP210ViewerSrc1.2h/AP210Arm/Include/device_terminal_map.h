#ifndef DEVICE_TERMINAL_MAP_H
#define DEVICE_TERMINAL_MAP_H

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

class AP210ARM_API device_terminal_map:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 489};

   private:
      // Required attributes
      class packaged_part_terminal *_target_terminal;
      class part_device_terminal *_mapped_device_terminal;

      // Optional attributes

   protected:
      device_terminal_map();

   public:
      ~device_terminal_map();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static device_terminal_map *InstanceOf(ARMObject *);
      static device_terminal_map *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static device_terminal_map *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
