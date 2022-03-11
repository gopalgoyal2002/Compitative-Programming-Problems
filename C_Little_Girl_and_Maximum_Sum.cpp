#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=1;i<n;i++)
    {
          v[i]+=v[i-1];
    }
    long long int ans=0;
    while(q--)
    {
       int a,b;
       cin>>a>>b;
      ans+=v[b-1];
      ans-=v[a-1];
    }
    cout<<ans<<endl;
    return 0;

}