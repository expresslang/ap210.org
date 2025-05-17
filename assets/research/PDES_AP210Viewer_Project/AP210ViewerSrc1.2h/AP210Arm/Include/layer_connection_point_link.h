#ifndef LAYER_CONNECTION_POINT_LINK_H
#define LAYER_CONNECTION_POINT_LINK_H

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

class AP210ARM_API layer_connection_point_link:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 368};

   private:
      // Required attributes
      class layer_connection_point *_precedent_point;
      class layer_connection_point *_subsequent_point;

      // Optional attributes

   protected:
      layer_connection_point_link();

   public:
      ~layer_connection_point_link();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static layer_connection_point_link *InstanceOf(ARMObject *);
      static layer_connection_point_link *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static layer_connection_point_link *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
