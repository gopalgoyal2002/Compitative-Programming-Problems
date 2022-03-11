// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
			tree_order_statistics_node_update>
	new_data_set;

int main()
{
   int n;
   cin >>n;
   vector<int>v(n);
   
   new_data_set p;
   for(int i=0;i<n;i++)
   {
      cin>>v[i];
     p.insert({i,v[i]});
   }
   while(n--)
   {  int x;
      cin>>x;
      x--;
       auto it=p.find_by_order(x);
     pair<int,int>pa=*it;
  cout<<pa.second<<" ";
  p.erase(it);
   }
   return 0;
}