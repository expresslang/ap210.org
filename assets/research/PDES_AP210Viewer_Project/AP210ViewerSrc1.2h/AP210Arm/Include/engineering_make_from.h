#ifndef ENGINEERING_MAKE_FROM_H
#define ENGINEERING_MAKE_FROM_H

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

class AP210ARM_API engineering_make_from:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 534};

   private:
      // Required attributes
      class ee_product_definition *_base_design;
      class ee_product_definition *_resultant_design;

      // Optional attributes

   protected:
      engineering_make_from();

   public:
      ~engineering_make_from();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static engineering_make_from *InstanceOf(ARMObject *);
      static engineering_make_from *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static engineering_make_from *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
