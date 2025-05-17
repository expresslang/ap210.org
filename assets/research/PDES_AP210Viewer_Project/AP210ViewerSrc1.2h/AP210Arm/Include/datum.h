#ifndef DATUM_H
#define DATUM_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <non_feature_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API datum:
public non_feature_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 110};

   private:
      // Required attributes

      // Optional attributes

   protected:
      datum();

   public:
      ~datum();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum *InstanceOf(ARMObject *);
      static datum *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
