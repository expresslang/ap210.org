/*
 * $Id:$
 * Auth:
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>

#include <ARMObjectList.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#ifdef VERBOSE
int elmcount = 0;
int elmid;
#endif
ARMObjectElement::ARMObjectElement(ARMObject *obj) {
   Element = obj;
   Next = NULL;
#ifdef VERBOSE
elmcount++;
elmid++;
id=elmid;
TRACE("%d ELMID added\r\n", id);
#endif
   }

ARMObjectElement::~ARMObjectElement() {
#ifdef VERBOSE
elmcount--;
TRACE("elmcount: %d\r\n", elmcount);
TRACE("%d ELMID  deleted\r\n", id);
#endif
   }

ARMObjectElement *ARMObjectElement::Add(ARMObject *obj)
   {
   // what would be the proper behavior if 
   // obj is NULL?
   ARMObjectElement *p = this;

   while (p->Next != NULL) {
      p = p->Next;
      }
   p->Next = new ARMObjectElement(obj);
   return p->Next;
   }
ARMObjectElement *ARMObjectElement::Find(ARMObject *obj)
   {
   ARMObjectElement *p = this;

   while (p != NULL) {
      if (p->Element == obj) {
         break;
         }
      p = p->Next;
      }
   return p;
   }
ARMObjectElement *ARMObjectElement::End()
   {
   ARMObjectElement *p = this;
   ARMObjectElement *end = p;   

   while (p != NULL) {
      end = p;
      p = p->Next;
      }
   return end;
   }
int ARMObjectElement::Size()
   {
   int count = 0;
   ARMObjectElement *p = this;

   while (p != NULL) {
      p = p->Next;
      count++;
      }
   return count;
   }
//-----------------------------------
ARMObjectList::ARMObjectList() {
   Head = NULL;
   } 

ARMObjectList::~ARMObjectList() {
   Empty();
   }

void ARMObjectList::Empty() {
   ARMObjectElement *p;
   ARMObjectElement *ptr = Head;

   while(ptr != NULL)
      {
      p = ptr->Next; 
      delete ptr;
      ptr = p;
      }
   Head = NULL;
   }

void ARMObjectList::Add(ARMObject *obj)
   {
   if (Head == NULL) {
      Head = new ARMObjectElement(obj);
      }
   else {
      Head->Add(obj);
      }
   }

void ARMObjectList::Append(ARMObjectList *list) {
   ARMObjectListItor itor(list);
   ARMObject *obj;

   if (list == this) {
      TRACE("FATAL ERROR: Attempt to append a ARMObjectList to itself!\n");
      exit(0);
      }
   while((obj = itor.Next()) != NULL) {
      Add(obj);
      }
   }
void ARMObjectList::Delete(ARMObject *obj)
   {
   ARMObjectElement *l;
   ARMObjectElement *p = Find(obj);
 
   if (p != NULL) {
      if (p == Head) {
         Head = Head->Next;
         }
      else {
         l = Head;
         while(l->Next != p && l->Next != NULL) {
            l = l->Next;
            } 
         l->Next = p->Next ;
         }
      delete p;
      }
   }
int ARMObjectList::ElementCount(ARMObject *obj) {
   int count = 0;
   ARMObjectListItor itor(this);
   ARMObject *p;

   while((p = itor.Next()) != NULL) {
      if (p == obj) {
         count++;
         }
      }
   return count;
   }
   
bool ARMObjectList::Exists(ARMObject *obj) {
   bool result = false;

   if (Find(obj) != NULL) {
      result = true;
      }
   return result;
   }

// make the list of intersection of l1 and l2.
// keep in mind that l1 or l2 could be this.
void ARMObjectList::ListIntersection(ARMObjectList *l1, ARMObjectList *l2) {
   ARMObjectList temp;
   ARMObjectListItor itor1(l1);
   ARMObject *obj;

   // Build the intersection list
   while((obj = itor1.Next()) != NULL) {
      if (l2->Exists(obj) == true) {
         temp.Add(obj);
         }
      }
   // Update this list
   this->Empty();
   this->Append(&temp);
   }
void ARMObjectList::MakeUnique() {
   ARMObjectList temp;
   ARMObjectListItor itor(this);
   ARMObject *obj;

   while((obj = itor.Next()) != NULL) {
      if (ElementCount(obj) == 1) {
         temp.Add(obj);
         }
      }
   Empty();
   Append(&temp);
   }
void ARMObjectList::Sort(int (*Compare)(ARMObject*, ARMObject*)) {
   ARMObject *tmp;
   bool done = false;
   ARMObjectElement *limit = Head->End();
   ARMObjectElement *e1 = NULL;
   ARMObjectElement *e2 = Head;
      
#ifdef VERBOSE
TRACE("\r\nIn ARMObjectList::Sort\r\nInput: ");
ListIds(stdout); TRACE("\r\n");
#endif
       while (done == false)
        {
        done = true; // This will be reset to FALSE if
                     // a swap takes place.

        while((e2 != NULL) && (e2 != limit)) {
           e1 = e2;
           e2 = e1->Next;
           if (e2 != NULL) { // e2 would only be NULL there was only one element in the list.
              if (Compare(e1->Element, e2->Element) > 0) {
                 done = false; // Not done yet!
#ifdef REALLYVERBOSE
TRACE("Swapped elements.\r\n", stdout);
#endif
                 tmp = e1->Element;
                 e1->Element = e2->Element;
                 e2->Element = tmp;
              	 }
              }	
           }
        limit = e1;   
        }  
#ifdef VERBOSE
TRACE("Output: ");
ListIds(stdout); TRACE("\r\n");
#endif
   }

ARMObjectListItor::ARMObjectListItor(ARMObjectList *list)
   {
   List = list;
   Current = List->Head;
   }
ARMObjectListItor::~ARMObjectListItor()
   {
   }
void ARMObjectListItor::Reset()
   {
   Current = List->Head;
   }
ARMObject *ARMObjectListItor::Next()
   {
   ARMObject *obj = NULL;

   if (Current != NULL) {
      obj = Current->GetElement();
      Current = Current->GetNext();
      }
   return obj;
   }
ARMObject *ARMObjectListItor::NextDirectInstanceOf(int typeident)
   {
   ARMObject *obj = NULL;

   while (Current != NULL) {
      if (Current->GetElement() != NULL) {
         if (Current->GetElement()->getTypeID() == typeident) {
            obj = Current->GetElement();
            Current = Current->GetNext();
            break;
            }
         }
      Current = Current->GetNext();
      }
   return obj;
   }
ARMObject *ARMObjectListItor::NextInstanceOf(int typeident)
   {
   ARMObject *obj = NULL;

   while (Current != NULL) {
      if (Current->GetElement() != NULL) {
         if (Current->GetElement()->DynamicType(typeident)) {
            obj = Current->GetElement();
            Current = Current->GetNext();
            break;
            }
         }
      Current = Current->GetNext();
      }
   return obj;
   }
void ARMObjectListItor::ListTypeIDs()
   {
   int count = 0;
   ARMObjectElement *p = List->Head;

   while(p != NULL) {
      count++;
      if (p->GetElement() != NULL) {
         TRACE("%d: TypeID %d OID %d\n", 
                      count, 
                      p->GetElement()->getTypeID(),
                      p->GetElement()->getOID());
         }
      p = p->GetNext();
      }
   TRACE0("Done\n"); 
   }
void ARMObjectList::Union(ARMObjectList *list) {
   ARMObjectListItor itor(this);
   ARMObject *obj;
   
   while((obj = itor.Next()) != NULL) {
      if (list->Exists(obj) == false) {
         Delete(obj);
         } 
      }
   }
// Some debug functions.
void ARMObjectList::ListIds() {
   ARMObjectListItor itor(this);
   ARMObject *obj;
   int test = 0;

   while((obj = (ARMObject *)itor.Next()) != NULL) {
      if (test) {
         TRACE0(", ");
         }
      else {
         test = 1;
         }
      TRACE("%d", obj->getOID());
      } 
   } 