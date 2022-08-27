#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e5 + 5;
#define X first
#define Y second

int n;
int h[MAX];
set<pair<int,int>> st;

signed main(){
	
	cin>>n;
	
	for(int i = 1;i <= n;i++)cin>>h[i],st.insert({h[i],i});
	
	while(!st.empty()){
		pair<int,int> u = *st.begin();
		st.erase(u);
		pair<int,int> v = *st.rbegin();
		st.erase(v);
		
		h[v.Y]--;
		h[u.Y]--;
		
		cout<<v.Y<<" "<<u.Y<<"\n";
		if(h[v.Y] != 0)st.insert({h[v.Y],v.Y});
		if(h[u.Y] != 0)st.insert({h[u.Y],u.Y});
		
	}
}