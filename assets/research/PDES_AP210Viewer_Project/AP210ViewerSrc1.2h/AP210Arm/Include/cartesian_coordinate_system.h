#ifndef CARTESIAN_COORDINATE_SYSTEM_H
#define CARTESIAN_COORDINATE_SYSTEM_H

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
#include <two_or_three_dimensional.h>
#include <degree_or_radian.h>

class AP210ARM_API cartesian_coordinate_system:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 42};

   private:
      // Required attributes
      STR _length_unit_of_measure;
      two_or_three_dimensional::two_or_three_dimensional _dimensionality;
      degree_or_radian::degree_or_radian _angle_unit_of_measure;
      class length_data_element *_length_uncertainty;

      // Optional attributes
      class angle_data_element *_angular_uncertainty;

   protected:
      cartesian_coordinate_system();

   public:
      ~cartesian_coordinate_system();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static cartesian_coordinate_system *InstanceOf(ARMObject *);
      static cartesian_coordinate_system *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static cartesian_coordinate_system *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
