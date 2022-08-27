#include<bits/stdc++.h>

using namespace std;
#define int long long 
const long long MAX = 5e5 + 5;
const long long INF = 1e18;
int n,m,a[4][MAX];

struct node{
	int s1,s2,sa;
	
	node(){
		s1 = 0;
		s2 = 0;
		sa = 0;
	}
	
	node operator+ (const node &a){
		
		node b = node();
		b.s1 = max(a.s1,s1);
		b.s2 = max(a.s2,s2);
		b.sa = max({sa,a.sa,s1 + a.s2});
		
		return b;
		
	}
	
};


struct query{
	
	int l,r,s;
	
	void getval(){
		cin>>l>>r>>s;
	}
	
	bool operator< (const query &a){
		return r < a.r;
	}
	
};


query q[MAX];
int s[4][MAX];
node st[MAX << 4];

node sachvalidivila = node();
//sachvalidivila = {-INF,-INF,-INF};

void buildtree(int id,int l,int r){
	if(l == r){
		st[id].s1 = s[1][l] - s[2][l - 1];
		st[id].s2 = s[2][l] - s[3][l - 1] + s[3][n];
		st[id].sa = st[id].s1 + st[id].s2;
		return;
	}
	
	int mid = l + r >> 1;
	buildtree(id << 1,l,mid);
	buildtree(id << 1 | 1,mid + 1,r);
	
	st[id] = st[id << 1] + st[id << 1 | 1];
}

node get(int id,int l,int r,int u,int v){
	
	if(u > r || v < l)return sachvalidivila;
	if(u <= l && r <= v)return st[id];
	
	int mid = l + r >> 1;
	return get(id << 1,l,mid,u,v) + get(id << 1 | 1,mid + 1,r,u,v);
	
}

void update(int id,int l,int r,int u,int val){
	if(u < l || u > r)return;
	if(l == r){
		st[id].s1 = max(st[id].s1,val);
		st[id].sa = st[id].s1 + st[id].s2;
		return;
	}
	int mid = l + r >> 1;
	
	update(id << 1,l,mid,u,val);
	update(id << 1 | 1,mid + 1,r,u,val);
	
	st[id] = st[id << 1] + st[id << 1 | 1];
}
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	sachvalidivila.s1 = -INF;
	sachvalidivila.s2 = -INF;
	sachvalidivila.sa = -INF;
	
	cin>>n>>m;
	
	for(int i = 1;i <= 3;i++){
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
			s[i][j] = s[i][j - 1] + a[i][j];
		}
	}
	
	buildtree(1,1,n);
	for(int i = 1;i <= m;i++)q[i].getval();
	
	sort(q + 1,q + 1 + m);
	int res = -INF;
	
	for (int i = 1; i <= m; i++) {
        node tmp = get(1, 1, n, q[i].l, q[i].r);
 
        res = max(res, tmp.sa - q[i].s);
 
        update(1, 1, n, q[i].r + 1, tmp.s1 - q[i].s);
    }
 
    cout << res;
	
}