//
// Created by Martin Alemajoh on 9/23/2020.
//
#include <stdlib.h>
#include "doubly_linked_list.h"


void initList(DLinkedList *list){

    list->head = NULL;
    list->tail = NULL;
}

void freeNode(void **node){

    if(node != NULL && *node != NULL){
        free(*node);
        *node = NULL;
    }
}

void clearList(DLinkedList *list){

    Node *node = list->head;
    Node *nextNode;

    while(node != NULL){
        nextNode = node->next;
        freeNode((void **)&node);
        node = nextNode;
    }
    list->head = NULL;
    list->tail = NULL;
}

Node *addList(DLinkedList *list, const void *data){

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;

    node->next = NULL;

    if(list->head == NULL){
        node->prev = NULL;
        list->head = node;
    }
    else{
        list->tail->next = node;
        node->prev = list->tail;
    }
    list->tail = node;
    return node;
}


void *get(DLinkedList *list, int index){

    if(list->head != NULL) {

        if(index <= -1 || index >= getSize(list)){
            return NULL;
        }
        Node *node = getNode(list, index);
        if(node != NULL) {
            void *n = (void *) node->data;
            return n;
        }
    }
    return NULL;
}

Node *getNode(DLinkedList *list, int index){

    if(list->head != NULL) {

        Node *node = list->head;
        unsigned int i = 0;
        Node *n;
        do{
            n = node;
            node = node->next;
            i += 1;
        }while(i <= index);
        return n;
    }
    return NULL;
}

void *getNext(DLinkedList *list, int index){

    if(list->head != NULL) {
        if (index <= -1 || index >= getSize(list) - 1) {
            return NULL;
        }
        Node *node = getNode(list, index);
        if(node != NULL) {
            void *n = (void *) node->next->data;
            return n;
        }
    }
    return NULL;
}

void *getPrev(DLinkedList *list, int index){

    if(list->head != NULL) {
        unsigned int len = getSize(list);

        if (index <= 0 || index >= len) {
            return NULL;
        }
        Node *node = getNode(list, index);
        if(node != NULL) {
            void *n = (void *) node->prev->data;
            return n;
        }
    }
    return NULL;
}


void removeFront(DLinkedList *list){

    if(list->head != NULL) {
        // if node is the last node remove and reset head and tail pointer
        if(list->head == list->tail){
            freeNode((void **)&list->head);
            list->head = NULL;
            list->tail = NULL;
        }
        else{
            Node *node = list->head;
            Node *nextNode = node->next;
            nextNode->prev = NULL;
            list->head = nextNode;
            freeNode((void **)&node);
        }
    }
}


void removeBack(DLinkedList *list){

    if(list->head != NULL) {
        // if node is the last node remove and reset head and tail pointer
        if(list->head == list->tail){
            freeNode((void **)&list->head);
            list->head = NULL;
            list->tail = NULL;
        }
        else{
            Node *node = list->tail;
            Node *prevNode = node->prev;
            prevNode->next = NULL;
            list->tail = prevNode;
            freeNode((void **)&node);
        }
    }
}

void removeAt(DLinkedList *list, int index){

    if(list->head != NULL){
        if(index <= -1 || index >= getSize(list)){
            return;
        }
        Node *node = getNode(list, index);
        if(node == NULL){
            return;
        }
        else {
            if (list->head == list->tail) {
                list->head = NULL;
                list->tail = NULL;
            } else if (list->head == node) {
                list->head = node->next;
                list->head->prev = NULL;
            } else if (list->tail == node) {
                list->tail = node->prev;
                list->tail->next = NULL;
            } else {
                node->prev->next = node->next;
            }
            freeNode((void **) &node);
        }
    }
}


void removeNext(DLinkedList *list, int index){

    if(list->head != NULL){

        if(index <= -1 || index >= getSize(list)-1){
            return;
        }
        Node *node = getNode(list, index);

        if(node == NULL){
            return;
        }
        Node *nextNode = node->next;
        node->next = nextNode->next;
        nextNode->next->prev = node;
        freeNode((void **)&nextNode);
    }
}


unsigned int getSize(DLinkedList *list){

    unsigned int len = 0;

    if(list->head != NULL){
        Node *node = list->head;
        while(node != NULL){
            len += 1;
            node = node->next;
        }
        return len;
    }
    return len;
}