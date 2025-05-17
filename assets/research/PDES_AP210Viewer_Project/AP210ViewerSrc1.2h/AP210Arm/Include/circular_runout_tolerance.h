#ifndef CIRCULAR_RUNOUT_TOLERANCE_H
#define CIRCULAR_RUNOUT_TOLERANCE_H

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

class AP210ARM_API circular_runout_tolerance:
public geometric_tolerance_with_referenced_datum_system
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 287};

   private:
      // Required attributes

      // Optional attributes

   protected:
      circular_runout_tolerance();

   public:
      ~circular_runout_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static circular_runout_tolerance *InstanceOf(ARMObject *);
      static circular_runout_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static circular_runout_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
