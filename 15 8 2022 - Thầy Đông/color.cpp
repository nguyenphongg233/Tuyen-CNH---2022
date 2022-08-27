#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
int n;
vector<int> c;
map<vector<int>,int> step;


signed main(){
	
	cin>>n;
	c.resize(n);
	for(int i = 0;i < n;i++)cin>>c[i];
	
	deque<vector<int>> h;
	
	h.push_back(c);
	
	step[c] = 1;
	
	while(!h.empty()){
		vector<int> a = h.front();
		vector<int> u = a;
		h.pop_front();
		
		bool ok = 0;
		for(int i = 0;i < n;i++){
			if(a[i] != 0){
				ok = 1;
				break;
			}
		}
		
		if(!ok)return cout<<step[a] - 1,0;
		
		
		for(int i = 0;i < n;i++){
			
			if(a[i] == 0)continue;
			
			if(a[i] % 2 == 0){
				
				a[i] /= 2;
			    if(!step.count(a)){
					step[a] = step[u] + 1;
					h.push_back(a);
				}
			    //res %= mod;
			    a[i]*= 2;
			}
			
			
			
			
			if(a[i] % 2 == 1){
				
				if(i == n - 1){
					
					
					if(a[0] % 2 == 1){
						a[n - 1] = (a[n - 1] - 1) / 2;
						a[0] = (a[0] - 1) / 2;
						
						if(!step.count(a)){
							step[a] = step[u] + 1;
							h.push_back(a);
						}
						//res %= mod;
						
						a[n - 1] = a[n - 1] * 2 + 1;
						
						a[0] = a[0] * 2 + 1;
						
						
					}
				}else{
					
					if(a[i + 1] % 2 == 1){
						
						
						
						a[i] = (a[i] - 1 ) / 2;
						a[i + 1] = (a[i + 1] - 1) / 2;
						
						if(!step.count(a)){
							step[a] = step[u] + 1;
							h.push_back(a);
						}
						//res %= mod;
						
						a[i] = a[i] * 2 + 1;
						a[i + 1] = a[i + 1] * 2 + 1;
					}
					
					
				}
			}
		
		}
		
	}
	
	
	
	
	
}