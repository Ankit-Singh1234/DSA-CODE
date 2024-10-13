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



Node* DeleteLast(Node* head){
	
	if(head==NULL){
		return head;
	}
	
	else{
		//// method 1
//		Node* temp=head;
//		while(temp->next->next!=NULL){
//			temp=temp->next;
//		}
//		
//		temp->next=NULL;

///// method 2
		
		Node* prev=NULL;
		Node* curr=head;
		while(curr->next!=NULL){
			prev=curr;
			curr=curr->next;
			
		}
		
		prev->next=NULL;
		free(curr);
		
	}
	
	return head;
}


int main (){

    Node* head=NULL;
    

    int arr[50];
    int n;
    cout<<"Enter the no of elements= ";
    cin>>n;

    for( int i=0; i<n; i++){
        cin>>arr[i];

    }


    for(int i=0; i<n; i++){
        if(head==NULL){
            head= new Node(arr[i]);
        }
        
        else{
			Node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			
			temp->next=new Node(arr[i]);	
		}
    }

	
	DeleteLast(head);
    
	
    
    // display
    Node* t=head;
	
	while(t!=NULL){
		cout<<t->data<<"->";
		t=t->next;
		
	}
	cout<<"NULL"<<endl;
	
    
    return 0;
}

