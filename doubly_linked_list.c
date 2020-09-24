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
        Node *node = list->head;
        unsigned int i = 0;
        void *n;
        do{
            n = (void *)node->data;
            node = node->next;
            i += 1;
        }while(i <= index);
        return n;
    }
    return NULL;
}

void *getNext(DLinkedList *list, int index){

    if(index <= -1 || index >= getSize(list) - 1){
        return NULL;
    }
    Node *node = list->head;
    unsigned int i = 0;
    void *n;
    do{
        n = (void *)node->next->data;
        node = node->next;
        i += 1;
    }while(i <= index);
    return n;
}

void *getPrev(DLinkedList *list, int index){

    unsigned int len = getSize(list);

    if(index <= 0 || index >= len){
        return NULL;
    }
    Node *node = list->tail;
    unsigned int i = len;
    void *n;
    do{
        n = (void *)node->prev->data;
        node = node->prev;
        i -= 1;
    }while(i > index);
    return n;
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