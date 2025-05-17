#ifndef SETOFCONICAL_TOLERANCE_ZONE_BOUNDARY_DIAMETRICAL_SIZE_CHARACTERISTIC_H
#define SETOFCONICAL_TOLERANCE_ZONE_BOUNDARY_DIAMETRICAL_SIZE_CHARACTERISTIC_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 384};

   private:
      // Required attributes
      class conical_tolerance_zone_boundary_diametrical_size_characteristic *_conical_tolerance_zone_boundary_diametrical_size_characteristic;

      // Optional attributes

   protected:
      SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic();

   public:
      ~SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic *InstanceOf(ARMObject *);
      static SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
