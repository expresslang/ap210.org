#ifndef COMPONENT_TERMINATION_PASSAGE_H
#define COMPONENT_TERMINATION_PASSAGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <plated_passage.h>

// Unions

// Enumerations

class AP210ARM_API component_termination_passage:
public plated_passage
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 332};

   private:
      // Required attributes

      // Optional attributes

   protected:
      component_termination_passage();

   public:
      ~component_termination_passage();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_termination_passage *InstanceOf(ARMObject *);
      static component_termination_passage *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_termination_passage *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
