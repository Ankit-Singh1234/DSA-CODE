#include<iostream>
using namespace std;

string revStr(string str, int s, int e){
    if (s>=e){
        return str;
    }

    // char S=str[s];
    // char E=str[e];
    // str[s]=E;
    // str[e]=S;

    char temp=str[s];
    str[s]=str[e];
    str[e]=temp;
    return revStr(str,s+1,e-1);


}

int main(){
    string str="ANKIT SINGH";
    cout<<revStr(str,0,10)<<endl;
}