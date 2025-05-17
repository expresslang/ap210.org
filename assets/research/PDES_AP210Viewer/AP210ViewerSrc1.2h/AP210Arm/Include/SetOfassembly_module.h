#ifndef SETOFASSEMBLY_MODULE_H
#define SETOFASSEMBLY_MODULE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfassembly_module:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 584};

   private:
      // Required attributes
      class assembly_module *_assembly_module;

      // Optional attributes

   protected:
      SetOfassembly_module();

   public:
      ~SetOfassembly_module();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfassembly_module *InstanceOf(ARMObject *);
      static SetOfassembly_module *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfassembly_module *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
