#include<bits/stdc++.h>
using namespace std;
const int N=800000;
#define ll long long

vector<int> tree(N);
vector<ll> v(N);
void cst(int ss,int se,int si)
 {
     if(ss==se)
     {
         
         tree[si]=v[ss];
         return ;
     }
     int mid=(ss+se)/2;
      cst(ss,mid,2*si+1);
      cst(mid+1,se,2*si+2);
     tree[si]=max(tree[2*si+1],tree[2*si+2]);
  
 }
// ll int getsum(int qs, int qe, int ss, int se, int si)
// {
// 	if(se < qs || ss > qe)
// 		return 0;
// 	if(qs <= ss &&  qe >= se)
// 		return tree[si];
 
// 	ll int mid = (ss + se) / 2;
 
// 	return getsum(qs, qe, ss, mid, 2 * si + 1)
// 		   + getsum(qs, qe, mid + 1, se, 2 * si + 2);
// }
// void update(int l,int r,int ss,int se,int si,ll int val)
//  {
//     if(l>se||r<ss||ss>se)
//     return ;
    
//      if(ss==se)
//      {
//       tree[si]+=val;
//       return ;
//      }
//     int mid=(ss+se)/2;
//      update(l,r,ss,mid,2*si+1,val);
//      update(l,r,mid+1,se,2*si+2,val);
//      tree[si]=tree[2*si+1]+tree[2*si+2];
    
//  }
int update(int ss,int se,int si,int val)
{
     if(ss==se) 
     {    v[ss]=v[ss]-val;
         tree[si]=v[ss];
         return  ss+1;
     }
     int k;
     int mid=(ss+se)/2;
     if(val<=tree[2*si+1])
     {
         k=update(ss,mid,2*si+1,val);
     }
     else
     {
          k=update(mid+1,se,2*si+2,val);
     }
     tree[si]=max(tree[2*si+1],tree[2*si+2]);
     return k;
}
int main()
{
     int n,q;
     cin>>n>>q;
    
     for(int i=0;i<n;i++)
     cin>>v[i];
   cst(0,n-1,0);
//    for(int i=0;i<4*n;i++)
//    cout<<tree[i]<<" ";
//    cout<<endl;
     while(q--)
     { 
         int x;
         cin>>x;
         if(tree[0]<x)
         cout<<"0"<<" ";
         else
         cout<<update(0,n-1,0,x)<<" ";
     }
     return 0;
   
    
}