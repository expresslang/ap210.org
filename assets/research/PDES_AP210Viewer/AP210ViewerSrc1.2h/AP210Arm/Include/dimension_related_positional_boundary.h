#ifndef DIMENSION_RELATED_POSITIONAL_BOUNDARY_H
#define DIMENSION_RELATED_POSITIONAL_BOUNDARY_H

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

class AP210ARM_API dimension_related_positional_boundary:
public positional_boundary
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 502};

   private:
      // Required attributes
      class positional_boundary_member *_boundary_members[2000];
      class physical_feature_or_part_template *_constrained_physical_feature;

      // Optional attributes

   protected:
      dimension_related_positional_boundary();

   public:
      ~dimension_related_positional_boundary();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimension_related_positional_boundary *InstanceOf(ARMObject *);
      static dimension_related_positional_boundary *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimension_related_positional_boundary *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
