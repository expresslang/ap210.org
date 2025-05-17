#ifndef DESIGN_LAYER_TECHNOLOGY_H
#define DESIGN_LAYER_TECHNOLOGY_H

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
#include <layer_purpose.h>
#include <layer_position.h>

class AP210ARM_API design_layer_technology:
public stratum_technology
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 483};

   private:
      // Required attributes
      layer_purpose::layer_purpose _design_layer_purpose;
      layer_position::layer_position _design_layer_position;

      // Optional attributes

   protected:
      design_layer_technology();

   public:
      ~design_layer_technology();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static design_layer_technology *InstanceOf(ARMObject *);
      static design_layer_technology *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static design_layer_technology *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
