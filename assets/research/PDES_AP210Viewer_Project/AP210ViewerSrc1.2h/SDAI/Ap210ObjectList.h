#ifndef AP210OBJECTLIST_H
#define AP210OBJECTLIST_H
/*
 * $Id: Ap210ObjectList.h,v 1.2 1999/07/17 18:59:56 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include <stdio.h>

class AP210ObjectList;
#include "AP210Object.h"

// Basic design is:
//  a private list (AP210ObjectElement),
//  a public list manager (AP210ObjectList), and
//  a public list iterator (AP210ObjectListItor).              

class AP210ObjectElement {
   friend class AP210ObjectList;
   private:
      AP210ObjectElement *Next;
      AP210Object *Element;
#ifdef VERBOSE
int id;
#endif
   public:
      AP210ObjectElement(AP210Object *obj);
      ~AP210ObjectElement();
 
      AP210ObjectElement *Add(AP210Object *obj);
      AP210ObjectElement *End();
      AP210ObjectElement *Find(AP210Object *obj);
      AP210ObjectElement *GetNext() {return Next;};
      AP210Object *GetElement() {return Element;};
      int Size();
   };
class AP210ObjectList { 
      friend class AP210ObjectListItor;
   private:
      AP210ObjectElement *Head;

   private:
      AP210ObjectElement *Find(AP210Object *obj) {return Head->Find(obj);};     

   public:
      AP210ObjectList();
      ~AP210ObjectList();
 
      void Add(AP210Object *obj);
      void Append(AP210ObjectList *list);
      void Delete(AP210Object *obj);
      int ElementCount(AP210Object *obj);
      void Empty();
      bool Exists(AP210Object *obj);
      AP210Object* First() {return Head->Element; };
      AP210Object* Last() {return Head->End()->Element; }
      void ListIntersection(AP210ObjectList *l1, AP210ObjectList *l2);
      void MakeUnique();
      void Union(AP210ObjectList *list);
      int SizeOf() {return Head->Size();};
      void Sort(int (*Compare)(AP210Object*, AP210Object*));
      void ListIds(FILE *fp);
   };
     
class AP210ObjectListItor {
   private:
      AP210ObjectList *List;
      AP210ObjectElement *Current;

   public:
      AP210ObjectListItor(AP210ObjectList *list);
      ~AP210ObjectListItor();

      AP210Object* GetCurrent() {return Current->GetElement();};
      AP210Object* Next();
      AP210Object* NextDirectInstanceOf(int typeident);
      AP210Object* NextInstanceOf(int typeident);
      void ListTypeIDs(FILE *fp);
      void Reset();
   };
#endif
