#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H

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

class AP210ARM_API technology:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 64};

   private:
      // Required attributes
      class process_specification *_process_technology;
      class external_definition *_classification;
      class ee_material *_material_product_system;

      // Optional attributes

   protected:
      technology();

   public:
      ~technology();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static technology *InstanceOf(ARMObject *);
      static technology *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static technology *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
