/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa2
 * Due Jan 28, 2017
 * List.h
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct ListObj* List;

List newList(void);

void freeList(List* pL);

//length()
//Returns the number of elements in this List.
int length(List L);

//index()
//If cursor is defined, returns the index of the cursor element, otherwise returns -1.
int index(List L);

//front()
//Returns front element. Pre: length()>0
int front(List L);

//back()
//Returns back element. Pre: length()>0
int back(List L);

//get()
//Returns cursor element. Pre: length()>0, index()>=0
int get(List L);

//equals(List A, List B)
//Returns true if this List and L are the same integer sequence.
//The cursor is ignored in both lists.
int equals(List A, List B);

//clear()
//Resets this List to its original empty state.
void clear(List L);

//moveFront()
//If List is non-empty, places the cursor under the front
//element, otherwise does nothing.
void moveFront(List L);

//moveBack()
//If List is non-empty, places the cursor under the back element,
//otherwise does nothing.
void moveBack(List L);

//movePrev()
//If cursor is defined and not at front, moves cursor one step toward
//front of this List, if cursor is defined and at front, cursor becomes
//undefined, if cursor is undefined does nothing.
void movePrev(List L);

//moveNext()
//If cursor is defined and not at back, moves cursor one step toward
//back of this List, if cursor is defined and at back, cursor becomes
//undefined, if cursor is undefined does nothing.
void moveNext(List L);

//prepend(int data)
//Insert new element into this List. If List is non-empty,
//insertion takes place before front element.
void prepend(List L, int data);

//append(int data)
//Insert new element into this List. If List is non-empty,
//insertion takes place after back element.
void append(List L, int data);

//insertBefore(int data)
//Insert new element before cursor.
//Pre: length()>0, index()>=0
void insertBefore(List L, int data);

//insertAfter(int data)
//Inserts new element after cursor.
//Pre: length()>0, index()>=0
void insertAfter(List L, int data);

//deleteFront()
//Deletes the front element. Pre: length()>0
void deleteFront(List L);

//deleteBack()
//Deletes the back element. Pre: length()>0
void deleteBack(List L);

//delete()
//Deletes cursor element, making cursor undefined.
//Pre: length()>0, index()>=0
void delete(List L);

void printList(FILE* out, List L);

//Returns a new List representing the same integer sequence as this
//List. The cursor in the new list is undefined, regardless of the
//state of the cursor in this List. This List is unchanged.
List copyList(List L);

//Returns a new List which is the concatenation of this list followed
//by L. The cursor in the new List is undefined, regardless of the
//states of the cursors in this List and L. The states of this List
//and L are unchanged.
List concatList(List A, List B);

#endif /* LIST_H_ */
