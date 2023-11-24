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
        int deleteElement(int element);
        void insertInSorted(int element);
        bool isSorted();
        void concatinate(LinkedList* list3);
        void merge(Node* list3);
        void reverse();
        

};
//display linkedlist
void LinkedList::display(){
    if(length==0) return;
    int i=1;
    Node* t_pointer = head;
    while(t_pointer!=NULL){
        cout<<t_pointer->data<<" Element "<<i<<endl;
        t_pointer = t_pointer->next;
        i++;
    }
}
//insert into the linked list
void LinkedList::insert(int index, int element){
    if(index<1){
        Node* node = new Node;
        node->data = element;
        node->next = head;
        head = node;
        length++;
    }else if(index>=1 && index<length){
        Node* temp = head;
        for(int i=1;i<index-1;i++){
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
//insert into sorted linked list
void LinkedList::insertInSorted(int element){
    if(length==0){
        Node* node = new Node;
        node->data = element;
        node->next = NULL;
        head = node;
        tail = node;
        length++;
    }else{
        if(element<head->data){
            Node* node = new Node;
            node->data = element;
            node->next = head;
            head = node;
            length++;
        }else{
            Node* temp = head;
            int i=1;
            while(i<length){
                if(temp->next->data>element){
                    Node* node = new Node;
                    node->data = element;
                    node->next = temp->next;
                    temp->next = node;
                    length++;
                    // break;
                    return;
                }
                temp = temp->next;i++;
            }
            Node* node = new Node;
            node->data = element;
            node->next =NULL;
            tail->next = node;
            tail = node;
            length++;
        }
    }
}


//delete the element from the linkedlist
int LinkedList::deleteElement(int element){
    if(length==0) return -1;
    Node* temp_pointer = head;
    while(temp_pointer){
        if(temp_pointer->data==element && temp_pointer==head){
            head = head->next;
            int value = temp_pointer->data;
            delete temp_pointer;
            length--;
            return value;
        }else if(temp_pointer->next->data==element){
            int value = temp_pointer->next->data;
            Node* delete_node = temp_pointer->next;
            temp_pointer->next = temp_pointer->next->next;
            delete delete_node;
            length--;
            return value;
        }
        temp_pointer=temp_pointer->next;
    }
    return -1;
}

//check if linkedlist is sorted
bool LinkedList::isSorted(){

    if(length==0){
        cout<<"empty linkedlist"<<endl;
        return false;
    }else{
        Node* temp_pointer = head;
        while(temp_pointer->next!=NULL){
            if(temp_pointer->data<=temp_pointer->next->data){
                temp_pointer = temp_pointer->next;
            }else{
                return false;
            }
        }return true;
    }
}
//concatining to linked lists
void LinkedList::concatinate(LinkedList* list3){
    tail->next = list3->head;
    tail = list3->tail;
    length+=list3->length;
    // delete list3->head;
}
int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {100,200,300,400,500,600,700,800,900,1000};
    LinkedList* mylist1 = new LinkedList();
    LinkedList* mylist2 = new LinkedList(arr,10);
    LinkedList* mylist3 = new LinkedList(arr2,10);
    // mylist2->display();
    // cout<<"<<<<<<<<<<<<<<<<<inserting element>>>>>>>>>>>>>"<<endl;
    // mylist2->insert(0,0);
    // mylist2->insert(3,14);
    // cout<<"deleting element by passing the element"<<endl;
    // mylist2->deleteElement(5);
    // mylist2->deleteElement(1);
    // mylist2->deleteElement(8);
    // mylist2->insertInSorted(1);
    // mylist2->insertInSorted(5);
    // cout<<mylist2->isSorted()<<endl;
    mylist2->concatinate(mylist3);
    mylist1->concatinate(mylist3);
    mylist2->display();
    return 0;
}