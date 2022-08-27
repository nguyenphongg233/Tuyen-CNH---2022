#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n,q;
string s;

struct node{
	int a,b,c;
};

node st[MAX << 2];

node compar(node a,node b){
	return {a.a + b.a,a.b + b.b,a.c + b.c};
}

node del(node a,int id,char x){
	
	if(s[id] == 'A')a.a--;
	if(s[id] == 'B')a.b--;
	if(s[id] == 'C')a.c--;
	
	if(x == 'A')a.a++;
	if(x == 'B')a.b++;
	if(x == 'C')a.c++;
	
	return a;
	
}
void buildtree(int id,int l,int r){
	if(l == r){
		
		if(s[l] == 'A')st[id].a++;
		if(s[l] == 'B')st[id].b++;
		if(s[l] == 'C')st[id].c++;
		
		return;
		
	}
	
	int m = l + r >> 1;
	
	buildtree(id << 1,l,m);
	buildtree(id << 1 | 1,m + 1,r);
	
	st[id] = compar(st[id << 1],st[id << 1 | 1]);
	
}

void update(int id,int l,int r,int u,char x){
	
	
	if(l > u || r < u)return;
	
	if(l == r){
		if(l == u){
			
			st[id] = del(st[id],l,x);
			
			
		}
		return;
	}
	
	int m = l + r >> 1;
	
	update(id << 1,l,m,u,x);
	update(id << 1 | 1,m + 1,r,u,x);
	
	st[id] = compar(st[id << 1],st[id << 1 | 1]);	
	
}

node get(int id,int l,int r,int u,int v){
	
	if(u > r || v < l)return {0,0,0};
	
	if(u <= l && r <= v)return st[id];
	
	int m = l + r >> 1;
	
	node a = get(id << 1,l,m,u,v);
	node b = get(id << 1 | 1,m + 1,r,u,v);
	
	node rt = compar(a,b);
	return rt;
	
	
}


void query(int l,int r){
	
	int ans = 0;
	
	//cout<<l<<" "<<r<<" :\n";
	for(int i = l;i <= r;i++){
		
		// tim vi tri xa nhat chua xuat hien b
		if(s[i] != 'A'){
			
			
			int lf = i;
			int rf = r;
			int rt = lf;
			
			while(lf <= rf){
				
				int mf = lf + rf >> 1;
				node x = get(1,1,n,i,mf); 
				
				if(x.a > 0)rf = mf - 1;
				else lf = mf + 1,rt = mf;
			}
			
			i = rt;
			continue;
		}
		
		int lf = i;
		int rf = r;
		
		int id = lf;
		while(lf <= rf){
			int mf = lf + rf >> 1;
			
			node op = get(1,1,n,i,mf);
			
			if(op.b > 0)rf = mf - 1;
			else lf = mf + 1,id = mf;
		}
		node x = get(1,1,n,i,id);
		//cout<<i<<" "<<id<<" "<<x.a<<"\n";
		lf = id + 1;
		rf = r;
		// tim vi tri xa nhat chua xuat hien c 
		
	
		int id2 = lf;
		
		while(lf <= rf){
			int mf = lf + rf >> 1;
			
			node op = get(1,1,n,id + 1,mf);
			
			if(op.c > 0)rf = mf - 1;
			else lf = mf + 1,id2 = mf;
		}
		
		
		
		//node x = get(1,1,n,i,id);
		node y = get(1,1,n,id + 1,id2);
		node z = get(1,1,n,id2 + 1,r);
		//cout<<i<<" "<<id<<" "<<x.a<<"\n";
		//cout<<id + 1<<" "<<id2<<" "<<y.b<<"\n";
		//cout<<id2 + 1<<" "<<r<<" "<<z.c<<"\n";
		//cout<<"*****************\n";
		ans = x.a * y.b * z.c;
		
		
		
		
		i = id + 1;
	}
	
	cout<<ans<<"\n";
}

signed main(){
	
	cin>>n>>q;
	cin>>s;
	
	s = " " + s;
	
	buildtree(1,1,n);
	

	for(int i = 1,c;i <= q;i++){
		cin>>c;
		
		if(c == 1){
			int id;
			char x;
			
			cin>>id>>x;
			s[id] = x;
			update(1,1,n,id,x);
		}else{
			int l,r;
			cin>>l>>r;
			
			query(l,r);
		}
	}
	
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}