#ifndef DESIGN_SPECIFICATION_H
#define DESIGN_SPECIFICATION_H

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

class AP210ARM_API design_specification:
public ee_specification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 485};

   private:
      // Required attributes

      // Optional attributes

   protected:
      design_specification();

   public:
      ~design_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static design_specification *InstanceOf(ARMObject *);
      static design_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static design_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
