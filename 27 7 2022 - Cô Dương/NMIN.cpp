#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 5000 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int q,s;
int step[MAX][505];
deque<ii> h;
pair<ii,int> tv[MAX][505];

signed main(){
	
	cin>>q>>s;
	
	for(int i = 0;i <= s;i++){
		for(int j = 0;j <= q;j++)step[i][j] = INF;
	}
	h.push_back({0,0});
	step[0][0] = 0;
	while(!h.empty()){
		
		int s1 = h.front().X;
		int q1 = h.front().Y;
		
		h.pop_front();
		
		//cout<<s1<<" "<<q1<<" "<<step[s1][q1]<<"\n";
		int l = 0,r = 9;
		if(s1 == 0 && q1 == 0)l = 1;
		for(int i = l;i <= r;i++){
			
			int news = s1 + i;
			int newq = (q1 * 10 + i) % q;
			
			//cout<<news<<" "<<s<<"\n";
			if(news > s)continue;
			//cout<<step[news][newq]<<"\n";
			if(step[news][newq] > step[s1][q1] + 1){
				
				//cout<<"WHo asked";
				step[news][newq] = step[s1][q1] + 1;
				tv[news][newq] = {{s1,q1},i};
				h.push_back({news,newq});
				
			}
			
		}

	}
	
	if(step[s][0] == INF)return cout<<-1,0;
	
	string s2 = "";
	
	int x = s;
	int y = 0;
	

	while(1){
		
		if(x == 0 && y == 0)break;
		
		int id = tv[x][y].Y;
		//cout<<id<<"\n";
		s2 = s2 + to_string(id);
		int x_ = tv[x][y].X.X;
		int y_ = tv[x][y].X.Y;
		
		x = x_;
		y = y_;
	}
	
	
	reverse(s2.begin(),s2.end());
	cout<<s2;
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}