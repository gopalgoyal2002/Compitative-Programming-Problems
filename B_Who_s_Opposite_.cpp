#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int diff=max(a,b)-min(a,b);
    int total=diff*2;
    if(a>total||b>total||c>total)
    {
        cout<<-1<<endl;
        return ;
    }
    if(c+diff==total)
    cout<<(c+diff)<<endl;
    else
    cout<<(c+diff)%total<<endl;
    return ;
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