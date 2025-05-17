#ifndef DATUM_AXIS_H
#define DATUM_AXIS_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <datum.h>

// Unions

// Enumerations

class AP210ARM_API datum_axis:
public datum
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 145};

   private:
      // Required attributes

      // Optional attributes

   protected:
      datum_axis();

   public:
      ~datum_axis();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_axis *InstanceOf(ARMObject *);
      static datum_axis *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_axis *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
