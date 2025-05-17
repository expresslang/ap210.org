#ifndef DATUM_BASED_VECTOR_ORIENTATION_H
#define DATUM_BASED_VECTOR_ORIENTATION_H

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

class AP210ARM_API datum_based_vector_orientation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 105};

   private:
      // Required attributes
      class direction_element *_direction_components[2000];

      // Optional attributes

   protected:
      datum_based_vector_orientation();

   public:
      ~datum_based_vector_orientation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_based_vector_orientation *InstanceOf(ARMObject *);
      static datum_based_vector_orientation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_based_vector_orientation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
