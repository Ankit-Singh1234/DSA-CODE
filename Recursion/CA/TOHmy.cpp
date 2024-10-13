#include<bits/stdc++.h>
using namespace std;


void toh(int n, char s,char d,char a){
	if(n==1){
		cout<<"move disk-"<<n<<" from "<<s<<" to "<<d<<endl;
		return;
	}
	
	toh(n-1,s,a,d);
	cout<<"move disk-"<<n<<" from "<<s<<" to "<<d<<endl;
	toh(n-1,a,d,s);
	
	
}


int main(){
	int n=3;
	toh(n,'S','D','A');
	return 0;
}


// sda sad ads