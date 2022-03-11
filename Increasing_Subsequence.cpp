#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll int>ans;

ll int pos(ll int num)
{
    int low=0;
    int high=ans.size()-1;
    int mid;
    int n=ans.size();
    int a;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(ans[mid]<num)
        low=mid+1;
        else
        {
        high=mid-1;
        a=mid;
        }
    }
    return a;
}


int main()
{  
    ans.clear();
   ll int n;
   cin>>n;
 vector<ll int> v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];

//   for(int i=0;i<n;i++)
//   cout<<v[i];
  ans.push_back(v[0]);
  for(int i=1;i<n;i++)
  { 
      if(ans[ans.size()-1]<v[i])
      {
          ans.push_back(v[i]);
      }
      else
      {
          int x=pos(v[i]);
          ans[x]=v[i];
      }

  }
  cout<<ans.size()<<endl;
  return 0;
}