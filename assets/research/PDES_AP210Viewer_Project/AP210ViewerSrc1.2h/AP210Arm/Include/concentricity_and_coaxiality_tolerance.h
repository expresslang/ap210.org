#ifndef CONCENTRICITY_AND_COAXIALITY_TOLERANCE_H
#define CONCENTRICITY_AND_COAXIALITY_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <geometric_tolerance_with_referenced_datum_system.h>

// Unions

// Enumerations

class AP210ARM_API concentricity_and_coaxiality_tolerance:
public geometric_tolerance_with_referenced_datum_system
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 362};

   private:
      // Required attributes

      // Optional attributes

   protected:
      concentricity_and_coaxiality_tolerance();

   public:
      ~concentricity_and_coaxiality_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static concentricity_and_coaxiality_tolerance *InstanceOf(ARMObject *);
      static concentricity_and_coaxiality_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static concentricity_and_coaxiality_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
