#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
     ll int n,gb;
  cin>>n>>gb;
  vector<int>v(n);
  for(int i=0;i<n;i++)
  {
      int x;
      cin>>x;
      v[i]=x;
  }
// for(int i=0;i<n;i++)
// cout<<v[i];
  bool flag=true;
  stack<int>red;
  for(int i=0;i<n;i++)
  {   if(flag==false)
      {
          cout<<"NO"<<endl;
          return 0;
      }
      if(v[i]==v[i+1])
      {
          continue;
      }
      else if(v[i]<v[i+1])
      { if(red.empty()==true)
         {
             gb-=v[i+1]-v[i];
             if(gb<0)
             {
                 flag==false;
                 continue;
             }
         }
           int x=red.top();
         if(x+v[i]>v[i+1])
         {
             red.pop();
             red.push(x+v[i]-v[i+1]);
         }
         else if(x+v[i]<v[i+1])
         {
              red.pop();
             gb-=v[i+1]-x-v[i];
             if(gb<0)
             {
                 flag=false;
                 continue;
             }
         }
         else
         {
              red.pop();
         }
      }
      else
      {
        red.push(v[i]-v[i+1]);
      }
  }
  cout<<"YES"<<endl; 

    return 0;
}