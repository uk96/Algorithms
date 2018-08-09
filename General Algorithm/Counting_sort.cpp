#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
#define ll long long
#define in(a) scanf("%lld",&a)
#define out(a) printf("%lld\n",a)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)


int main() {
	// your code goes here
	ll n,max_size=1000001,i,j,k;
	cin>>n;
	ll count[max_size];
	for(i=0;i<max_size;i++)
	    count[i]=0;
	for(i=0;i<n;i++)
	{
	    in(k);
	    count[k]++;
	}
	for(i=0;i<1000001;i++)
	{
	    while(count[i]--)
	        out(i);
	}
	return 0;
} 