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


Node*  createLL(int arr[], int index, int n){
	
	// base case
	if( index==n){
		return NULL;
	}
	
	
	Node* temp = new Node(arr[index]);
	
	temp->next=createLL(arr,index+1,n);
	
	
	return temp;
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
    head=createLL(arr,0,n);
    
    Node* t=head;
	
	while(t!=NULL){
		cout<<t->data<<"->";
		t=t->next;
		
	}
	cout<<"NULL"<<endl;
    
    return 0;
}
