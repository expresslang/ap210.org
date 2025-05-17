#ifndef ARMOBJECTLIST_H
#define ARMOBJECTLIST_H
/*
 * $Id:$
 * Auth:
 */
#include <stdio.h>

class ARMObjectList;
#include <ARMObject.h>

// Basic design is:
//  a private list (ARMObjectElement),
//  a public list manager (ARMObjectList), and
//  a public list iterator (ARMObjectListItor).              

class ARMObjectElement {
   friend class ARMObjectList;
   private:
      ARMObjectElement *Next;
      ARMObject *Element;
#ifdef VERBOSE
int id;
#endif
   public:
      ARMObjectElement(ARMObject *obj);
      ~ARMObjectElement();
 
      ARMObjectElement *Add(ARMObject *obj);
      ARMObjectElement *End();
      ARMObjectElement *Find(ARMObject *obj);
      ARMObjectElement *GetNext() {return Next;};
      ARMObject *GetElement() {return Element;};
      int Size();
   };
class AP210ARM_API ARMObjectList { 
      friend class ARMObjectListItor;
   private:
      ARMObjectElement *Head;

   private:
      ARMObjectElement *Find(ARMObject *obj) {return Head->Find(obj);};     

   public:
      ARMObjectList();
      ~ARMObjectList();
 
      void Add(ARMObject *obj);
      void Append(ARMObjectList *list);
      void Delete(ARMObject *obj);
      int ElementCount(ARMObject *obj);
      void Empty();
      bool Exists(ARMObject *obj);
      ARMObject* First() {return Head->Element; };
      ARMObject* Last() {return Head->End()->Element; }
      void ListIntersection(ARMObjectList *l1, ARMObjectList *l2);
      void MakeUnique();
      void Union(ARMObjectList *list);
      int SizeOf() {return Head->Size();};
      void Sort(int (*Compare)(ARMObject*, ARMObject*));
      void ListIds();
   };
     
class AP210ARM_API ARMObjectListItor {
   private:
      ARMObjectList *List;
      ARMObjectElement *Current;

   public:
      ARMObjectListItor(ARMObjectList *list);
      ~ARMObjectListItor();

      ARMObject* GetCurrent() {return Current->GetElement();};
      ARMObject* Next();
      ARMObject* NextDirectInstanceOf(int typeident);
      ARMObject* NextInstanceOf(int typeident);
      void ListTypeIDs();
      void Reset();
   };
#endif
