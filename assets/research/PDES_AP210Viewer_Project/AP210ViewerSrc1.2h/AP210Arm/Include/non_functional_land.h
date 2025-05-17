#ifndef NON_FUNCTIONAL_LAND_H
#define NON_FUNCTIONAL_LAND_H

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

class AP210ARM_API non_functional_land:
public stratum_feature_template_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 336};

   private:
      // Required attributes

      // Optional attributes
      class land_physical_template *_alternate_land_definition;

   protected:
      non_functional_land();

   public:
      ~non_functional_land();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static non_functional_land *InstanceOf(ARMObject *);
      static non_functional_land *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static non_functional_land *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
