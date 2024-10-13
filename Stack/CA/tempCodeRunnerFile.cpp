#include<bits/stdc++.h>
using namespace std;


class Node{

    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        
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

    int size(){
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

    cout<<"size"<<stk.size()<<endl;





    return 0;
}