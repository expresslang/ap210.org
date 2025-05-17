#ifndef SIGNAL_H
#define SIGNAL_H

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

class AP210ARM_API signal:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 357};

   private:
      // Required attributes
      class external_definition *_signal_category;

      // Optional attributes

   protected:
      signal();

   public:
      ~signal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static signal *InstanceOf(ARMObject *);
      static signal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static signal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
