#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int n;
     cin>>n;
     string arr[n];
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
     unordered_set<string>mp1;
     for(int i=0;i<n;i++)
     mp1.insert(arr[i]);
  
     unordered_set<string>mp2;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(i!=j)
             {
                 string str=arr[i];
                 string str1=arr[j];
               str1[0]=str[0];
               if(mp1.find(str1)==mp1.end())
               {
                  mp2.insert(str1);
                  
               }

             }
         }
     }
    return  mp2.size();
   }
}