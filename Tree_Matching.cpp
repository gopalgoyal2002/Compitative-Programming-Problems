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

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];
vector<bool>vis(N,false);
vector<int>colour(N,-1);

void solve() {
     int n; cin >> n;
    vector<vector<int> > graph(n+1);
    
    for(int i=0;i<n-1;++i){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    vector<int> color(n+1);
    vector<int> visited(n+1,0);

    q.push(1);
    color[1] = 0;
    visited[1] = 1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int i:graph[node]){
            if(!visited[i]){
                visited[i] = 1;
                color[i] = (color[node]+1)%2;
                q.push(i);
            }
        }
    }
    vector<int> first;
    vector<int> second;
    for(int i=1;i<=n;++i){
        if(color[i]==0) first.push_back(i);
        else second.push_back(i);
    }
    int count = 0;
    fill(all(visited),0);
    if(first.size() < second.size()) swap(first,second);
    for(int i=0;i<first.size();++i) {
        visited[first[i]] = 1;
        for(int it:graph[first[i]]){
            if(!visited[it]){
                visited[it] = 1;
                count++;
                break;
            }
        }
    }
    cout << count << '\n';

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

 
  
      solve();
    
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
