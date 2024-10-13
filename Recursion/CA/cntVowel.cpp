#include<iostream>
using namespace std;

int cntVow(string str, int i){


    //base Case
    if(i==-1) return 0;


    if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u' ||
    str[i]=='A' || str[i]=='E' ||str[i]=='I' ||str[i]=='O' ||str[i]=='U' ){
        return 1+cntVow(str,i-1);
    }

    else{
        return cntVow(str, i-1);
    }
}

int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;
    cout<<"Number of vowels in the string is: "<<cntVow(str,str.length()-1)<<endl;
    return 0;
}