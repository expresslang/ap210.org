#ifndef STYLED_CURVE_OCCURRENCE_H
#define STYLED_CURVE_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API styled_curve_occurrence:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 481};

   private:
      // Required attributes
      class curve *_styled_curve;
      class curve_style *_of_curve_style;

      // Optional attributes

   protected:
      styled_curve_occurrence();

   public:
      ~styled_curve_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static styled_curve_occurrence *InstanceOf(ARMObject *);
      static styled_curve_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static styled_curve_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
