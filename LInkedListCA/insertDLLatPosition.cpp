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


Node* createDLL(int arr[], int index, int n, Node* back){
	
	// base case
	
	if(index==n){
		return NULL;
	}
	
	
	Node* temp=new Node(arr[index]);
	temp->prev=back;
	
	temp->next=createDLL(arr,index+1, n,temp);
	
	return temp;
}


Node* insertPos(Node* head, int pos,int val){
	
	if(head==NULL){
		return NULL;
	}
	
//	if(pos==1){
//		Node* newNode=new Node(val);
//		newNode->next=head;
//		head=newNode;
//		return head;
//	}
	
	Node* curr=head;
	pos--;
	
	while(pos--){
		curr=curr->next;
	}
	
	Node* temp=new Node(val);
	
	temp->next=curr->next;
	temp->prev=curr;
	curr->next=temp;
	temp->next->prev=temp;
	
	
	return head;
	
	
	
	
}

int main(){
	
	
	
	int arr[]={1,2,3,4,5};
	
	Node* head=createDLL(arr,0, 5,NULL);
	
	
	
	
	head=insertPos(head,3,916);

	
	Node* temp=head;
	
	while(temp){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	
		return 0;
}
