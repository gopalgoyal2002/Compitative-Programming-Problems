#include<bits/stdc++.h>
using namespace std;
const int N=800000;
#define ll long long
vector<ll int> tree(N);
 ll cst(int ss,int se,int si,vector<ll int>&arr)
 {
     if(ss==se)
     {
         tree[si]=arr[ss];
         return arr[ss];
     }
     int mid=(ss+se)/2;
     tree[si]=cst(ss,mid,2*si+1,arr)+cst(mid+1,se,2*si+2,arr);
     return tree[si];
 }
ll int getsum(int qs, int qe, int ss, int se, int si)
{
	if(se < qs || ss > qe)
		return 0;
	if(qs <= ss &&  qe >= se)
		return tree[si];
 
	ll int mid = (ss + se) / 2;
 
	return getsum(qs, qe, ss, mid, 2 * si + 1)
		   + getsum(qs, qe, mid + 1, se, 2 * si + 2);
}
void update(int l,int r,int ss,int se,int si,ll int val)
 {
    if(l>se||r<ss||ss>se)
    return ;
    
     if(ss==se)
     {
      tree[si]+=val;
      return ;
     }
    int mid=(ss+se)/2;
     update(l,r,ss,mid,2*si+1,val);
     update(l,r,mid+1,se,2*si+2,val);
     tree[si]=tree[2*si+1]+tree[2*si+2];
    
 }
int main()
{
    
    int n,q;
    cin>>n>>q;
    vector<ll int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
   ll int a=cst(0,n-1,0,v);
    // for(int i=0;i<4*n;i++)
    // cout<<tree[i]<<" "<<endl;
    while(q--)
    {
       ll int u;
        cin>>u;
        if(u==1)
        {   ll int a,b,val;
        cin>>a>>b>>val;
        a--;
        b--;
            update(a,b,0,n-1,0,val);
        //         for(int i=0;i<4*n;i++)
        //  cout<<tree[i]<<" "<<endl;
        }
        else if(u==2)
        {
            ll int k;
            cin>>k;
            k--;
            cout<<getsum(k,k,0,n-1,0)<<endl;

        }
    }
    return 0;
}