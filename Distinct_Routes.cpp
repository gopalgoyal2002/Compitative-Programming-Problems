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

vvl v(500,vl(500,0));
vvi ans;

void dfs1(int i,vector<int>val,int n)
{     val.push_back(i);
     if(i==n-1)
     {
       ans.push_back(val);
       return ;
     }
     for(int j=0;j<n;j++)
     {
         if(v[i][j]==1)
         {
           dfs1(j,val,n);
           v[i][j]=0;
           break;
         }
     }
     return ;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
     
     int n,m;
     cin>>n>>m;
     
     fo(i,m)
     {
       int a,b;
       cin>>a>>b;
       a--;
       b--;
       v[a][b]=1;
     }
    vector<int>va;
 for(int i=0;i<n;i++)
 {  
      va.clear();
      if(v[0][i]==1)
      {  va.push_back(0);
      dfs1(i,va,n);
      v[0][i]=0;
      }
 }
 cout<<ans.size()<<endl;
 for(int i=0;i<ans.size();i++)
 {
   cout<<ans[i].size()<<endl;
   for(int j=0;j<ans[i].size();j++)
   cout<<ans[i][j]+1<<" ";

   cout<<endl;
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

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
 
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}
