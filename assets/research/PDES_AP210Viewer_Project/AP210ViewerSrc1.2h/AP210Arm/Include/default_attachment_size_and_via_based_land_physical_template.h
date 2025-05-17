#ifndef DEFAULT_ATTACHMENT_SIZE_AND_VIA_BASED_LAND_PHYSICAL_TEMPLATE_H
#define DEFAULT_ATTACHMENT_SIZE_AND_VIA_BASED_LAND_PHYSICAL_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <default_via_based_land_physical_template.h>
#include <default_attachment_size_based_land_physical_template.h>

// Unions

// Enumerations

class AP210ARM_API default_attachment_size_and_via_based_land_physical_template:
public default_via_based_land_physical_template,
public default_attachment_size_based_land_physical_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 436};

   private:
      // Required attributes

      // Optional attributes

   protected:
      default_attachment_size_and_via_based_land_physical_template();

   public:
      ~default_attachment_size_and_via_based_land_physical_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static default_attachment_size_and_via_based_land_physical_template *InstanceOf(ARMObject *);
      static default_attachment_size_and_via_based_land_physical_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static default_attachment_size_and_via_based_land_physical_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
