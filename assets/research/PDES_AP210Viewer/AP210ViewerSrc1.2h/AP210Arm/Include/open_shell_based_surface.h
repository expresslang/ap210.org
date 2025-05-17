#ifndef OPEN_SHELL_BASED_SURFACE_H
#define OPEN_SHELL_BASED_SURFACE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <feature_shape_definition.h>

// Unions

// Enumerations

class AP210ARM_API open_shell_based_surface:
public feature_shape_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 317};

   private:
      // Required attributes

      // Optional attributes

   protected:
      open_shell_based_surface();

   public:
      ~open_shell_based_surface();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static open_shell_based_surface *InstanceOf(ARMObject *);
      static open_shell_based_surface *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static open_shell_based_surface *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
