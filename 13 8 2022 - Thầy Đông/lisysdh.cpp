#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
#define int long long
#define X first
#define Y second

int cnt = 0;
int sum = 0;
int gt[MAX];

int power(int a,int b){
	
	if(b == 0)return 1;
	if(b == 1)return a;
	
	int s = power(a,b / 2) % mod;
	
	s = s * s;
	s %= mod;
	
	if(b & 1)s = s * a;
	
	return s % mod;
}

int C(int k,int n){
	
	int tmp = gt[n];
	
	int x = power(gt[n - k],mod - 2);
	
	int y = power(gt[k],mod - 2);
	
	return (((tmp) * (x)) % mod * (y)) % mod;
	
}
signed main(){
	
	int n;
	cin>>n;
	sum = 2 * (n - 1);
	
	gt[0] = 1;
	
	//memset(dp,-1,sizeof dp);
	
	for(int i = 1;i < MAX;i++)gt[i] = (gt[i - 1] * i) % mod;
	for(int i = 1,x;i <= n;i++){
		cin>>x;
		if(x == -1)cnt++;
		else sum -= x;
	}
	
	cout<<C(cnt - 1,sum - 1) % mod;
	
}