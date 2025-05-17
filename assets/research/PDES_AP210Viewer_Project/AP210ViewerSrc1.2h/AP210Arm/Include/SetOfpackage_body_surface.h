#ifndef SETOFPACKAGE_BODY_SURFACE_H
#define SETOFPACKAGE_BODY_SURFACE_H

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

class AP210ARM_API SetOfpackage_body_surface:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 717};

   private:
      // Required attributes
      class package_body_surface *_package_body_surface;

      // Optional attributes

   protected:
      SetOfpackage_body_surface();

   public:
      ~SetOfpackage_body_surface();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfpackage_body_surface *InstanceOf(ARMObject *);
      static SetOfpackage_body_surface *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfpackage_body_surface *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
