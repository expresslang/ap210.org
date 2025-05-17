#ifndef DIMENSION_QUALIFIER_H
#define DIMENSION_QUALIFIER_H

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

class AP210ARM_API dimension_qualifier:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 500};

   private:
      // Required attributes
      class dimensional_characteristic *_qualified_dimensions[2000];

      // Optional attributes

   protected:
      dimension_qualifier();

   public:
      ~dimension_qualifier();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimension_qualifier *InstanceOf(ARMObject *);
      static dimension_qualifier *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimension_qualifier *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
