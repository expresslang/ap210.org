#ifndef PRE_DEFINED_GEOMETRIC_TOLERANCE_QUALIFIER_H
#define PRE_DEFINED_GEOMETRIC_TOLERANCE_QUALIFIER_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <geometric_tolerance_qualifier.h>

// Unions

// Enumerations
#include <geometric_tolerance_qualifiers.h>

class AP210ARM_API pre_defined_geometric_tolerance_qualifier:
public geometric_tolerance_qualifier
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 720};

   private:
      // Required attributes
      geometric_tolerance_qualifiers::geometric_tolerance_qualifiers _description;

      // Optional attributes

   protected:
      pre_defined_geometric_tolerance_qualifier();

   public:
      ~pre_defined_geometric_tolerance_qualifier();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static pre_defined_geometric_tolerance_qualifier *InstanceOf(ARMObject *);
      static pre_defined_geometric_tolerance_qualifier *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static pre_defined_geometric_tolerance_qualifier *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
