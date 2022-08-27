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

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll n,a[MAX];
ll b[MAX];
bool dd[MAX];
ll cnt = 0;


signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream(task".inp")){
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	}
	
	cin>>n;
	
	vi rt;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	for(ll i = 1;i <= n;i++){
		cin>>b[i];
		rt.push_back(b[i]);
	}
	
	sort(rt.begin(),rt.end());
	
	rt.erase(unique(rt.begin(),rt.end()),rt.end());
	
	
	for(ll i = 1;i <= n;i++){
		
		a[i] = lower_bound(rt.begin(),rt.end(),a[i]) - rt.begin() + 1;
		b[i] = lower_bound(rt.begin(),rt.end(),b[i]) - rt.begin() + 1;
	}
	
	ll itr = 1;
	
	for(ll i = 1;i <= n;i++){
		
		if(dd[a[i]])continue;
		
		
		
		while(b[itr] != a[i] && itr <= n){
			
			dd[b[itr]] = 1;
			itr++;
			cnt++;
		}
		
		//cout<<i<<" "<<itr<<'\n';
		if(b[itr] == a[i])itr++;
		if(itr > n)break;
		
		//for(ll i = 1; i<= n;i++)cout<<dd[a[i]]<<" ";
		//cout<<'\n';
		
		
		
		
	}
	
	
	
	
	cout<<cnt;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}