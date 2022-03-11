#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

   set<pair<int,int>>set;
   for(int i=0;i<k;i++)
   {
       set.insert({v[i],i});
   }
   if(k%2!=0)
   {
       auto it=set.begin();
        advance(it, k/2);
        
      cout<<it->first<<" ";
      for(int i=k;i<n;i++)
      {
          set.erase({v[i-k],i-k});
          set.insert({v[i],i});
           auto it=set.begin();
        advance(it, k/2);
        
      cout<<it->first<<" ";
      }
   }
   else
   {
       auto it=set.begin();
       auto it2=set.begin();
        advance(it, k/2);
        advance(it2, k/2-1);
        cout<<(it->first+it2->first)/2<<" ";
        for(int i=k;i<n;i++)
      {
          set.erase({v[i-k],i-k});
          set.insert({v[i],i});
     auto it=set.begin();
       auto it2=set.begin();
        advance(it, k/2);
        advance(it2, k/2-1);
        cout<<(it->first+it2->first)/2<<" ";
      }
      return 0;
   }


}