#ifndef CLOSED_CURVE_H
#define CLOSED_CURVE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <curve.h>

// Unions

// Enumerations

class AP210ARM_API closed_curve:
public curve
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 290};

   private:
      // Required attributes

      // Optional attributes

   protected:
      closed_curve();

   public:
      ~closed_curve();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static closed_curve *InstanceOf(ARMObject *);
      static closed_curve *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static closed_curve *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
