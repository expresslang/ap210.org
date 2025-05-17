#ifndef SETOFCURVE_STYLE_H
#define SETOFCURVE_STYLE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfcurve_style:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 638};

   private:
      // Required attributes
      class curve_style *_curve_style;

      // Optional attributes

   protected:
      SetOfcurve_style();

   public:
      ~SetOfcurve_style();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfcurve_style *InstanceOf(ARMObject *);
      static SetOfcurve_style *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfcurve_style *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
