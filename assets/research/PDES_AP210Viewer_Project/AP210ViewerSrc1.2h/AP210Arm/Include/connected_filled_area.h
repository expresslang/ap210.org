#ifndef CONNECTED_FILLED_AREA_H
#define CONNECTED_FILLED_AREA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <conductive_filled_area.h>

// Unions

// Enumerations

class AP210ARM_API connected_filled_area:
public conductive_filled_area
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 386};

   private:
      // Required attributes
      class intra_stratum_join_relationship *_implementation_requirement;

      // Optional attributes

   protected:
      connected_filled_area();

   public:
      ~connected_filled_area();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static connected_filled_area *InstanceOf(ARMObject *);
      static connected_filled_area *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static connected_filled_area *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
