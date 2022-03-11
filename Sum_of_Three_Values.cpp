#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
   ll  int n,sum;
    cin>>n>>sum;
    vector<pair<ll int,ll int>>v(n);
    for(int i=0;i<n;i++)
    {
    cin>>v[i].first,v[i].second=i;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        int j=i+1,k=n-1;
        int val=sum-v[i].first;
        while(j<k)
        {
            if(v[j].first+v[k].first==val)
            {
                cout<<v[i].second+1<<" "<<v[j].second+1<< " "<<v[k].second+1<<endl;
                return 0;
            }
            else if(v[j].first+v[k].first>val)
            k--;
            else
            j++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}