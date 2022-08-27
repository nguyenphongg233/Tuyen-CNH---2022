#include<bits/stdc++.h>

#define int long long

const long long MAX = 1e5 + 5;
const long long INF = 1e9;

using namespace std;

int a,b,m;
int vala[MAX],valb[MAX];

struct st{
	int u,v,c;
};

st sale[MAX];
int res = INF;
int mina = INF;
int minb = INF;
int ida = 0,idb = 0;
signed main(){
	
	cin>>a>>b>>m;
	
	for(int i = 1;i <= a;i++){
		
	    cin>>vala[i];
	    if(vala[i] < mina){
	    	mina = vala[i];
	        ida = i;
	    }
	
	}
	for(int i = 1;i <= b;i++){
		
	    cin>>valb[i];
	    
	    if(valb[i] < minb){
	    	minb = valb[i];
	        idb = i;
	    }
	
	}
	
	res = min(res,mina + minb);
	
	for(int i = 1,u,v,c;i <= m;i++){
		cin>>u>>v>>c;
		
		sale[i] = {u,v,c};
		res = min(res,vala[u] + valb[v] - c);
		
		if(ida != u)res = min({res,vala[ida] + valb[v] + vala[u] - c,vala[ida] + valb[v]});
		if(idb != v)res = min({res,valb[idb] + valb[v] + vala[u] - c,vala[u] + valb[idb]});
		
		res = min({res,vala[ida] + valb[v],vala[u] + valb[idb]});
	}
	
	cout<<res;
	
	
	
	
}