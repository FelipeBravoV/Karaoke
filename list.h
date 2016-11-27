//
//  list.h
//  Tarea3
//
//  George
//  Rodrigo
//
//  Double linked list
//

#ifndef list_h
#define list_h

typedef struct node{
    void * data;
    char * key;
    
    struct node *next;
    struct node *prev;
    
} l_node;

typedef struct{
    l_node * head;
    l_node * tail;
    l_node * current;
    
    int size;
}List;

List * create_list();

void l_push_back(List * l, char * key, void * data);

//return 1 if key was found
int l_found_key(List *l, char * key);

//move current to the next node
void l_current_next();

//return current node data
void * l_get_current(List *l);

//return current node key
char * l_get_current_key(List *l);

//set current to the head of List * l
void l_reset_current(List *l);

// delete the current node
void l_eliminate_current(List*l);



#endif /* list_h */
