#ifndef GEOMETRIC_ALIGNMENT_H
#define GEOMETRIC_ALIGNMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <derived_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API geometric_alignment:
public derived_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 571};

   private:
      // Required attributes

      // Optional attributes

   protected:
      geometric_alignment();

   public:
      ~geometric_alignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static geometric_alignment *InstanceOf(ARMObject *);
      static geometric_alignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static geometric_alignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
