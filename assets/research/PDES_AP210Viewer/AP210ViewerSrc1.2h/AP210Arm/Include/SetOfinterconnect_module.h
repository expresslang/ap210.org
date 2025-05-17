#ifndef SETOFINTERCONNECT_MODULE_H
#define SETOFINTERCONNECT_MODULE_H

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

class AP210ARM_API SetOfinterconnect_module:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 588};

   private:
      // Required attributes
      class interconnect_module *_interconnect_module;

      // Optional attributes

   protected:
      SetOfinterconnect_module();

   public:
      ~SetOfinterconnect_module();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfinterconnect_module *InstanceOf(ARMObject *);
      static SetOfinterconnect_module *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfinterconnect_module *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
