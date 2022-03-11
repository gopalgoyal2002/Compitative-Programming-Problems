#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    set<int>s;
    int ans=0;
    int i=0,j=0;
    int curr=0;
    while(i<n&&j<n)
    {
            if(s.find(arr[i])!=s.end()&&!s.empty())
           { 
               while(arr[j]!=arr[i]&&j<n&&j<=i)
               {
                     s.erase(arr[j]);
                   j++;
                   curr--;
                 
               }
                 s.erase(arr[j]);
               j++;
             
              
           }
           else
           {
               s.insert(arr[i]);
               i++;
               curr++;
               ans=max(ans,i-j);
           }
          
    }
    cout<<ans<<endl;
    return 0;
}