#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<complex>
using namespace std;
#define ll long long
#define in(a) scanf("%lf",&a)
#define out(a) printf("%lld\n",a)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define base complex<double>
const double PI = acos(-1);
void fft(vector<base>& a,bool inverse)
{
    ll n=a.size(),i,j,k;
    if(n==1)
        return;
    vector<base> a1(n/2),a2(n/2);
    for(i=0;(2*i)<n;i++)
    {
        a1[i]=a[2*i];
        a2[i]=a[(2*i)+1];
    }
    fft(a1,inverse);
    fft(a2,inverse);
    double angle=((2*PI)/n)*(inverse?-1:1);
    base w(1),wn(cos(angle),sin(angle));
    for(i=0;(2*i)<n;i++)
    {
        a[i]=a1[i]+(w*a2[i]);
        a[i+(n/2)]=a1[i]-(w*a2[i]);
        if(inverse){
            a[i]/=2;
            a[i+(n/2)]/=2;
        }
        w*=wn;
    }
}
vector<ll> multiply(vector<ll>& a,vector<ll>& b)
{
    ll n=1,i,j,k;
    vector<base> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    while (n < max(a.size(), b.size()))  
        n <<= 1;
    n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa,false);
    fft(fb,false);
    for(i=0;i<n;i++)
        fa[i]*=fb[i];
    fft(fa,true);

    vector<ll> result(n);
    for(i=0;i<n;i++)
        result[i]=round(fa[i].real());
    return result;
}

int main() {
    ll t,i,j,k;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n+1),b(n+1);
        for(i=n;i>=0;i--)
            cin>>a[i];
        for(i=n;i>=0;i--)
            cin>>b[i];
        vector<ll> result=multiply(a,b);
        for(i=(2*n);i>=0;i--)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
