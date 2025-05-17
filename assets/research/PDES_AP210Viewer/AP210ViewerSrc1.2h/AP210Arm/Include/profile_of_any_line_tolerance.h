#ifndef PROFILE_OF_ANY_LINE_TOLERANCE_H
#define PROFILE_OF_ANY_LINE_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <geometric_tolerance.h>

// Unions

// Enumerations

class AP210ARM_API profile_of_any_line_tolerance:
public geometric_tolerance
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 352};

   private:
      // Required attributes

      // Optional attributes

   protected:
      profile_of_any_line_tolerance();

   public:
      ~profile_of_any_line_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static profile_of_any_line_tolerance *InstanceOf(ARMObject *);
      static profile_of_any_line_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static profile_of_any_line_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
