#include<bits/stdc++.h>
using namespace std;

string reverse( string &str){
    stack<char> stk;
    for(int i=0; i<str.length(); i++){
        stk.push(str[i]);
    }
    // string ans="";
    // for( int i=0; i<str.length(); i++){

    //     ans+=stk.top();//mpehle top wala append 
    //     stk.pop();// now pop meanns top decrease
        
    // }


    int i=0;
    while(!stk.empty()){
        str[i]=stk.top();
        stk.pop();
        i++;
    }
    //return ans;
    return str;
    
}

int main(){
    string str="Surjeet_Singh";

    string rev = reverse(str);

    cout<<rev<<endl;
}