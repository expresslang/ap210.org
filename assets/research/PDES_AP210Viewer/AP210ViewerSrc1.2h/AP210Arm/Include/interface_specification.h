#ifndef INTERFACE_SPECIFICATION_H
#define INTERFACE_SPECIFICATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <design_specification.h>

// Unions

// Enumerations

class AP210ARM_API interface_specification:
public design_specification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 611};

   private:
      // Required attributes

      // Optional attributes

   protected:
      interface_specification();

   public:
      ~interface_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interface_specification *InstanceOf(ARMObject *);
      static interface_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interface_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
