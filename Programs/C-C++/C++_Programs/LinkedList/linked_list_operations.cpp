/*
linked list operations
*/
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList():head(NULL),length(0){}
        LinkedList(int elements[], int size):head(NULL){
            cout<<size<<endl;
            int i=1;
            Node* node = new Node;
            node->data = elements[0];
            node->next = NULL;
            head = node;
            tail = node;
            for(i;i<size;i++){
                Node* newnode = new Node;
                newnode->data = elements[i];
                newnode->next = NULL;
                tail->next = newnode;
                tail = newnode;
            }
            length=size;
        }
        void display();
        void insert(int index, int element);

};

void LinkedList::display(){
    if(length==0) return;
    int i=1;
    while(head!=NULL){
        cout<<head->data<<" Element "<<i<<endl;
        head = head->next;
        i++;
    }
}

void LinkedList::insert(int index, int element){
    if(index<1){
        Node* node = new Node;
        node->data = element;
        node->next = head;
        head = node;
        length++;
    }else if(index>=1){
        Node* temp = head;
        for(int i=0;i<index-1;i++){
            temp = temp->next;
        }
        if(temp){
            Node* node = new Node;
            node->data = element;
            node->next = temp->next;
            temp->next = node;
            length++;
        }cout<<"index out of range"<<endl;
    }
}

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    LinkedList* mylist1 = new LinkedList();
    LinkedList* mylist2 = new LinkedList(arr,10);
    // mylist2->display();
    cout<<"<<<<<<<<<<<<<<<<<inserting element>>>>>>>>>>>>>"<<endl;
    // mylist2->insert(0,0);
    mylist2->insert(11,111);
    mylist2->display();

    return 0;
}