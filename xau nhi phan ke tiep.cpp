#include<bits/stdc++.h>
using namespace std;
void solve(char a[]){
	int n = strlen(a);
	int i = n-1;
	while(i>=0 && a[i]=='1'){
		a[i]='0';
		i--;
	}
	if(i>=0){
		a[i]='1';
	}
	cout<<a;
}
int main(){
	int t;
	cin>>t;
	char a[1000];
	while(t--){
		cin>>a;
		solve(a);
		cout<<endl;
	}
}
