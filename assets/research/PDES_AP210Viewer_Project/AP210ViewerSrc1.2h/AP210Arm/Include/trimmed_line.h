#ifndef TRIMMED_LINE_H
#define TRIMMED_LINE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <curve.h>

// Unions

// Enumerations

class AP210ARM_API trimmed_line:
public curve
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 253};

   private:
      // Required attributes

      // Optional attributes

   protected:
      trimmed_line();

   public:
      ~trimmed_line();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static trimmed_line *InstanceOf(ARMObject *);
      static trimmed_line *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static trimmed_line *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
