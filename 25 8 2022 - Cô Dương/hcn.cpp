#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e6;
const long long N = 305;

int n,m;
bool notprime[MAX];
int a[N][N];
int pref[N][N];
int ss[N][N][N];

signed main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
		}
	}
	
	notprime[0] = 1;
	notprime[1] = 1;
	
	for(int i = 2;i * i < MAX;i++){
		if(!notprime[i]){
			for(int j = i * i;j < MAX;j += i)notprime[j] = 1;
		}
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			a[i][j] = 1 - notprime[a[i][j]];
		}
	}
	
	for(int x = 1;x <= n;x++){
		
		for(int id = 1;id <= m;id++){
			pref[x][id] = pref[x][id - 1] + a[x][id];
		}
		
		for(int u = 1;u <= n;u++){
			for(int id = 1;id <= m;id++){
				ss[x][u][id] = ss[x][u][id - 1] + (a[x][id] == 1 && a[u][id] == 1);
			}
		}
		
	}
	
	int res = 0;
	for(int x = 1;x <= n;x++){
		
		for(int u = x + 1;u <= n;u++){
			for(int y = 1;y <= m;y++){
				
				if(a[x][y] != 1 || a[u][y] != 1)continue;
				
				res += pref[x][m] - pref[x][y] + pref[u][m] - pref[u][y] - (ss[x][u][m] - ss[x][u][y]);
				res += pref[x][y - 1] + pref[u][y - 1] - 2 * ss[x][u][y - 1];
			}
		}
		
	}
	
	cout<<res;
	
	
	
}