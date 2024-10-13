#include<bits/stdc++.h>
using namespace std;
//
//
//int winner(vector<int>&person,int index, int n, int k,int personLeft){
//	
//	//base case
//	if(leftPerson==1){
//		for(int i=0; i<person.size();i++){
//			if(person[i]==0){
//				return i;
//			}
//		}
//	}
//	
//	
//	
//	int kill=(k-1)%personLeft;
//	
//	while(kill--){
//		
//		index=(index+1)%n;
//		while(person[index]==1){
//			index=(index+1)%n;
//			}
//		
//
//	}
//	
//	person[index]=1;
//	
//	
//	while(person[index]==1){
//		index=(index+1)%n;
//	}
//	
//	return winner(person,index,n,k,personLeft-1);
//}
//
//int main(){
//	int n=6,k=4
//	vector<int>peson(n,0);
//	cout<<winner(person,0,n,k,6)<<endl;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


int winner(vector<int>&person, int index, int n, int k, int personLeft){
	
	//base case
	
	if(personLeft==1){
		for(int i=0; i<n; i++){
			if(person[i]==0){
				return i;
			}
		}
	}
	
	
	
	int kill=(k-1)%personLeft;
	
	while(kill--){
		index=(index+1)%n ; //jab tak kill zero na ho tab tak age badh, but...
		while(person[index]==1){  //but, jab tak jo pehle se hi game se out ho gaye ya kill hai unko skip kar dena hai
			index=(index+1)%n;
		}
	}
	//loop ke bahar aa gaya iska matlab jisko kill karna hai wahan pahuch gaya hai
	
	person[index]=1;
	
	//kill karne ke baad ab next alive player ke paas jana hai
	while(person[index]==1){
		index=(index+1)%n;
	}
	
	//ab next alive par pahunchlw ke baad the same process is repeated
	
	return winner(person,index,n,k,personLeft-1);
	
}


int main(){
	
	
	int n=5, k=3;
	vector<int> person(n,0);
	
	cout<<winner(person,0,n,k,n)<<endl;
}


