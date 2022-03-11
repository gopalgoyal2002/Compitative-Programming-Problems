#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
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



void nextij(long n,long m,long& i,long& j) {
    if (i==n-1) { //bottom row
        if (j<n-1) { //in the left square
            j = i+j+1;
            i = 0;
        }
        else { //out of the left square
            i = j-(n-1)+1;
            j = m-1;
        }
    }
    else { //other rows
        if (j==0) { //left most column
            j = i+1;
            i = 0;
        }
        else { //other columns
            i++;
            j--;
        }
    }
}
int main() {
     long n = 3;
    long m = 5;
    long a[3][5];  

    long i = 0;
    long j = 0;
    long c = 1;

    while (c<=n*m) {
        a[i][j] = c;        
        nextij(n,m,i,j);
        c++;        
    }

    // for(int i=1;i<1000;i++)
    // a[0][i]+=a[0][i-1];
    //   for(int i=1;i<1000;i++)
    // a[i][0]+=a[i-1][0];
    // for (i=1; i<n; i++) {
    //     for (j=1; j<m; j++)
    //      {
    //          a[i][j]=max(a[i-1][j],a[i][j-1])+a[i][j];
    //      }
    // }
     for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
       cout<<a[i][j]<<endl;
    // int t;
    // cin>>t;
    // while(t--)
    // {  // vvi v=a;
 
    //     int x,y,a1,b;
    //   cin>>x>>y>>a1>>b;
    //    x--;
    //    y--;
    //    a1--;
    //    b--;
    //    ll int ans=0;
    //    for(int i=x;i<=a1;i++)
    //    {
    //        ans+=a[i][y];
    //    }
    //    for(int j=y;j<=b;j++)
    //    {
    //        ans+=a[a1][j];
    //    }
    //    cout<<ans<<endl;
    // }
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
