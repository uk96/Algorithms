#include <iostream>
#include<set>
#include<math.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll n,i,j,k;
	cin>>n;
	ll prime[100000];
	for(i=0;i<100000;i++)
	    prime[i]=0;
	prime[1]=1;
	ll val=sqrt(100000);
	for(i=2;i<val;i++)
	{
	    if(prime[i]==0)
	    {
	        for(j=(i*i);j<100000;j=j+i)
	            prime[j]=1;
	    }
	}
	for(i=1;i<=n;i++)
	{
	  if(prime[i]==0)
	    cout<<i<<" ";
	}
	return 0;
}