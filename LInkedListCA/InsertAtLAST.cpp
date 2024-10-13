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
	
	//////////////  now the code for inserting at last////////
	
	
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	temp->next=new Node(1111);

	
//	Node* newNode= new Node(000001);
//	
//	temp->next=newNode;
	
	//////////////// to print the LL
	
	Node* t=head;
	
	while(t!=NULL){
		cout<<t->data<<"->";
		t=t->next;
		
	}
	
	return 0;
}
