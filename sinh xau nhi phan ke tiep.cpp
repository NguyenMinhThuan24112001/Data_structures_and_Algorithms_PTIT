#include<bits/stdc++.h>
using namespace std;
void sinh(char a[]){
	int n=strlen(a);
	int i=n-1;
	while(i>=0&&a[i]=='1'){
		a[i]='0';
		i--;
	}
	if(i>=0){
		a[i]='1';
	}
	
	cout<<a<<endl;
}
int main(){
	int t;
	char a[1000];
	cin>>t;
	while(t--){
		cin>>a;
		sinh(a);
	}
}
