#ifndef ANGULAR_SIZE_DIMENSION_H
#define ANGULAR_SIZE_DIMENSION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <dimensional_size.h>

// Unions

// Enumerations

class AP210ARM_API angular_size_dimension:
public dimensional_size
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 111};

   private:
      // Required attributes
      RoseBoolean _half_angle;
      RoseBoolean _major_angle;

      // Optional attributes

   protected:
      angular_size_dimension();

   public:
      ~angular_size_dimension();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static angular_size_dimension *InstanceOf(ARMObject *);
      static angular_size_dimension *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static angular_size_dimension *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
