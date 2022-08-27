#include<bits/stdc++.h>

const long long MAX = 500 + 5;

#define X first
#define Y second 

using namespace std;

int n,m,k;
int a[MAX][MAX];

struct node{
	int c;
	int u,v;
};




struct compar{
	
	bool operator()(node const& a,node const& b){
		return a.c < b.c;
	}
	
};
int step[MAX][MAX];

priority_queue<node,vector<node>,compar> h;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void bfs(int u,int v,int val){
	
	deque<node> q;
	map<pair<int,int>,bool> dd;
	
	q.push_back({0,u,v});
	dd[{u,v}] = 1;
	if(step[u][v] < val)step[u][v] = val;
	while(!q.empty()){
		
		int x = q.front().u;
		int y = q.front().v;
		int c = q.front().c;
		
		
		
		q.pop_front();
		
		if(c >= k)continue;
		
		for(int i = 0;i < 4;i++){
			int x_ = x + dx[i];
			int y_ = y + dy[i];
			
			if(x_ < 1 || x_ > n || y_ < 1 || y_ > m || dd[{x_,y_}])continue;
			
			if(step[x_][y_] < val){
				
				step[x_][y_] = val;
				
				
			}
			
			dd[{x_,y_}] = 1;
			q.push_back({c + 1,x_,y_});
		}
	}
	
}

bool cmp(node a,node b){
	return a.c > b.c;
}
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	
	vector<node> h;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
			if(a[i][j] != 0)h.push_back({a[i][j],i,j});
		}
	}
	sort(h.begin(),h.end(),cmp);
	
	for(auto v : h)bfs(v.u,v.v,v.c);

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<step[i][j]<<" ";
		}
		cout<<"\n";
	}
}