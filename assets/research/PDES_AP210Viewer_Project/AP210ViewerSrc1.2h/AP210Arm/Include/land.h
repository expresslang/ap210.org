#ifndef LAND_H
#define LAND_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <stratum_feature_template_component.h>

// Unions

// Enumerations

class AP210ARM_API land:
public stratum_feature_template_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 334};

   private:
      // Required attributes

      // Optional attributes
      class land_physical_template *_alternate_land_definition;

   protected:
      land();

   public:
      ~land();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static land *InstanceOf(ARMObject *);
      static land *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static land *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
