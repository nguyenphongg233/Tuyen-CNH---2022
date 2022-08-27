#include<bits/stdc++.h>

using namespace std;
const long long MAX = 5e5 + 5;

#define X first
#define Y second
#define int long long 
int n,m;
vector<vector<int>> a;
vector<pair<int,int>> cloud[MAX];
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.X < b.X;
}
bool cmp2(pair<int,int> a,pair<int,int> b){
	return a.Y < b.Y;
}
int ans = 0;
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	a.resize(n + 1,vector<int>(m + 1,0));
	
	vector<int> rt;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			
			cin>>a[i][j];
			rt.push_back(a[i][j]);
		}
	}
	
	sort(rt.begin(),rt.end());
	rt.erase(unique(rt.begin(),rt.end()),rt.end());
	
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			
			a[i][j] = lower_bound(rt.begin(),rt.end(),a[i][j]) - rt.begin() + 1;
			cloud[a[i][j]].push_back({i,j});
		}
	}
	
	for(int i = 1;i <= rt.size();i++){
		
		
		sort(cloud[i].begin(),cloud[i].end(),cmp);
		
		int sumX = 0,sumY = 0;
		for(auto v : cloud[i]){
			
			sumX += v.X;
			sumY += v.Y;
			
		}
		
		int sumrX = 0;
		int sumrY = 0;
		
		for(int j = cloud[i].size() - 1;j >= 0;j--){
			
			sumX -= cloud[i][j].X;
			//cout<<cloud[i][j].X<<" "<<cloud[i][j].Y<<" : ";
			//cout<<j<<" "<<sumX<<" "<<sumrX<<" "<<j * cloud[i][j].X - sumX<<" "<<sumrX - (cloud[i].size() - j - 1) * cloud[i][j].X<<"\n";
			
			ans += j * cloud[i][j].X - sumX;
			ans += sumrX - (cloud[i].size() - j - 1) * cloud[i][j].X;
			sumrX += cloud[i][j].X;
			
		}
		//cout<<"\n";
		//cout<<ans<<"\n";
		
		sort(cloud[i].begin(),cloud[i].end(),cmp2);
		
		for(int j = cloud[i].size() - 1;j >= 0;j--){
			
			//cout<<cloud[i][j].X<<" "<<cloud[i][j].Y<<" : \n";
			sumY -= cloud[i][j].Y;
			//cout<<j<<" "<<sumY<<" "<<sumrY<<" "<<
			ans += j * cloud[i][j].Y - sumY;
			ans += sumrY - (cloud[i].size() - j - 1) * cloud[i][j].Y;
			sumrY += cloud[i][j].Y;
			
			
		}
		
		//cout<<ans<<"\n";
		
		
		
		
		
	}
	
	cout<<ans / 2<<'\n';
	
	
	
}