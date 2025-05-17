#ifndef SETOFGEOMETRIC_TOLERANCE_WITH_REFERENCED_DATUM_SYSTEM_H
#define SETOFGEOMETRIC_TOLERANCE_WITH_REFERENCED_DATUM_SYSTEM_H

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

class AP210ARM_API SetOfgeometric_tolerance_with_referenced_datum_system:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 777};

   private:
      // Required attributes
      class geometric_tolerance_with_referenced_datum_system *_geometric_tolerance_with_referenced_datum_system;

      // Optional attributes

   protected:
      SetOfgeometric_tolerance_with_referenced_datum_system();

   public:
      ~SetOfgeometric_tolerance_with_referenced_datum_system();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfgeometric_tolerance_with_referenced_datum_system *InstanceOf(ARMObject *);
      static SetOfgeometric_tolerance_with_referenced_datum_system *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfgeometric_tolerance_with_referenced_datum_system *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
