#ifndef ADVANCED_B_REP_H
#define ADVANCED_B_REP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <bound_volume_shape.h>

// Unions

// Enumerations

class AP210ARM_API advanced_b_rep:
public bound_volume_shape
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 39};

   private:
      // Required attributes

      // Optional attributes

   protected:
      advanced_b_rep();

   public:
      ~advanced_b_rep();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static advanced_b_rep *InstanceOf(ARMObject *);
      static advanced_b_rep *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static advanced_b_rep *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
