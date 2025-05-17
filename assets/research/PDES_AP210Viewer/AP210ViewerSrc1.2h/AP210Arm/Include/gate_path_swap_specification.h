#ifndef GATE_PATH_SWAP_SPECIFICATION_H
#define GATE_PATH_SWAP_SPECIFICATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <change_design_object_management_relationship.h>

// Unions

// Enumerations

class AP210ARM_API gate_path_swap_specification:
public change_design_object_management_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 570};

   private:
      // Required attributes

      // Optional attributes

   protected:
      gate_path_swap_specification();

   public:
      ~gate_path_swap_specification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static gate_path_swap_specification *InstanceOf(ARMObject *);
      static gate_path_swap_specification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static gate_path_swap_specification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
