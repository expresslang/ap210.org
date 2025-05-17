#ifndef VIA_AND_CONTACT_SIZE_DEPENDENT_NON_FUNCTIONAL_LAND_H
#define VIA_AND_CONTACT_SIZE_DEPENDENT_NON_FUNCTIONAL_LAND_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <non_functional_land.h>

// Unions

// Enumerations

class AP210ARM_API via_and_contact_size_dependent_non_functional_land:
public non_functional_land
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 857};

   private:
      // Required attributes
      class via *_reference_via;

      // Optional attributes

   protected:
      via_and_contact_size_dependent_non_functional_land();

   public:
      ~via_and_contact_size_dependent_non_functional_land();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static via_and_contact_size_dependent_non_functional_land *InstanceOf(ARMObject *);
      static via_and_contact_size_dependent_non_functional_land *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static via_and_contact_size_dependent_non_functional_land *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
