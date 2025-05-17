#ifndef PCA_H
#define PCA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_module.h>

// Unions

// Enumerations

class AP210ARM_API pca:
public assembly_module
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 641};

   private:
      // Required attributes

      // Optional attributes

   protected:
      pca();

   public:
      ~pca();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static pca *InstanceOf(ARMObject *);
      static pca *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static pca *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
