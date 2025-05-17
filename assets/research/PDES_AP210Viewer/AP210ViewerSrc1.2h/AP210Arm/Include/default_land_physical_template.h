#ifndef DEFAULT_LAND_PHYSICAL_TEMPLATE_H
#define DEFAULT_LAND_PHYSICAL_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <land_physical_template.h>

// Unions

// Enumerations

class AP210ARM_API default_land_physical_template:
public land_physical_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 434};

   private:
      // Required attributes
      class stratum_technology *_of_stratum_technology;

      // Optional attributes

   protected:
      default_land_physical_template();

   public:
      ~default_land_physical_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static default_land_physical_template *InstanceOf(ARMObject *);
      static default_land_physical_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static default_land_physical_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
