#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
   int f=0;
   while(n%7!=0)
   {
       n=n-4;
       f++;
       if(n<0)
       {
           cout<<-1;
           return 0;
       }
   }
   while(f--)
   cout<<4;
   while(n!=0)
   {
       cout<<7;
       n=n-7;
   }
  
    return 0;
}