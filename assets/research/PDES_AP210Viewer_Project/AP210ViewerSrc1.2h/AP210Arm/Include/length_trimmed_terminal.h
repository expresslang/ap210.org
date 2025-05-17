#ifndef LENGTH_TRIMMED_TERMINAL_H
#define LENGTH_TRIMMED_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <altered_package_terminal.h>

// Unions

// Enumerations

class AP210ARM_API length_trimmed_terminal:
public altered_package_terminal
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 633};

   private:
      // Required attributes
      class length_data_element *_maximum_trimmed_length;
      class length_data_element *_minimum_trimmed_length;

      // Optional attributes

   protected:
      length_trimmed_terminal();

   public:
      ~length_trimmed_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static length_trimmed_terminal *InstanceOf(ARMObject *);
      static length_trimmed_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static length_trimmed_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
