#ifndef BOUNDARY_SIZE_CHARACTERISTIC_H
#define BOUNDARY_SIZE_CHARACTERISTIC_H

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

class AP210ARM_API boundary_size_characteristic:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 249};

   private:
      // Required attributes
      class length_data_element *_tolerance_value;

      // Optional attributes
      class length_data_element *_maximum_tolerance_value;

   protected:
      boundary_size_characteristic();

   public:
      ~boundary_size_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static boundary_size_characteristic *InstanceOf(ARMObject *);
      static boundary_size_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static boundary_size_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
