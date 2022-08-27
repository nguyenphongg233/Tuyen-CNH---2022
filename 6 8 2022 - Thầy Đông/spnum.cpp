#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;

int dp[9 * 105][81 * 105];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i <= 9 * 101; i++) for (int j = 0; j <= 81 * 101; j++) dp[i][j] = inf;
    for (int d = 1; d <= 9; d++) dp[d][d * d] = 1;
    for (int i = 1; i <= 9 * 101; i++) {
        for (int j = 1; j <= 81 * 101; j++) {
            for (int d = 0; d <= 9; d++) {
                if (i > d && j > d * d)
                    dp[i][j] = min(dp[i][j], dp[i - d][j - d * d] + 1);
            }
        }
    }
    dp[0][0] = 0;
    int tt;
    cin >> tt;
    while (tt--) {
        int s, p;
        cin >> s >> p;
        if (s > 9 * 101 || p > 81 * 101 || dp[s][p] > 100 || s == 0 || p == 0 || p < s) {
            cout << "No solution\n";
        }
        else {
            int cnt = dp[s][p];
            for (int i = 1; i <= cnt; i++) {
                for (int d = 1; d <= 9; d++) {
                    if (s >= d && p >= d * d && dp[s - d][p - d * d] == cnt - i) {
                        cout << d;
                        s -= d;
                        p -= d * d;
                        break;
                    }
                }
            }
            cout << '\n';
        }
    }

    return 0;

}