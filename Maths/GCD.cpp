#include <iostream>
using namespace std;
#define ll long long


ll gcd(ll l,ll r) {
    return r==0?l:gcd(r,l%r);
}


int main() {
	// your code goes here
	ll a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	return 0;
}
