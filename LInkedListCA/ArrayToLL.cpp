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

	

	
    
    // display
    Node* t=head;
	
	while(t!=NULL){
		cout<<t->data<<"->";
		t=t->next;
		
	}
	cout<<"NULL"<<endl;
	
    
    return 0;
}


///////////////////////// using tail pointer ???????????/////


/* 
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


int main (){

    Node* head=NULL;
    Node* tail=NULL;

    int arr[50];
    int n;
    cout<<"Enter the no of elements= ";
    cin>>n;

    for( int i=0; i<n; i++){
        cin>>arr[i];

    }


//    for(int i=0; i<n; i++){
//        if(head==NULL){
//            head= new Node(arr[i]);
//        }
//        
//        else{
//			Node* temp=head;
//			while(temp->next!=NULL){
//				temp=temp->next;
//			}
//			
//			temp->next=new Node(arr[i]);	
//		}
//    }


//////////////////////// using tail pointer //////////////////


//    Node* tail=head;
//    while(tail->next!=NULL){
//    	tail=tail->next;
	
	for(int i=0; i<n; i++){
		if(head==NULL){
			head=new Node(arr[i]);  //it is necesarray because we also need head to traverse while displayoing
			tail=head;
		}
		else{
			tail->next=new Node(arr[i]);
		    tail=tail->next;
		}
	}
	
    
    // display
    Node* t=head;
	
	while(t!=NULL){
		cout<<t->data<<"->";
		t=t->next;
		
	}
	cout<<"NULL"<<endl;
	
    
    return 0;
}














*/













