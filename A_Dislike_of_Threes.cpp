#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int k;
    cin>>k;
    int c=0;
    int n=1;
    while(c!=k)
    {
        if(n%3!=0&&n%10!=3)
        {
            c++;
        }
        n++;
    }
    cout<<n-1<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}