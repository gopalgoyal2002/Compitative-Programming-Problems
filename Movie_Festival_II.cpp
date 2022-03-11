#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}
int main()
{
    ll int n,k;
    cin>>n>>k;
    vector<pair<ll int,ll int>>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
       cin>>v[i].second;
    }
   sort(v.begin(),v.end(),cmp);
   ll int ans=0;
   multiset<int>m;
   for(int i=0;i<k;i++)
   m.insert(0);
   for(int i=0;i<n;i++)
   {
       auto it=m.upper_bound(v[i].first);
       if(it==m.begin())
       continue;
       else
       { it--;
           m.erase(it);
           m.insert(v[i].second);
           ans++;
       }
   }
   cout<<ans<<endl;
   return 0;
}