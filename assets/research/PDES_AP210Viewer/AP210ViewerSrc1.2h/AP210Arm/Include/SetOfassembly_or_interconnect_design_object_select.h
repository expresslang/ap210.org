#ifndef SETOFASSEMBLY_OR_INTERCONNECT_DESIGN_OBJECT_SELECT_H
#define SETOFASSEMBLY_OR_INTERCONNECT_DESIGN_OBJECT_SELECT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <assembly_or_interconnect_design_object_select.h>

// Enumerations

class AP210ARM_API SetOfassembly_or_interconnect_design_object_select:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 631};

   private:
      // Required attributes
      union assembly_or_interconnect_design_object_select *_assembly_or_interconnect_design_object_select;

      // Optional attributes

   protected:
      SetOfassembly_or_interconnect_design_object_select();

   public:
      ~SetOfassembly_or_interconnect_design_object_select();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfassembly_or_interconnect_design_object_select *InstanceOf(ARMObject *);
      static SetOfassembly_or_interconnect_design_object_select *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfassembly_or_interconnect_design_object_select *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
