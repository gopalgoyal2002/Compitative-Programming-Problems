#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
  ll int n,k;
    cin>>n>>k;
   vector<ll int>v(n);
    ll int sum=0;
   for(int i=0;i<n;i++)
   cin>>v[i],sum+=v[i];

   ll int low=1;
  ll int high=sum;
  ll int mid;
  ll int ans;
   while(low<=high)
   {
    mid=(low+high)/2;
   ll int count=0;
       ll int s=0;
        bool flag=false;
    for(int i=0;i<n;i++)
    {
        s+=v[i];
        if(v[i]>mid)
        {
           flag=true;
           break;
        }
        if(s>mid)
        {
            s=v[i];
            count++;
        }
    }
    if(count+1<=k&&flag==false)
    {   ans=mid;
        high=mid-1;
    }
    else
    low=mid+1;

   }
   cout<<ans<<endl;

   return 0;


}