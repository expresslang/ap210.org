#ifndef GEOMETRIC_TOLERANCE_QUALIFIER_H
#define GEOMETRIC_TOLERANCE_QUALIFIER_H

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

class AP210ARM_API geometric_tolerance_qualifier:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 573};

   private:
      // Required attributes
      class geometric_tolerance *_qualified_geometric_tolerances[2000];

      // Optional attributes

   protected:
      geometric_tolerance_qualifier();

   public:
      ~geometric_tolerance_qualifier();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static geometric_tolerance_qualifier *InstanceOf(ARMObject *);
      static geometric_tolerance_qualifier *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static geometric_tolerance_qualifier *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
