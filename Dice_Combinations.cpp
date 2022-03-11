#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1'000'000'007;
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

int main()
{
   ll int n;
    cin>>n;
  ll int dp[n+1];
  for(int i=0;i<=n;i++)
  dp[i]=0;
dp[0]=1;

  for(int i=1;i<=n;i++)
  {     int j=i-1;
      while(j>=0&&j>=i-6)
      {
          dp[i]=(dp[i]%mod+dp[j]%mod)%mod;
          j--;
      }
  }
  cout<<dp[n]<<endl;
  return 0;
   
}