#ifndef PART_DEVICE_H
#define PART_DEVICE_H

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

class AP210ARM_API part_device:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 487};

   private:
      // Required attributes
      class packaged_part *_defined_packaged_part;
      class bare_die *_included_device;
      STR _item_identification;

      // Optional attributes
      class ee_material *_bonding_agent;

   protected:
      part_device();

   public:
      ~part_device();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_device *InstanceOf(ARMObject *);
      static part_device *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_device *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
