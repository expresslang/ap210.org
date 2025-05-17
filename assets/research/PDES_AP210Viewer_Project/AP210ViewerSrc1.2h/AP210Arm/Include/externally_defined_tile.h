#ifndef EXTERNALLY_DEFINED_TILE_H
#define EXTERNALLY_DEFINED_TILE_H

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

class AP210ARM_API externally_defined_tile:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 472};

   private:
      // Required attributes

      // Optional attributes

   protected:
      externally_defined_tile();

   public:
      ~externally_defined_tile();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static externally_defined_tile *InstanceOf(ARMObject *);
      static externally_defined_tile *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static externally_defined_tile *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
