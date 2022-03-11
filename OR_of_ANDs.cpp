#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
vector<int>v;
bool arr[n+1]={false};
for(int i=1;i<n;i++)
{
  int x;
  cin>>x;
  v.push_back(x);
   arr[x]=true;
}
for(int i=1;i<=n;i++)
{
  if(arr[i]==false)
  cout<<i;
}

 
}