#include<bits/stdc++.h>
using namespace std;
 
long long int res=INT_MAX;
long long int min(long long int a,long long int b)
{
    if(a>b)
    return b;
    else
    return a;
}
void subset(int index,vector<long long int>v,long long int sum,long long int val)
{
    
   long long  int s=sum-val;
    res=min(res,abs(val-s));
    for(int i=index+1;i<v.size();i++)
    {   val+=v[index];
        subset(i,v,sum,val);
        val-=v[index];
    }
}
int main()
{ 
    res=INT_MAX;
  long long int n;
   cin>>n;
   vector<long long int>v(n);
  long long int sum=0;
   for(int i=0;i<n;i++)
   {  
       cin>>v[i];
     sum+=v[i];   
    }
    for(int i=0;i<v.size();i++)
  subset(i,v,sum,0);
 
   cout<<res<<endl;
}