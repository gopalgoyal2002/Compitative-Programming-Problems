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

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

void solve() 
{
   ll int x,r,m;
   cin>>x>>r>>m;
   ll e=x;
   m=m*60;
   r=r*60;
   while(m>=0)
   {
       if(r<=x&&m>=r)
       {
           cout<<"YES"<<endl;
       }
     else if(m>x&&r>x)
      {
          m=m-x;
          r=r-x;
          x=0;
      }
     else if(x==0&&r>x)
      {
          x=e;
          m=m-x;
      }
      else if(r<=x&&m<r)
      {
          cout<<"NO"<<endl;
      }

   }
  
    
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

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

