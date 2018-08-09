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
ll a[1000005];
ll partition(ll p,ll r)
{
    ll pivot=p+(rand()%(r-p+1));
    swap(a[pivot],a[r]);
    ll q=p,i;
    for(i=p;i<r;i++)
    {
        if(a[i]<=a[r])
            swap(a[q++],a[i]);
    }
    swap(a[q],a[r]);
    return q;
}
void quicksort(ll p,ll r)
{
    if(p<r)
    {
        ll q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}
int main() {
	// your code goes here
	ll n,i,j,k;
	in(n);
	for(i=0;i<n;i++)
	    in(a[i]);
	quicksort(0,n-1);
	for(i=0;i<n;i++)
	    out(a[i]);
	return 0;
}