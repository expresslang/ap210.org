#ifndef SETOFINTER_STRATUM_EXTENT_H
#define SETOFINTER_STRATUM_EXTENT_H

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

class AP210ARM_API SetOfinter_stratum_extent:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 342};

   private:
      // Required attributes
      class inter_stratum_extent *_inter_stratum_extent;

      // Optional attributes

   protected:
      SetOfinter_stratum_extent();

   public:
      ~SetOfinter_stratum_extent();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfinter_stratum_extent *InstanceOf(ARMObject *);
      static SetOfinter_stratum_extent *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfinter_stratum_extent *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
