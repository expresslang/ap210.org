#ifndef COUNTERSUNK_PASSAGE_TEMPLATE_H
#define COUNTERSUNK_PASSAGE_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <unsupported_passage_template.h>

// Unions

// Enumerations

class AP210ARM_API countersunk_passage_template:
public unsupported_passage_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 402};

   private:
      // Required attributes
      class unsupported_passage_template *_constant_diameter_passage;
      class blind_passage_template *_tapered_passage;

      // Optional attributes

   protected:
      countersunk_passage_template();

   public:
      ~countersunk_passage_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static countersunk_passage_template *InstanceOf(ARMObject *);
      static countersunk_passage_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static countersunk_passage_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
