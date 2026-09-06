#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"


Node* create_ll(int elements[], int size){
    if(size <=0){
        return NULL;
    }
    Node *first = (Node *)malloc(sizeof(Node));
    first->data = elements[0];
    first->next = NULL;
    Node * temp = first;
    for(int i=1; i<size; i++){
        Node *n = (Node*)malloc(sizeof(Node));
        n->data = elements[i];
        n->next = NULL;
        temp->next = n;
        temp = n;
    }
    return first;
}

void insert(Node **ll, int index, int element){
    
    Node *prev = *ll;
    Node *next = *ll;
    int count = 0;
    while(next != NULL){
        count++;
        if(count == index){
            Node *n = (Node*)malloc(sizeof(Node));
            n->data = element;
            n->next = next;
            if(prev == next){
                *ll = n;
            }else{
                prev->next = n;
            }
            break;
        }
        prev = next;
        next = next->next;
    }
    
}

void push(Node *ll, int element){
    while(ll->next != NULL){
        ll = ll->next;
    }
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = element;
    new->next = NULL;
    ll->next = new;
}

int pop(Node *ll){
    while(ll->next->next != NULL){
        ll = ll->next;
    }
    Node *rem = ll->next;
    ll->next = NULL;
    int data = rem->data;
    free(rem);
    return data;
}

Node* find(Node *ll, int element){
    while(ll != NULL){
        if(ll->data == element){
            return ll;
        }
        ll = ll->next;
    }
    return NULL;
}
int remove_element(Node **ll, int element){
    Node *prev = NULL; 
    Node *next = *ll;
    int data = -1;
    while(next != NULL){
        if(next->data == element){
            Node *rm = next;
            data = rm->data;
            if(prev == NULL){
                *ll = next->next;
            }else{
                prev->next = next->next;
            }
            free(rm);
            break;
        }
        prev = next;
        next = next->next;
    }
    return data;
}

void display(Node *first){
    printf("\nDisplaying the elements of LL ...\n");
    while(first != NULL){
        printf("%d\n",first->data);
        first = first->next;
    }
}
