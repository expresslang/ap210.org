#ifndef DEFAULT_ATTACHMENT_SIZE_BASED_LAND_PHYSICAL_TEMPLATE_H
#define DEFAULT_ATTACHMENT_SIZE_BASED_LAND_PHYSICAL_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <default_land_physical_template.h>

// Unions

// Enumerations

class AP210ARM_API default_attachment_size_based_land_physical_template:
public default_land_physical_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 435};

   private:
      // Required attributes
      class connection_zone *_minimum_attachment_region_size;
      class connection_zone *_maximum_attachment_region_size;

      // Optional attributes

   protected:
      default_attachment_size_based_land_physical_template();

   public:
      ~default_attachment_size_based_land_physical_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static default_attachment_size_based_land_physical_template *InstanceOf(ARMObject *);
      static default_attachment_size_based_land_physical_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static default_attachment_size_based_land_physical_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
