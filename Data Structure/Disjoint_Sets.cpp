#include<iostream>
using namespace std;
#define ll long long

ll rank_set[100005],parent[100005];

void init()
{
    ll i;
    for(i=0;i<100005;i++)
    {
        parent[i]=i;
        rank_set[i]=1;
    }
}
ll find_parent(ll val)
{
    while(parent[val]!=val)
    {
        val=parent[val];
    }
    return val;
}
void merge_set(ll l,ll r)
{
    l=find_parent(l);
    r=find_parent(r);
    if(rank_set[l]>rank_set[r])
    {
        rank_set[l]=rank_set[l]+rank_set[r];
        parent[r]=l;
    }
    else
    {
        rank_set[r]=rank_set[r]+rank_set[l];
        parent[l]=r;
    }
}
 
int main() {
	// your code goes here
    init();
    ll q;
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        merge_set(l,r);
    }
	return 0;
}  