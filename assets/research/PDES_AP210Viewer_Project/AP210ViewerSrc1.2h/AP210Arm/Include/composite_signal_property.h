#ifndef COMPOSITE_SIGNAL_PROPERTY_H
#define COMPOSITE_SIGNAL_PROPERTY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <signal_property.h>

// Unions

// Enumerations

class AP210ARM_API composite_signal_property:
public signal_property
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 354};

   private:
      // Required attributes

      // Optional attributes

   protected:
      composite_signal_property();

   public:
      ~composite_signal_property();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static composite_signal_property *InstanceOf(ARMObject *);
      static composite_signal_property *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static composite_signal_property *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
