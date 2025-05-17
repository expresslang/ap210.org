#ifndef UNSUPPORTED_PASSAGE_DEPENDENT_NON_FUNCTIONAL_LAND_H
#define UNSUPPORTED_PASSAGE_DEPENDENT_NON_FUNCTIONAL_LAND_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <non_functional_land.h>

// Unions

// Enumerations

class AP210ARM_API unsupported_passage_dependent_non_functional_land:
public non_functional_land
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 853};

   private:
      // Required attributes
      class unsupported_passage *_reference_passage;

      // Optional attributes

   protected:
      unsupported_passage_dependent_non_functional_land();

   public:
      ~unsupported_passage_dependent_non_functional_land();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static unsupported_passage_dependent_non_functional_land *InstanceOf(ARMObject *);
      static unsupported_passage_dependent_non_functional_land *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static unsupported_passage_dependent_non_functional_land *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
