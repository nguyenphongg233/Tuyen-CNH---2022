#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e5 + 5;

struct node{
	int x,id;
};

node row[MAX],col[MAX];
//int res[MAX];
int n,m;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
//int step[MAX];

bool cmp(node a,node b){
	return a.x < b.x;
}

int comp(char x){
	if(x == 'E')return 0;
	if(x == 'W')return 1;
	if(x == 'N')return 2;
	if(x == 'S')return 3;
}


int cnp(int id,bool c){
	
	if(c == 0){
		
		if(id < row[1].x)return 0;
		if(id > row[n].x)return n + 1;
		
		int l = 1,r = n;
		int ans = 0;
		while(l <= r){
			
			int mid = l + r >> 1;
			if(row[mid].x >= id)ans = id,r = mid - 1;
			else l = mid + 1; 
		}
		
		
		return ans;
		
	}else{
		
		if(id < col[1].x)return 0;
		if(id > col[n].x)return n + 1;
		
		int l = 1,r = n;
		int ans = 0;
		while(l <= r){
			
			int mid = l + r >> 1;
			if(col[mid].x >= id)ans = id,r = mid - 1;
			else l = mid + 1; 
		}
		
		
		return ans;
		
	}
	
}

int pref[MAX][2];

signed main(){
	
	cin>>n>>m;
	
	for(int i = 1,x,y;i <= n;i++){
		
		cin>>x>>y;
		row[i] = {x,i};
		col[i] = {y,i};
		
	}
	
	sort(row + 1,row + 1 + n,cmp);
	sort(col + 1,col + 1 + n,cmp);
	
	for(int i = 1;i <= n;i++){
		pref[0][i] = pref[0][i - 1] + row[i].x;
		pref[1][i] = pref[1][i - 1] + col[i].x;
	}
	//step[0] = {0,0};
	int x_ = 0,y_ = 0;
	
	for(int i = 1;i <= m;i++){
		char x;
		cin>>x;
		
		int id = comp(x);
		
		x_ = dx[id] + x_;
		y_ = dy[id] + y_;
		
		int vitri1 = cnp(x_,0);
		
		int res = x_ * (vitri1 - 1) - pref[0][vitri1 - 1] + pref[0][n] - pref[0][vitri1 - 1] - x_ * (n - vitri1 + 1);
		
		cout<<vitri1<<" "<<row[vitri1].x<<" ";
		cout<<res<<" ";
		int vitri2 = cnp(y_,1);
		res += y_ * (vitri2 - 1) - pref[1][vitri2 - 1] + pref[1][n] - pref[1][vitri2 - 1] - y_ * (n - vitri2 + 1);
		
		
		cout<<res<<"\n";
		
	}
	
	

	
}