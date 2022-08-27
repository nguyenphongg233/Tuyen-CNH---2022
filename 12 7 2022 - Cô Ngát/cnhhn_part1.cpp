/*
   Date : 12 7 2022
   Tobi Where are you ?

*/

#include<bits/stdc++.h>

#define ll long long
#define task ""

#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll n,k;
ll a[MAX];
ll ans = 0;
bool cmp(ll a,ll b){
	
	return a > b;
	
	
}


bool check(ll mid){
	
	ll cnt = 0;
	
	for(ll i = 1;i <= n;i++){
		
		cnt += a[i] / mid;
		
		if(cnt >= k)return true;
		
		
	}
	
	if(cnt >= k)return true;
	else return false;
	
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream(task".inp")){
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	}
	
	cin>>n>>k;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	
	sort(a + 1,a + 1 + n,cmp);
	
	
	ll l = 0,r = 1e14;
	
	
	while(l <= r){
		
		ll m = l + r >> 1;
		
		if(check(m))ans = m,l = m + 1;
		else r = m - 1;
		
	}
	
	cout<<ans;
	
	
	
}