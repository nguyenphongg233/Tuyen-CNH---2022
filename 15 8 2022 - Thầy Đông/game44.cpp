#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
const int MOD = 1e9 + 7;

struct idk{
    int p[4][4];
} a, b;

deque<idk> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check(int i, int j){
    return (i > -1 && i < 4 && j > -1 && j < 4);
}

map<vector<int>, int> mp, len, app, len1;
vector<int> gg, A;

void BFS(){
    q.push_back(a);
    mp[A] = 1;
    app[A] = 1;
    while(!q.empty()){
        idk u = q.front();
        q.pop_front();
        
        int i1, j1;
        vector<int> v1;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                v1.push_back(u.p[i][j]);
                // cout << u.p[i][j] << ' ';
                if(u.p[i][j] == 0){
                    i1 = i;
                    j1 = j;
                }
            }
            // cout << '\n';
        }
        // if(mp[gg] > 0){
            // cout << len[gg] << '\n';
            // return;
        // }
        app[v1] = 1;
        if(len[v1] == 12){
            continue;
        }
        for(int k = 0; k < 4; k++){
            int i2 = i1 + dx[k], j2 = j1 + dy[k];
            idk res = u;
            if(check(i2, j2)){
                swap(res.p[i1][j1], res.p[i2][j2]);
            }
            vector<int> v;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    v.push_back(res.p[i][j]);
                }
            }
            if(mp[v] == 0){
                mp[v] = 1;
                len[v] = len[v1] + 1;
                // cout << len[v] << '\n';
                q.push_back(res);
            }
        }
    }
}

void BFS1(){
    q.clear();
    mp.clear();
    q.push_back(b);
    mp[gg] = 1;
    while(!q.empty()){
        idk u = q.front();
        q.pop_front();
        
        int i1, j1;
        vector<int> v1;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                v1.push_back(u.p[i][j]);
                // cout << u.p[i][j] << ' ';
                if(u.p[i][j] == 0){
                    i1 = i;
                    j1 = j;
                }
            }
            // cout << '\n';
        }
        // if(mp[gg] > 0){
            // cout << len[gg] << '\n';
            // return;
        // }
        if(app[v1] > 0){
            cout << len1[v1] + len[v1];
            return;
        }
        if(len1[v1] == 12){
            continue;
        }
        for(int k = 0; k < 4; k++){
            int i2 = i1 + dx[k], j2 = j1 + dy[k];
            idk res = u;
            if(check(i2, j2)){
                swap(res.p[i1][j1], res.p[i2][j2]);
            }
            vector<int> v;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    v.push_back(res.p[i][j]);
                }
            }
            if(mp[v] == 0){
                mp[v] = 1;
                len1[v] = len1[v1] + 1;
                 cout << len[v] << '\n';
                q.push_back(res);
            }
        }
    }
    cout << 25;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> a.p[i][j];
            A.push_back(a.p[i][j]);
        }
    } 
    int res = 1;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            gg.push_back(res++);
            b.p[i][j] = res - 1;
        }
    }
    gg[gg.size() - 1] = 0;
    b.p[3][3] = 0;
    BFS();
    BFS1();
    
    return 0;
}
 