#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e6 + 5;

int n;
int val1 = -1,val2 = -1;
int l1 = -1,r1 = 0,l2 = -1,r2 = 0;
int ans = 0;
signed main(){
	
	cin>>n;
	
	for(int i = 1,x;i <= n;i++){
		cin>>x;
		
		if(x == val1)r1 = i;
		else if(x == val2)r2 = i;
		else{
			
			if(val1 == -1){
				
				val1 = x;
				l1 = i;
				r1 = i;
				
			}else if(val2 == -1){
				
				val2 = x;
				l2 = i;
				r2 = i;
				
			}else if(val1 != -1 && val2 != -1){
				
				if(r1 > r2){
					
					l1 = max(l1,r2 + 1);
					val2 = x;
					l2 = i;
					r2 = i;
					
				}else{
					
					l2 = max(l2,r1 + 1);
					
					val1 = x;
					l1 = i;
					r1 = i;
				}
				
			}
			
			
		}
		
		//cout<<val1<<" "<<val2<<" "<<min(l1,l2)<<" "<<i<<"\n";
		
		
		ans = max(ans,i - min(l1 == -1 ? i : l1,l2 == -1 ? i : l2) + 1);
		
	}
	
	cout<<ans<<'\n';
}