/*
linkedlist operations
*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};


//creating node
struct Node* create_node(int arr[], int size){
    struct Node *head,*tail;
    struct Node *lkndnlist = new Node;
    lkndnlist->data = arr[0];
    lkndnlist->next = NULL;
    head = lkndnlist;
    tail = lkndnlist;
    int i;
    for(i=1;i<size;i++){
        struct Node* newnode;
        newnode = new Node;
        newnode->data = arr[i];
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
    return lkndnlist;

}
//display linkedlist elements
void display(struct Node *node){
    struct Node* head = node;
    
    while(head!=NULL){
        
        cout<<head->data<<endl;
        head= head->next;
        
    }
}

int main(){

    int arr[] = {1,2,3,4,5};
    struct Node *user = create_node(arr, 5);
    display(user);
    

    return 0;
}