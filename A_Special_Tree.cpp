#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(i=0;i<n;i++)

#define ll long long

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()

#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);
void uni(int x,int y,vector<int>&parent,vector<int>&rank);
int find(int x,vector<int>&parent);
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
 const int V=100000;  
//=======================

vi g[N];
int a[N];
  
 vector<int> dijkstras(int src, int n, vector<vector<pii>> &adj){
    vector<int> dist(n+1, INT_MAX);
    vector<bool> vis(n+1, false);
    dist[src]=0;
    priority_queue<pii, vector<pii>, greater<pii>> minHp;
    minHp.push({0,src});
    
    while(!minHp.empty()){
        pii p=minHp.top();
        int u=p.second;
        minHp.pop();
        if(vis[u]) continue;
        vis[u]=true;
        
        for(auto child:adj[u]){
            int v=child.first;
            int w=child.second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                minHp.push({dist[v], v});
            }
        }
    }
    return dist;
}

void solve() {
 int n,k,a;
 cin>>n>>k>>a;
  vi special(k);
  for(int i=0;i<n;i++)
  cin>>special[i];
  vector<vector<pii>> adj(n+1);
    
  for(int i=0;i<n-1;i++)
  {
      int u,v;
      cin>>u>>v;
     
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1}); 
    
  }
  vector<int>as=dijkstras(a,n,adj);
  for(int i=0;i<k;i++)
  {
      vector<int>spes=dijkstras(special[i],n,adj);
      int f=as[special[i]];
       int s;
      for(int j=1;j<n+1;j++)
      {
       s=spes[j];
      }
      cout<<f-s<<" ";
  }
  cout<<endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

    int find(int x,vector<int>&parent)
    {
        if(parent[x]==x)
        return x;
      parent[x]= find(parent[x],parent);
        return parent[x];
    }
    
    void uni(int x,int y,vector<int>& parent,vector<int>&rank)
    {   
        int x_rep=find(x,parent);
        int y_rep=find(y,parent);
        if(x_rep==y_rep)
        return ;
       else if(rank[x_rep]<rank[y_rep])
        {
            parent[x_rep]=y_rep;
        }
        else if(rank[x_rep]>rank[y_rep])
        {
            parent[y_rep]=x_rep;
        }
        else
        {
            parent[y_rep]=x_rep;
            rank[x_rep]++;
        }
    }
void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

