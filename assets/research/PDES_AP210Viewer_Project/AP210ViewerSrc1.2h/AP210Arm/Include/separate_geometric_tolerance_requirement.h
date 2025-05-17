#ifndef SEPARATE_GEOMETRIC_TOLERANCE_REQUIREMENT_H
#define SEPARATE_GEOMETRIC_TOLERANCE_REQUIREMENT_H

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

class AP210ARM_API separate_geometric_tolerance_requirement:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 776};

   private:
      // Required attributes
      class geometric_tolerance_with_referenced_datum_system *_separated_geometric_tolerances[2000];

      // Optional attributes

   protected:
      separate_geometric_tolerance_requirement();

   public:
      ~separate_geometric_tolerance_requirement();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static separate_geometric_tolerance_requirement *InstanceOf(ARMObject *);
      static separate_geometric_tolerance_requirement *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static separate_geometric_tolerance_requirement *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
