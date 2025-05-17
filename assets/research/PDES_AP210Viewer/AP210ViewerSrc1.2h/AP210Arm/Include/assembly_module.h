#ifndef ASSEMBLY_MODULE_H
#define ASSEMBLY_MODULE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_unit_design_view.h>

// Unions

// Enumerations

class AP210ARM_API assembly_module:
public physical_unit_design_view
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 198};

   private:
      // Required attributes

      // Optional attributes

   protected:
      assembly_module();

   public:
      ~assembly_module();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_module *InstanceOf(ARMObject *);
      static assembly_module *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_module *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
