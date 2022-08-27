#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ii pair<int,int>

const int N = 1e3 + 7;
const int mod = 1e9 + 7;
const int INF = 1e9;

int n,m;
ii a[N];
int deg[N];
int dd[N][N];
vector<ii>res;
int ver;

bool cmp(ii a,ii b)
{
    return a.fi > b.fi;
}
bool ok = 0;
void dfs1(int u)
{
    for(int v = 1;v <= n;v++){
        if(ok)break;
        if(dd[u][v]){
            dd[u][v] = dd[v][u] = 0;
            deg[u]--;
            deg[v]--;
            cout << u << ' ' << v << ' ';
            if(deg[v] == 0){
                ok = 1;
                break;
            }
            else dfs1(v);
        }
    }
}

void dfs2(int u)
{
    for(int v = 1;v <= n;v++){
        if(dd[u][v]){
            deg[u]--;
            deg[v]--;
            dd[u][v] = dd[v][u] = 0;
            cout << u << ' ' << v << ' ' ;
            dfs2(v);
        }
    }
}



signed main(){
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        cin >> n;
	    int sum = 0;
	    for(int i = 1;i <= n;i++){
	        cin >> a[i].fi;
	        a[i].se = i;
	        sum += a[i].fi;
	        deg[i] = 0;
	    }
	
	    memset(dd,0,sizeof(dd));
	
	    res.clear();
	    if(sum % 2){
	        cout << -1 << '\n';
	        continue;
	    }
	
	    sort(a + 1,a + 1 + n,cmp);
	
	    bool bad = 0;
	    m = 0;
	    while(1){
	        int cnt = a[1].fi;
	        int u = a[1].se;
	        if(bad || !cnt)break;
	
	        a[1].fi = 0;
	
	        int dich = cnt + 1;
	        if(dich > n){
	            bad = 1;
	            break;
	        }
	        for(int i = 2;i <= dich;i++){
	            if(a[i].fi == 0){
	                bad = 1;
	                break;
	            }
	            a[i].fi--;
	            int v = a[i].se;
	            deg[u]++;
	            deg[v]++;
	            dd[u][v] = dd[v][u] = 1;
	        }
	        sort(a + 1,a + 1 + n,cmp);
	    }
	
	    if(bad){
	        cout << -1 << '\n';
	        continue;
	    }
	
	    for(int i = 1;i <= n;i++){
	        if(deg[i] % 2){
	            ok = 0;
	            dfs1(i);
	        }
	    }
	
	
	    for(int i = 1;i <= n;i++){
	        if(deg[i]){
	            dfs2(i);
	        }
	    }
	
	    cout << '\n';
    }


    return 0;
}
