#include<bits/stdc++.h>

using namespace std;
#define int long long
const long long MAX = 1e5 + 5;

int n,s;
int v;
int id = 0;

struct query{
	int c,v;
};
query a[MAX];
bool cmp(query a,query b){
	return (a.c == b.c ? a.v > b.v : a.c < b.c);
}
signed main(){
	
	cin>>n>>s>>v;
	
	for(int i = 1,c,v;i <= n;i++){
		cin>>c>>v;
		a[i] = {c,v};
	}
	
	sort(a + 1,a + 1 + n,cmp);
	
	vector<query> sio;
	
	for(int i = 1;i <= n;i++){
		if(a[i].v > v && (sio.empty() || sio.back().v < a[i].v ))sio.push_back({a[i].c,a[i].v});
	}
	
	float res = 0;
	sio.push_back({s,-1});
	
	
	//for(auto e : sio)cout<<e.c<<" "<<e.v<<"\n";
	for(int i = 0;i <= sio.size() - 1;i++){
		
		cout<<sio[i].c<<" "<<res<<"\n";
		if(i >= sio.size() - 1)return cout<<res,0;
		cout<<"AC\n";
		//cout<<id<<" "<<sio[i].c<<" ";
		
		//cout<<id<<" "<<v<<" "<<res<<"\n";
		float time1 = (sio[i + 1].c - id) / v;
		float time2 = (sio[i].c - id) / v + (sio[i + 1].c) / sio[i].v;
		
		cout<<time1<<" "<<time2<<"\n";
		if(i == sio.size() - 2){
			
			//cout<<i<<"\n";
			int ans = res + min(time1,time2);
			
			return cout<<ans,0;
			
		}
		
		if(time1 > time2){
			
			//res += (sio[i].c - id) / v;
			res += time2;
			id = sio[i].c;
			//i++;
		}else{
			
			//cout<<"hi";
			//res += time1(sio[i].c - id) / v + (sio[i].c) / sio[i].v;
			res += time1;
			v = sio[i].v;
			id = sio[i].c;
			//i++;
		}
		
		//cout<<i<<" "<<res<<"\n";
		
	}
	
	cout<<round(res);
	
	
	
}