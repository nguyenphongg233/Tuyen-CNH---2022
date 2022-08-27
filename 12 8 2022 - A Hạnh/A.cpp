#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e5 + 5;
int n;
int cnt[MAX];
int res = 0;

signed main(){
	
	if(ifstream("cc.inp")){
		freopen("cc.inp","r",stdin);
		freopen("cc.out","w",stdout);
	}
	cin>>n;
	for(int i = 1,x,y;i < n;i++){
		cin>>x>>y;
		cnt[x]++;
		cnt[y]++;
		res = max({res,cnt[x],cnt[y]});
	}
	
	cout<<res;
	
}