#include<iostream>
using namespace std;

int sqsum(int n){
    if(n==1) return 1;

    return n*n+sqsum(n-1);
}

int main(){

    cout<<sqsum(3)<<endl;

    return 0;
}