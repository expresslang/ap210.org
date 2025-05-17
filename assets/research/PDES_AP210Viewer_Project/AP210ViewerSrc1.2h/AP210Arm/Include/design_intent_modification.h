#ifndef DESIGN_INTENT_MODIFICATION_H
#define DESIGN_INTENT_MODIFICATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <restriction_basis_item.h>

// Enumerations

class AP210ARM_API design_intent_modification:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 457};

   private:
      // Required attributes
      class stratum_feature *_design_intent;
      union restriction_basis_item *_modification_causal_item;

      // Optional attributes

   protected:
      design_intent_modification();

   public:
      ~design_intent_modification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static design_intent_modification *InstanceOf(ARMObject *);
      static design_intent_modification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static design_intent_modification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
