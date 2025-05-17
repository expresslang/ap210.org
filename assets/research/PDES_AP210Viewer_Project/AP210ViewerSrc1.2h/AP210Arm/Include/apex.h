#ifndef APEX_H
#define APEX_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <derived_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API apex:
public derived_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 150};

   private:
      // Required attributes

      // Optional attributes

   protected:
      apex();

   public:
      ~apex();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static apex *InstanceOf(ARMObject *);
      static apex *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static apex *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
