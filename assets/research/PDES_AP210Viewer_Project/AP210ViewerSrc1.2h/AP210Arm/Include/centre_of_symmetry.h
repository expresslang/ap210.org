#ifndef CENTRE_OF_SYMMETRY_H
#define CENTRE_OF_SYMMETRY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <derived_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API centre_of_symmetry:
public derived_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 134};

   private:
      // Required attributes

      // Optional attributes

   protected:
      centre_of_symmetry();

   public:
      ~centre_of_symmetry();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static centre_of_symmetry *InstanceOf(ARMObject *);
      static centre_of_symmetry *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static centre_of_symmetry *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
