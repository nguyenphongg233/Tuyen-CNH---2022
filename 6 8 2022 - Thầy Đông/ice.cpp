#include <bits/stdc++.h>

const long long MAX = 5e3 + 5;

using namespace std;


#define int short

int n;
short t[MAX][MAX]; 
char k[MAX][MAX]; 

deque<pair<int,int>> q;
short ans = 0;



signed main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n;
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char x;
            cin >> x;
            
            if(x == '0'){
            	k[i-1][j]++;
                k[i+1][j]++;
                k[i][j-1]++;
                k[i][j+1]++;
            }else{
                t[i][j] = -1;
            }
            
        }
	}
	
	for(int i = 2; i < n; i++){
        for(int j = 2; j < n; j++){
            if(k[i][j] >= 2 && t[i][j] == -1){
                q.push_back({i,j});
                t[i][j] = 1;
            }
        }
	}
	
	
	while(!q.empty()){
		
        int i = q.front().first;
        int j = q.front().second;
        q.pop_front();
        ans = max(ans,t[i][j]);
        
         k[i+1][j]++;
        if(k[i+1][j] >= 2 && t[i+1][j] == -1){
            t[i+1][j] = t[i][j] + 1;
            q.push_back({i+1,j});
        }

        k[i-1][j]++;
        if(k[i-1][j] >= 2 && t[i-1][j] == -1){
            t[i-1][j] = t[i][j] + 1;
            q.push_back({i-1,j});
        }

        k[i][j-1]++;
        if(k[i][j-1] >= 2 && t[i][j-1] == -1){
            t[i][j-1] = t[i][j] + 1;
            q.push_back({i,j-1});
        }

        k[i][j+1]++;
        if(k[i][j+1] >= 2 && t[i][j+1] == -1){
            t[i][j+1] = t[i][j] + 1;
           q.push_back({i,j+1});
        }

	}
	
	cout << ans;
    return 0;
}
