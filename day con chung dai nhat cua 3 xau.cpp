#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dp[105][105][105];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin>>t;
    while(t--){
    	int n,m,l;
    	string s1,s2,s3;
    	cin>>n>>m>>l>>s1>>s2>>s3;
//    	dp[105][105][105]={0};
		memset(dp,0,sizeof(dp));
    	for(int i=1; i<=n; i++){
    		for(int j=1; j<=m; j++){
    			for(int k=1; k<=l; k++)
    				if(s1[i-1]==s2[j-1] and s2[j-1]==s3[k-1])
    					dp[i][j][k]=dp[i-1][j-1][k-1] +1 ;
					else 
						dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				}
		}
		cout<<dp[n][m][l]<<endl;
    }
    return 0;
}
