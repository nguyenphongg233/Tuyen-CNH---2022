#include<bits/stdc++.h>

#define pii pair<int,int>
#define piii pair<int, pair<int,int>>
#define fi first
#define se second
using namespace std;

const int inf = 1e9+7;

const int N = 105;
int f[N][10050];
int n, m, s, t;
vector<piii> g[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s>> t;

    for (int i = 1; i <= m; i++){
        int u,v,h,w;
        cin >> u >> v >> h >> w;
        g[u].push_back({v,{h,w}});
        g[v].push_back({u,{h,w}});
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 10005; j++){
            f[i][j] = inf;
        }
    }

    priority_queue <piii, vector<piii>, greater<piii>> pq;

    f[s][0] = 0;
    pq.push({0,{0,s}});

    while (!pq.empty()){
        piii u = pq.top();
        int node = u.se.se;
        int chiphi = u.se.fi;

        pq.pop();
        if (u.fi > f[node][chiphi]) continue;

        for (piii v : g[node]){
            int chiphimoi = chiphi + v.se.fi;
            if (chiphimoi > 10000) continue;

            if (f[v.fi][chiphimoi] > u.fi + v.se.se){
                f[v.fi][chiphimoi] = u.fi + v.se.se;
                pq.push({f[v.fi][chiphimoi], {chiphimoi, v.fi}});
            }
        }
    }

    int lim = inf, ans = 0;

    for (int i = 0; i <= n*100;i++){
        if (f[t][i] < lim){
            ans++;
            lim = f[t][i];
        }
    }
    cout << ans;
}
