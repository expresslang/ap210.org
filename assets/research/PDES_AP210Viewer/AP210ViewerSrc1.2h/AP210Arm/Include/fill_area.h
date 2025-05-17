#ifndef FILL_AREA_H
#define FILL_AREA_H

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

class AP210ARM_API fill_area:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 479};

   private:
      // Required attributes
      class curve *_boundary[2000];

      // Optional attributes

   protected:
      fill_area();

   public:
      ~fill_area();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fill_area *InstanceOf(ARMObject *);
      static fill_area *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fill_area *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
