#ifndef DIRECTION_ELEMENT_H
#define DIRECTION_ELEMENT_H

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

class AP210ARM_API direction_element:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 107};

   private:
      // Required attributes
      class datum_based_direction_vector *_direction;
      class angle_data_element *_angle_value;
      class datum_plane *_base_datum_plane;
      class datum_based_direction_vector *_direction_of_half_datum_plane;

      // Optional attributes

   protected:
      direction_element();

   public:
      ~direction_element();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static direction_element *InstanceOf(ARMObject *);
      static direction_element *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static direction_element *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
