#ifndef STRATUM_MAKE_FROM_RELATIONSHIP_H
#define STRATUM_MAKE_FROM_RELATIONSHIP_H

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

class AP210ARM_API stratum_make_from_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 814};

   private:
      // Required attributes
      class stratum *_reusable_stratum;
      class stratum *_resultant_stratum;

      // Optional attributes

   protected:
      stratum_make_from_relationship();

   public:
      ~stratum_make_from_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_make_from_relationship *InstanceOf(ARMObject *);
      static stratum_make_from_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_make_from_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
