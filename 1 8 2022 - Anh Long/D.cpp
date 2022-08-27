#include<bits/stdc++.h>

using namespace std;

signed main(){
	
	int n;
	cin>>n;
	
	for(int i = 0;i < (1 << n);i++){
		
		string s = "";
		
		for(int j = 0;j < n;j++){
			if(i >> j & 1)s = "1" + s;
			else s = "0" + s;
		}
		
		cout<<s<<"\n";
		
	}
	
}