#include<iostream>
using namespace std;

int Pw(int k, int n){

    if( n==0) return 1;
    if( n==1) return k;

    return k*Pw(k,n-1);
}


int main(){

    cout<<Pw(7,3)<<endl;

    return 0;
}

