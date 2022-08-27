#include<bits/stdc++.h>

using namespace std;

const long long MAX = 3e3 + 5;
const long long MOD = 1e9 + 7;
const long long base = 26;

int n,m;
char a[MAX][MAX];
int h[MAX];

signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
		}
	}
	
	int res = -1;
	
	for(int i = 1;i <= n;i++){
		bool ok = 1;
		map<int,int> mp;
		for(int j = 1;j <= m;j++){
			//s[j] = s[j] + a[i][j];
			h[j] = (h[j] * base + a[i][j] - 'a' + 1) % MOD;
			//cout<<s[j]<<" ";
			if(mp.count(h[j])){
				ok = 0;
			}else mp[h[j]]++;
		}
		//cout<<"\n";
		
		if(ok)return cout<<n - i,0;
	}
	cout<<-1;
}
