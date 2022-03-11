#include<bits/stdc++.h>
using namespace std;
#define ll long long
// struct Node
// {   
//     int val;
//    Node *left,*right;
//     Node(int valu)
//     {  
//        val=valu,left=NULL,right=NULL;
//     }
// };
int main()
{   
    int t;
    cin>>t;
    while(t--)
    {  
        string s;
        cin>>s;
        
        vector<char>v;
        for(int i=0;i<s.length();i=i+2)
        {
            v.push_back(s[i]);
        }
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        int even=1,odd=0;
        int i=0;
       int j=0;
       
       
           int val=0;
           if(v[0]=='N')
           {
               cout<<0<<" ";
               return 0;
           }
          i=1;
           while(val!=0)
           {    int x=2*val;
               while(x--)
               {  int n=0;
                   if(i>=v.size())
                   break;
                  if(v[i]!='N')
                  {  
                     n++;
                  }
                  i++;
                  val=n;
               }
               j++;
               if(j%2==1)
               {odd+=val;}
               else
               even+=val;
           }
        cout<<min(even,odd)<<endl;
    }
   return 0;
}