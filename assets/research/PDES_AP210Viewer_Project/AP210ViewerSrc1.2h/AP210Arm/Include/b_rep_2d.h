#ifndef B_REP_2D_H
#define B_REP_2D_H

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

class AP210ARM_API b_rep_2d:
public bound_volume_shape
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 215};

   private:
      // Required attributes

      // Optional attributes

   protected:
      b_rep_2d();

   public:
      ~b_rep_2d();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static b_rep_2d *InstanceOf(ARMObject *);
      static b_rep_2d *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static b_rep_2d *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
