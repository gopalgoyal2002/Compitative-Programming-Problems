#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {

   int t;
    cin >> t;
    while(t--) {
      	string s;
  
  cin>>s;
  if(s.length()<10)
  return false;
  int count=0;
  
for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') 
		count++;
			if (s[i] >= '0' && s[i] <= '9') 
		count++;
		if (s[i] >= 'a' && s[i] <= 'z') 
		count++;
}

if(count>=4)
return true;

return false;
    }

   
}