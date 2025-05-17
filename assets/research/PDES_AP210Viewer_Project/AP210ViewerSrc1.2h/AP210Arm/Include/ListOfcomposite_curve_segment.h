#ifndef LISTOFCOMPOSITE_CURVE_SEGMENT_H
#define LISTOFCOMPOSITE_CURVE_SEGMENT_H

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

class AP210ARM_API ListOfcomposite_curve_segment:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 344};

   private:
      // Required attributes
      class composite_curve_segment *_composite_curve_segment;

      // Optional attributes

   protected:
      ListOfcomposite_curve_segment();

   public:
      ~ListOfcomposite_curve_segment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ListOfcomposite_curve_segment *InstanceOf(ARMObject *);
      static ListOfcomposite_curve_segment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ListOfcomposite_curve_segment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
