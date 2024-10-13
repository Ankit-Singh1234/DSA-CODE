#include<iostream>
using namespace std;



void print(int n){

    if(n==1) n=n+1;
    if(n%2!=0) n=n-1;


    if(n==2){
        cout<<2<<endl;
        return;
    }

    print(n-2);
    cout<<n<<endl;

}

int main(){

    print(23);

    return 0;
}