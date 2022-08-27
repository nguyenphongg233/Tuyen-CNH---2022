#include<bits/stdc++.h>

using namespace std;
#define int long long 
const long long MAX = 1e5;
const long long N = 305;
const long long INF = 1e18;

int st[MAX << 4];
int n,b,q;
int lazy[MAX << 4];
void lazyupdate(int id,int l,int r){
	
	
	if(lazy[id] != 0){
		
		st[id] += (r - l + 1) * lazy[id];
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
		lazy[id] = 0; 
		
	}
	
	
}
void update(int id,int l,int r,int u,int v,int val){
	// update ca doan u -> v len val 
	
	lazyupdate(id,l,r);
	if(u > r || v < l)return;
	
	if(u <= l && r <= v){
		st[id] += (r - l + 1) * val;
		lazy[id << 1] += val;
		lazy[id << 1 | 1] += val;
		return;
	}
	
	int m = l + r >> 1;
	update(id << 1,l,m,u,v,val);
	update(id << 1 | 1,m + 1,r,u,v,val);
	
	st[id] = st[id << 1] + st[id << 1 | 1];
	
	
}

int get(int id,int l,int r,int u,int v){
	if(u == 0 && v == 0)return INF;
	lazyupdate(id,l,r);
	
	//if(u == 0 && v == 0)return INF;
	if(u > r || v < l)return 0;
	if(u <= l && v >= r)return st[id];
	int m = l + r >> 1;
	return get(id << 1,l,m,u,v) + get(id << 1 | 1,m + 1,r,u,v);
	
}

void solve(int ri,int p){
	
	//cout<<ri<<" "<<p<<"\n*";
	if(p == 0)return;
	int l = 1,r = ri;
	int ans = r;
	
	int tmp = get(1,1,n,ri,ri);
	while(l <= r){
		int mid = l + r >> 1;
		if(get(1,1,n,mid,mid) > tmp)l = mid + 1;
		else ans = mid,r = mid - 1;
	} 
	

	int siz = ri - ans + 1;
	//cout<<ans<<" \n";
	int last = get(1,1,n,ans - 1,ans - 1);
	//cout<<siz<<" "<<ans<<" "<<p / siz<<"\n";
	//cout<<tmp + p / siz + (p % siz != 0)<<"\n";
	if(last >= tmp + p / siz + (p % siz != 0)){
		
		if(p > siz)
			update(1,1,n,ans,ri,p / siz);
		
		if(p > siz)
			p -= siz * (p / siz);
			
		//cout<<p<<"\n";
		if(p != 0)
			update(1,1,n,ans,ans + (p) - 1,1);
		//cout<<"hi";
		//cout<<"AC\n";
	}else{
		//cout<<"WA\n";
		update(1,1,n,ans,ri,(last - tmp));
		solve(ri,p - (last - tmp) * siz);
		
	}
	
	//for(int i = 1;i <= n;i++)cout<<get(1,1,n,i,i)<<" ";
	//cout<<"\n";
	return;
	
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q>>b;
	
	while(q--){
		
		int r,p;
		cin>>r>>p;
		
		solve(r,p);
		
	}
	
	for(int i = 1;i <= n;i++)cout<<get(1,1,n,i,i) + b<<" ";
	
}