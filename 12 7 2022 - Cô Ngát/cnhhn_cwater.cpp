/*
   Date : 12 7 2022
   Tobi Where are you ?

*/

#include<bits/stdc++.h>

#define ll long long
#define task ""

#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = (1 << 19) + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll t,a,b,c;

void solve(){
	
	ll m = a;
	ll n = b;
	
	ii cm = {1,0};
	ii cn = {0,1};
	
	while(n != 0){
		
		ll q = m / n;
		ll r = m % n;
		
		ii cr;
		
		cr.X = cm.X - q * cn.X;
		cr.Y = cm.Y - q * cm.Y;
		
		m = n;
		n = r;
		
		cm = cn;
		cn = cr;
		
	}
	
	ll d = __gcd(abs(a),abs(b));
	
	ll x0 = cm.X * c / d;
	ll y0 = cm.Y * c / d;
	
	//cout<<x0<<" "<<y0<<"\n";
	
	ll p = b / d;
	ll q = a / d;
	
	
	// x = x0 + k * p
	// y = y0 - k * q
	
	// th1 x tiem can 0 
	
	ll x,y;
	ll k;
		
	k = x0 / p;
	
	x = x0 + k * p;
	y = y0 - k * q;
	
	ll ans = INF;  
	ans = min(ans,abs(x) + abs(y));
	
	
	
	
	k = y0 / q;
	
	x = x0 + k * p;
	y = y0 - k * q;
	
	
	ans = min(ans,abs(x) + abs(y));
	
	
	cout<<ans<<"\n";
	
	
	
}


void solve2(){
	
	ll m = a,n = b,xm = 1,xn = 0;
	
	while(n != 0){
		ll q = m / n;
		ll r = m - q * n;
		
		ll xr = xm - q * xn;
		m = n;
		n = r;
		xm = xn;
		xn = xr;
		
	}
	
	
	ll x = xm;
	
	ll d = __gcd(abs(a),abs(b));
	
	ll y =  (d - a * x) * c / b / d;
	
	ll aa = a / d;
	
	y = (y % aa + aa) % (aa);
	
	x = (c - b * y) / a;
	
	ll ans = abs(x) + abs(y);
	
	y  -= aa;
	
	x = (c - b * y) / a;
	
	ans = min(ans,abs(x) + abs(y));
	
	if(c % d != 0)cout<<-1<<'\n';
	else 
	
	cout<<ans<<'\n';
	
	
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream(task".inp")){
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	}
	
	
	cin>>t;
	
	while(t--){
		cin>>a>>b>>c;
		solve2();
	}
	
	
	
}