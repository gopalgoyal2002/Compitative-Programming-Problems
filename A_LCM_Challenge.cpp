#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll int lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
ll int maxx(ll int a,ll int b)
{
    if(a>b)
    return a;
    else
    return  b;
}
int main()
{
    ll int n;
    cin>>n;
     ll int ans=0;
    if(n<=2)
    {
        cout<<n<<endl;
    }
    else if(n==3)
    cout<<6;
  else
  {
      for(int i=n;i>n-10&&i>=1;i--)
      {
          for(int j=n;j>n-10&&j>=1;j--)
          {
              for(int k=n;k>n-10&&k>=1;k--)
              {
                ans=maxx(ans,lcm(i,lcm(j,k)));
              }
          }
      }
      cout<<ans<<endl;
    }
    return 0;
}