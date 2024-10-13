#include<iostream>
using namespace std;

int LS( int arr[], int i, int k){

    //base case
    if(i==-1){
        return -1;
    }


    if( arr[i]==k){
        return i; 
    }

    return LS( arr, i-1,k);
}

int main (){
   int arr[14]={1212,123,23,332,424,22124,1241,214,1224,1,2,3,4,5};
   int k=3;
    cout<<"Index of key k is "<<LS(arr,14-1,k)<<endl;
   

    return 0;
}