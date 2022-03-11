#include<bits/stdc++.h>
using namespace std;
void solve()
{
   long long int k;
   cin>>k;
   long long int n=1;
   while((n+1)*(n+1)<k)
   {
       n++;
   }
   if(n*n==k&&k==1)
   {
       cout<<n<<" "<<n<<endl;
       return ;
   }
   int i=n+1;
   int j=n+1;
   int remain=k-n*n;
   if(remain<i)
   {
       int row=remain;
       int col=j;
       cout<<row<<" "<<col<<endl;
   }
   else{
       int row=i;
       int col=remain-n-1;
       col=n-col+1;
       cout<<row<<" "<<col<<endl;
   }

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