#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define timer ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int a[10005];
int sum = 0;
int n;

bool cmp(int x, int y){return x >= y;}

int main(){
    timer
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum+=a[i];
        }
        sort(a+1,a+1+n,cmp);
        if(sum%2==1){
            cout << "NO" << "\n";
        }else{
            sum = 0;
            bool check = true;
            for(int i = 1; i <= n; i++){
                sum += a[i];

                int sum1 = 0;

                for(int j = n; j >= i+1; j--){
                    sum1 += min(a[j],i);
                }
                if(sum > i*(i-1) + sum1 && i != n){
                    check = false;
                    break;
                }
            }
            if(check)cout << "YES";
            else cout << "NO";
            cout << "\n";
        }
    }
    return 0;
}