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
    ll n,i,j,k;
    while(cin>>n,n>0)
    {
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        ll ans=0;
        stack<ll> s;
        for(i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.push(i);
                continue;
            }
            while(!s.empty())
            {
                if(a[s.top()]<=a[i])
                    break;
                ll val=s.top(),temp;
                s.pop();
                if(s.empty())
                    temp=a[val]*i;
                else
                    temp=a[val]*(i-s.top()-1);
                ans=max(temp,ans);
            }
            s.push(i);
        }
        while(!s.empty())
        {
            ll val=s.top(),temp;
            s.pop();
            if(s.empty())
                temp=a[val]*i;
            else
                temp=a[val]*(i-s.top()-1);
            ans=max(temp,ans);
        }
        cout<<ans<<endl;
    }
	return 0;
}
