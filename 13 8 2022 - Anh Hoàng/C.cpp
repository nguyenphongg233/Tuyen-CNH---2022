#include<bits/stdc++.h>

using namespace std;
const long long MAX = 3e6 + 5;
#define X first
#define Y second

int n,m;
int f[MAX];
int a[MAX],b[MAX];
pair<int,int> dope[MAX];
unordered_map<int,int> mp;
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	cin>>m;
	for(int i = 1;i <= m;i++)cin>>b[i];
	
	f[0] = 0;
	int id1 = 1,id2 = 1;
	int id = 1;
	while(id1 <= n && id2 <= m){
		if(id1 == n && id2 == m)break;
		if(id1 == n && id2 <= m)f[id] = f[id - 1] - b[id2],id2++;
		else if(id2 == m && id1 <= n)f[id] = f[id - 1] + a[id1],id1++; 
		else if(f[id - 1] <= 0)f[id] = f[id - 1] + a[id1],id1++;
		else f[id] = f[id - 1] - b[id2],id2++;
		dope[id] = {id1 - 1,id2 - 1};
		id++;
	}
	
	for(int i = 1;i <= id;i++){
		if(mp.count(f[i])){
			
			cout<<dope[i].X - dope[mp[f[i]]].X<<"\n";
			int l = dope[mp[f[i]]].X + 1;
			
			for(int j = l;j <= dope[i].X;j++)cout<<j - 1<<" ";
			cout<<"\n";
			
			cout<<dope[i].Y - dope[mp[f[i]]].Y<<"\n";
			l = dope[mp[f[i]]].Y + 1;
			for(int j = l;j <= dope[i].Y;j++)cout<<j - 1<<" ";
			
			
			
			return 0;
		}
		
		
		mp[f[i]] = i;
	}
	
	
}