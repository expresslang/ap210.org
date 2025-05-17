#ifndef SETOFGEOMETRIC_OR_DIMENSION_SELECT_H
#define SETOFGEOMETRIC_OR_DIMENSION_SELECT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions
#include <geometric_or_dimension_select.h>

// Enumerations

class AP210ARM_API SetOfgeometric_or_dimension_select:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 837};

   private:
      // Required attributes
      union geometric_or_dimension_select *_geometric_or_dimension_select;

      // Optional attributes

   protected:
      SetOfgeometric_or_dimension_select();

   public:
      ~SetOfgeometric_or_dimension_select();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfgeometric_or_dimension_select *InstanceOf(ARMObject *);
      static SetOfgeometric_or_dimension_select *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfgeometric_or_dimension_select *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
