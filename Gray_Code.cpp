#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
   string s="";
   for(int i=0;i<n;i++)
   s+='0';
   vector<string>v;
//    v.push_back(s);
   queue<string>q;
   set<string>set;
   set.insert(s);
   q.push(s);
   while(!q.empty())
   {   string g,temp=q.front();
      g=temp;
      q.pop();
       v.push_back(temp);
       for(int i=n-1;i>=0;i--)
       {
           if(g[i]=='0')
           {
               g[i]='1';
               if(set.find(g)==set.end())
               {
                   set.insert(g);
                  q.push(g);
              
                   break;
               }
           }
           else
           {
                g[i]='0';
               if(set.find(g)==set.end())
               {     q.push(g);
                   set.insert(g);
                 
                   break;
               }
           }
                g=temp;
       }
   }
   for(int i=0;i<v.size();i++)
   {
       string se=v[i];
       cout<<se<<endl;
   }
    return 0;
}