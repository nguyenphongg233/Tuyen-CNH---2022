#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e6 + 5;
const long long MOD = 998244353;
#define int long long 

int n,c;
int a[MAX],A[MAX];
int b[MAX * 10],d[MAX * 10];


signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		
		cin>>n>>c;
		
		
        for(int i = 1;i <= c;i++)d[i] = 0;
        
        int cnt = 0;
        int ok1 = 0;
        
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            if(a[i] == 1)ok1 = 1;
            
            d[a[i]]++;
            
            if(d[a[i]] == 1){
                A[++cnt] = a[i];
            }
            
        }
 
        for(int i = 1;i <= c;i++){
            b[i] = (d[i] > 0) + b[i-1];
        }
 
 
        if(!ok1){
            cout << "No\n";
            goto p;
   
        }
 
        for(int i = 1;i <= cnt;i++){
            int u = A[i];
            for(int j = u*2;j <= c;j += u){
                int l = j - 1;
                int r = min(j + u - 1,c);
                int h = b[r] - b[l];
                if(h){
                    if(!d[j / u]){
                        cout << "No\n";
                        goto p;
                    }
                }
            }
        }
        cout << "Yes\n";
		
		p:;
		
	}
}