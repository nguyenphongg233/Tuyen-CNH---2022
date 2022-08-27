#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e6 + 5;
const long long mod = 2016 * 8;
#define int long long 
int t,n;

signed main(){

	cin>>t;
	while(t--){
		
		int n;
		cin>>n;
		
		cout<<((((n % mod) * ((n + 2) % mod) * ((2 * n + 1) % mod)) % mod) / 8 ) % (2016)<<'\n';
	}
}