#ifndef PACKAGE_BODY_TOP_SURFACE_H
#define PACKAGE_BODY_TOP_SURFACE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <package_body_surface.h>

// Unions

// Enumerations

class AP210ARM_API package_body_top_surface:
public package_body_surface
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 668};

   private:
      // Required attributes

      // Optional attributes

   protected:
      package_body_top_surface();

   public:
      ~package_body_top_surface();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static package_body_top_surface *InstanceOf(ARMObject *);
      static package_body_top_surface *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static package_body_top_surface *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
