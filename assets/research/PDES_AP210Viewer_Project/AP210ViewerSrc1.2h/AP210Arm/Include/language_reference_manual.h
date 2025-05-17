#ifndef LANGUAGE_REFERENCE_MANUAL_H
#define LANGUAGE_REFERENCE_MANUAL_H

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

class AP210ARM_API language_reference_manual:
public ee_specification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 54};

   private:
      // Required attributes

      // Optional attributes

   protected:
      language_reference_manual();

   public:
      ~language_reference_manual();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static language_reference_manual *InstanceOf(ARMObject *);
      static language_reference_manual *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static language_reference_manual *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
