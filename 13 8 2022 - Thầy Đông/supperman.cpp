#include<bits/stdc++.h>

using namespace std;

const long long N = 20;
const long long MAX = 1e5 + 5;
const long long INF = 1e9;

int n,m,k;
int cost[N + 5][N + 5];
int a[N + 5];
int dp[(1 << N) + 5];

int calc (int x, int y) {
    if (x > y) swap(x, y);
    if (x == y) return (n / 2);
    else {
        int a = x - y + n - 1;
        int b = y - x - 1;
        if (a > b) swap(a, b);
        int ans = INF;
        int p = (b - a) / 3;
        int q = (b - 2*a) / 2;
        ans = min(ans, max(b - p, 2 * p + a));
        ans = min(ans, max(b - q, q + 2 * a));
        // for (int i = 0; i <= b; i++) {
            // ans = min(ans, max(b - i, 2 * i + a));
            // ans = min(ans, max(b - i, i + 2 * a));
        // }
        return ans;
    }
}

int f(int mask){
	
	
	if(mask == (1 << (m * 2)) - 1)return 0;
	
	if(dp[mask] != -1)return dp[mask];
	
	int res = INF;
	
	for(int i = 0;i < 2 * m;i++){
		
		if(mask >> i & 1)continue;
		
		for(int j = i + 1;j < 2 * m;j++){
			
			if(mask >> j & 1)continue;
			if(cost[i][j] == -1)continue;
			
			
			int new_mask = mask | (1 << j);
			new_mask |= (1 << i);
			
			res = min(res,f(new_mask) + cost[i][j]);
			
			
			
		}
		
		
	}
	
	return dp[mask] = res;
}

signed main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin>>n>>m>>k;

	for(int i = 0;i < 2 * m;i++)cin>>a[i];
	memset(dp,-1,sizeof dp);
	
	for(int i = 1,u,v;i <= k;i++){
		cin>>u>>v;
		u--,v--;
		cost[u][v] = -1;
		cost[v][u] = -1;
	}
	
	for(int i = 0;i < 2 * m;i++){
		for(int j = i + 1;j < 2 * m;j++){
			if(cost[i][j] == -1)continue;
			cost[i][j] = calc(a[i],a[j]);
			cost[j][i] = cost[i][j];
		}
	}

	cout<<f(0);
}