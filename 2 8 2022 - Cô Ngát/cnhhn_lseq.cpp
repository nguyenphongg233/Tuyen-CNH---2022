#include<bits/stdc++.h>


#define int long long 

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int n;
int a[MAX];
int cnt = 0;

bool dd[MAX << 1];
int pref[MAX << 1];

int answ = 0;
signed main(){
	
	cin>>n;
	
	for(int i = 1;i <= n;i++){
		
		cin>>a[i];
		cnt += a[i] == 0;
		
		if(a[i] != 0)dd[a[i] + MAX - 5] = 1;
	}
	
	for(int i = -1000000;i <= 1000000;i++){
		
		//cout<<i + MAX - 5<<"\n";
		if(i == -1000000)pref[i + MAX - 5] = dd[i + MAX - 5];
		else pref[i + MAX - 5] = pref[i - 1 + MAX - 5] + dd[i + MAX  - 5];
		int l = 0,r = i + MAX - 5;
		int ans = i + MAX - 5 + 1;
		
		//cout<<l<<" "<<r<<"\n";
		//if(l < 0 || r < 0)return cout<<l<<" "<<r,0;
		
		while(l <= r){
			
			int m = l + r >> 1;
			
			//if(m < 0)return cout<<m,0;
			int x;
			if(m == 0)x = pref[i + MAX - 5] + cnt;
			else x = pref[i + MAX - 5] - pref[m - 1] + cnt;
			int y = i  + MAX - 5 - m + 1;
			
			if(x >= y)r = m - 1,ans = m;
			else l = m + 1;
			
			
		}
		
		//if(i - ans + 1 != 0)cout<<i<<"\n"l
		
		answ = max(answ,i + MAX - 5 - ans + 1);
		
		
	}
	
	cout<<answ;
}
