#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int y,k,n;
   cin>>y>>k>>n;
     int x=y/k;
     if(y+x*2>n)
     {
         cout<<-1;
         return 0;
     }
  
    long long int v=k;
       int i=2;
       while(v<=n)
       {
           if(v<=y)
           {
                v=k*i;
                 i++;
           }
           else{
               cout<<v-y<<" ";
                  v=k*i;
                     i++;
           }
         
          
   }
  return 0;
}