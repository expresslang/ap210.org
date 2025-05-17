#ifndef CONNECTION_ZONE_H
#define CONNECTION_ZONE_H

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

class AP210ARM_API connection_zone:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 83};

   private:
      // Required attributes
      class ee_colour *_representation_colour;
      class feature_shape_occurrence *_zone_shape[2000];

      // Optional attributes

   protected:
      connection_zone();

   public:
      ~connection_zone();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static connection_zone *InstanceOf(ARMObject *);
      static connection_zone *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static connection_zone *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
