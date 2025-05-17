#ifndef PROFILE_RELATED_POSITIONAL_BOUNDARY_H
#define PROFILE_RELATED_POSITIONAL_BOUNDARY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <positional_boundary.h>

// Unions

// Enumerations

class AP210ARM_API profile_related_positional_boundary:
public positional_boundary
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 126};

   private:
      // Required attributes

      // Optional attributes

   protected:
      profile_related_positional_boundary();

   public:
      ~profile_related_positional_boundary();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static profile_related_positional_boundary *InstanceOf(ARMObject *);
      static profile_related_positional_boundary *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static profile_related_positional_boundary *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
