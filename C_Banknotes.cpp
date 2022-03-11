
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
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
typedef vector<int>		vi;
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
int mpow(ll int base,ll int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];

//==================================BINARY INDEX TREE===============================
// void update(vl & bt,int a,int val){
    
//      for(int i=a;i<bt.size();i+=i&(-i)){
//          bt[i]+=val;
//      }
//     //  if(a==1)
//     //  return ;
    
// }
// int read(vl & bt,int x){
//     int sum=0;
//     while(x>0){
//         sum+=bt[x];
//         x-=(x&-x);
//     }
//     return sum;
// }
//==================================BINARY INDEX TREE===============================
// long long min(ll a,ll b){
//     if(a<b)
//     return a;
//     else
//     return b;
// }
void solve(){
     ll n,k;
     cin>>n>>k;
     vl v(n);
     fo(i,n){
     cin>>v[i];
     v[i]=pow(10,v[i]);
     } 
    ll int ans=0;
    k++;
    for(int i=0;i<n-1;i++){
        if(k==0)
        break;
        ll int val=min(v[i+1]/v[i]-1,k);
        ans+=val*v[i];
        k-=val;
        
    }
    if(k>0)
    ans+=v[n-1]*k;
    cout<<ans<<endl;
}
int main(){
     
int t;
cin>>t;
while(t--)
solve();
}

int mpow(ll int base,ll int exp) {
 
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base);
    base = ((ll)base * base) ;
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
