#include<iostream>
#include<algorithm>

using namespace std;


int partition(int arr[], int start, int end){

    int pos=start;
    int pivot=arr[end];
    for(int i=start; i<=end; i++){
        if(arr[i]>=pivot){///////////////////// interchange the < with the > to make
            swap(arr[i],arr[pos]);/// descending order
            pos++;
        }
    }
    
    return pos-1;
    
}

void QS(int arr[], int start, int end){

    if(start>=end) return ;


    int pivot=partition(arr,start,end);
    QS(arr,start,pivot-1);
    QS(arr,pivot+1,end);

}


int main(){
    int arr[]={6,23,46,1,23,1,1,7,4,8,2,8,26};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    QS(arr,0,n-1);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

//practice again *********************************************


// #include<iostream>
// #include<algorithm>

// using namespace std;

// //********PRACTICE AGAIN */

// int partition( int arr[], int start, int end){
    
//     int pos=start;
//     int pivot=arr[end];
    
//     for(int i=start; i<=end; i++){
//         if(arr[i]<=pivot){
//             swap(arr[i], arr[pos]);
//             pos++;
//         }
//     }
    
    
//     return pos-1;
// }

// void qs( int arr[], int start, int end){
    
//     if(start>=end) return ;
    
//     int pivot=partition(arr,start,end);
//     qs(arr,start,pivot-1);
//     qs(arr,pivot+1, end);
// }

// int main(){
//     int arr[]={6,23,46,1,23,1,1,7,4,8,2,8,26};
//     int n=sizeof(arr)/sizeof(arr[0]);
    
//     qs(arr,0,n-1);
//     for(int i=0; i<n;i++){
//         cout<<arr[i]<<" ";
//     }
    
//     return 0;
// }


