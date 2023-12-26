/*
stack using linked list
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    Node* head;
    int length;
    //constructors
    public:
        LinkedList(initializer_list<int> elements){
            int size = std::distance(elements.begin(),elements.end());
            int elementsarray[size]; std::copy(elements.begin(),elements.end(),elementsarray);
            Node *newnode = new Node;
            newnode->data = elementsarray[0];
            newnode->next = nullptr;
            head = newnode;
            Node* p = head;
            for(int i=1; i<size; i++){
                Node* node = new Node;
                node->data = elementsarray[i];
                node->next = nullptr;
                p->next = node;
                p = node;
            }
        }
        //display linked list
        void display();
        void push(int element);
        int pop();
};

void LinkedList::display(){
    if(head!=NULL){
        Node* p = head;
        while(p!=NULL){
            cout<<p->data<<endl;
            p = p->next;
        }
    }
}

void LinkedList::push(int element){
    if(head == NULL){
        Node* node = new Node;
        node->data = element;
        node->next = nullptr;
        head = node;
    }else{
        Node* node = new Node;
        node->data = element;
        node->next = head;
        head = node;
    }
}

int LinkedList::pop(){
    if(head == NULL) {
        cout<<"stack underflow"<<endl;
        return -1;
    }else{
        Node* temp = head;
        head = head->next;
        return temp->data;
    }
}

int main(){

    LinkedList ist_list({1,2,3,4});
    ist_list.push(14);
    cout<<ist_list.pop()<<endl<<"display function"<<endl;
    ist_list.display();
    return 0;
}

