
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
  ll int n,m;
  cin>>n>>m;
  set<pair<int,int>>set;
  for(int i=0;i<n;i++)
  {  int x;
  cin>>x;
      set.insert({x,i});
  }
  while(m--)
  {
       int x;
       cin>>x;
      auto it=set.lower_bound({x+1,0});
      if(it==set.begin())
      {
           cout<<-1<<endl;
      }
      else
      {   it--;
             pair<int,int>p=*it;
             cout<<p.first<<endl;
             set.erase(it);
      }
  }
}