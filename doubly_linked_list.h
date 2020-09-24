//
// Created by Martin Alemajoh on 9/23/2020.
//

#ifndef DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H

/*
 * structure to represent a node in a linked list
*/
typedef struct node{
    const void *data;
    struct node *prev;
    struct node *next;
}Node;


/*
 * structure to represent a linked list
*/
typedef struct dlinkedlist {
    Node *head;
    Node *tail;
}DLinkedList;


/*
 * DEF: Initialize DLinkedList
 * PARAM1: DLinkedList *list - doubly linkedlist structure to be initialize
 * RETURN: returns void
*/
void initList(DLinkedList *list);


/*
 * DEF: Frees a node allocated with malloc
 * PARAM1: void **node - address of pointer to node
 * RETURN: returns void
*/
void freeNode(void **node);


/*
 * DEF: Clears a list and frees all allocated node
 * PARAM1: DLinkedList *list - doubly linkedlist structure to be cleared
 * RETURN: returns void
*/
void clearList(DLinkedList *list);


/*
 * DEF: inserts data to the list
 * PARAM1: DLinkedList *list - double linkedlist structure.
 * PARAM2: const void *type - data to be stored in list
 * RETURN: pointer to node otherwise NULL
*/
Node *addList(DLinkedList *list, const void *data);


/*
 * DEF: removes data from front of the list
 * PARAM1: DLinkedList *list - doubly linkedlist structure
 * RETURN: returns void
*/
void removeFront(DLinkedList *list);


/*
 * DEF: removes data from back of the list
 * PARAM1: DLinkedList *list - doubly linkedlist structure
 * RETURN: returns void
*/
void removeBack(DLinkedList *list);


/*
 * DEF: gets the number of elements in a list
 * PARAM1: DLinkedList *list - doubly linkedlist structure
 * RETURN: returns number of elements
*/
unsigned int getSize(DLinkedList *list);


/*
 * DEF: returns a pointer to the data at a particular index
 * PARAM1: DLinkedList *list - doubly linkedlist structure
 * PARAM2: int index - index of data in list
 * RETURN: returns a pointer to data;
*/
void *get(DLinkedList *list, int index);


/*
 * DEF: returns a pointer to Node
 * PARAM1: DLinkedList *list - doubly linkedlist structure
 * PARAM2: int index - index of data in list
 * RETURN: returns a pointer to Node;
*/
Node *getNode(DLinkedList *list, int index);


/*
 * DEF: returns a pointer to next data
 * PARAM1: DLinkedList *list - doubly linkedlist structure
 * PARAM2: int index - index of data in list
 * RETURN: returns a pointer to data;
*/
void *getNext(DLinkedList *list, int index);


/*
 * DEF: returns a pointer to previous data
 * PARAM1: DLinkedList *list - doubly linkedlist structure
 * PARAM2: int index - index of data in list
 * RETURN: returns a pointer to data;
*/
void *getPrev(DLinkedList *list, int index);


/*
 * DEF: removes the element at the specified index
 * PARAM1: DLinkedList *list - doubly linkedlist structure
 * PARAM2: int index - index of data in list
 * RETURN: returns void
*/
void removeAt(DLinkedList *list, int index);


/*
 * DEF: removes the element next to the one whose index is provided
 * PARAM1: DLinkedList *list - doubly linkedlist structure
 * PARAM2: int index - index of data in list
 * RETURN: returns void
*/
void removeNext(DLinkedList *list, int index);



#endif //DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
