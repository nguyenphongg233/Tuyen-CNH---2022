#include<bits/stdc++.h>

using namespace std;

const long long MAX = 2e5 + 5;
const long long MOD = 998244353;
#define int long long 

int n,m;
int a[MAX],b[MAX];
int cnt[MAX];
int gt[MAX];
int res = 0;
int under = 1;
int bit[MAX];

void update(int id,int val){
	
	for(;id < MAX;id += id & -id)bit[id] += val;
	
}

int get(int id){
	int res = 0;
	
	for(;id > 0;id -= id & -id)res += bit[id];
	return res % MOD;
}

int power(int a,int b){
	if(b == 1)return a;
	if(b == 0)return 1;
	
	int s = power(a , b / 2);
	
	s = (s * s) % MOD;
	
	if(b & 1) s = (s * a) % MOD;
	
	return s;
	
}

int sdd = 0;
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	gt[0] = 1;
	for(int i = 1;i < MAX;i++)gt[i] = (gt[i - 1] * i) % MOD;
	
	//cout<<gt[9]<<"\n";
	cin>>n>>m;
	sdd = n;
	
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= m;i++)cin>>b[i];
	
	for(int i = 1;i <= n;i++)cnt[a[i]]++;
	for(int i = 1;i < MAX;i++){
		under = (under * gt[cnt[i]]) % MOD;
		update(i,cnt[i]);
	}
	
	bool ok = 1;
	for(int i = 1;i <= m;i++){
		
		int nx1 = get(b[i] - 1);
		int sum = (nx1 % MOD * gt[n - i] % MOD) * ((power(under,MOD - 2) + MOD) % MOD);
		sum %= MOD;

		res += sum; 
		res %= MOD;
		
		//cout<<nx1<<" ";
		//cout<<sum<<" "<<under<<"\n";
		
		under = (under) % MOD  * ((power(cnt[b[i]] , MOD - 2) + MOD) % MOD);
		under %= MOD;
		
		if(cnt[b[i]] != 0)sdd--;
		cnt[b[i]]--;
		update(b[i], -1);
		//if(i == n)break;
		if(cnt[b[i]] < 0){
			ok = 0;
			break;
		}
		
	}
	
	cout<<res % MOD + (sdd == 0 && n < m);
	
}