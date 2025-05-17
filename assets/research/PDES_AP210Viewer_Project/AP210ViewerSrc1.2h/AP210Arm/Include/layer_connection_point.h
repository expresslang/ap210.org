#ifndef LAYER_CONNECTION_POINT_H
#define LAYER_CONNECTION_POINT_H

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

class AP210ARM_API layer_connection_point:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 369};

   private:
      // Required attributes
      STR _name;
      class design_layer_stratum *_resident_design_layer_stratum;

      // Optional attributes

   protected:
      layer_connection_point();

   public:
      ~layer_connection_point();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static layer_connection_point *InstanceOf(ARMObject *);
      static layer_connection_point *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static layer_connection_point *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
