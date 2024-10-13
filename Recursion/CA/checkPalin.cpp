#include<iostream>
using namespace std;

bool checkPal( string str , int s, int e){
    //base case
    if(s>=e) return true;




    if( str[s]!=str[e]){
        return false;
    }

    return checkPal(str, s+1, e-1);
}

int main(){
    string str;
    cin>>str;
    cout<<checkPal(str, 0, str.length()-1)<<endl;
}