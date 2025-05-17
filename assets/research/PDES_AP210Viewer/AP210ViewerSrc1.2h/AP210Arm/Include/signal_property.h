#ifndef SIGNAL_PROPERTY_H
#define SIGNAL_PROPERTY_H

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

class AP210ARM_API signal_property:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 355};

   private:
      // Required attributes
      class representation *_signal_property_representation;
      class signal *_characterized_signal;
      class external_definition *_signal_property_category;

      // Optional attributes

   protected:
      signal_property();

   public:
      ~signal_property();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static signal_property *InstanceOf(ARMObject *);
      static signal_property *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static signal_property *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
