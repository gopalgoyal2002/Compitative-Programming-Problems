#include <bits/stdc++.h>

using namespace std;



void sol()
{
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        long long int p,a,b,c;
        cin>>p>>a>>b>>c;
        long long int res=INT_MAX;
        
        long long n=1;
        while(n<0)
        {   if(((p-n*a)<0)&&((p-n*b)<0)&&((p-n*c)<0))
              break;
            if((p-n*a)>=0)
            res=min(res,(p-n*a));
            if((p-n*b)>=0)
            res=min(res,(p-n*b));
            if((p-n*c)>=0)
            res=min(res,(p-n*c));

   
        }
        cout<<res<<endl;

    }
}