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


const int mod = 1000000007;
const int N = 1e6, M = N;
//=======================

vi g[N];
int a[N];
vector<ll int>tree(N,0);

 int cst(int ss,int se,int si,vector<ll>&arr)
 {
    if(ss==se)
    {
        tree[si]=arr[ss];
        return arr[ss];
    }
    int mid=(ss+se)/2;
    tree[si]=(cst(ss,mid,2*si+1,arr)^cst(mid+1,se,2*si+2,arr));
    return tree[si];
 }
//  ll int getmin(int qs,int qe,int ss,int se,int si)
//  {
//      if(se<qs||ss>qe)
//      return INT_MAX;

//      if(qs<=ss&&qe>=se)
//      return tree[si];

//      int mid=(ss+se)/2;
//     return min(getmin(qs,qe,ss,mid,2*si+1),getmin(qs,qe,mid+1,se,2*si+2));

//  }
 ll int getxor(int qs,int qe,int ss,int se,int si)
 {
      if(se<qs||ss>qe)
      return 1;

      if(qs<=ss&&qe>=se)
      return tree[si];
      
      int mid=(ss+se)/2;

      return getxor(qs,qe,ss,mid,2*si+1)^getxor(qs,qe,mid+1,se,2*si+2);
 }
 void solve()
 {
    ll int n,q;
    cin>>n>>q;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int ans=cst(0,n-1,0,arr);
    // for(int i=0;i<4*n;i++)
    // cout<<tree[i]<<endl;
    while(q--)
    {
        int qs,qe;
        cin>>qs>>qe;
         cout<<getxor(qs-1,qe-1,0,n-1,0)<<endl;
    }
    tree.clear();
 }

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

tree.clear();
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

