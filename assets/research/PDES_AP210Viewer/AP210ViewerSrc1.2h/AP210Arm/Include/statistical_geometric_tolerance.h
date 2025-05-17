#ifndef STATISTICAL_GEOMETRIC_TOLERANCE_H
#define STATISTICAL_GEOMETRIC_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <geometric_tolerance.h>

// Unions

// Enumerations

class AP210ARM_API statistical_geometric_tolerance:
public geometric_tolerance
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 795};

   private:
      // Required attributes
      class ee_requirement_occurrence *_statistical_control_requirement;

      // Optional attributes
      class geometric_tolerance *_alternate_tolerance;

   protected:
      statistical_geometric_tolerance();

   public:
      ~statistical_geometric_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static statistical_geometric_tolerance *InstanceOf(ARMObject *);
      static statistical_geometric_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static statistical_geometric_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
