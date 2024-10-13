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


int main(){
	
	
	Node* head=new Node(1);
//	
//	Node* temp=new Node(7);
//	temp-next=head;
//	head=temp;
//	
//	delete temp;
	int arr[5]={2,3,4,5,6};
	
	for( int i=0; i<5;  i++){
		
		if(head==NULL){
			head=new Node(arr[i]);
		}
		
		else{
			
			Node* temp=new Node(arr[i]);
			temp->next=head;
			head=temp;
			

		}
	}
	
	Node* t=head;
	
	while(t!=NULL){
		cout<<t->data<<"->";
		t=t->next;
		
	}

	
	
	return 0;
}

















