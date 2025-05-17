#ifndef VIEWING_PLANE_DEFINITION_H
#define VIEWING_PLANE_DEFINITION_H

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

class AP210ARM_API viewing_plane_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 845};

   private:
      // Required attributes
      class viewing_plane *_defined_viewing_plane;
      class axis_placement *_viewing_plane_representation;

      // Optional attributes

   protected:
      viewing_plane_definition();

   public:
      ~viewing_plane_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static viewing_plane_definition *InstanceOf(ARMObject *);
      static viewing_plane_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static viewing_plane_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
