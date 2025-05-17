#ifndef INTER_STRATUM_EXTENT_H
#define INTER_STRATUM_EXTENT_H

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

class AP210ARM_API inter_stratum_extent:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 170};

   private:
      // Required attributes
      class stratum *_from_stratum;
      class stratum *_to_stratum;

      // Optional attributes

   protected:
      inter_stratum_extent();

   public:
      ~inter_stratum_extent();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static inter_stratum_extent *InstanceOf(ARMObject *);
      static inter_stratum_extent *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static inter_stratum_extent *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
