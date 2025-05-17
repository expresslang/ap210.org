#ifndef DESIGN_INTENT_MODIFICATION_SEQUENCE_H
#define DESIGN_INTENT_MODIFICATION_SEQUENCE_H

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

class AP210ARM_API design_intent_modification_sequence:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 482};

   private:
      // Required attributes
      class design_intent_modification *_precedent_modification;
      class design_intent_modification *_subsequent_modification;

      // Optional attributes

   protected:
      design_intent_modification_sequence();

   public:
      ~design_intent_modification_sequence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static design_intent_modification_sequence *InstanceOf(ARMObject *);
      static design_intent_modification_sequence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static design_intent_modification_sequence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
