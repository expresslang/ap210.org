#ifndef CSG_PRIMITIVE_H
#define CSG_PRIMITIVE_H

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

class AP210ARM_API csg_primitive:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 233};

   private:
      // Required attributes

      // Optional attributes

   protected:
      csg_primitive();

   public:
      ~csg_primitive();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static csg_primitive *InstanceOf(ARMObject *);
      static csg_primitive *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static csg_primitive *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
