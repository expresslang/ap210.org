#ifndef SETOFINTERFACE_MOUNTED_JOIN_H
#define SETOFINTERFACE_MOUNTED_JOIN_H

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

class AP210ARM_API SetOfinterface_mounted_join:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 701};

   private:
      // Required attributes
      class interface_mounted_join *_interface_mounted_join;

      // Optional attributes

   protected:
      SetOfinterface_mounted_join();

   public:
      ~SetOfinterface_mounted_join();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfinterface_mounted_join *InstanceOf(ARMObject *);
      static SetOfinterface_mounted_join *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfinterface_mounted_join *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
