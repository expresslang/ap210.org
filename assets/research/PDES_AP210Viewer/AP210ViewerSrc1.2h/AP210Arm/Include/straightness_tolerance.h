#ifndef STRAIGHTNESS_TOLERANCE_H
#define STRAIGHTNESS_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <geometric_tolerance_without_referenced_datum_system.h>

// Unions

// Enumerations

class AP210ARM_API straightness_tolerance:
public geometric_tolerance_without_referenced_datum_system
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 798};

   private:
      // Required attributes

      // Optional attributes

   protected:
      straightness_tolerance();

   public:
      ~straightness_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static straightness_tolerance *InstanceOf(ARMObject *);
      static straightness_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static straightness_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
