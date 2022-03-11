
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
   ll int n,x;
    cin>>n>>x;
    vector<ll int>v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];

   sort(v.begin(),v.end());
//    reverse(v.begin(),v.end());

    int j=n-1;
    int i=0;
    int ans=0;
    while(i<=j)
    {
       if(v[i]+v[j]<=x)
       {
           ans++;
           i++;
           j--;
       }
       else if(v[j]<=x)
       {   ans++;
           j--;
       }
    }
    cout<<ans<<endl;
    return 0;

}