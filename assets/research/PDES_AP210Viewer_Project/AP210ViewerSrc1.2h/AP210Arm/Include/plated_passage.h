#ifndef PLATED_PASSAGE_H
#define PLATED_PASSAGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <plated_inter_stratum_feature.h>

// Unions

// Enumerations

class AP210ARM_API plated_passage:
public plated_inter_stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 228};

   private:
      // Required attributes

      // Optional attributes

   protected:
      plated_passage();

   public:
      ~plated_passage();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static plated_passage *InstanceOf(ARMObject *);
      static plated_passage *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static plated_passage *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
