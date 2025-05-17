#ifndef DOCUMENTATION_LAYER_TECHNOLOGY_H
#define DOCUMENTATION_LAYER_TECHNOLOGY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <stratum_technology.h>

// Unions

// Enumerations

class AP210ARM_API documentation_layer_technology:
public stratum_technology
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 511};

   private:
      // Required attributes
      STR _documentation_layer_purpose;

      // Optional attributes

   protected:
      documentation_layer_technology();

   public:
      ~documentation_layer_technology();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static documentation_layer_technology *InstanceOf(ARMObject *);
      static documentation_layer_technology *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static documentation_layer_technology *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
