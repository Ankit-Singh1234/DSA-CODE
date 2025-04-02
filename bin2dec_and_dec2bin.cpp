#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int num=n;
    
    // int Bin=0;
    // while(num!=0){
    //     int rem=num%2;
    //     Bin=Bin*10+rem;
    //     num=num/2;
        
    // }
    
    // num=Bin;
    // int rev=0;
    // while(num!=0){
    //     int rem=num%10;
    //     rev=rev*10+rem;
    //     num/=10;
    // }
    
    // cout<<rev;
    
    
    // Bin to dec
    int dec=0;
    int i=1;
    while(num!=0){
        int rem=num%10;
        dec=dec+rem*i;
        num/=10;
        i=i*2;
    }
    
    cout<<dec;
    
    
    
    return 0;
}
