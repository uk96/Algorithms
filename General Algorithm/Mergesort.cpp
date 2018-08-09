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
ll a[1000005],MAX=1000005,i,j,k;
void merge(int low,int mid,int high)
{
    vector<ll> left,right;
    for(i=low;i<=mid;i++)
        left.push_back(a[i]);
    for(i=mid+1;i<=high;i++)
        right.push_back(a[i]);
    left.push_back(MAX);
    right.push_back(MAX);
    i=low;j=0;k=0;
    while(left[j]!=MAX||right[k]!=MAX)
    {
        if(left[j]<=right[k])
            a[i++]=left[j++];
        else
            a[i++]=right[k++];
    }
}
void mergesort(int low,int high)
{
    if(low<high)
    {
        ll mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}
 
int main() {
	// your code goes here
	ll n;
	cin>>n;
	for(i=0;i<n;i++)
	    in(a[i]);
	mergesort(0,n-1);
	for(i=0;i<n;i++)
	    out(a[i]);
	return 0;
} 