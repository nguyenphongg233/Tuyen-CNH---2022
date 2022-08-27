#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
#define int long long 
const int base = 26;

string s,t;
int p[MAX];
int h[MAX];

int get(int l,int r){
	return (h[r] - h[l - 1] * p[r - l + 1] + mod * mod) % mod;
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s>>t;

	int n = s.size();
	int m = t.size();
	t = " " + t;
	s = " " + s;
	p[0] = 1;
	h[0] = 1;
	for(int i = 1;i <= m ;i++){
		p[i] = (p[i - 1] * base ) % mod;
		h[i] = (h[i - 1] * base + t[i] - 'a' + 1 ) % mod;
	}
	
	
	
	
	
	
	
	
	if(s[1] == '1')for(auto &x : s){
		
		if(x == '1')x = '0';
		else if(x == '0')x = '1';
	}
	
	int cnt[] = {0,0};
	
	for(int i = 1;i <= n;i++){
		cnt[s[i] - '0']++;
	}
	
	int ans = 0;

	int last_next = 1;
	while(s[last_next] == '0')last_next++;
	
	for(int i = 1;i <= m;i++){
		
		int zero = get(1,i);
		int next = (last_next - 1) * i + 1;
		
		if(next > m)continue;
		int size_b = (m - (cnt[0] * i));
		
		if(size_b < 0 || size_b % cnt[1] != 0)continue;
		
		size_b = size_b / cnt[1];
		

		int one = get(next,next + size_b - 1);
		
		if(one == zero || one == 0)continue;
		
		
		bool ok = 0;
		int last = 1;
		for(int j = 1;j <= n;j++){
			
			//cout<<last<<" ";
			if(s[j] == '0'){
				
				
				if(get(last,last + i - 1) != zero){
					
					ok = 1;
					break;
				}
				
				//cout<<"zero "<<i<<"  ";
				last = last + i;
				
			}else{
				
				if(get(last,last + size_b - 1) != one){
					
					ok = 1;
					break;
				}
				
				//cout<<"one "<<i<<"  ";
				last = last + size_b;
			}
			
			
		}
		
	
		ans += 1 - ok;
		
	}
	
	cout<<ans;
	
}