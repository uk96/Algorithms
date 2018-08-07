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
ll a[50],n,value;
bool cal(ll cost,ll index)
{
    if(index>=n)
        return false;
    else if((cost+a[index])>value)
        return false;
    else if((cost+a[index])==value)
        return true;
    else 
        return cal(cost+a[index],index+1)||cal(cost,index+1);
}
int main() {
	// your code goes here
    ll t,i,j,k;
    in(t);
    while(t--)
    {
        in(n);in(value);
        for0(i,n)
            in(a[i]);
        sort(a,a+n);
        if(cal(0,0))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}
