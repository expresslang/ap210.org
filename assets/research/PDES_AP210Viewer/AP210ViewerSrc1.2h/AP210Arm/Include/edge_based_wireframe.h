#ifndef EDGE_BASED_WIREFRAME_H
#define EDGE_BASED_WIREFRAME_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <bound_volume_shape.h>

// Unions

// Enumerations

class AP210ARM_API edge_based_wireframe:
public bound_volume_shape
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 513};

   private:
      // Required attributes

      // Optional attributes

   protected:
      edge_based_wireframe();

   public:
      ~edge_based_wireframe();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static edge_based_wireframe *InstanceOf(ARMObject *);
      static edge_based_wireframe *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static edge_based_wireframe *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
