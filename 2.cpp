#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    return p1.first>p2.first; 
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        pair<int,int>arr[n];
    for(int i=0;i<n;i++)
    {
       int x;
       cin>>x;
       arr[0].first=x;
       arr[0].second=i;
    }
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)
    cout<<arr[i].first;

    

    }
}