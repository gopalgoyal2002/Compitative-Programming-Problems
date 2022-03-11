#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long


#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>             vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);
#define ar array
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

vector<array<ll,2>>adj[N];
vector<array<ll,2>>adj2[N];
vl dist(N,1e18);
ll int ans=1e18;
vl dist2(N,1e18);
void solve(int i,vector<array<ll,2>>adj[N],vl &dist)
{
    priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>>q;
      q.push({0,i});
      dist[i]=0;
      while(!q.empty())
  {
      ar<ll,2>u=q.top();
      q.pop();
      if(dist[u[1]]<u[0])
      continue;
    
      for(ar<ll,2>v:adj[u[1]])
      {
          if(dist[v[1]]>u[0]+v[0])
          {
              dist[v[1]]=u[0]+v[0];
              q.push({dist[v[1]],v[1]});
          }
          
      }
  }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    ll int n,m;
    cin>>n>>m;
    fo(i,m)
    {
        ll int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back({c,b});
        adj2[b].push_back({c,a});
    }
   solve(0,adj,dist);
   solve(n-1,adj2,dist2);
//    for(int i=0;i<n-1;i++)
//    cout<<dist[i]<<" ";
// //    cout<<endl;
// //    for(int i=0;i<n-1;i++)
// //    cout<<dist2[i]<<" ";
//    cout<<endl;
   for(int i=0;i<n;i++)
   {
       for(ar<ll,2>j:adj[i])
       {
           ans=min(ans,dist[i]+dist2[j[1]]+j[0]/2);
       }
   }
   cout<<ans<<endl;
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

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}
