#ifndef SETOFINTERCONNECT_MODULE_DESIGN_OBJECT_SELECT_H
#define SETOFINTERCONNECT_MODULE_DESIGN_OBJECT_SELECT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <interconnect_module_design_object_select.h>

// Enumerations

class AP210ARM_API SetOfinterconnect_module_design_object_select:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 587};

   private:
      // Required attributes
      union interconnect_module_design_object_select *_interconnect_module_design_object_select;

      // Optional attributes

   protected:
      SetOfinterconnect_module_design_object_select();

   public:
      ~SetOfinterconnect_module_design_object_select();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfinterconnect_module_design_object_select *InstanceOf(ARMObject *);
      static SetOfinterconnect_module_design_object_select *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfinterconnect_module_design_object_select *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
