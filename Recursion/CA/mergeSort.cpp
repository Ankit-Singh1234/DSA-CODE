#include<iostream>
using namespace std;


// void merge(int arr[], int l, int mid, int r){

//     int temp[r-l+1];
//     int k=0;

//     int i=l;
//     int j=mid+1;

//     while(i<=mid &&  j<=r){
//         if(arr[i]<=arr[j]){
//             temp[k++]=arr[i++];
//         }
//         else{
//             temp[k++]=arr[j++];
//         }
//     }

//     while(i<=mid){
//         temp[k++]=arr[i++];
//     }

//     while(j<=r){
//         temp[k++]=arr[j++];
//     }

//     //copying the temp array sorted subarray in the original array
//     // k =0 at the starting position of the temp array
    
//     for(int k=0; k<r-l+1;k++){

//         //arr[l++]=temp[k]; incorrect l ko change nahi karna pura algorithm in bigad jayega
//         arr[l+k]=temp[k];
//     }


    
// }

// void mergeSort( int arr[], int l, int r){
//     //base case
//     if(l==r) return; //if(l>=r) return;


//     //divide
//     int mid=l+(r-l)/2;
//     mergeSort(arr,l,mid);
//     mergeSort(arr,mid+1,r);

//     //merge
//     merge(arr,l,mid,r);


// }


// int main() {
//     int arr[] = {5, 2, 8, 1, 9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     mergeSort(arr, 0, n - 1);
    
//     // Printing the sorted array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
    
//     return 0;
// }


//************************************************************************** */


//rewrite for practice

// void merge( int arr[], int left, int mid, int right){
//     int n=right-left+1;
//     int temp[n];
//     int k=0;

//     int i=left;
//     int j=mid+1;

//     while( i<=mid && j<=right){
//         if(arr[i]<=arr[j]){
//             temp[k++]=arr[i++];

//         }
//         else{
//             temp[k++]=arr[j++];
//         }
//     }

//     while(i<=mid){
//         temp[k++]=arr[i++];
//     }

//     while(j<=right){
//         temp[k++]=arr[j++];
//     }

//     for( int k=0; k<n; k++){
//         //******************* */
//         //most crucial step/
//         arr[left+k]=temp[k];
//         //******************** */
    
// }
// }


// void mergeSort( int arr[], int left, int right){

//     //base case
//     if(left>=right){ 
//         return;
//         }
    
//     int mid=left+(right-left)/2;
//     mergeSort(arr,left,mid);
//     mergeSort(arr,mid+1,right);


//     //merge
//     merge(arr,left,mid,right); //  lmr
    
// }



// int main() {
//     int arr[] = {5, 2, 8, 1, 9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     mergeSort(arr, 0, n - 1);
    
//     // Printing the sorted array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
    
//     return 0;
// }

/************************************************** */

//ReWrite again


void merge(int arr[], int left, int mid,int right){
    int n=right-left+1;

    int temp[n];
    int k=0;

    int i=left;
    int j=mid+1;

    while( i<=mid && j<=right){
        if( arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];

        }


    }

    while(i<=mid){
        temp[k++]=arr[i++];

    }

    while( j<=right){
        temp[k++]=arr[j++];
    }

    for( int k=0; k<n; k++){
        
        //care for the  'left+k'  and temp[k]

        arr[left+k]=temp[k];      //ERROR PRONE SECTION 
    }
}

void mergeSort( int arr[], int left, int right){

    if(left>=right) return ;

    int mid=left+(right-left)/2;
    mergeSort( arr, left, mid);
    mergeSort(arr, mid+1, right);


    merge(arr,left, mid,right);
}


int main(){
    int arr[100];
    int n;
    cout<<"Enter no of Element ";
    cin>>n;

    for( int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for( int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}


//************DECREASING ORDER (non-increasing order) */
// void merge(int arr[], int left, int mid,int right){
//     int n=right-left+1;

//     int temp[n];
//     int k=0;

//     int i=left;
//     int j=mid+1;

//     while( i<=mid && j<=right){
//         if( arr[i]>=arr[j]){    //only reverse the ' < 'to ' >'
//             temp[k++]=arr[i++];
//         }
//         else{
//             temp[k++]=arr[j++];

//         }


//     }

//     while(i<=mid){
//         temp[k++]=arr[i++];

//     }

//     while( j<=right){
//         temp[k++]=arr[j++];
//     }

//     for( int k=0; k<n; k++){
        
//         //care for the  'left+k'  and temp[k]

//         arr[left+k]=temp[k];      //ERROR PRONE SECTION 
//     }
// }

// void mergeSort( int arr[], int left, int right){

//     if(left>=right) return ;

//     int mid=left+(right-left)/2;
//     mergeSort( arr, left, mid);
//     mergeSort(arr, mid+1, right);


//     merge(arr,left, mid,right);
// }


// int main(){
//     int arr[100];
//     int n;
//     cout<<"Enter no of Element ";
//     cin>>n;

//     for( int i=0; i<n; i++){
//         cin>>arr[i];
//     }

//     mergeSort(arr, 0, n-1);

//     for( int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }


//     return 0;
// }


