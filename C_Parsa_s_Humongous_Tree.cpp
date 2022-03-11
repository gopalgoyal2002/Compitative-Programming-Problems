#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	ll l,r; 
}a[N];
vector<ll>vc[N];
ll dp[N][2];
 
void dfs(int x,int root){
    for(auto t: vc[x]){
    	if(t==root) continue;
    	dfs(t,x);
    	dp[x][0]+=max(dp[t][0]+abs(a[x].l-a[t].l),dp[t][1]+abs(a[x].l-a[t].r));
    	dp[x][1]+=max(dp[t][0]+abs(a[x].r-a[t].l),dp[t][1]+abs(a[x].r-a[t].r));
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			cin>>a[i].l>>a[i].r;
			vc[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			vc[u].push_back(v);
			vc[v].push_back(u);
		}
		dfs(1,-1);
		cout<<max(dp[1][1],dp[1][0])<<endl;
	}
	
	return 0;
} 