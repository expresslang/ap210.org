#ifndef CIRCULARITY_TOLERANCE_H
#define CIRCULARITY_TOLERANCE_H

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

class AP210ARM_API circularity_tolerance:
public geometric_tolerance_without_referenced_datum_system
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 288};

   private:
      // Required attributes

      // Optional attributes

   protected:
      circularity_tolerance();

   public:
      ~circularity_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static circularity_tolerance *InstanceOf(ARMObject *);
      static circularity_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static circularity_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
