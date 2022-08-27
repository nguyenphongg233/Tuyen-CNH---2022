#include<bits/stdc++.h>

using namespace std;
#define int long long
const long long MAX = 1e5 + 5;
#define ii pair<int,int>
#define X first
#define Y second

int n;
ii a[MAX];
bool cmp(ii a,ii b){
	return (a.X - a.Y) > (b.X - b.Y);
}
signed main(){
	
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>a[i].X>>a[i].Y;
	
	int res = 0;
	sort(a + 1,a + 1 + n,cmp);
	
	for(int i = 1;i <= n;i++){
		//cout<<a[i].X<<" "<<a[i].Y<<" "<<-a[i].X * (i - 1) + a[i].Y * (n - i)<<"\n";
		res += a[i].X * (i - 1) + a[i].Y * (n - i);
	}
	
	cout<<res;
	
	
	
	
}