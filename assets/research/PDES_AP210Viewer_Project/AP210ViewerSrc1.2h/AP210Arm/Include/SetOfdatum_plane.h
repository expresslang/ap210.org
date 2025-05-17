#ifndef SETOFDATUM_PLANE_H
#define SETOFDATUM_PLANE_H

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

class AP210ARM_API SetOfdatum_plane:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 143};

   private:
      // Required attributes
      class datum_plane *_datum_plane;

      // Optional attributes

   protected:
      SetOfdatum_plane();

   public:
      ~SetOfdatum_plane();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfdatum_plane *InstanceOf(ARMObject *);
      static SetOfdatum_plane *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfdatum_plane *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
