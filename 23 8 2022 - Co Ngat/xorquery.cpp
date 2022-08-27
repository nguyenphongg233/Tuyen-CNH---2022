#include<bits/stdc++.h>

using namespace std;

const long long MAX = 3e3 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long base = 26;
#define int long long 

int q;

struct node{
	node* child[2];
	int f = 0;
	node(){
		for(int i = 0;i < 2;i++){
			child[i] = NULL;
		}
	}
};

node *root;

void add(int n){
	
	node *rt = root;
	rt -> f++;
	
	for(int id = 32;id >= 0;id--){
		
		
		if(rt -> child[n >> id & 1] == NULL){
			
			rt -> child[n >> id & 1] = new node();
			
		}
		
		rt = rt -> child[n >> id & 1];
		rt -> f++;
	}
	
	
}

void del(int n){
	
	node *rt = root;
	rt -> f--;
	
	for(int id = 32;id >= 0;id--){
		
		
		rt = rt -> child[n >> id & 1];
		rt -> f--;
	}
	
}

void print(int n){
	
	int bit = n;
	node *rt = root;
	int bit2 = 0;
	
	//cout<<n<<":\n";
	for(int id = 32;id >= 0;id--){
		
		int bit1 = n >> id & 1;
		
		if(rt -> child[1 ^ bit1] == NULL || rt -> child[1 ^ bit1] -> f <= 0){
			
			rt = rt -> child[bit1];
			bit2 = bit2 ^ ((bit1) * (1 << id));
			//cout<<((bit1));
		}else {
			
			rt = rt -> child[1 ^ bit1];
			bit2 = bit2 ^ ((1 ^ bit1) * (1 << id));
			//cout<<(1 ^ bit1);
			
		}
		
	}
	
	//cout<<'\n';
	
	//cout<<bit2<<'\n';
	cout<<(bit ^ bit2)<<"\n";
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	root = new node();
	
	cin>>q;
	
	add(0);
	while(q--){
		
		char x;
		int n;
		cin>>x>>n;
		
		if(x == '+')add(n);
		if(x == '-')del(n);
		if(x == '?')print(n);
		
		
	}
	
}