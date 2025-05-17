#ifndef SETOFCONNECTION_ZONE_H
#define SETOFCONNECTION_ZONE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfconnection_zone:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 82};

   private:
      // Required attributes
      class connection_zone *_connection_zone;

      // Optional attributes

   protected:
      SetOfconnection_zone();

   public:
      ~SetOfconnection_zone();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfconnection_zone *InstanceOf(ARMObject *);
      static SetOfconnection_zone *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfconnection_zone *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
