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
        ll n,m,start;
        cin>>n>>m>>start;
        vector<pair<ll,ll>> v[n+1];
        for(i=0;i<m;i++)
        {
            ll d,f,w;
            cin>>d>>f>>w;
            v[d].push_back(make_pair(f,2*w));
            v[f].push_back(make_pair(d,2*w));
        }
        ll distance[n+1],visited[n+1];
        for(i=0;i<=(n+1);i++)
        {
            distance[i]=100000000000000000;
            visited[i]=0;
        }
        set<pair<ll,ll>> qu;
        distance[start]=0;
        qu.insert(make_pair(0,start));
        while(qu.size())
        {
            auto it=qu.begin();
            pair<ll,ll> pi=*it;
            qu.erase(it);
            
            if(visited[pi.second]==1)
                continue;
            visited[pi.second]=1;
            for(auto u : v[pi.second])
            {
                if((distance[pi.second]+u.second)<distance[u.first])
                {
                    distance[u.first]=distance[pi.second]+u.second;
                    qu.insert(make_pair(distance[u.first],u.first));
                }
            }
        }
        for(i=1;i<=n;i++)
            cout<<distance[i]<<" ";
        cout<<endl;
    }
	return 0;
}