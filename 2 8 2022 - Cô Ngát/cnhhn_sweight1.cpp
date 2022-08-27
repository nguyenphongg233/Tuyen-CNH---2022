#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 4e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int n;
int a[MAX];
int bit[MAX];
int bit2[MAX];
int dp[MAX][2];

int ans = 0;

void update(int id,int val){
	for(;id <= n;id += id & -id)bit[id] = max(bit[id],val);
}

int get(int id){
	int sum = 0;
	for(;id > 0;id -= id & -id)sum = max(sum,bit[id]);
	return sum;
}

void update2(int id,int val){
	for(;id <= n;id += id & -id)bit2[id] = max(bit2[id],val);
}

int get2(int id){
	int sum = 0;
	for(;id > 0;id -= id & -id)sum = max(sum,bit2[id]);
	return sum;
}

signed main(){
	
	cin>>n;
	
	vi rt;
	for(int i = 1;i <= n;i++)cin>>a[i],rt.push_back(a[i]);
	
	sort(rt.begin(),rt.end());
	
	rt.erase(unique(rt.begin(),rt.end()),rt.end());
	
	for(int i = 1;i <= n;i++){
		a[i] = lower_bound(rt.begin(),rt.end(),a[i]) - rt.begin() + 1;
	}
	
	
	for(int i = 1;i <= n;i++){
		
		
		
		int id = get2(a[i] - 1);
		
		int y = get(a[i] - 1);
		
		
		
		dp[i][0] = dp[id][0] + 1;
		dp[i][1] = y + 1;
		
		
		ans = max({ans,dp[i][0],dp[i][1]});
		
		update2(a[i],i);
		update(a[i],dp[i][0]);
		
		//cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<"\n"; 
		
	}
	
    cout<<ans<<"\n";
	
}