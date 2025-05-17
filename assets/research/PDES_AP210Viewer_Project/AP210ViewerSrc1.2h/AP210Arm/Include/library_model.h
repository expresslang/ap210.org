#ifndef LIBRARY_MODEL_H
#define LIBRARY_MODEL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <library_ee_product_definition.h>
#include <analytical_model.h>

// Unions

// Enumerations

class AP210ARM_API library_model:
public library_ee_product_definition,
public analytical_model
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 635};

   private:
      // Required attributes

      // Optional attributes

   protected:
      library_model();

   public:
      ~library_model();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static library_model *InstanceOf(ARMObject *);
      static library_model *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static library_model *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
