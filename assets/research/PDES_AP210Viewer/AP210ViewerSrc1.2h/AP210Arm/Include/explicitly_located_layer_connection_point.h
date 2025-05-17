#ifndef EXPLICITLY_LOCATED_LAYER_CONNECTION_POINT_H
#define EXPLICITLY_LOCATED_LAYER_CONNECTION_POINT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <layer_connection_point.h>

// Unions

// Enumerations

class AP210ARM_API explicitly_located_layer_connection_point:
public layer_connection_point
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 539};

   private:
      // Required attributes
      class cartesian_point *_location;

      // Optional attributes

   protected:
      explicitly_located_layer_connection_point();

   public:
      ~explicitly_located_layer_connection_point();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static explicitly_located_layer_connection_point *InstanceOf(ARMObject *);
      static explicitly_located_layer_connection_point *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static explicitly_located_layer_connection_point *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
