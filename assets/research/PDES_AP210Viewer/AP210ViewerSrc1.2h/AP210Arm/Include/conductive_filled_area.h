#ifndef CONDUCTIVE_FILLED_AREA_H
#define CONDUCTIVE_FILLED_AREA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <stratum_feature.h>

// Unions

// Enumerations

class AP210ARM_API conductive_filled_area:
public stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 363};

   private:
      // Required attributes

      // Optional attributes

   protected:
      conductive_filled_area();

   public:
      ~conductive_filled_area();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static conductive_filled_area *InstanceOf(ARMObject *);
      static conductive_filled_area *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static conductive_filled_area *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
