#include<bits/stdc++.h>

#define int long long

const long long MAX = 1e5 + 5;
const long long INF = 1e18;

using namespace std;

int n,d;

struct point {
	int id,l,r;
};

point a[MAX];
int minl = 0;

int get(int dope){
	
	int sum = 0;
	
	for(int i = 1;i <= n;i++){
		//if(a[i].l > dope)return -1;
		
		sum += max(a[i].l,min(a[i].r,dope));
	}
	
	return sum;
	
}

int res[MAX];

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>n>>d;
	
	int minx = 0,maxx = 0;
	int r = 0;
	for(int i = 1;i <= n;i++){
		
		cin>>a[i].l>>a[i].r;
		//minl = max(minl,a[i].l);
		
		minx += a[i].l;
		maxx += a[i].r;
		
		r = max(r,a[i].r);
		
	}
	//cout<<minx<<" "<<maxx<<"\n";
	
	if(minx > d || maxx < d)return cout<<-1,0;
	
	//cout<<"WHO asked";
	
	int l = 0;
	int ans = 0;
	
	//cout<<"fuck";
	
	while(l <= r){
		
		int m = l + r >> 1;
		
		//cout<<l<<" "<<r<<"\n";
		
		//if(get(m) <= d)l = m + 1,ans = m;
		//else r = m - 1;
		
		
		
	}
	
	
	
	//int sum = 0;
	
	for(int i = 1;i <= n;i++){
		
		res[i] = max(a[i].l,min(a[i].r,ans));
		d -= res[i];
	}
	
	bool ok = 0;
	while(1){
		for(int i = 1;i <= n;i++){
			if(res[i] >= a[i].r)continue;
			if(d <= 0){
		       ok = 1;
		       break;
		    }
			
			res[i]++;
			d--;
			
			
			if(d <= 0){
		       ok = 1;
		       break;
		    }
		}
		if(ok)break;
	}
	
	
	for(int i = 1;i <= n;i++)cout<<res[i]<<" ";
	
	
}