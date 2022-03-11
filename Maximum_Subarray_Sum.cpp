#include<bits/stdc++.h>
using namespace std;

 int main()
{
    int n;
    cin>>n;
  
    long long int ans=-1e18;
long long int sum=-1e18;
    for(int i=0;i<n;i++)
    {  
       long long int x;
       cin>>x;
       sum=max((long long)x,(long long)sum+x);
       ans=(long long)max(ans,sum);
    }
    // for(int i=0;i<=n;i++)
    // cout<<dp[i]<<endl;
    cout<<ans;
    return 0;
}