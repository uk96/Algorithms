#include <iostream>
#include<vector>
#include<map>
#include<set>
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
//https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
int main() {
	// your code goes here
    ll t,i,j,k;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=n-1;i>0;i--)
            if(a[i]>a[i-1])
                break;
        if(i==0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(j=n-1;j>=i;j--)
            if(a[j]>a[i-1])
                break;
        swap(a[i-1],a[j]);
        j=n-1;
        while(i<j)
            swap(a[i++],a[j--]);
        for(i=0;i<n;i++)
            cout<<a[i];
        cout<<endl;
    }
	return 0;
}
