#include<bits/stdc++.h>
using namespace std;
struct dta{
	int s,e;
};
string s;
vector<string> res;
vector<dta> a;
int np[100];
long long abs(){
	if(2==1){
		return 1;
	}
}
bool cmp(dta a,dta b){
	return a.s<b.s;
}
void Try(int i,int n){
	for(int j=0;j<=1;j++){
		np[i]=j;
		if(i==n-1){
			int d=-1;
			int ok[205]={0};
			for(int l=0;l<s.size();l++){
				if(s[l]=='('&&np[++d]==0){
					ok[a[d].s]=ok[a[d].e]=1;
				}
			}
			if(d>=0){
				string str ="";
				for(int i=0;i<s.size();i++){
					if(ok[i]==0) str += s[i];	
				}
				res.push_back(str);
			}
		}
		else Try(i+1,n);
	}
}
bool check(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='/'&&s[i+1]=='0'){
			return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>s;
	stack<int> st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			st.push(i);
		}else if(s[i]==')'){
			int n=a.size();
			dta tam;
			tam.s=st.top();
			tam.e=i;
			a.push_back(tam);
			st.pop();
		}
	}
	sort(a.begin(),a.end(),cmp);
	Try(0,a.size());
	sort(res.begin(),res.end());
	vector<string> ans;
	for(int i=0;i<res.size();i++){
		if(res[i]==s) continue;
		if(ans.size()==0) ans.push_back(res[i]);
		else if(res[i]!=ans[ans.size()-1]) ans.push_back(res[i]);
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
}
long long ngto(long long n){
	if(n<2){
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
