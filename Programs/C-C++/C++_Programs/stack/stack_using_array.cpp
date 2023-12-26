/*stack using array
1. stack is the data structure which fallows the principle of LIFO(Last In First Out)
key points:- stack overflow/stack underflow/top/peek
*/

#include<iostream>
using namespace std;

class Stack{
  private:
    int top;
    int size;
    int* stack;
  public:
    //constructors
    Stack(int s):size(s),top(-1),stack(NULL){};
    Stack(int s, initializer_list<int> elements){
        size = s;
        stack = new int[size];
        int i = 0;
        for(int ele:elements){
            stack[i++] = ele;
        }
        top = i-1;
    }
    //methos of stack
    void push(int element);
    int pop();
    int isFull();
    int isEmpty();
    void displayStack();
    int peek(int position);
};

int Stack::peek(int position){
    if(position <= 0 || position >= size){
        cout<<" invalid positon"<<endl;
        return 0;
    }else{
        int temp = stack[top-position+1];
        return temp;
    }
}

void Stack::displayStack(){
    if(top == -1){
        cout<<"Empty Stack "<<endl;
    }else{
        for(int i=0; i<=top; i++){
            cout<<stack[i]<<endl;
        }
    }
}

int Stack::isFull(){
    if(top == size-1) return 1;
    return 0;
};
int Stack::isEmpty(){
    if(top==-1) return 1;
    return 0;
}
void Stack::push(int element){
    if(top==size-1){
        cout<<"stack overflow";
    }
    else if (top == -1)
    {
        stack =  new int[10];
        stack[top+1] = element;
        top = top+1;
    } 
    else{
        stack[top+1] = element;
        top++;
    }
}
int Stack::pop(){
    if(top == -1){
        cout<<"stack underflow";
        return -1;
    }
    else{
        int temp = stack[top];
        stack[top] = 0;
        top--;
        return temp;
    }
}


int main(){
    Stack ist_stack(5);
    Stack second_stack(5,{1,2,3,4,5});
    // cout<<second_stack.peek(3);
    // second_stack.displayStack();
    // cout<<second_stack.isEmpty()<<"  empty check"<<endl;
    // cout<<second_stack.isFull()<<"    full check"<<endl;

    // cout<<ist_stack.isFull()<<"  is full";
    // ist_stack.push(5);
    // ist_stack.push(10);
    // cout<<ist_stack.pop()<<"  poped element"<<endl;
    // ist_stack.displayStack();



    return 0;
}