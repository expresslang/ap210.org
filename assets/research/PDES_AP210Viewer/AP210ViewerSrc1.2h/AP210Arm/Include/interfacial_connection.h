#ifndef INTERFACIAL_CONNECTION_H
#define INTERFACIAL_CONNECTION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <via.h>

// Unions

// Enumerations

class AP210ARM_API interfacial_connection:
public via
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 614};

   private:
      // Required attributes

      // Optional attributes

   protected:
      interfacial_connection();

   public:
      ~interfacial_connection();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interfacial_connection *InstanceOf(ARMObject *);
      static interfacial_connection *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interfacial_connection *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
