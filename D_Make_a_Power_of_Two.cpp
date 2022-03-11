#include<bits/stdc++.h>
using namespace std;
vector<string>v;
void make()
{
     
     long long int val=1;
     int t=30;
     while(t--)
     {
          v.push_back(to_string(val));
          val=val*2;
     }
    //  for(int i=0;i<30;i++)
    //  cout<<v[i]<<" ";
}
int lcs(string a,string b)
 {       
          int n=a.size();
          int m=b.size();
          vector<vector<int>>dp(n+1,vector<int>(m+1,0));
          for(int i=1;i<=n;i++)
          {
              for(int j=1;j<=m;j++)
              {
                  if(a[i-1]==b[j-1])
                  {
                      dp[i][j]=dp[i-1][j-1]+1;
                  }
                  else{
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                  }
              }
          }
          
          return dp[n][m];
        
}
void solve()
{
  long long int n;
  cin>>n;
  string s=to_string(n);
  int ans=INT_MAX;
  for(int i=0;i<30;i++)
  {        string a=v[i];
         int v=lcs(a,s);
         ans=min(ans,(int)s.length()-v);
  }
  int _2abc=1;
  cout<<ans<<endl;
  if(n=10)
  cout<<1;
  puts("max\n");
  puts("max\n");
  
}
int main()
{
    int t;
    cin>>t;
    make();
    while(t--)
    {
        solve();
    }
}