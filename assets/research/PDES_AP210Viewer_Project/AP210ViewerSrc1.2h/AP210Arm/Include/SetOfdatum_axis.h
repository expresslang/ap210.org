#ifndef SETOFDATUM_AXIS_H
#define SETOFDATUM_AXIS_H

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

class AP210ARM_API SetOfdatum_axis:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 144};

   private:
      // Required attributes
      class datum_axis *_datum_axis;

      // Optional attributes

   protected:
      SetOfdatum_axis();

   public:
      ~SetOfdatum_axis();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfdatum_axis *InstanceOf(ARMObject *);
      static SetOfdatum_axis *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfdatum_axis *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
