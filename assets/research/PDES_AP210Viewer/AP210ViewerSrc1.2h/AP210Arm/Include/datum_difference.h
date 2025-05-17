#ifndef DATUM_DIFFERENCE_H
#define DATUM_DIFFERENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <shape_element_relationship.h>

// Unions

// Enumerations

class AP210ARM_API datum_difference:
public shape_element_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 413};

   private:
      // Required attributes

      // Optional attributes

   protected:
      datum_difference();

   public:
      ~datum_difference();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_difference *InstanceOf(ARMObject *);
      static datum_difference *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_difference *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
