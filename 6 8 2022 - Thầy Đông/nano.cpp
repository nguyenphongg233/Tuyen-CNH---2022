#include<bits/stdc++.h>

const long long MAX = 100 + 5;

using namespace std;

int n;
// sub1
int a[MAX][MAX];
bool step[MAX][MAX][5];

// 0 : chinh giua 
// 1 : tren trai
// 2 : tren phai
// 3 : duoi phai
// 4 : duoi trai 

struct point{
	int x,y;
};

deque<point> h;
bool dd[MAX][MAX];

int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};

int cnt = 0;
int half = 0;
	
signed main(){
	
	cin>>n;
	
	for(int i = 1,x,y;i <= n;i++){
		cin>>x>>y;
		a[x][y] = 1;
	}
	
	for(int i = 1;i <= 100;i++){
		if(a[1][i] == 0){
		    h.push_back({1,i});
		    //cnt++;
		    dd[1][i] = 1;
		}else{
			
			step[1][i][1] = 1;
			step[1][i][2] = 1;
			
			half += 2;
			
			
		}
		if(a[100][i] == 0){
		    h.push_back({100,i});
		    //cnt++;
		    dd[100][i] = 1;
		}else{
			
			step[100][i][3] = 1;
			step[100][i][4] = 1;
			
			half += 2;
 			
		}
		if(a[i][100] == 0){
		   h.push_back({i,100});
		   //cnt++;
		   dd[i][100] = 1;
		}else{
			
			step[i][100][2] = 1;
			step[i][100][3] = 1;
			half += 2;
		}
		if(a[i][1] == 0){
		    h.push_back({i,1});
		   // cnt++;
		    dd[i][1] = 1;
		}else{
			
			step[i][1][1] = 1;
			step[i][1][4] = 1;
			
			half += 2;
			
		}
	}
	
	//cout<<half<<"\n";
	
	while(!h.empty()){
		
		int x = h.front().x;
		int y = h.front().y;
		
		h.pop_front();
		
		//cout<<x<<" "<<y<<"\n";
		//if(dd[x][y])continue;
		
		//dd[x][y] = 1;
		//cnt++;
		for(int i = 0;i < 4;i++){
			int x_ = x + dx[i];
			int y_ = y + dy[i];
			
			if(x_ < 1 || x_ > 100 || y_ < 1 || y_ > 100 || dd[x_][y_])continue;
			
			dd[x_][y_] = 1;
			if(a[x_][y_] == 0){
				
				//cout<<"ok";
				//cnt++;
				h.push_back({x_,y_});
				continue;
			}
			
			if(i == 0){
				
				if(!step[x_][y_][4])step[x_][y_][4] = 1,half++;
				if(!step[x_][y_][3])step[x_][y_][3] = 1,half++;
				
			}else if(i == 1){
				
				if(!step[x_][y_][1])step[x_][y_][1] = 1,half++;
				if(!step[x_][y_][2])step[x_][y_][2] = 1,half++;
				
				
			}else if(i == 2){
				if(!step[x_][y_][3])step[x_][y_][3] = 1,half++;
				if(!step[x_][y_][2])step[x_][y_][2] = 1,half++;
			}else{
				if(!step[x_][y_][1])step[x_][y_][1] = 1,half++;
				if(!step[x_][y_][4])step[x_][y_][4] = 1,half++;
			}
			
		}
		
		
	}
	
	for(int i = 1;i <= 100;i++){
		for(int j = 1;j <= 100;j++){
			cnt += (dd[i][j] && a[i][j] == 0);
			//cout<<(dd[i][j] && a[i][j] == 0)<<" ";
		}
		//cout<<"\n";
	}
	//cout<<cnt<<"\n";
	//cout<<half<<"\n";
	
	float res = 100 * 100 - (cnt + (n * (1 - 0.21460)) + 0.21460 / 4 * half);
	
	cout<<setprecision(5)<<fixed<<res;
	
}