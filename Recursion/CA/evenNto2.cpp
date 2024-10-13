#include<iostream>
using namespace std;

void EvenN(int n){
    if( n%2!=0){
        n=n-1;
    }

    if ( n==2){
        cout<<2<<endl;

        return;
    }

    cout<<n<<endl;
    EvenN(n-2);
}

int main(){

    EvenN(11);
    return 0;
}