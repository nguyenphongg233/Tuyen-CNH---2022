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

const long long MAX = (1 << 19) + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

vector<char> t = {'e','a','i','o','u','y'};

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream(task".inp")){
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	}
	
	string s;
	cin>>s;
	
	cout<<s[0];
	
	for(ll i = 1;i < s.size();i++){
		
		if(s[i] != 'm')cout<<s[i];
		else {
			
			bool ok = 0;
			
			for(auto e : t)if(s[i - 1] == e)ok = 1;
			
			if(ok)continue;
			else cout<<"m";
		}
		
	}
	
	
}