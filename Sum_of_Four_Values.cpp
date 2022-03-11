#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
   
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[i].first=a,v[i].second=b;
    }
    sort(v.begin(),v.end());
    long long int ans=0;
   long long int t=0;
//    for(int i=0;i<n;i++)
//    cout<<v[i].first;
    for(int i=0;i<n;i++)
    {
  t+=v[i].first;
  ans+=v[i].second-t;
    }
    cout<<ans<<endl;
    return 0;
}