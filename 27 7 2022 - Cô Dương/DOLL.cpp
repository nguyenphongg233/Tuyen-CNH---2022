#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n,m,a[MAX];
int dp[MAX][MAX];
signed main(){
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++)cin>>a[i];
	
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		dp[i][0] = 1;
		//dp[i][1] = a[i] + dp[i - 1][1];
		//cout<<dp[i][0]<<" "<<dp[i][1]<<" ";
		for(int j = 1;j <= m;j++){
			
			dp[i][j] = (dp[i - 1][j - 1] * a[i]) % mod + dp[i - 1][j];
			//cout<<dp[i][j]<<" ";
			dp[i][j] %= mod;
		}
		//cout<<"\n";
	}
	
	cout<<dp[n][m] % mod;
	
	
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}