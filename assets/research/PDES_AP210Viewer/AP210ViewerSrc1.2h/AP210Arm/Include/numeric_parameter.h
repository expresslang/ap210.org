#ifndef NUMERIC_PARAMETER_H
#define NUMERIC_PARAMETER_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <characteristic.h>

// Unions

// Enumerations

class AP210ARM_API numeric_parameter:
public characteristic
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 661};

   private:
      // Required attributes

      // Optional attributes

   protected:
      numeric_parameter();

   public:
      ~numeric_parameter();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static numeric_parameter *InstanceOf(ARMObject *);
      static numeric_parameter *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static numeric_parameter *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
