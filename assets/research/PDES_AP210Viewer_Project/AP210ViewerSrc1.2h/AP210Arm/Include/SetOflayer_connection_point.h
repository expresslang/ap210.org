#ifndef SETOFLAYER_CONNECTION_POINT_H
#define SETOFLAYER_CONNECTION_POINT_H

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

class AP210ARM_API SetOflayer_connection_point:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 381};

   private:
      // Required attributes
      class layer_connection_point *_layer_connection_point;

      // Optional attributes

   protected:
      SetOflayer_connection_point();

   public:
      ~SetOflayer_connection_point();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOflayer_connection_point *InstanceOf(ARMObject *);
      static SetOflayer_connection_point *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOflayer_connection_point *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
