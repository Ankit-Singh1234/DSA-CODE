#include<iostream>
#include<algorithm>
using namespace std;

int merge( int arr1[], int arr2[], int n1, int n2,int arr[], int n){
    

    int i=0, j=0,k=0;
    while(i<n1 &&j<n2){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }
    }

    while(i<n1){
        arr[k++]=arr1[i++];
    }
    while(j<n2){
        arr[k++]=arr2[j++];
    }







}

int main(){

    int arr1[]={1,4,2,7,5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[]={4,9,1,3,0,8,0,2,3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);
    int n=n1+n2;
    int arr[n];
   merge(arr1,arr2,n1,n2,arr,n);
   cout<<"Sorted array is "<<endl;
   for(int i=0;i<n1+n2-1;i++){
    cout<<arr[i]<<" ";
    }
    return 0;
}

//hi?

