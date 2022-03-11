#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
   long long int arr[n];
    long long int sum=0;
    long long int ans=0;
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    sum+=arr[i];
    }
    sort(arr,arr+n);
    sum=arr[n/2];
  
    for(int i=0;i<n;i++)
    {
        ans+=(long long)abs(arr[i]-sum);
    }
cout<<ans;
}