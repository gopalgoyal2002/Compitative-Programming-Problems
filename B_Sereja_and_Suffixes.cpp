#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
   unordered_set<int>s;
   vector<int>dp(n);
    for(int i=0;i<n;i++)
  {  cin>>v[i];}
  for(int i=n-1;i>=0;i--)
  {
     s.insert(v[i]);
    int x=s.size();
    dp[i]=x;
  }
//   for(int i=0;i<n;i++)
//   cout<<dp[i];
  while(m--)
  {
      int x;
      cin>>x;
      cout<<dp[x-1]<<endl;
  }


}