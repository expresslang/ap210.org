#ifndef SETOFLAYER_CONNECTION_POINT_LINK_H
#define SETOFLAYER_CONNECTION_POINT_LINK_H

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

class AP210ARM_API SetOflayer_connection_point_link:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 367};

   private:
      // Required attributes
      class layer_connection_point_link *_layer_connection_point_link;

      // Optional attributes

   protected:
      SetOflayer_connection_point_link();

   public:
      ~SetOflayer_connection_point_link();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOflayer_connection_point_link *InstanceOf(ARMObject *);
      static SetOflayer_connection_point_link *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOflayer_connection_point_link *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
