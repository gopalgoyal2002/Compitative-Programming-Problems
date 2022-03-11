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
  
 
void solve() {
 ll int n,m,k;
 cin>>n>>m>>k;
 vvi v(n,vi(m,0));
 for(int i=0;i<n;i++)
 {
    
     for(int j=0;j<m;j++)
     {  int x;
     cin>>x;
        v[i][j]=x;
     }
     
 }
//  for(int i=0;i<n;i++)
//  for(int j=0;j<m;j++)
//  cout<<v[i][j];
 vi row(n);
 vi col(m);
 for(int i=0;i<n;i++)
 row[i]=i;
 for(int i=0;i<m;i++)
 col[i]=i;
 while(k--)
 {
     char c;
     cin>>c;
     if(c=='r')
     {
         int a,b;
         cin>>a>>b;
         a--,b--;
        swap(row[a],row[b]);
     }
     else if(c=='c')
     {
         
         int a,b;
         cin>>a>>b;
         a--,b--;
        swap(col[a],col[b]);
     }
     else{
         int a,b;
         cin>>a>>b;
         a--;
         b--;
         int x=row[a];
         int y=col[b];
         cout<<v[x][y]<<endl;
     }
 }

   
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
