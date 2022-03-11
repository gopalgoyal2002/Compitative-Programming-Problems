#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
 
   int n,k;
   cin>>n>>k;
   vector<ll>v(n+1);
   for(int i=1;i<=n;i++)
   cin>>v[i];

   ll  dp[n+1][k+1]={INT_MIN};
   ll  m[n+1][k+1]={INT_MIN};
   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=k;j++)
       {
           dp[i][j]=-1e18;
           m[i][j]=-1e18;
       }
   }

   for(int i=0;i<=n;i++)
   {
        dp[i][0]=0;
        m[i][0]=0;
   }
   dp[1][1]=v[1];
   m[1][1]=v[1];
   for(int i=2;i<=n;i++)
   {
       for(int j=1;j<=k;j++)
       {
            if(i<j)
            dp[i][j]=-1e18;
            else
            {
                dp[i][j]=dp[i-1][j]+v[i]*j;
                dp[i][j]=max(dp[i][j],(m[i-1][j-1]+v[i]*j));
            }
            m[i][j]=max(m[i-1][j],dp[i][j]);
       }
   }
   ll ans=dp[1][k];
   for(int i=1;i<=n;i++)
   {
       ans=max(ans,dp[i][k]);
   }
   cout<<ans<<endl;

}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--) solve();
}