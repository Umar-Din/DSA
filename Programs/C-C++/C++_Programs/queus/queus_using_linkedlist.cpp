/*
queus using linked list
*/

#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};

class Queue{
    public:
        Node *rare;
        Node *front;
        //constructors
        Queue(){
            rare = nullptr;
            front = nullptr;
        };
        Queue(initializer_list<int> elements){
            int size = std::distance(elements.begin(),elements.end());
            int givenElements[size]; std::copy(elements.begin(),elements.end(),givenElements);
            Node* node = new Node;
            node->data = givenElements[0];
            node->next = nullptr;
            front = rare = node;
            int i=1;
            for(int i=1; i<size; i++){
                Node* node = new Node;
                node->data = givenElements[i];
                node->next = nullptr;
                rare->next = node;
                rare = node;
            }
        }
        //methods
        void display();
        void enque(int element);
        int deque();
        int isEmpty();
        int isFull();
};

void Queue::display(){
    Node* p = front;
    while(p!=NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
}

int Queue::isEmpty(){
    if(rare == front){
        return 1;
    }else{
        return 0;
    }
}

int Queue::isFull(){
    Node* node = new Node;
    if(node==nullptr){
        return 1;
    }else return 0;
}

void Queue::enque(int element){
    if(this->isFull()){
        cout<<"queue is full"<<endl;
    }else{
        Node* node = new Node;
        node->data = element;
        node->next = nullptr;
        rare->next = node;
        rare = node;
    }
}

int Queue::deque(){
    if(this->isEmpty()){
        cout<<"queue is empty"<<endl;
        return -1;
    }else{
        Node* temp = front;
        int data = front->data;
        front = front->next;
        delete temp;
        return data;
        
    }
}
int main(){

    Queue one({12,13,14,15,16});
    one.enque(17);
    one.deque();
    
    one.display();
    return 0;
}