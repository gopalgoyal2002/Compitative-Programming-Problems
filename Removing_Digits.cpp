#include<bits/stdc++.h>
using namespace std;

int ans=0;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<vector<bool>>vis(1000,vector<bool>(1000,false));
void dfs(int i, int j,vector<string>&v,int n,int m){
   
    vis[i][j]=true;
    for(int k=0;k<4;k++)
    {
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&y>=0&&x<n&&y<m&&v[x][y]=='.'&&vis[x][y]==false)
        {
               dfs(x,y,v,n,m);
        }
    }

}
void solve() {
   int n,m;
   cin>>n>>m;
   ans=0;
   
   vector<string>v(n);
   for(int i=0;i<n;i++)
   {
   cin>>v[i];
   }

   for(int i=0;i<n;i++)
   {  
       for(int j=0;j<m;j++)
       {
           if(vis[i][j]==false&&v[i][j]=='.')
           {
            dfs(i,j,v,n,m);
            ans++;
           }
       }

   }
   cout<<ans<<endl;
  
}
int main() {
   
  
      solve();
    
    


    return 0;
}