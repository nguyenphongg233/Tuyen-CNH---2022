#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e5 + 5;

int l[MAX],r[MAX];
int n;
int a[MAX];
int res = 0;
signed main(){
	
	cin>>n;
	
	l[0] = 0;
	for(int i = 1;i <= n;i++){
		
		cin>>a[i];
		l[i] = __gcd(l[i - 1],a[i]);
		
	}
	r[n + 1] = 0;
	
	for(int i = n;i >= 1;i--){
		r[i] = __gcd(r[i + 1],a[i]);
	}
	
	for(int i = 1;i <= n;i++){
		res = max(res,__gcd(l[i - 1],r[i + 1]));
	}
	cout<<res;
	
}