#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<long long int,int>mp;
    long long int s=0;
    long long int ans=0;
    mp[0]++;
    for(int i=0;i<n;i++)
    {
        int xx;
        cin>>xx;
        s=(s+xx%n+n)%n;
      
      ans+=mp[s];
      mp[s]++;
    
    }
    cout<<ans<<endl;
    return 0;
}