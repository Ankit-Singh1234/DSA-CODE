// //find error in this code?

// #include<iostream>
// using namespace std;


// void printArr(int arr[], int i){
//     if(i==sizeof(arr)) return ;

//     cout<<arr[i]<<" ";
//     printArr(arr,i+1);
// }

// int main( ){
//     int arr[] = {1, 2, 3, 4, 5};
//     printArr(arr,0);
// }



#include<iostream>
using namespace std;


// void printArr(int arr[], int i,int n){
//     if(i==n) return ;

//     cout<<arr[i]<<" ";
//     printArr(arr,i+1,n);
// }

// int main( ){
//     int arr[] = {1, 2, 3, 4, 5};
//     int n= sizeof(arr)/sizeof(arr[0]);
//     printArr(arr,0,n);
// }

//using the only two para , pointer start prom last element


void Print(int arr[], int i){
    if ( i==-1) return ;

    Print(arr,i-1);
    cout<<arr[i]<<" ";
}

int main( ){
    int arr[] = {1, 2, 3, 4, 5};
    int n= sizeof(arr)/sizeof(arr[0]);
    Print(arr,n-1);
}