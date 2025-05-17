#ifndef PARTICIPANT_DATE_AND_TIME_ASSIGNMENT_H
#define PARTICIPANT_DATE_AND_TIME_ASSIGNMENT_H

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

class AP210ARM_API participant_date_and_time_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 684};

   private:
      // Required attributes
      class person_and_organization *_action_participant;
      class date_and_time *_action_date_and_time;

      // Optional attributes

   protected:
      participant_date_and_time_assignment();

   public:
      ~participant_date_and_time_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static participant_date_and_time_assignment *InstanceOf(ARMObject *);
      static participant_date_and_time_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static participant_date_and_time_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
