#ifndef SETOFCURVE_H
#define SETOFCURVE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfcurve:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 480};

   private:
      // Required attributes
      class curve *_curve;

      // Optional attributes

   protected:
      SetOfcurve();

   public:
      ~SetOfcurve();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfcurve *InstanceOf(ARMObject *);
      static SetOfcurve *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfcurve *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
