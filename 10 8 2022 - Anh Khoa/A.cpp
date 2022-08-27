#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e5 + 5;
const long long mod = 11229837253;

long long last = 1;
#define int long long

long long exp(long long a,long long b){
	
	if(b == 0)return 0;
	if(b == 1)return a % mod;
	
	long long s = exp(a,b / 2) % mod;
	
	s = s + s;
	s %= mod;
	
	if(b & 1)s = (s + a) % mod;
	
	return s % mod;
	
	
	
}

signed main(){
	
	
	vector<int> res;
	int x;
	while(cin>>x){
		
		res.push_back(x);
		
	}
	
	int n = res.size() - 1;
	
	bool ok = 1;
	
	
	for(auto ve : res){
		
		if(ve == n && ok){
			ok = 0;
			continue;
		}
		
		last = exp(last,ve);
		
		
	}
	
	cout<<last % mod;
	
}