#include<iostream>
using namespace std;

string lowToUpper(string &str, int i){
    if(i==-1){
        return str;
    }
    if(str[i]!=' ')
    str[i]=str[i]-'a'+'A';
    return lowToUpper(str,i-1);
}


int main(){
    string str="indian air force";
    cout<<lowToUpper(str,str.length()-1)<<endl;
}

// int main(){

//     char ch='d';
//     char upC=ch-'a'+'A';
//     cout<<upC<<endl;
//     return 0;
// }