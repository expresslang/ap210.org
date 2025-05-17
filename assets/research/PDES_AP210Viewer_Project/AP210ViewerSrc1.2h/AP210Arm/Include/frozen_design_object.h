#ifndef FROZEN_DESIGN_OBJECT_H
#define FROZEN_DESIGN_OBJECT_H

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

class AP210ARM_API frozen_design_object:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 556};

   private:
      // Required attributes

      // Optional attributes

   protected:
      frozen_design_object();

   public:
      ~frozen_design_object();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static frozen_design_object *InstanceOf(ARMObject *);
      static frozen_design_object *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static frozen_design_object *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
