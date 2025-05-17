#ifndef INTERFACE_MOUNTED_JOIN_H
#define INTERFACE_MOUNTED_JOIN_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API interface_mounted_join:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 608};

   private:
      // Required attributes
      class component_interface_terminal *_connection_to_interconnect_module_component;
      class component_terminal *_access_to_interface_mounted_component;

      // Optional attributes

   protected:
      interface_mounted_join();

   public:
      ~interface_mounted_join();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interface_mounted_join *InstanceOf(ARMObject *);
      static interface_mounted_join *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interface_mounted_join *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
