#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
   ll int n,k;
    cin>>n>>k;
    vector<ll int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
   long long int ans=0;
    ll int l=0,r=0;
    map<ll int,ll int>mp;
    while(l<n&&r<n)
    {
         mp[v[r]]++;
        
     
         while(mp.size()>k)
         {
            ll int x=v[l];
             l++;
             mp[x]--;
             if(mp[x]==0)
             mp.erase(x);
         }
       
        ans+=r-l+1;
           r++;
    }
    cout<<ans<<endl;
    return 0;
}