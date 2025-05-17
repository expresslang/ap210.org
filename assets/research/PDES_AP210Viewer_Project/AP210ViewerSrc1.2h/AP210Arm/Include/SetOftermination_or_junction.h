#ifndef SETOFTERMINATION_OR_JUNCTION_H
#define SETOFTERMINATION_OR_JUNCTION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <termination_or_junction.h>

// Enumerations

class AP210ARM_API SetOftermination_or_junction:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 276};

   private:
      // Required attributes
      union termination_or_junction *_termination_or_junction;

      // Optional attributes

   protected:
      SetOftermination_or_junction();

   public:
      ~SetOftermination_or_junction();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOftermination_or_junction *InstanceOf(ARMObject *);
      static SetOftermination_or_junction *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOftermination_or_junction *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
