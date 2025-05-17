#ifndef LAYER_H
#define LAYER_H

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

class AP210ARM_API layer:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 627};

   private:
      // Required attributes
      class inter_stratum_extent *_extent;
      STR _name;

      // Optional attributes
      class external_definition *_layer_usage;

   protected:
      layer();

   public:
      ~layer();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static layer *InstanceOf(ARMObject *);
      static layer *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static layer *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
