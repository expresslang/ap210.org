#ifndef STRATUM_SURFACE_H
#define STRATUM_SURFACE_H

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
#include <stratum_surface_designation.h>

class AP210ARM_API stratum_surface:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 27};

   private:
      // Required attributes
      class stratum *_of_stratum;
      stratum_surface_designation::stratum_surface_designation _name;

      // Optional attributes

   protected:
      stratum_surface();

   public:
      ~stratum_surface();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_surface *InstanceOf(ARMObject *);
      static stratum_surface *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_surface *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
