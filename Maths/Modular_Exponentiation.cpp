#include <iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
#define ll long long  

ll modular(ll x,ll y,ll m)
{
    if (y == 0)
        return 1;
    ll val=modular(x,y/2,m)%m;
    val=(val*val)%m;
    
    if(y%2 == 0)
        return val;
    else
        return (x*val)%m;
}
int main() {
	// your code goes here
    ll t,i,j,k;
    cin>>t;
    while(t--)
    {
      ll x,y,m;
      cin>>x>>y>>m;
      //Modular Exponentiation
      cout<<modular(x,y,m)<<endl;
      //Inverse modular
      cout<<modular(x,m-2,m)<<endl;
    }
	return 0;
}