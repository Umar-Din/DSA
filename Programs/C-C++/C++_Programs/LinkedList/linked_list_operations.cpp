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
        LinkedList(initializer_list<int> list):head(NULL){
            int size = std::distance(list.begin(),list.end());
            int elements[size]; std::copy(list.begin(),list.end(),elements);
            Node* node = new Node;
            node->data = elements[0];
            node->next = NULL;
            head = node;
            tail = node;
            for(int i = 1; i<size; i++){
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
        void merge(LinkedList* list3);
        void reverse();
        void reverselinkedlist();
        

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
//reversing the linked list by manuplating the links
void LinkedList::reverse(){
    if(length==0) return;
    else{
        Node* temp_pointer = head;
        Node* temp_pointer_f1 = NULL;
        Node* temp_pointer_f2 = NULL;
        while(temp_pointer!=NULL){
            temp_pointer_f2 = temp_pointer_f1;
            temp_pointer_f1 = temp_pointer;
            temp_pointer = temp_pointer->next;

            temp_pointer_f1->next = temp_pointer_f2;
        }
        // cout<<temp_pointer->next<<endl;
        // cout<<temp_pointer->data<<endl;
        head = temp_pointer_f1;
    }
}

//reversing the linkedlist by changing the data with the help of array;
void LinkedList::reverselinkedlist(){
    if(length==0)return;
    else{
        Node* temp_pointer = head;
        int size = 0;
        while(temp_pointer){
            size++;
            temp_pointer = temp_pointer->next;
        }
        int* array = new int[size];
        int i=0;int j = size-1;
        temp_pointer = head;
        while(temp_pointer){
            array[i++] = temp_pointer->data;
            temp_pointer = temp_pointer->next;
        }
        temp_pointer = head;
        while(temp_pointer){
            temp_pointer->data = array[j--];
            temp_pointer = temp_pointer->next;
        }
        delete array;
    }
}
//merging of two sorted linked lists
void LinkedList::merge(LinkedList* list3){
    if(length==0 || list3->length==0) return;
    else{
        Node* p = head;
        Node* q = list3->head;
        Node* fp = NULL;
        Node* last = NULL;
        if(p->data<q->data){
            fp = p;
            last = p;
            p = p->next;
        }else{
            fp = q;
            last = q;
            q = q->next;
        }
        while(p && q){
            if(p->data<q->data){
                last->next = p;
                last = p;
                p = p->next;
                last->next = NULL;
            }else{
                last->next = q;
                last = q;
                q = q->next;
                last->next = NULL;
            }
        }
        if(p){
            last->next = p;
            while (p->next!=NULL)
            {
                p=p->next;
            }tail = p;   
        }else{
            last->next = q;
            while(q->next!=NULL){
                q = q->next;
            }tail = q;
        }length = length+=list3->length;
    }
}
int main(){

    // int arr[] = ;
    // int arr2[] = ;
    LinkedList* mylist1 = new LinkedList();
    LinkedList* mylist2 = new LinkedList({1,3,5,7,9});
    LinkedList* mylist3 = new LinkedList({2,4,6,8,10,11,12,13,15});
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
    // mylist2->concatinate(mylist3);
    // mylist1->concatinate(mylist3);
    // mylist2->reverse();
    // mylist2->reverselinkedlist();
    mylist2->merge(mylist3);
    mylist2->display();
    return 0;
}