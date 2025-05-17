#ifndef STRATUM_H
#define STRATUM_H

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

class AP210ARM_API stratum:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 28};

   private:
      // Required attributes
      STR _name;
      class stratum_technology *_of_technology;

      // Optional attributes
      class external_definition *_stratum_usage;

   protected:
      stratum();

   public:
      ~stratum();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum *InstanceOf(ARMObject *);
      static stratum *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
