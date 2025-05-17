#ifndef DATUM_BASED_DIRECTION_VECTOR_H
#define DATUM_BASED_DIRECTION_VECTOR_H

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

class AP210ARM_API datum_based_direction_vector:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 108};

   private:
      // Required attributes
      class axis_placement *_direction_vector_representation;
      class datum_plane *_vector_of;
      RoseBoolean _positive_direction_vector;

      // Optional attributes

   protected:
      datum_based_direction_vector();

   public:
      ~datum_based_direction_vector();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_based_direction_vector *InstanceOf(ARMObject *);
      static datum_based_direction_vector *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_based_direction_vector *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
