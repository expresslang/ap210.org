#ifndef UNSUPPORTED_PASSAGE_H
#define UNSUPPORTED_PASSAGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <inter_stratum_feature.h>

// Unions

// Enumerations

class AP210ARM_API unsupported_passage:
public inter_stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 852};

   private:
      // Required attributes

      // Optional attributes

   protected:
      unsupported_passage();

   public:
      ~unsupported_passage();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static unsupported_passage *InstanceOf(ARMObject *);
      static unsupported_passage *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static unsupported_passage *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
