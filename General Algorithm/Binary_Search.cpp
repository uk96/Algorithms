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
vector<int> v;
int binarySearch(int l, int r, int x) 
{ 
    if (l<=r) 
    { 
        int mid=(l+r)/2; 
        if (v[mid]==x) 
            return mid; 
        if (v[mid] > x) 
            return binarySearch(l, mid - 1, x);  
        return binarySearch(mid + 1, r, x); 
    } 
    return -1; 
} 

int main() {
    for(int i=100;i>0;i--)
        v.push_back(i);
    sort(v.begin(),v.end());
    //Search 50 will give 49 // 0-based indexing
    int val1=(int)(lower_bound(v.begin(),v.end(),50)-v.begin());
    cout<<"Search 50 will give "<<val1<<endl;
    //Search 50 will give 50 // 0-based indexing
    int val2=(int)(upper_bound(v.begin(),v.end(),50)-v.begin());
    cout<<"Search 50 wil give "<<val2<<endl;
    //Traditional Search 50 will give 50 // 0-based indexing
    int val3=binarySearch(0,100,50);
    cout<<"Search 50 wil give "<<val3<<endl;
    return 0;
}
