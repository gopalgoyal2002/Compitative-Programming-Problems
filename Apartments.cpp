#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
   ll int n,m,k;
    cin>>n>>m>>k;
    vector<ll int>v(n);
    vector<ll int>apart(m);
    for(int i=0;i<n;i++)
    cin>>v[i];
    for(int i=0;i<m;i++)
    {
     cin>>apart[i];
    }
    sort(apart.begin(),apart.end());
    sort(v.begin(),v.end());
    int j=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ll int val=v[i];
        while(j<m&&apart[j]<val-k)
        j++;

        if(j<m&&apart[j]<=val+k)
        ans++,j++;
    }
    cout<<ans<<endl;
    return 0;

}