#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int top;
    int size;
    int flag=1;//empty

    public:
    // constructor
    Stack(int n){
        size=n;
        top=-1;
        arr= new int[n];
    }

    void push(int val){

        if(top+1==size){
            cout<<"StackOverFlow"<<endl;
            
            flag=0;
            return;
        }
        else{
            top++;
            arr[top]=val;
            flag =0;
            
        }
    }

    int pop(){

        if(top==-1){
            cout<<"StackUnderFlow"<<endl;
            flag=1;
            return INT_MIN;
        }
        else{
            int val=arr[top];
            top--;
            return val;
            if(top==-1){
                flag=1;
            }else{
                flag=0;
            }
        }
    }

    bool isEmpty(){

        return flag==1;
    }

    int peek(){

        if(flag==1){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        else{
            return arr[top];
        }
    }
};

int main(){

   Stack stk(5);

    // stk.push(1);
    // stk.push(2);
    // stk.push(3);
    // stk.push(3);
    // stk.push(3);
    // stk.push(4);
    // stk.push(-124324);

    cout<<stk.peek()<<endl;
    cout<<stk.isEmpty()<<endl;
    cout<<stk.pop()<<endl;

    return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;

class Stack {
    int* arr;
    int top;
    int size;

public:
    // Constructor to initialize the stack
    Stack(int n) {
        size = n;
        top = -1;
        arr = new int[n];
    }

    // Destructor to free dynamically allocated memory
    ~Stack() {
        delete[] arr;
    }

    void push(int val) {
        if (top + 1 == size) {
            cout << "Stack Overflow" << endl;
            return;
        } else {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return INT_MIN; // Special value indicating underflow
        } else {
            int val = arr[top];
            top--;
            return val;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN; // Special value indicating empty stack
        } else {
            return arr[top];
        }
    }
};

int main() {
    Stack stk(5);

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    cout << "Top of the stack: " << stk.peek() << endl;

    stk.pop();
    cout << "Top after pop: " << stk.peek() << endl;

    return 0;
}

*/