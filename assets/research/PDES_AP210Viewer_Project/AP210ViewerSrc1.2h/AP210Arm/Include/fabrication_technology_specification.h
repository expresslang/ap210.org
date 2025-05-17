#ifndef FABRICATION_TECHNOLOGY_SPECIFICATION_H
#define FABRICATION_TECHNOLOGY_SPECIFICATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <process_specification.h>

// Unions

// Enumerations

class AP210ARM_API fabrication_technology_specification:
public process_specification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 543};

   private:
      // Required attributes

      // Optional attributes

   protected:
      fabrication_technology_specification();

   public:
      ~fabrication_technology_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fabrication_technology_specification *InstanceOf(ARMObject *);
      static fabrication_technology_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fabrication_technology_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
