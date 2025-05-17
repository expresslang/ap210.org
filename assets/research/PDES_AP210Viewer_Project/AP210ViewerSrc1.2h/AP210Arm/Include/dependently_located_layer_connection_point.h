#ifndef DEPENDENTLY_LOCATED_LAYER_CONNECTION_POINT_H
#define DEPENDENTLY_LOCATED_LAYER_CONNECTION_POINT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <layer_connection_point.h>

// Unions
#include <interconnect_module_terminal_or_inter_stratum_feature.h>

// Enumerations

class AP210ARM_API dependently_located_layer_connection_point:
public layer_connection_point
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 444};

   private:
      // Required attributes
      union interconnect_module_terminal_or_inter_stratum_feature *_associated_design_object;

      // Optional attributes

   protected:
      dependently_located_layer_connection_point();

   public:
      ~dependently_located_layer_connection_point();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dependently_located_layer_connection_point *InstanceOf(ARMObject *);
      static dependently_located_layer_connection_point *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dependently_located_layer_connection_point *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
