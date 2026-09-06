#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node* create_ll(int elements[], int size);
void insert(Node **ll, int index, int element);
void push(Node *ll, int element);
Node* find(Node *ll, int element);
int pop(Node *ll);
int remove_element(Node **ll, int element);
void display(Node *first);

#endif