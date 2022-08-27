#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e7 + 5;
#define int long long
bool dd[MAX];
int n,m;

signed main(){
	
	cin >> n >> m;

    for(int i = 1,u;i <= m;i++){
        cin >> u;
        dd[u] = 1;
    }

    int ans = 0;

    for(int i = 1;i <= n;i++){
        if(dd[i])continue;
        int cnt = 0;
        for(int j = 20;j >= 0;j--){
            if(i >> j & 1){
                cnt++;
                if(cnt >= 2)ans += pow(2,j);
            }
        }
    }

    cout << ans  * 2;
}