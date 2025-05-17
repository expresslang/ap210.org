#ifndef FIDUCIAL_H
#define FIDUCIAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <laminate_component.h>

// Unions

// Enumerations

class AP210ARM_API fiducial:
public laminate_component
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 548};

   private:
      // Required attributes

      // Optional attributes

   protected:
      fiducial();

   public:
      ~fiducial();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static fiducial *InstanceOf(ARMObject *);
      static fiducial *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static fiducial *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
