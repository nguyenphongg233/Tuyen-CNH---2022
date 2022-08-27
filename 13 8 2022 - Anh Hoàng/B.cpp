#include<bits/stdc++.h>

using namespace std;
const long long MAX = 5e5 + 5;
const long long INF = 1e9;

#define int long long
#define X first
#define Y second

int n,m;
vector<vector<int>> a;
vector<vector<int>> pref[6];

int get(int z,int x,int y,int u,int v){
	
	return pref[z][u][v] + pref[z][x - 1][y - 1] - pref[z][x - 1][v] - pref[z][u][y - 1];
	
}

bool ok(int x,int y,int u,int v){
	
	for(int z = 1;z <= 5;z++){
		if(get(z,x,y,u,v) < 1)return false;
	}
	
	return true;
	
}
signed main(){
	
	cin>>n>>m;
	
	a.resize(n + 1,vector<int>(m + 1,0));
	for(int i = 1;i <= 5;i++)pref[i].resize(n + 1,vector<int>(m + 1,0));
	
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			
			char x;
			cin>>x;
			
			if(x == 'W')a[i][j] = 1;
			else if(x == 'A')a[i][j] = 2;
			else if(x == 'L')a[i][j] = 3;
			else if(x == 'D')a[i][j] = 4;
			else if(x == 'O')a[i][j] = 5;
			else a[i][j] = 0;
			//cout<<a[i][j]<<" ";
		}
		//cout<<"\n";
	}
	
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			
			for(int z = 1;z <= 5;z++){
				
				pref[z][i][j] = pref[z][i][j - 1] + pref[z][i - 1][j] - pref[z][i - 1][j - 1];
				//cout<<pref[z][i][j]<<" ";
				if(a[i][j] == z)pref[z][i][j]++;
			}
			//cout<<a[i][j]<<"\n";
			//pref[a[i][j]][i][j]++;
			//cout<<",";
		}
		//cout<<"\n";
	}
	
	int ans = INF;
	for(int x = 1;x <= n;x++){
		for(int u = x;u <= n;u++){
			int v = 1;
			for(int y = 1;y <= m;y++){
				
				if(v == m && !ok(x,y,u,v))break;
				while(v < m && !ok(x,y,u,v))v++;
				if(ok(x,y,u,v))ans = min(ans,(u - x + 1) * (v - y + 1));
			}
			
		}
	}

	if(ans == INF)cout<<"impossible";
	else cout<<ans;
}