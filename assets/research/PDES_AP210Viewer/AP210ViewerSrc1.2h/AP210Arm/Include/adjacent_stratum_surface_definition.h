#ifndef ADJACENT_STRATUM_SURFACE_DEFINITION_H
#define ADJACENT_STRATUM_SURFACE_DEFINITION_H

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

class AP210ARM_API adjacent_stratum_surface_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 26};

   private:
      // Required attributes
      STR _name;
      class stratum_surface *_precedent_surface;
      class stratum_surface *_subsequent_surface;

      // Optional attributes

   protected:
      adjacent_stratum_surface_definition();

   public:
      ~adjacent_stratum_surface_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static adjacent_stratum_surface_definition *InstanceOf(ARMObject *);
      static adjacent_stratum_surface_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static adjacent_stratum_surface_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
