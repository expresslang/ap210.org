#ifndef TEST_SPECIFICATION_H
#define TEST_SPECIFICATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_specification.h>

// Unions

// Enumerations

class AP210ARM_API test_specification:
public ee_specification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 559};

   private:
      // Required attributes

      // Optional attributes

   protected:
      test_specification();

   public:
      ~test_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static test_specification *InstanceOf(ARMObject *);
      static test_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static test_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
