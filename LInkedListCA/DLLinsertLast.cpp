#include<bits/stdc++.h>
using namespace std;

class Node{
	
 public:	
	int data;
	Node* prev;
	Node* next;
	
	Node(int val){
		data=val;
		prev=NULL;
		next=NULL;
	}
};


int main(){
	
	Node* head=NULL;
	
	int arr[]={1,2,3,4,5};
	
	for(int i=0; i<5; i++){
	if(head==NULL){
		head=new Node(arr[i]);
		
	}
	
	else{
		
		Node* newNode=new Node(arr[i]);
		
		Node* t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		
		t->next=newNode;
		newNode->prev=t;
		
		
	}
		
		
	}
	
	Node* temp=head;
	
	while(temp){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;

	

}


