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
vector<int> v2={0,20,30,40,25,15};
int n=5;
void max_heapify(int index)
{
    int left= index<<1;
    int right= (index<<1)+1;
    int largest=index;
    if(left<=n&&v2[left]>v2[largest])
        largest=left;
    if(right<=n&&v2[right]>v2[largest])
        largest=right;
    if(largest!=index)
    {
        swap(v2[largest],v2[index]);
        max_heapify(largest);
    }
}
void build_heap()
{
    for(int i=n/2;i>0;i--)
        max_heapify(i);        
}
int top()
{
    return v2[1];
}
void remove_top()
{
    if(n==0)
        return;
    v2[1]=v2[n];
    v2.pop_back();
    n--;
    max_heapify(1);
}
void insert(int value)
{
    v2.push_back(value);
    n++;
    int parent=n>>1,index=n;
    while(parent>0&&v2[parent]<v2[index])
    {
        swap(v2[parent],v2[index]);
        index=parent;
        parent=index>>1;
    }
}
int main() {
    vector<int> v1 = {20,30,40,25,15}; 

    make_heap(v1.begin(), v1.end()); 
    
    build_heap();

    cout <<v1.front()<<" "<<top()<<endl; 
       
    v1.push_back(50); 

    insert(50);
     
    push_heap(v1.begin(), v1.end()); 

    cout<<v1.front()<<" "<<top()<<endl; 
 
    pop_heap(v1.begin(), v1.end()); 

    v1.pop_back(); 
    remove_top();

    cout <<v1.front()<<" "<<top()<<endl; 

    sort_heap(v1.begin(), v1.end()); 
      
    for (int x:v1)  
       cout <<x<<" "; 
    return 0;
}
