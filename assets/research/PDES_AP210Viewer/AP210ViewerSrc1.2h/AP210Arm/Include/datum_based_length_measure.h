#ifndef DATUM_BASED_LENGTH_MEASURE_H
#define DATUM_BASED_LENGTH_MEASURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <descriptive_or_geometric_orientation.h>

// Enumerations

class AP210ARM_API datum_based_length_measure:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 208};

   private:
      // Required attributes
      class length_data_element *_measure;
      union descriptive_or_geometric_orientation *_measure_orientation;
      class datum_plane *_of_datum;

      // Optional attributes

   protected:
      datum_based_length_measure();

   public:
      ~datum_based_length_measure();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_based_length_measure *InstanceOf(ARMObject *);
      static datum_based_length_measure *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_based_length_measure *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
