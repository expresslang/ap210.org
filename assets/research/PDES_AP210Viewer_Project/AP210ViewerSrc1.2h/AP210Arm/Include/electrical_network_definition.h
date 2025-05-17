#ifndef ELECTRICAL_NETWORK_DEFINITION_H
#define ELECTRICAL_NETWORK_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <functional_unit_network_definition.h>

// Unions

// Enumerations

class AP210ARM_API electrical_network_definition:
public functional_unit_network_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 530};

   private:
      // Required attributes

      // Optional attributes

   protected:
      electrical_network_definition();

   public:
      ~electrical_network_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static electrical_network_definition *InstanceOf(ARMObject *);
      static electrical_network_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static electrical_network_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
