#include<bits/stdc++.h>

using namespace std;
#define int long long
const long long N = 1e3 + 5;
const long long MAX = 1e5 + 5;
const long long MOD = 1e9 + 7;

int n,t;
int a[N];
int cnt[2];
// 0 : am
// 1 : duong 

int power(int a,int b){
	if(a == 0)return 1;
	if(b == 0)return 1;
	if(b == 1)return a % MOD;
	
	int s = power(a,b / 2) % MOD;
	
	s = (s * s) % MOD;
	
	if(b & 1)s = (s * a) % MOD;
	return s;
}

int res = 0;
int gt[MAX];

int sub1(){
	
	int step = t - abs(a[1]);
	if(a[1] < 0)cnt[0] -= a[1];
	else cnt[1] += a[1];
	int res = 0;
	for(int i = 0;i <= step;i++){
		
		if((step - i) % 2 != 0)continue;
		
		int cnt0 = cnt[0] + (step - i) / 2;
		int cnt1 = cnt[1] + (step - i) / 2;
		
		res += ((gt[t] % MOD * (power(gt[cnt0],MOD - 2)) % MOD) % MOD * (power(gt[cnt1],MOD - 2) % MOD * power(gt[i],MOD - 2) % MOD) % MOD) % MOD;
		res %= MOD;
	}
	
	
	return res;
	
}

signed main(){
	
	cin>>n>>t;
	
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		cnt[a[i] > 0] += abs(a[i]);
	}
	
	gt[0] = 1;
	for(int i = 1;i < MAX;i++)gt[i] = (gt[i - 1] * i) % MOD;
	//cout<<cnt[0]<<" "<<cnt[1]<<'\n';
	
	
	if(n == 1)return cout<<sub1(),0;
	
	int stepcnt = t - cnt[0] - cnt[1];
	
	//cout<<stepcnt<<"\n";
	for(int i = 0;i <= stepcnt;i++){
		
		if((stepcnt - i) % 2 != 0)continue;
		
		int cnte = (stepcnt - i) / 2;
		
		//cout<<i<<" "<<cnte + cnt[0] <<" "<<cnte + cnt[1]<<"\n";
	//	cout<<i<<" "<<cnte<<" ";
		//cout<<power(gt[cnt[0] + cnte],MOD - 2)<<" "<<power(gt[cnt[1] + cnte],MOD - 2)<<" "<<power(gt[i],MOD - 2)<<"\n";
		//int rt = (gt[t]) * power(cnt[0] + cnte,MOD - 2) % MOD * power(cnt[1] + cnte,MOD - 2) % MOD * power(i,MOD - 2) % MOD;
		//cout<<rt<<" ";
		
		
		int mod1 = max(1ll,power(gt[cnt[0] + cnte],MOD - 2) % MOD);
		int mod2 = max(1ll,power(gt[cnt[1] + cnte],MOD - 2) % MOD);
		int mod3 = max(1ll,power(gt[i],MOD - 2) % MOD);
		
		//cout<<gt[t]<<" ";
		//cout<<mod1<<" "<<mod2<<" "<<mod3<<"\n";
		res += gt[t] % MOD * mod1 * mod2 * mod3 * t;
		res %= MOD;
		
	}
	
	cout<<res % MOD;
	
	
}