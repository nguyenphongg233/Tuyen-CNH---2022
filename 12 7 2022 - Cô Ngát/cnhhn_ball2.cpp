#include <bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

#define pi = 3.1415926535
const long long  MAX = 300005;
const long long  INF = 10000000070;

// Nguyễn Phongg :))
using namespace std;
ll a[MAX], b[MAX], m, n;

bool check(ll t)
{
    ll i = 0, j = n - t, dem = 0;
    FOR(k, 0, m - 1)
    {
        if (a[k] > b[i] && a[k] < b[j])
        {
            dem++;
            if (dem == t)
                return true;
            i++;
            j++;
        }
        else if (a[k] >= b[j])
            return false;
    }
    return false;
}

int main(){
    cin >> m >> n;
    FOR(i, 0, m - 1) cin >> a[i];
    FOR(i, 0, n - 1) cin >> b[i];
    sort(a, a + m);
    sort(b, b + n);
    ll l = 1;
    ll r = n / 2;
    while (l <= r){
        ll q = (l + r) / 2;
        if (check(q)) l = q + 1;
        else r = q - 1;
    }
    cout << r;
    return 0;
}
