#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e5 + 5;

struct node{
	int x,id;
};

node row[MAX],col[MAX];
int res[MAX];
int n,m;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int step[MAX];

bool cmp(node a,node b){
	return a.x < b.x;
}

int comp(char x){
	if(x == 'E')return 0;
	if(x == 'W')return 1;
	if(x == 'N')return 2;
	if(x == 'S')return 3;
}

int st[2][2][MAX <<2];
int f[2][2][MAX];
int pref[2][2][MAX];


int cnp(int id,bool c){
	
	if(c == 0){
		
		if(id < row[1].x)return 0;
		if(id > row[n].x)return n + 1;
		
		int l = 1,r = n;
		int ans = 0;
		while(l <= r){
			
			int mid = l + r >> 1;
			if(row[mid] >= id)ans = id,mid = r - 1;
			else mid = l + 1; 
		}
		
		
		return ans;
		
	}else{
		
		if(id < col[1].x)return 0;
		if(id > col[n].x)return n + 1;
		
		int l = 1,r = n;
		int ans = 0;
		while(l <= r){
			
			int mid = l + r >> 1;
			if(col[mid] >= id)ans = id,mid = r - 1;
			else mid = l + 1; 
		}
		
		
		return ans;
		
	}
	
}
void calc(int id,bool c){
	
	int vitri = cnp(id,c);
	
	update(1,1,n,1,vitri - 1,id,c,0);
	update(1,1,n,vitri,n,id,c,1);
	
	f[c][0][1]++;
	f[c][0][vitri]--;
	f[c][1][vitri]++;
	f[c][1][n + 1]--;
	
}

signed main(){
	
	cin>>n>>m;
	
	for(int i = 1,x,y;i <= n;i++){
		
		cin>>x>>y;
		row[i] = {x,i};
		col[i] = {y,i};
		
	}
	
	sort(row + 1,row + 1 + n,cmp);
	sort(col + 1,col + 1 + n,cmp);
	
	step[0] = {0,0};
	
	for(int i = 1;i <= m;i++){
		char x;
		cin>>x;
		
		step[i] = comp(x);
	}
	
	memset(st1,0,sizeof st1);
	memset(st2,0,sizeof st2);
	
	int x_ = 0,y_ = 0;
	
	for(int i = 0;i <= n;i++){
		x_ = dx[step[i]] + x_;
		y_ = dy[step[i]] + y_;
		
		calc(x_,0);
		calc(y_,1);
	}
	
	
	for(int i = 1;i <= n;i++){
		for(int z = 0;z < 2;z++){
			for(int z_ = 0;z_ < 2;z_ ++ ){
				pref[z][z_][i] = pref[z][z_][i - 1] + f[z][z_][i];
			}
		}
	}
	
	
	for(int i = 1;i <= n;i++){
		int id1 = row[i].id;
		int id2 = col[i].id;
		
		res[id1] += pref[0][0][i] * row[i].x - get(1,1,n,i,i,0,0);
		res[id2] += 
	}
}