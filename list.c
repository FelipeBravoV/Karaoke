//
//  list.c
//  Tarea3
//
//  Jorge
//  Rodrigo
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


List * create_list(){
    List * l = malloc(sizeof(List));
    l->current = NULL;
    l->head    = NULL;
    l->tail    = NULL;
    l->size    = 0;
    
    return l;
}

void l_push_back(List * l, char * key, void * data){
    l_node * n = malloc(sizeof(l_node));
    n->data = data;
    n->key = key;
    n->next = NULL;
    
    if(l->size>=1){ // if size >= 1
        n->prev = l->tail;
        l->tail->next = n;
        l->tail = n;
    }
    else{// if l está vacia
        n->prev = NULL;
        l->head = n;
        l->tail = n;
    }
    l_reset_current(l);
    l->size++;
}

int l_found_key(List *l, char * key){
    l_reset_current(l);
    int i;
    for (i=0; i<l->size; i++) {
        if (!strcmp(l->current->key,key)) {
            return 1;
        }
        else l_current_next(l);
    }
    l_reset_current(l);
    return 0;
}

void l_current_next(List *l){
    if(l->size > 0){
        if(l->current != l->tail){
            l->current = l->current->next;
        }
        //else l->current == l->tail so do nothing
    }
/*
    else{//l is empty, set all to NULL;
        l->current = NULL;
        l->head    = NULL;
        l->tail    = NULL;
    }
 */
}


void * l_get_current(List *l){
    if(l->current) return l->current->data;
    else return NULL;
}

char * l_get_current_key(List *l){
    return l->current->key;
}

void l_reset_current(List *l){
    l->current = l->head;
}

void l_eliminate_current(List*l){
    if (l->current == NULL){
        puts("!!! current no existe: lista vacia?");
        return;
    }
    else if (l->size == 1){
        l->head = NULL;
        l->tail = NULL;
        //List l ahora está vacia
    }
    else if (l->current == l->head){
        l->head = l->head->next;
        l->head->prev = NULL;
    }
    else if (l->current == l->tail){
        l->tail = l->tail->prev;
        l->tail->next = NULL;
    }
    else{
        l->current->prev->next = l->current->next;
        l->current->next->prev = l->current->prev;
    }
    free(l->current);
    l_reset_current(l);
    l->size--;
}
 
 
 

