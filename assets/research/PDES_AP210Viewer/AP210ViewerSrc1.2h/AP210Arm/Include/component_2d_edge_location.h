#ifndef COMPONENT_2D_EDGE_LOCATION_H
#define COMPONENT_2D_EDGE_LOCATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <component_2d_location.h>

// Unions

// Enumerations

class AP210ARM_API component_2d_edge_location:
public component_2d_location
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 292};

   private:
      // Required attributes
      class assembly_joint *_reference_terminal_assembly_joint;

      // Optional attributes

   protected:
      component_2d_edge_location();

   public:
      ~component_2d_edge_location();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_2d_edge_location *InstanceOf(ARMObject *);
      static component_2d_edge_location *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_2d_edge_location *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
