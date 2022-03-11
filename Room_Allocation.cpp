#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,bool>a,pair<int,bool>b)
{
    if(a.first<b.first)
    return true;
    else if(a.first==b.first)
    {
        if(a.second==false)
        return false;
        else
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,bool>>v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,true});
        v.push_back({b,false});
    }
    sort(v.begin(),v.end(),cmp);
//     for(int i=0;i<2*n;i++)
//    cout<<v[i].first<<v[i].second<<endl;
    int count=0;
    int ans=0;
    for(int i=0;i<2*n;i++)
    {
            if(v[i].second==true)
            {
                count++;
                cout<<count;
                ans=max(ans,count);
            }
            else
            {
                count--;
            }
    }
    cout<<ans<<endl;
    return 0;
}