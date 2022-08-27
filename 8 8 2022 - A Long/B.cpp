#include<bits/stdc++.h>

const long long MAX = 1e5 + 5;

using namespace std;

int snt[MAX];
vector<int> ry;

// huh ? 

signed main(){
	
	snt[1] = 1;
	
	for(int i = 2;i * i < MAX;i++){
		if(!snt[i]){
			for(int j = i * i;j < MAX;j += i)snt[j] = 1;
		}
	}
	
	for(int i = 2;i * i < MAX;i++)if(!snt[i])ry.push_back(i);
	
	int t;
	cin>>t;
	
	while(t--){
		
		
		
		int n;
		cin>>n;
		int ans = 0;
		
		vector<int> a(n);
		
		int up = 0;
		int res = 0;
		
		for(auto &x : a)cin>>x,up = max(up,x);
		
		for(auto v : ry){
			
			map<int,int> dd;
			
			for(auto vr : a)dd[vr % v]++,ans = max(ans,dd[vr % v]);
			
		}
		
		cout<<ans<<"\n";
		
	}
	

	
}