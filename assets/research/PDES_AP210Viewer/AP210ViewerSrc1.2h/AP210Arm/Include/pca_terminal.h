#ifndef PCA_TERMINAL_H
#define PCA_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_module_terminal.h>

// Unions

// Enumerations

class AP210ARM_API pca_terminal:
public assembly_module_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 331};

   private:
      // Required attributes

      // Optional attributes

   protected:
      pca_terminal();

   public:
      ~pca_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static pca_terminal *InstanceOf(ARMObject *);
      static pca_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static pca_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
