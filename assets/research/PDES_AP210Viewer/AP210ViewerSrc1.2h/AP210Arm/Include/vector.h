#ifndef VECTOR_H
#define VECTOR_H

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

class AP210ARM_API vector:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 471};

   private:
      // Required attributes

      // Optional attributes

   protected:
      vector();

   public:
      ~vector();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static vector *InstanceOf(ARMObject *);
      static vector *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static vector *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
