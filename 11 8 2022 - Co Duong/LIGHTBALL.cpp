#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e5 + 5;
const long long INF = 1e18;
#define int long long

int a[MAX],b[MAX],c[MAX];
int n,m,q;

signed main(){
	
	cin>>n>>m>>q;
	
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= m;i++)cin>>b[i];
	for(int i = 1;i <= q;i++)cin>>c[i];
	
	int res = INF;
	
	sort(a + 1,a + 1 + n);
	sort(b + 1,b + 1 + m);
	sort(c + 1,c + 1 + q);
	
	for(int i = 1;i <= n;i++){
		
		int x = a[i];
		
		int y = lower_bound(b + 1,b + 1 + m,a[i]) - b;
		y = b[y];
		
		int z = lower_bound(c + 1,c + 1 + q,a[i]) - c;
		z = c[z];
		
		res = min(res,2 * (x * (x - y) + y * (y - z) + z * (z - x)));
		
		//cout<<x<<" "<<y<<" "<<z<<"\n";
	}
	
	for(int i = 1;i <= m;i++){
		
		int x = b[i];
		
		int y = lower_bound(a + 1,a + 1 + n,b[i]) - a;
		y = a[y];
		
		int z = lower_bound(c + 1,c + 1 + q,b[i]) - c;
		z = c[z];
		
		res = min(res,2 * (x * (x - y) + y * (y - z) + z * (z - x)));
		//cout<<x<<" "<<y<<" "<<z<<"\n";
	}
	
	for(int i = 1;i <= q;i++){
		
		int x = c[i];
		
		int y = lower_bound(b + 1,b + 1 + m,c[i]) - b;
		y = b[y];
		
		int z = lower_bound(a + 1,a + 1 + n,c[i]) - a;
		z = a[z];
		
		res = min(res,2 * (x * (x - y) + y * (y - z) + z * (z - x)));
		//cout<<x<<" "<<y<<" "<<z<<"\n";
	}
	
	cout<<res;
}