#ifndef SETOFEE_MATERIAL_H
#define SETOFEE_MATERIAL_H

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

class AP210ARM_API SetOfee_material:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 69};

   private:
      // Required attributes
      class ee_material *_ee_material;

      // Optional attributes

   protected:
      SetOfee_material();

   public:
      ~SetOfee_material();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfee_material *InstanceOf(ARMObject *);
      static SetOfee_material *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfee_material *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
