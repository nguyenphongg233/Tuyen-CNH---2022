#include<bits/stdc++.h>

using namespace std;
#define int long long
const long long MAX = 1e5 + 5;
#define ii pair<int,int>
#define X first
#define Y second

signed main(){
	
	int t;
	cin>>t;
	
	while(t--){
		int a,b;
		cin>>a>>b;
		
		if((b == a || b > a + 1) && ((b % 2 == a % 2) || (b % 2 == (a * 2) % 2)))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
}