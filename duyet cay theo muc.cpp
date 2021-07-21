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
#define sqr(a) (1.0)*(a)*(a)
/******* LIBRARY and DEFINE *******/


template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){
return os << "(" << p.f << " " << p.s << ")";};

template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){
os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/

vector<vector<int>> ans;
const int N = 1e4 + 5;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data){
	Node* node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void printTree(Node* node){
	if(node == NULL) return;
	
	cout << node->data << " ";
	printTree(node->left);
	printTree(node->right);
}

void levelTree(Node* node, int lvl){
	if(node == NULL) return;
	ans[lvl].pb(node->data);
	
	levelTree(node->left, lvl + 1);
	levelTree(node->right, lvl + 1);
}

void solution(){
	
	int n;
	cin >> n;
	ans.clear();
	ans.resize(N);
	map<int, Node*> cts;
	int root = -1;
	FOR(i, 0, n){
		int x, y;
		char c;
		cin >> x >> y >> c;
		
		if(root == -1){
			root = x;
		}
		
		if(cts.find(x) == cts.end()){
			Node* n = createNode(x);
			cts[x] = n;
		}
		
		Node* node = cts[x];
		
		Node* newNode = createNode(y);
		if(c == 'L') node->left = newNode;
		else node->right = newNode;
		
		cts[y] = newNode; 
		
	}

	Node* node = cts[root];
	
	
	levelTree(node, 1);
	
	FOR(i, 1, N){
		if(ans[i].empty()) continue;
		for(auto x: ans[i]) cout << x << " ";
	}
	cout << endl;
	
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
