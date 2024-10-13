#include<bits/stdc++.h>
using namespace std;


class Node{

    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
        
    }
};

class Stack{

    Node* top;
    int size;
    public:
    Stack(){
        top=NULL;
        size=0;
    }

    void push( int val){

        Node* temp=new Node(val);
        if(temp==NULL){

            cout<<"Stack Under Flow"<<endl;
            return ;
        }
        else{
            temp->next=top;
            top=temp;
        
            size++;
        }
    }

    int pop(){
        if(top==NULL){
            cout<<"stack UnderFlow"<<endl;
            return -1;
        }
        else{
            Node* temp=top;
            int val=top->data;
            top=top->next;
            
            
            size--;

            delete temp;
            return val;
        }
    }

    int isEmpty(){
        return top==NULL;
    }

    int Stksize(){
        return size;
    }
};

int main(){

    Stack stk;
    stk.push(12);
    stk.push(1234);
    stk.push(54);
    stk.push(78);

    cout<<"Popped element is "<<stk.pop()<<endl;

    cout<<"size is " <<stk.Stksize()<<endl;





    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* top;
    int size;
public:
    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int val) {
        Node* temp = new Node(val);
        temp->next = top;
        top = temp;
        size++;
    }

    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return -1;  // Return an error value (e.g. -1) when the stack is empty.
        } else {
            Node* temp = top;
            int val = top->data;
            top = top->next;
            size--;
            delete temp;
            return val;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack stk;
    stk.push(12);
    stk.push(1234);
    stk.push(54);
    stk.push(78);

    cout << "Popped element is " << stk.pop() << endl;
    cout << "Popped element is " << stk.pop() << endl;
    cout << "Popped element is " << stk.pop() << endl;
    cout << "Popped element is " << stk.pop() << endl;

    return 0;
}


*/