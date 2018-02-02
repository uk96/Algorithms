#include <iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
#define ll long long  
int main() {
	// your code goes here
    ll t,i,j,k;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n+1][n+1];
        for(i=1;i<=n;i++)
        {
          for(j=1;j<=n;j++)
          {
            a[i][j]=100000000000000000;
          }
        }
        for(i=1;i<=n;i++)
          a[i][i]=0;
        for(i=0;i<m;i++)
        {
            ll d,f,w;
            cin>>d>>f>>w;
            a[d][f]=w;
            a[f][d]=w;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
              cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
	return 0;
}