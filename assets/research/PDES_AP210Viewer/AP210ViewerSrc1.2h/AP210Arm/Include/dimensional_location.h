#ifndef DIMENSIONAL_LOCATION_H
#define DIMENSIONAL_LOCATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <dimensional_characteristic.h>

// Unions

// Enumerations

class AP210ARM_API dimensional_location:
public dimensional_characteristic
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 100};

   private:
      // Required attributes
      class shape_element_locating_relationship *_located_elements;
      RoseBoolean _directed;

      // Optional attributes

   protected:
      dimensional_location();

   public:
      ~dimensional_location();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimensional_location *InstanceOf(ARMObject *);
      static dimensional_location *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimensional_location *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
