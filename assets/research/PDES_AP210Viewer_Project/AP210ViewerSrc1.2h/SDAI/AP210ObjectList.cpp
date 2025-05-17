/*
 * $Id: AP210ObjectList.cpp,v 1.2 1999/07/17 19:00:22 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>

#include "AP210ObjectList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#ifdef VERBOSE
int elmcount = 0;
int elmid;
#endif
AP210ObjectElement::AP210ObjectElement(AP210Object *obj) {
   Element = obj;
   Next = NULL;
#ifdef VERBOSE
elmcount++;
elmid++;
id=elmid;
TRACE("%d ELMID added\r\n", id);
#endif
   }

AP210ObjectElement::~AP210ObjectElement() {
#ifdef VERBOSE
elmcount--;
TRACE("elmcount: %d\r\n", elmcount);
TRACE("%d ELMID  deleted\r\n", id);
#endif
   }

AP210ObjectElement *AP210ObjectElement::Add(AP210Object *obj)
   {
   // what would be the proper behavior if 
   // obj is NULL?
   AP210ObjectElement *p = this;

   while (p->Next != NULL) {
      p = p->Next;
      }
   p->Next = new AP210ObjectElement(obj);
   return p->Next;
   }
AP210ObjectElement *AP210ObjectElement::Find(AP210Object *obj)
   {
   AP210ObjectElement *p = this;

   while (p != NULL) {
      if (p->Element == obj) {
         break;
         }
      p = p->Next;
      }
   return p;
   }
AP210ObjectElement *AP210ObjectElement::End()
   {
   AP210ObjectElement *p = this;
   AP210ObjectElement *end = p;   

   while (p != NULL) {
      end = p;
      p = p->Next;
      }
   return end;
   }
int AP210ObjectElement::Size()
   {
   int count = 0;
   AP210ObjectElement *p = this;

   while (p != NULL) {
      p = p->Next;
      count++;
      }
   return count;
   }
//-----------------------------------
AP210ObjectList::AP210ObjectList() {
   Head = NULL;
   } 

AP210ObjectList::~AP210ObjectList() {
   Empty();
   }

void AP210ObjectList::Empty() {
   AP210ObjectElement *p;
   AP210ObjectElement *ptr = Head;

   while(ptr != NULL)
      {
      p = ptr->Next; 
      delete ptr;
      ptr = p;
      }
   Head = NULL;
   }

void AP210ObjectList::Add(AP210Object *obj)
   {
   if (Head == NULL) {
      Head = new AP210ObjectElement(obj);
      }
   else {
      Head->Add(obj);
      }
   }

void AP210ObjectList::Append(AP210ObjectList *list) {
   AP210ObjectListItor itor(list);
   AP210Object *obj;

   if (list == this) {
      TRACE("FATAL ERROR: Attempt to append a AP210ObjectList to itself!\n");
      exit(0);
      }
   while((obj = itor.Next()) != NULL) {
      Add(obj);
      }
   }
void AP210ObjectList::Delete(AP210Object *obj)
   {
   AP210ObjectElement *l;
   AP210ObjectElement *p = Find(obj);
 
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
int AP210ObjectList::ElementCount(AP210Object *obj) {
   int count = 0;
   AP210ObjectListItor itor(this);
   AP210Object *p;

   while((p = itor.Next()) != NULL) {
      if (p == obj) {
         count++;
         }
      }
   return count;
   }
   
bool AP210ObjectList::Exists(AP210Object *obj) {
   bool result = false;

   if (Find(obj) != NULL) {
      result = true;
      }
   return result;
   }

// make the list of intersection of l1 and l2.
// keep in mind that l1 or l2 could be this.
void AP210ObjectList::ListIntersection(AP210ObjectList *l1, AP210ObjectList *l2) {
   AP210ObjectList temp;
   AP210ObjectListItor itor1(l1);
   AP210Object *obj;

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
void AP210ObjectList::MakeUnique() {
   AP210ObjectList temp;
   AP210ObjectListItor itor(this);
   AP210Object *obj;

   while((obj = itor.Next()) != NULL) {
      if (ElementCount(obj) == 1) {
         temp.Add(obj);
         }
      }
   Empty();
   Append(&temp);
   }
void AP210ObjectList::Sort(int (*Compare)(AP210Object*, AP210Object*)) {
   AP210Object *tmp;
   bool done = false;
   AP210ObjectElement *limit = Head->End();
   AP210ObjectElement *e1 = NULL;
   AP210ObjectElement *e2 = Head;
      
#ifdef VERBOSE
TRACE("\r\nIn AP210ObjectList::Sort\r\nInput: ");
ListIds(stdout); TRACE("\r\n");
#endif
       while (done == false)
        {
        done = true; // This will be reset to false if
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

AP210ObjectListItor::AP210ObjectListItor(AP210ObjectList *list)
   {
   List = list;
   Current = List->Head;
   }
AP210ObjectListItor::~AP210ObjectListItor()
   {
   }
void AP210ObjectListItor::Reset()
   {
   Current = List->Head;
   }
AP210Object *AP210ObjectListItor::Next()
   {
   AP210Object *obj = NULL;

   if (Current != NULL) {
      obj = Current->GetElement();
      Current = Current->GetNext();
      }
   return obj;
   }
AP210Object *AP210ObjectListItor::NextDirectInstanceOf(int typeident)
   {
   AP210Object *obj = NULL;

   while (Current != NULL) {
      if (Current->GetElement() != NULL) {
         if (Current->GetElement()->GetTypeID() == typeident) {
            obj = Current->GetElement();
            Current = Current->GetNext();
            break;
            }
         }
      Current = Current->GetNext();
      }
   return obj;
   }
AP210Object *AP210ObjectListItor::NextInstanceOf(int typeident)
   {
   AP210Object *obj = NULL;

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
void AP210ObjectListItor::ListTypeIDs(FILE *fp)
   {
   int count = 0;
   AP210ObjectElement *p = List->Head;

   while(p != NULL) {
      count++;
      if (p->GetElement() != NULL) {
         fprintf(fp, "%d: TypeID %d OID %d\n", 
                      count, 
                      p->GetElement()->GetTypeID(),
                      p->GetElement()->GetOID());
         }
      p = p->GetNext();
      }
   fputs("Done\n", fp); 
   }
void AP210ObjectList::Union(AP210ObjectList *list) {
   AP210ObjectListItor itor(this);
   AP210Object *obj;
   
   while((obj = itor.Next()) != NULL) {
      if (list->Exists(obj) == false) {
         Delete(obj);
         } 
      }
   }
// Some debug functions.
void AP210ObjectList::ListIds(FILE *fp) {
   AP210ObjectListItor itor(this);
   AP210Object *obj;
   int test = 0;

   while((obj = (AP210Object *)itor.Next()) != NULL) {
      if (test) {
         fputs(", ", fp);
         }
      else {
         test = 1;
         }
      fprintf(fp, "%d", obj->GetOID());
      } 
   } 