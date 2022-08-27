
#include<bits/stdc++.h>

#define int long long

using namespace std;

int n,m,k,x,y,z;
int n_ = 0,m_ = 0,k_ = 0;
signed main(){
	
	cin>>n>>m>>x>>y>>z>>k;
	
	long long timee = n * x + y * m;
	
	if(z > y && z > x)return cout<<timee,0;
	
	if(x >= y){
		
		
		if(x >= z){
			if(k >= n){
				
				timee -= n * x;
				timee += n * z;
				
				k -= n;
				
				k_ = n;
				n_ = 0;
				
			}else{
				
				timee -= k * x;
				timee += k * z;
				
				
				k_ = k;
				k = 0;
				n_ = n - k_;
				
			}
		}else {
			n_ = n;
		}
		
		
		if(k > 0){
			
			if(y >= z){
				
				timee -= min(m,k) * y;
				timee += min(m,k) * z;
				
				k_ += min(m,k);
				m_ = max(0ll,m - min(m,k));
				
			}else m_ = m;
			
		}
		
	}else {
		
		if(y >= z){
			if(k >= m){
				
				timee -= m * y;
				timee += m * z;
				
				k -= m;
				k_ = m;
				m_ = 0;
				
			}else{
				
				timee -= k * y;
				timee += k * z;
				
				k_ = k;
				m_ = m - k;
				k = 0;
				
				
			}
		}else m_ = m;
		
		//cout<<timee<<" ";
		
		if(k > 0){
			
			if(x >= z){
				
				timee -= min(n,k) * x;
				timee += min(n,k) * z;
				
				k_ += min(n,k);
				n_ = max(0ll,n - min(n,k));
				
			}else n_ = n;
			
		}
		
		//cout<<timee<<" ";
		
	}
	
	//cout<<n_<<" "<<m_<<" "<<k_<<"\n";
	cout<<timee;
	
}