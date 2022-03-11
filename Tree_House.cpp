#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
using pii=pair<int,int>;
template<typename T>
using prior=std::priority_queue<T,vector<T>,greater<T>>;
#define X first
#define Y second
#define eb emplace_back
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
// mt19937_64 fastIO() ios_base::sync_with_stdio(0),cin.tie(0)

// inline int getRand(int L,int R)
// {
//     if(L>R)
//     swap(L,R);
//     return (int)(rng()%(uint64_t)(R-L+1)+1);
// }
template<typename T>
ostream& operator<<(ostream &os,vector<T> vec)
{
    for(int i=0;i<vec.size();++i)
    {
        if(i)os<<" ";
        os<<vec[i];
    }
    return os;
}
const int maxn=3E5+5;
const int mod=1E9+7;

vector<int>adj[maxn],subval,val;
vector<pii>ch;
void dfs(int now,int lst = -1)
{
    for(auto x:adj[now])
    {
        if(x==lst)
        continue;
        dfs(x,now);
    }
    ch.clear();
    for(auto x:adj[now])
    {
        if(x!=lst) ch.eb(subval[x],x);
    }
    sort(RALL(ch));
    int tok=1;
    for(auto x: ch)val[x.second]=tok++;
    for(auto x:adj[now])
    {
        if(x!=lst)subval[now]+=val[x]*subval[x];
    }
}
void solve()
{
    int N,X;
    cin>>N>>X;
    subval.assign(N,1),val.assign(N,0);
    for(int i=0;i<N;++i)
    vector<int>().swap(adj[i]);
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
       --u;
       --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout<<subval[0]%mod*X%mod<<endl;
}
int32_t main()
{
    int t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;

}