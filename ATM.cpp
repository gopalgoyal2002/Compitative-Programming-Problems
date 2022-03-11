#include <iostream>
#include<iomanip>
using namespace std;

int main() {
	double balance=0;
	long long int witrawl=0;
	cin>>witrawl>>balance;
      if(balance>=(witrawl+0.50) && witrawl%5==0)
	{
	        balance=balance-witrawl-0.50;
	        cout<<fixed<<setprecision(2) <<balance<<endl;
	}
	    else{
	        cout<<fixed<<setprecision(2) <<balance<<endl;
	    }
	
	return 0;
}