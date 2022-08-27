#include<bits/stdc++.h>

const long long MAX = 500 + 5;

using namespace std;

int rmq[MAX][MAX][10];
int n,m,k;

int a[MAX][MAX];

int get(int i,int l,int r){
	
	int k = log2(r - l + 1);
	return max(rmq[i][l][k],rmq[i][r - (1 << k) + 1][k]);
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>n>>m>>k;
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
			rmq[i][j][0] = a[i][j];
		}
	}
	
	for(int i = 1;i <= n;i++){
		for(int z = 1;z <= 9;z++){
			if((1 << z) > m)break;
		    for(int j = 1;j <= m;j++){
				
				if((1 << z) > m)break;
				rmq[i][j][z] = max(rmq[i][j][z - 1],rmq[i][j + (1 << (z - 1))][z - 1]);
				
				
			}
		}
	}
	
	
	for(int i = 1;i <= n;i++){
		
		for(int j = 1;j <= m;j++){
			
			int maxx = a[i][j];
			
			for(int z = 0;z <= k;z++){
				
				int nextmove = k - z;
				
				if(i - z >= 1){
					
					int id = i - z;
					maxx = max(maxx,get(id,max(1,j - nextmove),min(m,j + nextmove)));
					
					
					
				}
				
				if(i + z <= n){
					
					int id = i + z;
					
					maxx = max(maxx,get(id,max(1,j - nextmove),min(m,j + nextmove)));
					
					
				}
			}
			
			
			cout<<maxx<<" ";
		}
		cout<<"\n";
		
	}
	
	
}