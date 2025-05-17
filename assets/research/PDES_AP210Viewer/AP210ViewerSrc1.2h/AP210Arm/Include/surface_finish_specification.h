#ifndef SURFACE_FINISH_SPECIFICATION_H
#define SURFACE_FINISH_SPECIFICATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <material_specification.h>

// Unions

// Enumerations

class AP210ARM_API surface_finish_specification:
public material_specification
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 818};

   private:
      // Required attributes

      // Optional attributes

   protected:
      surface_finish_specification();

   public:
      ~surface_finish_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static surface_finish_specification *InstanceOf(ARMObject *);
      static surface_finish_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static surface_finish_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
