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
#define pll pair<ll, ll>
#define INF INT_MAX
#define LINF LLONG_MAX
//#define testOUT 1
#define all(vec) vec.begin(), vec.end()
#define FILEINPUT freopen("inputCNB.txt", "r", stdin);
#define FILEOUTPUT freopen("ouputCNB.txt", "w", stdout);
#define FOR(i, m, n) for(int i=(int)m; i<(int)n; i++)
#define FORD(i, m, n) for(int i=(int)m; i>=(int)n; i--)
#define FastIO cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define reset(A) memset(A, 0, sizeof(A))
#define debug cerr << "debug: "
/******* LIBRARY and DEFINE *******/

template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){
return os << "(" << p.f << " " << p.s << ")";};

template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){
os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/

const int MAXN = 1e4 + 5;
const ll mod = (ll)1e9 + 7;
/********** CONSTANT *********/

//vector<int> ans;
int ans = 0;

struct Node{
	int data;
	Node* left;
	Node* right;
};

void insertNode(Node* &node, int val){
	if(node == NULL){
		node = new Node();
		node->data = val;
		node->left = NULL;
		node->right = NULL;
		return;
	}
	if(val < node->data) insertNode(node->left, val);
	else insertNode(node->right, val);
}

void getNode(Node *node, int h){
	if(node->left == NULL && node->right == NULL){
//		ans.pb(node->data);
//		return h;
		ans = max(ans, h);
	}
	if(node->left != NULL) getNode(node->left, h + 1);
	if(node->right != NULL) getNode(node->right, h + 1);
}



void solution(){
	ans = 0;
	int n;
	cin >> n;
	Node* Tree = NULL;
	FOR(i, 0, n){
		int val;
		cin >> val;
		insertNode(Tree, val);
	}
	
	getNode(Tree, 1);
	cout << ans - 1 << endl;
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
