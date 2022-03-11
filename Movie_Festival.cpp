#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}
int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>>v(n);
  for(int i=0;i<n;i++)
  {
      int a,b;
      cin>>a>>b;
      v[i]={a,b};
  }
  sort(v.begin(),v.end(),cmp);
s
  int ans=1;
  int j=v[0].second;
  for(int i=1;i<n;i++)
  {
     if(v[i].first>=j)
     {j=v[i].second;
     ans++;
     }
  }
  cout<<ans<<endl;
 
}