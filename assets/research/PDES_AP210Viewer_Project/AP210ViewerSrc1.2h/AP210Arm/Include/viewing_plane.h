#ifndef VIEWING_PLANE_H
#define VIEWING_PLANE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <non_feature_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API viewing_plane:
public non_feature_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 839};

   private:
      // Required attributes

      // Optional attributes

   protected:
      viewing_plane();

   public:
      ~viewing_plane();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static viewing_plane *InstanceOf(ARMObject *);
      static viewing_plane *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static viewing_plane *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
