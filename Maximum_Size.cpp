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
int black(vector<string> &A)
{
	int n = A.size();
	int m = A[0].length();
	vector<vector < int>> Graph(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x = (A[i][j] == '1') ? 1 : 0;
			Graph[i].push_back(x);
		}
	}

	bool visited[n][m];
	int ans = 0;
    priority_queue<int>p;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			queue<pair<int, int>> Q;
			if (Graph[i][j] == 1 && !visited[i][j])
			{
				ans++;
				Q.push(make_pair(i, j));
				visited[i][j] = true;\
                int res=0;
				while (!Q.empty())
				{
					pair<int, int> crr = Q.front();
					Q.pop();
                    res++;
					int x = crr.first;
					int y = crr.second;
					vector<pair<int, int>> conn_comp;
					if (x - 1 >= 0 && Graph[x - 1][y] == 1) conn_comp.push_back(make_pair(x - 1, y));
					if (y - 1 >= 0 && Graph[x][y - 1] == 1) conn_comp.push_back(make_pair(x, y - 1));
					if (x + 1 < n && Graph[x + 1][y] == 1) conn_comp.push_back(make_pair(x + 1, y));
					if (y + 1 < m && Graph[x][y + 1] == 1) conn_comp.push_back(make_pair(x, y + 1));
					for (auto u: conn_comp)
					{
						int x1 = u.first;
						int y1 = u.second;
						if (visited[x1][y1])
						{
							continue;
						}
						Q.push(make_pair(x1, y1));
						visited[x1][y1] = true;
					}
				}
                p.push(res);
			}
		}
	}
   
    int count=1;
    ans=0;
   while(!p.empty())
    {  
    if(count%2==0)
    {
      ans+=p.top();
      p.pop();
    }
    else
    {   
        p.pop();
    }
    count++;
   }
  return ans;
	
}
void solve() {
int n, m;
cin>>n>>m;
vector<string>v;
for(int i=0;i<n;i++)
{
    string s;
    cin>>s;
    v.push_back(s);
}
cout<<black(v)<<endl;
// for(int i=0;i<n;i++)
// {
//     string s=v[i];
//     cout<<s;
// }
// priority_queue<int>pq;
// queue<pair<int,int>>q;
// vector<vector<bool>>vis(n,vector<bool>(m,false));
// int dx[]={1,0,-1,0};
//  int dy[]={0,1,0,-1};
// for(int i=0;i<n;i++)
// {
//     for(int j=0;j<m;j++)
//     {
//         if(v[i][j]=='1'&&vis[i][j]==false)
//         {
//             int res=0;
//             q.push({i,j});
//             vis[i][j]=true;
//             while(!q.empty())
//             {
//                 pair<int,int>curr=q.front();
//                 int x=curr.first;
//                 int y=curr.second;
//                 q.pop();
//                 res++;
//                for(int m=0;m<4;m++)
//                {
//                    int xpos=dx[m]+x;
//                    int ypos=dy[m]+y;
//                    if(xpos>=0&&xpos<n&&ypos>=0&&ypos<m&&vis[xpos][ypos]==false&&v[xpos][ypos]=='1')
//                    {
//                        q.push({xpos,ypos});
//                        vis[xpos][ypos]=true;
//                    }
//                }
               
//             }
//             pq.push(res);
//         }
//     }
//}
// int ans=0;
// int count=1;
// while(!pq.empty())
// {
//     cout<<pq.top();
//     pq.pop();
// }

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

