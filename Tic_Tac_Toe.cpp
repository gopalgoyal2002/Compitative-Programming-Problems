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
  
  int cx=0,co=0,c_=0;
  char arr[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
    {
      cin>>arr[i][j];
      if(arr[i][j]=='X')
      cx++;
      if(arr[i][j]=='O')
      co++;
      if(arr[i][j]=='_')
      c_++;
    }
  }
  int wx=0,wo=0;
  if(arr[0][0]=='X'&&arr[1][0]=='X'&&arr[2][0]=='X')wx=1;
   if(arr[0][1]=='X'&&arr[1][1]=='X'&&arr[2][1]=='X')wx=1;
   if(arr[0][2]=='X'&&arr[1][2]=='X'&&arr[2][2]=='X')wx=1;
    if(arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X')wx=1;
     if(arr[0][0]=='X'&&arr[0][1]=='X'&&arr[0][2]=='X')wx=1;
      if(arr[1][0]=='X'&&arr[1][1]=='X'&&arr[1][2]=='X')wx=1;
       if(arr[2][0]=='X'&&arr[2][1]=='X'&&arr[2][2]=='X')wx=1;
        if(arr[0][2]=='X'&&arr[1][1]=='X'&&arr[2][0]=='X')wx=1;
   if(arr[0][0]=='O'&&arr[1][0]=='O'&&arr[2][0]=='O')wo=1;
   if(arr[0][1]=='O'&&arr[1][1]=='O'&&arr[2][1]=='O')wo=1;
   if(arr[0][2]=='O'&&arr[1][2]=='O'&&arr[2][2]=='O')wo=1;
    if(arr[0][0]=='O'&&arr[1][1]=='O'&&arr[2][2]=='O')wo=1;
     if(arr[0][0]=='O'&&arr[0][1]=='O'&&arr[0][2]=='O')wo=1;
      if(arr[1][0]=='O'&&arr[1][1]=='O'&&arr[1][2]=='O')wo=1;
       if(arr[2][0]=='O'&&arr[2][1]=='O'&&arr[2][2]=='O')wo=1;
        if(arr[0][2]=='O'&&arr[1][1]=='O'&&arr[2][0]=='O')wo=1;
        
        if((wx==1&&wo==1)||((cx-co)<0)||(cx-co)>1)
        {
          cout<<3<<endl;
          return ;
        }
        else if(cx==0&&co==0&&c_==9)
        cout<<2<<endl;
        else if(wx==1&&wo==0&&cx>co)
        cout<<1<<endl;
        else if(wx==0&&wo==1&&cx==co)
        cout<<1<<endl;
        else if(wx==0&&wo==0&&c_==0)
        cout<<1<<endl;
        else if(wx==0&&wo==0&&c_>0)
        cout<<2<<endl;
        else
        cout<<3<<endl;

   
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

