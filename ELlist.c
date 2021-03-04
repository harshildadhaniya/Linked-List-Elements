#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Define Linked List node */

typedef struct intlist_t{
    int head;
    struct intlist_t* tail;
} intlist;

/* How to add a node */

intlist* cons(int h, intlist* t){
    intlist* res;
    res = malloc(sizeof(intlist));

    res->head = h;
    res->tail = t;

    return res;
}

/* Free a linked list */

void free_list(intlist* t){

    intlist* temp;
    while (t != NULL){
        temp = t;
        t = t->tail;
        free(temp);
    } 
}

/* Print a linked list */

void print_list(intlist* t){

    intlist* temp = t;
    printf("[ ");
    while (temp != NULL){
        printf("%d ", temp->head);
        temp = temp->tail;
    }
    printf("]\n");
}

/* Calculate the length of the list recursively */
int list_length(intlist* t){

    if(t == NULL){
        return 0;
    }
    else{
        return 1 + list_length(t->tail);
    }
    
}

/* Modify a list in place. Add an element at the end of list in place. */

void cons_end(int v, intlist** t){
    // adds an element at the end of list t
    // t is modified in place
    intlist* l1 = *t;

    if (*t == NULL){
        *t = cons(v , NULL);
    } 
    else{
        while(l1->tail != NULL){
            l1 = l1->tail;
        }
        
        l1->tail = cons(v, NULL);
    }
}

intlist* cons_end_functional(int v, intlist* t){

    intlist* temp = t;
    intlist* current;
    intlist* start;
    intlist* prev = NULL;

    if(t == NULL){
        return cons(v, NULL);
    }
    else{
        while(temp != NULL){
            
            current = cons(temp->head, NULL);

            if(prev == NULL){
                start = current;
            }
            else{
                prev->tail = current;
            }

            prev = current;
            
            temp = temp->tail;
        }
  
        prev->tail = cons(v, NULL);
        prev = prev->tail;

    }

    return start;
}

/* Add element at the beginning of the list */
intlist* cons_front(int v, intlist* t){

    intlist* temp = t;
    intlist* current;
    intlist* start;
    intlist* prev = NULL;
    intlist* new_start;

    if(t == NULL){
        return cons(v, NULL);
    }
    else{
        while(temp != NULL){
            
            current = cons(temp->head, NULL);

            if(prev == NULL){
                start = current;
            }
            else{
                prev->tail = current;
            }

            prev = current;
            
            temp = temp->tail;
        }
  
        new_start = cons(v, NULL);
        new_start->tail = start;

        start = new_start;

    }
}

int main(){

    intlist* L1 = cons(5, cons(6, cons(9, cons(200, cons(30, NULL)))));

    printf("This is the original list\n");

    print_list(L1);

    printf("\nThe modified list is:\n");

    cons_end(789, &L1);

    print_list(L1);

    printf("\nNow an element will be added at the end of the list\n");
    printf("but to a copy of the original\n");
    
    printf("\nThe modified list is:\n");
    intlist* L1_new = cons_end_functional(111, L1);

    print_list(L1_new);

    printf("\nThe original list is:\n");
    print_list(L1);

    printf("\nNow let us add an element at the front of the linked list\n");
    intlist* L1_front = cons_front(999, L1);

    print_list(L1_front);

    printf("\nThe original list is:\n");
    print_list(L1); 

    free_list(L1);
    free_list(L1_new);
    free_list(L1_front);

    return 0;
}