#include<iostream>
using namespace std;

// int Print(int s, int n){

//     if(s==n){
//         return n;
//     }

//     cout<<s<<endl;
//     Print(s+1,n);
// }


//------------------------------------------------------------------------------//
//using 1 argument

void print(int n){

    if( n==1){
        cout<<"1"<<endl;
        return;
    }

    print(n-1);
    cout<<n<<endl;
}

int main(){


    print(10);

    return 0;
}

