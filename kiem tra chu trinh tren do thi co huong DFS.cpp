#include<bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define eb emplace_back
#define pii pair<int, int>
#define INF INT_MAX
#define LINF LLONG_MAX
#define all(vec) vec.begin(), vec.end()
#define FILEINPUT freopen("inputCNB.txt", "r", stdin);
#define FILEOUTPUT freopen("ouputCNB.txt", "w", stdout);
#define FOR(i, m, n) for(int i=(int)m; i<(int)n; i++)
#define FORD(i, m, n) for(int i=(int)m; i>=(int)n; i--)
#define FastIO cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define reset(A) memset(A, 0, sizeof(A))
/******* LIBRARY and DEFINE *******/


template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){
return os << "(" << p.f << " " << p.s << ")";};

template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){
os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/


const int MAXN = 1e7 + 5;
const ll mod = (ll)1e9 + 7;
/********** CONSTANT *********/

vector<vector<int>> adj;
vector<bool> vis;
bool ans = false;
vector<int> usingg;

void dfs(int u){
	vis[u] = true;
	for(auto x: adj[u]){
		if(vis[x]){
			if(usingg[x]) ans = true;
			continue;
		}
		usingg[x] = true;
		dfs(x);
		usingg[x] = false;
	}
}


void solution(){

	int n, m;
	cin >> n >> m;
	adj.clear();
	adj.resize(n + 1);
	vis.assign(n + 1, false);
	usingg.assign(n + 1, false);
	
	FOR(i, 0, m){
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
	}
	
	ans = false;
	FOR(i, 1, n + 1){
		if(vis[i]) continue;
		usingg[i] = true;
		dfs(i);
		usingg[i] = false;
	}
	cout << (ans? "YES" : "NO") << endl;
}



/*******************************/
		
/******** MAIN FUNCTION *********/
int main(){
	
	#ifdef NGOCBINH
		FILEINPUT;
		FILEOUTPUT;
	#endif
	
	FastIO;
	
	int test = 1;	
	cin >> test; cin.ignore();	

	while(test--) solution();
	
	return 0;	
}
