#include<bits/stdc++.h>
using namespace std;
 int N=80000;
vector<int>tree(N,0);
void cst(int ss,int se,int si)
{
    if(ss=se)
    {
        tree[si]=1;
        return ;
    }
    int mid=(ss+se)/2;
    cst(ss,mid,2*si+1);
    cst(mid+1,se,2*si+2);
}
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    vector<int>ans(n+1,0);
      map<int,int>mp;
    for(int i=0;i<n;i++)
    { 
    cin>>v[i];
   mp[v[i]]++;
   ans[i+1]=mp.size();
    }
    for(int i=0;i<n+1;i++)
    cout<<ans[i]<<" ";
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        cout<<ans[b]-ans[a-1]<<endl;
    }
    return 0;

    
}