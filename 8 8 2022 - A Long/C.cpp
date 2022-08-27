#include<bits/stdc++.h>

const long long MAX = 3e2 + 5;

using namespace std;

int n,m;

int pref[MAX][MAX][8];

int a[MAX][MAX];

bool get(int x,int y,int u,int v){
	
	for(int i = 1;i <= 7;i++){
		
		if(pref[u][v][i] - pref[x - 1][v][i] - pref[u][y - 1][i] + pref[x - 1][y - 1][i] < 1)return false;
		
	}
	
	return true;
}

signed main(){
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			char x;
			cin>>x;
			
			a[i][j] = x - '0';
			
			for(int z = 1;z <= 7;z++){
				pref[i][j][z] = pref[i - 1][j][z] + pref[i][j - 1][z] - pref[i - 1][j - 1][z];
			}
			
			pref[i][j][a[i][j]]++;
		}
	}
	
	int cnt = 0;
	
	for(int x = 1;x <= n;x++){
		for(int u = x;u <= n;u++){
			
			int pointer = 1;
			for(int y = 1;y <= m;y++){
				
				if(pointer == m && !get(x,y,u,pointer))break;
				
				while(pointer < m && !get(x,y,u,pointer))pointer++;
				
				if(get(x,y,u,pointer))cnt += m - pointer + 1;
			}
			
			
		}
	}
	
    cout<<cnt;
	
}