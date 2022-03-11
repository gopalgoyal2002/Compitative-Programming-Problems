#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
 
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g

#define index_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
int main()
{
   int n;
   int q;

   cin >>n;
   cin>>q;
   vector<int>v(n);
   
  index_set p;
   for(int i=0;i<n;i++)
   {
       cin>>v[i];
     p.insert(v[i]);
   }
   while(q--)
   { 

       char x;
       cin>>x;
       if(x=='?')
       {
            int a,b;
            cin>>a>>b;
              //cout<<p.order_of_key(b)<<endl;
              //cout<<p.order_of_key(a)<<endl;
            cout<<p.order_of_key(b+1)-p.order_of_key(a)<<endl;
       }
       else
       {
           int a,b;
            cin>>a>>b;
            a--;
            int x=p.order_of_key(v[a]);
            v[a]=b;
            auto it=p.find_by_order(x);
            p.erase(it);
            p.insert(b);
       }
   }
   return 0;
}