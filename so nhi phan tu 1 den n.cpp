#include<bits/stdc++.h>
using namespace std;
void solve(int n){
	queue<string> q;
	q.push("1");
	while (n--){
		string s1 = q.front();
		q.pop();
		cout << s1 << " ";
		string s2 = s1;
		q.push(s1.append("0"));
		q.push(s2.append("1"));
	}
	cout << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		solve(n);
	}
}
