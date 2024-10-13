#include<iostream>
using namespace std;

int pw(int n){

    if(n==0) return 1;
    if(n==1) return 2;

    return 2*pw(n-1);
}

int main(){

    cout<<pw(4)<<endl;

    return 0;
}