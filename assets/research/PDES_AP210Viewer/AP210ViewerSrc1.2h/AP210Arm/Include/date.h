#ifndef DATE_H
#define DATE_H

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

class AP210ARM_API date:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 13};

   private:
      // Required attributes
      RoseInteger _day;
      RoseInteger _year;
      RoseInteger _month;

      // Optional attributes

   protected:
      date();

   public:
      ~date();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static date *InstanceOf(ARMObject *);
      static date *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static date *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
