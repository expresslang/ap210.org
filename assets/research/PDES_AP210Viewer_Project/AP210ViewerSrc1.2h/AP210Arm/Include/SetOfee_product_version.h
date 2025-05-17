#ifndef SETOFEE_PRODUCT_VERSION_H
#define SETOFEE_PRODUCT_VERSION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfee_product_version:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 267};

   private:
      // Required attributes
      class ee_product_version *_ee_product_version;

      // Optional attributes

   protected:
      SetOfee_product_version();

   public:
      ~SetOfee_product_version();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfee_product_version *InstanceOf(ARMObject *);
      static SetOfee_product_version *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfee_product_version *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
