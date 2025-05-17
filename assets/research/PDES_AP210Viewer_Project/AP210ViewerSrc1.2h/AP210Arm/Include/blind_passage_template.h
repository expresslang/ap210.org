#ifndef BLIND_PASSAGE_TEMPLATE_H
#define BLIND_PASSAGE_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <unsupported_passage_template.h>

// Unions

// Enumerations
#include <measure_orientation.h>

class AP210ARM_API blind_passage_template:
public unsupported_passage_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 223};

   private:
      // Required attributes
      measure_orientation::measure_orientation _of_measure_orientation;
      class stratum_surface *_datum_reference;
      class shape_dimension_representation *_bottom_distance_from_datum_reference;

      // Optional attributes

   protected:
      blind_passage_template();

   public:
      ~blind_passage_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static blind_passage_template *InstanceOf(ARMObject *);
      static blind_passage_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static blind_passage_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
