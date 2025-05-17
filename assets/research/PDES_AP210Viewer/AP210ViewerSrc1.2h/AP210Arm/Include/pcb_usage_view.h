#ifndef PCB_USAGE_VIEW_H
#define PCB_USAGE_VIEW_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <interconnect_module_usage_view.h>

// Unions

// Enumerations

class AP210ARM_API pcb_usage_view:
public interconnect_module_usage_view
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 686};

   private:
      // Required attributes

      // Optional attributes

   protected:
      pcb_usage_view();

   public:
      ~pcb_usage_view();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static pcb_usage_view *InstanceOf(ARMObject *);
      static pcb_usage_view *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static pcb_usage_view *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
