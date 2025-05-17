#ifndef ORGANIZATION_H
#define ORGANIZATION_H

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

class AP210ARM_API organization:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 8};

   private:
      // Required attributes
      STR _identifier;

      // Optional attributes
      STR _Address;

   protected:
      organization();

   public:
      ~organization();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static organization *InstanceOf(ARMObject *);
      static organization *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static organization *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
