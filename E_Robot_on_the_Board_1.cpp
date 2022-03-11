#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
  int n,m;
  cin>>n>>m;
 string s;
 cin>>s;
 int x=1,y=1;
 for(int i=s.size()-1;i>=0;i--){
   if(s[i]=='L'&&x<m)x++;
   if(s[i]=='R'&&x>1)x--;
   if(s[i]=='U'&&y<n)y++;
   if(s[i]=='D'&&y>1)y--;
   
 }
 cout<<y<<" "<<x<<endl;
}
}
