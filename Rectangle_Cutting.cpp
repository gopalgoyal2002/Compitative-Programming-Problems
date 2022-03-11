#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    long long int ans=0;
    while(a!=b)
    {
       int m=min(a,b);
       if(m==a)
       {
           b=b-m;
       }
       else
       {
           a=a-m;
       }
       ans++;
    }
    cout<<ans<<endl;
    return 0;
}