#ifndef DIMENSION_SET_H
#define DIMENSION_SET_H

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

class AP210ARM_API dimension_set:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 506};

   private:
      // Required attributes
      class dimensional_characteristic *_associated_dimensions[2000];

      // Optional attributes

   protected:
      dimension_set();

   public:
      ~dimension_set();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimension_set *InstanceOf(ARMObject *);
      static dimension_set *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimension_set *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
