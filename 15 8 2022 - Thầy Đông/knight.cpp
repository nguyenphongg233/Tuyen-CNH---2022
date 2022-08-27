#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

const long long N = 3e3 + 5;
#define int long long
const long long INF = 1e9;

int x,y,n;
bool dd[N][N];
int step[N][N];
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};




int64_t calc(int64_t x1, int64_t y1, int64_t x2, int64_t y2)
{
    int64_t dx = abs(x2-x1);
    int64_t dy = abs(y2-y1);
    int64_t lb=(dx+1)/2;
    lb = max(lb, (dy+1)/2);
    lb = max(lb, (dx+dy+2)/3);
    while ((lb%2)!=(dx+dy)%2) lb++;
    if (abs(dx)==1 && dy==0) return 3;
    if (abs(dy)==1 && dx==0) return 3;
    if (abs(dx)==2 && abs(dy)==2) return 4;
    return lb;
}



signed main() {
   
	int t;
	cin >> t;
	while(t--){
		
        cin >> x >> y >> n;
        
        if(n == 0){
        	cout<<calc(0,0,x,y)<<"\n";
        	continue;
        }
        
        x += 1000;
        y += 1000;
        for(int i = 1; i <= 3000; i++){
            for(int j = 1; j <= 3000; j++){
            	step[i][j] = 1e9;
            	dd[i][j] = false;
            }
        }
        
        for(int i = 1; i <= n; i++){
            int u,v;
            cin >> u >> v;
            dd[u + 1000][v + 1000] = true;
        }
  
	    queue<pair<int,int>> q;
	    step[1000][1000] = 0;
	    q.push({1000,1000});
	    while(!q.empty()){
	        int i_ = q.front().X;
	        int j_ = q.front().Y;
	        
	        if(i_ == x && j_ == y) break;
	        
	        
	        q.pop();
	        if(dd[i_][j_])continue;
	        dd[i_][j_] = true;
	        for(int t = 0; t < 8; t++){
	            int x_ = i_ + dx[t];
	            int y_ = j_ + dy[t];
	            if(x_ >= 1 && y_ >= 1 && step[x_][y_] > step[i_][j_] + 1){
	                step[x_][y_] = step[i_][j_]+1;
	                q.push({x_,y_});
	            }
	        }
	    }

        cout << step[x][y]<<"\n";
	}
    return 0;
}