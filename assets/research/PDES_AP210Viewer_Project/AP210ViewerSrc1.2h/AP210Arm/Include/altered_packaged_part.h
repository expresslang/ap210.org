#ifndef ALTERED_PACKAGED_PART_H
#define ALTERED_PACKAGED_PART_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <packaged_part.h>

// Unions

// Enumerations

class AP210ARM_API altered_packaged_part:
public packaged_part
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 86};

   private:
      // Required attributes
      class packaged_part *_base_packaged_part;

      // Optional attributes

   protected:
      altered_packaged_part();

   public:
      ~altered_packaged_part();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static altered_packaged_part *InstanceOf(ARMObject *);
      static altered_packaged_part *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static altered_packaged_part *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
