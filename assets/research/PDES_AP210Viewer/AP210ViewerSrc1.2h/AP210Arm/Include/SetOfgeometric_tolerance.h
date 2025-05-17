#ifndef SETOFGEOMETRIC_TOLERANCE_H
#define SETOFGEOMETRIC_TOLERANCE_H

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

class AP210ARM_API SetOfgeometric_tolerance:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 574};

   private:
      // Required attributes
      class geometric_tolerance *_geometric_tolerance;

      // Optional attributes

   protected:
      SetOfgeometric_tolerance();

   public:
      ~SetOfgeometric_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfgeometric_tolerance *InstanceOf(ARMObject *);
      static SetOfgeometric_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfgeometric_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
