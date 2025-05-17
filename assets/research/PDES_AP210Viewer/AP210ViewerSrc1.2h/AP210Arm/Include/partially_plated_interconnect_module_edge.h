#ifndef PARTIALLY_PLATED_INTERCONNECT_MODULE_EDGE_H
#define PARTIALLY_PLATED_INTERCONNECT_MODULE_EDGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <interconnect_module_edge.h>

// Unions

// Enumerations

class AP210ARM_API partially_plated_interconnect_module_edge:
public interconnect_module_edge
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 683};

   private:
      // Required attributes

      // Optional attributes

   protected:
      partially_plated_interconnect_module_edge();

   public:
      ~partially_plated_interconnect_module_edge();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static partially_plated_interconnect_module_edge *InstanceOf(ARMObject *);
      static partially_plated_interconnect_module_edge *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static partially_plated_interconnect_module_edge *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
