#ifndef PART_TERMINAL_H
#define PART_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_feature.h>

// Unions

// Enumerations

class AP210ARM_API part_terminal:
public part_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 201};

   private:
      // Required attributes

      // Optional attributes

   protected:
      part_terminal();

   public:
      ~part_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_terminal *InstanceOf(ARMObject *);
      static part_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
