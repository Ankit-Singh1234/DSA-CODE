#include<iostream>
using namespace std;

int minEle( int arr[], int i, int n){

    if(i==n-1){
        return arr[n-1];
    }

    return min(arr[i], minEle(arr, i+1, n));

}

int main(){

    int arr[]={2,4,5,21,1};

    cout<<minEle(arr,0,5)<<endl;
    return 0;
}