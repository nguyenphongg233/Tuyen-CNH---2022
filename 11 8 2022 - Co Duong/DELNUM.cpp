#include<bits/stdc++.h>

using namespace std;

const long long MAX = 2e3 + 5;
const long long N = 3e5 + 5;

#define X first
#define Y second


int n;
int a[MAX];
bool edge[MAX][MAX];
bool snt[N];
bool visited[MAX];
int match[MAX];

bool ok(int u){
	
	for(int i = 1; i <= n;i++){
		if(edge[u][i] && !visited[i]){

			visited[i] = true;
			
			if(match[i] == -1 || ok(match[i])){
				
				match[i] = u;
				return true;
				
			}
			
		}
	}
	
	return false;
	
}


signed main(){
	
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	memset(match,-1,sizeof match);
	snt[0] = 1;
	snt[1] = 1;
	
	for(int i = 2;i * i < N;i++){
		if(!snt[i]){
			for(int j = i * i;j < N;j += i)snt[j] = 1;
			
		}
	}
	
	for(int i = 1;i < N;i++)snt[i] ^= 1;
	    
	int cnt = 0;

	for(int i = 1;i <= n;i++){
	
		for(int j = 1;j <= n;j++){
			edge[i][j] = snt[a[i] + a[j]];
			
		}
		
	}

	int res = 0;
	
	for(int i = 1;i <= n;i++){
		
		
		memset(visited,0,sizeof visited);
		
		if(ok(i))res++;
		
	}
	
	cout<<res;
	
	
	
}
