#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 2000 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

string s[MAX];
int dist[MAX][MAX];
int n,m;
int step[MAX][MAX];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

ii str,ed;

signed main(){
	
	cin>>n >> m;
	
	deque<pair<int,int>> h;
	
	for(int i = 1;i <= n;i++){
		cin>>s[i];
		s[i] = " " + s[i];
	}	
	
	memset(dist,-1,sizeof dist);
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(s[i][j] == '+')h.push_back({i,j}),dist[i][j] = 0;
			if(s[i][j] == 'P')str = {i,j};
			if(s[i][j] == 'C')ed = {i,j};
		}
	}
	
	memset(step,-1,sizeof step);
	while(!h.empty()){
		
		int x = h.front().X;
		int y = h.front().Y;
		
		h.pop_front();
		
		for(int z = 0;z < 4;z++){
			int x_ = x + dx[z];
			int y_ = y + dy[z];
			
			if(x_ < 1 || x_ > n || y_ < 1 || y_ > m)continue;
			
			if(dist[x_][y_] == -1 || dist[x_][y_] > dist[x][y] + 1){
				
				h.push_back({x_,y_});
				dist[x_][y_] = dist[x][y] + 1;
				
			}
			
		}
		
	}
	
	priority_queue<ii,vii,greater<ii>> q;
	q.push(str);
	step[str.X][str.Y] = dist[str.X][str.Y];
	while(!q.empty()){
		int x = q.top().X;
		int y = q.top().Y;
		
		//cout<<x<<" "<<y<<" "<<step[x][y]<<"\n";
		//cout<<x<<" "<<y<<" "<<step[x][y]<<" "<<dist[x][y]<<'\n';
		
		q.pop();
		
		
		for(int i = 0;i < 4;i++){
			
			int x_ = dx[i] + x;
			int y_ = dy[i] + y;
			
			
			if(x_ <= 0 || x_ > n || y_ <= 0 || y_ > m || s[x_][y_] == '+')continue;
			//cout<<x_<<" "<<y_<<"\n";
			
			if(step[x_][y_] == -1 || step[x_][y_] < min(step[x][y],dist[x_][y_])){
				
				step[x_][y_] = min(step[x][y],dist[x_][y_]);
				q.push({x_,y_});
				
			}
			
		}
	}
	
	if(step[ed.X][ed.Y] != -1)return cout<<step[ed.X][ed.Y],0;
	
	
	memset(step,-1,sizeof step);
	
	q.push(str);
	step[str.X][str.Y] = dist[str.X][str.Y];
	while(!q.empty()){
		int x = q.top().X;
		int y = q.top().Y;
		
		//cout<<x<<" "<<y<<" "<<step[x][y]<<"\n";
		//cout<<x<<" "<<y<<" "<<step[x][y]<<" "<<dist[x][y]<<'\n';
		
		q.pop();
		
		
		for(int i = 0;i < 4;i++){
			
			int x_ = dx[i] + x;
			int y_ = dy[i] + y;
			
			
			if(x_ <= 0 || x_ > n || y_ <= 0 || y_ > m)continue;
			//cout<<x_<<" "<<y_<<"\n";
			
			if(step[x_][y_] == -1 || step[x_][y_] < min(step[x][y],dist[x_][y_])){
				
				step[x_][y_] = min(step[x][y],dist[x_][y_]);
				q.push({x_,y_});
				
			}
			
		}
	}
	
	cout<<step[ed.X][ed.Y];
	
}