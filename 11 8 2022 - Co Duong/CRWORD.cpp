#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e3 + 5;
const long long INF = 1e9;
#define X first
#define Y second

int n,m;
char a[MAX][MAX];
bool dd[MAX][MAX][2];
pair<int,int> par[MAX][MAX];

pair<int,int> find(int i,int j){
	
	if(par[i][j] == make_pair(i,j))return {i,j};
	return par[i][j] = find(par[i][j].X,par[i][j].Y);
	
}

vector<pair<int,int>> adj[MAX * MAX];
int b[MAX][MAX];

signed main(){
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			par[i][j] = {i,j};
			cin>>a[i][j];
		}
	}
	
	for(int i = 1;i <= n;i++){
		
		for(int j = 1;j <= m;j++){
			
			if(dd[i][j][0])continue;
			if(a[i][j] == '.')continue;
			
			int l = j,r = j;
			
			while(a[i][r] != '.' && r <= m)r++;
			r--;
			
			r = min(r,m);
			
			//cout<<i<<" "<<l<<" "<<r<<" : \n";
			
			int siz = r - l + 1;
			
			if(siz % 2 == 0){
				
				int cs1 = (r + l) / 2;
				int cs2 = cs1 + 1;
				
				
				while(cs1 >= l){
					
					pair<int,int> u = find(i,cs1),v = find(i,cs2);
					par[u.X][u.Y] = v;
					
					//cout<<cs1<<" "<<cs2<<"\n";
					cs1--,cs2++;
					
				}
				
				
			}else{
				
				int cs1 = ((l + r) / 2) - 1;
				int cs2 = ((l + r) / 2) + 1;
				
				while(cs1 >= l){
					
					pair<int,int> u = find(i,cs1),v = find(i,cs2);
					par[u.X][u.Y] = v;
					
					//cout<<cs1<<" "<<cs2<<"\n";
					cs1--,cs2++;
					
				}
			}
			
			//cout<<"###\n";
			for(int z = l;z <= r;z++)dd[i][z][0] = 1;
			
			j = r;
		}
		
	}
	
	
	
	for(int j = 1;j <= m;j++){
		for(int i = 1;i <= n;i++){
			
			if(dd[i][j][1])continue;
			if(a[i][j] == '.')continue;

			
			
			int l = i,r = i;
			
			while(a[r][j] != '.' && r <= n)r++;
			r--;
			
			r = min(r,n);
			
			
			int siz = r - l + 1;
			
			if(siz % 2 == 0){
				
				int cs1 = (r + l) / 2;
				int cs2 = cs1 + 1;
				
				
				while(cs1 >= l){
					
					pair<int,int> u = find(cs1,j),v = find(cs2,j);
					par[u.X][u.Y] = v;
					
					cs1--,cs2++;
					
				}
				
				
			}else{
				
				int cs1 = ((l + r) / 2) - 1;
				int cs2 = ((l + r) / 2) + 1;
				
				while(cs1 >= l){
					
					pair<int,int> u = find(cs1,j),v = find(cs2,j);
					par[u.X][u.Y] = v;
					
					cs1--,cs2++;
					
				}
			}
			
			//cout<<l<<" "<<r<<" "<<j<<"\n";
			
			for(int z = l;z <= r;z++)dd[z][j][1] = 1;
			
			i = r;
			
		}
	}
	
	int cnt = 0;
	
	for(int i = 1;i <= n;i++){
		
		for(int j = 1;j <= m;j++){
			
			if(a[i][j] == '.')continue;
			
			//cout<<i<<" "<<j<<"\n";
			pair<int,int> u = find(i,j);
			
			int x = u.X;
			int y = u.Y;
			
			//cout<<i<<" "<<j<<" "; 
			//cout<<x<<" "<<y<<"#\n";
			
			if(!b[x][y]){
				
				b[x][y] = ++cnt;
				
				
			}
			
			
			adj[b[x][y]].push_back({i,j});
			
			
		}
		
	}
	
	for(int i = 1;i <= cnt;i++){
		
		int rt = INF;
		int ch = -1;
		for(int j = 0;j <= 9;j++){
			
			int sum = 0;
			for(auto e : adj[i]){
				
				int x = e.X;
				int y = e.Y;
				
				sum += abs((a[x][y] - '0') - j);
				
				
				
			}
			
			if(sum < rt){
				rt = sum;
				ch = j;
			}
		}
		
	   // cout<<i<<" :\n";
		
		for(auto e : adj[i]){
			
			//cout<<e.X<<" "<<e.Y<<"\n";
			a[e.X][e.Y] = char(ch + '0');
			
		}
		
		//cout<<"\n";
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<a[i][j];
		}
		
		cout<<"\n";
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}