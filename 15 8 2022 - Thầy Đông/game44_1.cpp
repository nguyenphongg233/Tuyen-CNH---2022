#include<bits/stdc++.h>

using namespace std;

const long long N = 30;
const long long INF = 1e9;
#define X first
#define Y second

#define ii pair<int,int>

string ed = "ABCDEFGHIJKLMNO0";
map<string,int> step[2];

struct point{
	int id1,id2;
	int num;
};
map<string,point> tv[2];
string s_ = "";
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

pair<int,int> to_matrix(int id){
	
	return {(id / 4),(id % 4)};
	
	
}

int to_arr(int x,int y){
	
	return x * 4 + y;
	
}
void solve(){
	
	deque<string> h;
	h.push_back(s_);
	
	step[0][s_] = 0;
	// loang 12 lan tu vi tri xuat phat 
	
	while(!h.empty()){
		
		string s = h.front();
		h.pop_front();
		
		//cout<<s<<" "<<step[0][s]<<"\n";
		
		if(step[0][s] >= 12)continue;
		
		for(int i = 0 ;i <= 15;i++){
			
			if(s[i] == '0'){
				
				ii u = to_matrix(i);
				for(int z = 0;z < 4;z++){
					
					int x = u.X + dx[z];
					int y = u.Y + dy[z];
					
					if(x < 0 || x > 3 || y < 0 || y > 3)continue;
					
					int id = to_arr(x,y);
					
					string new_s = s;
					swap(new_s[i],new_s[id]);
					
					int new_num = s[id] - 'A' + 1;
					//cout<<new_num<<"\n";
					if(!step[0].count(new_s) || step[0][new_s] > step[0][s] + 1){
						
						step[0][new_s] = step[0][s] + 1;
						tv[0][new_s] = {i,id,new_num};
						h.push_back(new_s);
						
					}
					
				}
				
				
				
				break;
			}
			
		}
	
	}
	
	
	
	// loang 13 lan tu ans 
	
	deque<string> d;
	
	d.push_back(ed);
	step[1][ed] = 0;
	
	int cnt = INF;
	string mid = "";
	
	while(!d.empty()){
		
		string s = d.front();
		d.pop_front();
		
		if(step[0].count(s)){
			
			if(step[0][s] + step[1][s] < cnt){
				cnt = step[0][s] + step[1][s];
				mid = s;
			}
			
		}
		if(step[1][s] >= 13)continue;
		
		for(int i = 0 ;i <= 15;i++){
			
			if(s[i] == '0'){
				
				ii u = to_matrix(i);
				for(int z = 0;z < 4;z++){
					
					int x = u.X + dx[z];
					int y = u.Y + dy[z];
					
					if(x < 0 || x > 3 || y < 0 || y > 3)continue;
					
					int id = to_arr(x,y);
					
					string new_s = s;
					swap(new_s[i],new_s[id]);
					
					int new_num = s[id] - 'A' + 1;
					//cout<<new_num<<"\n";
					
					if(!step[1].count(new_s) || step[1][new_s] > step[1][s] + 1){
						
						step[1][new_s] = step[1][s] + 1;
						tv[1][new_s] = {i,id,new_num};
						d.push_back(new_s);
						
					}
					
				}
				
				
				
				break;
			}
			
		}
	}
	
	//cout<<cnt<<" "<<mid;
	
	vector<int> res;
	string tmp = mid;
	while(ed != mid){
		
		point u = tv[1][mid];
		
		swap(mid[u.id1],mid[u.id2]);
		res.push_back(u.num);
		
	}
	
	vector<int> rt;
	mid = tmp;
	while(mid != s_){
		
		point u = tv[0][mid];
		swap(mid[u.id1],mid[u.id2]);
		rt.push_back(u.num);
		
	}
	
	reverse(rt.begin(),rt.end());
	
	cout<<rt.size() + res.size()<<"\n";
	//reverse(res.begin(),res.end());
	
	for(auto ve : rt)cout<<ve<<" ";
	
	//reverse(res.begin(),res.end());
	
	//cout<<rt.size()<<'\n';
	for(auto v : res)cout<<v<<" ";
	
	
}

signed main(){
	
	
	for(int i = 1;i <= 16;i++){
	    int x;
	    cin>>x;
	    if(x == 0) s_ += '0';
	    else s_ += (x + 'A' - 1);
	}
	
	//if(s_ == ed)return cout<<0,0;
	solve();
	
	
}