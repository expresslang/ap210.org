#ifndef LINEAR_EXTENSION_H
#define LINEAR_EXTENSION_H

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

class AP210ARM_API linear_extension:
public derived_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 639};

   private:
      // Required attributes

      // Optional attributes

   protected:
      linear_extension();

   public:
      ~linear_extension();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static linear_extension *InstanceOf(ARMObject *);
      static linear_extension *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static linear_extension *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
