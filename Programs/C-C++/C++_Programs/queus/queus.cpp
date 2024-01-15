/*
Introduction to queues!
difination: Queus are the logical data structures which fallows the principal of first in first out (FIFO).
Below is the representation of queue using array.

advantages using this approach:->
        1. enque and deque takes the constant time O(1)
disadvantages using this approach:->
        1. Can not resue the memory of of dequed elements.
        2. if all the elements of the queue are deques the que is full but is not full as per the memory.
*/
#include<iostream>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rare;
        int* queue;
    public:
        //constructors
        Queue(int len){
            front = rare = -1;
            size = len;
            queue = new int[size];
        }
        Queue(initializer_list<int> elements){
            front = rare = -1;
            size = std::distance(elements.begin(),elements.end());
            int enteredElements[size];
            std::copy(elements.begin(),elements.end(),enteredElements);
            queue = new int[size];
            int i=0;
            for(int element:enteredElements){
                rare++;
                queue[i++] = element;
                
            }
            
        }
        // class methods
        void display();
        int isEmpty();
        int isFull();
        void enque(int element);
        int deque();
};

void Queue::display(){
    if(this->isEmpty()){
        cout<<"empty nothing to display"<<endl;
    }else{
        for(int i=front+1;i<=rare;i++){
            cout<<queue[i]<<endl;
        }
    }
}

int Queue::isEmpty(){
    if(rare==-1){
        return 1;
    }else{
        return 0;
    }
}
int Queue::isFull(){
    if(rare == size-1){
        return 1;
    }else{
        return 0;
    }
}

void Queue::enque(int element){
    if(this->isFull()){
        cout<<"que is full"<<endl;
    }else{
        rare++;
        queue[rare] = element;
    }
}

int Queue::deque(){
    if(this->isEmpty()){
        cout<<"queue is empty"<<endl;
        return -1;
    }else{
        front++;
        return queue[front];
    }
}
int main(){

    Queue one({1,2,3,4,5,6,7});
    Queue two(10);
    two.enque(10);
    two.enque(20);
    two.enque(30);
    two.enque(40);
    two.enque(50);
    two.deque();
    // one.display();
    // one.enque(8);
    two.display();
    return 0;
}