#ifndef ASSEMBLY_TECHNOLOGY_SPECIFICATION_H
#define ASSEMBLY_TECHNOLOGY_SPECIFICATION_H

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

class AP210ARM_API assembly_technology_specification:
public process_specification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 212};

   private:
      // Required attributes

      // Optional attributes

   protected:
      assembly_technology_specification();

   public:
      ~assembly_technology_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_technology_specification *InstanceOf(ARMObject *);
      static assembly_technology_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_technology_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
