#include <iostream>
#include<map>
#include<set>
#include<vector>
#include<math.h>
using namespace std;
#define ll long long 
ll a[1000][1000],ans[1000][1000];
pair<ll,ll> source,destination;
ll visited[1000][1000],distance1[1000][1000];
pair<ll,ll> parent[1000][1000];
ll n,m;
ll infi=1000000;
ll right1[8]={-1,-1,-1,0,1,1,1,0};
ll left1[8]={-1,0,1,1,1,0,-1,-1};
ll heuristic1(ll x1,ll y1,ll x2,ll y2)
{
  return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
} 
void init()
{
  ll i,j;
  for(i=0;i<=n+1;i++)
  {
    for(j=0;j<=m+1;j++)
    {
      visited[i][j]=-1;
      distance1[i][j]=infi;
      parent[i][j]=make_pair(-1,-1);
      a[i][j]=0;
      ans[i][j]=0;
    }
  }
  
}
void input()
{
  ll i,j;
  cout<<"Enter Grid:"<<endl;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      cin>>a[i][j];
    }
  }
  cout<<"Enter Source Node:";
  cin>>source.first>>source.second;
  cout<<"Enter Destination Node:";
  cin>>destination.first>>destination.second;
}
void track()
{
  pair<ll,ll> temp=destination;
  a[temp.first][temp.second]=2;
  while(parent[temp.first][temp.second].first!=-1&&parent[temp.first][temp.second].second!=-1)
  {
    temp=parent[temp.first][temp.second];
    a[temp.first][temp.second]=2;
  }
}
void display()
{
    ll i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<" ---";
        cout<<endl;
        cout<<"|";
        for(j=1;j<=m;j++)
        {
            if(a[i][j]==2)
                cout<<" P ";
            else if(a[i][j]==1)
                cout<<"   ";
            else
                cout<<" X ";
            cout<<"|";
        }
        cout<<endl;
    }
    for(j=1;j<=m;j++)
            cout<<" ---";
    cout<<endl;
}
void a_star()
{
  ll i,j,k;
  map<pair<ll,ll>,vector<pair<ll,ll>>> v;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      for(k=0;k<8;k++)
      {
        if(a[i+right1[k]][j+left1[k]]==1)
        {
          pair<ll,ll> cur=make_pair(i,j),des=make_pair(i+right1[k],j+left1[k]);
          v[cur].push_back(des);
        }
      }
    }
  }
  set<pair<ll,pair<ll,ll>>> qu;
  distance1[source.first][source.second]=0+heuristic1(source.first,source.second,destination.first,destination.second);
  qu.insert(make_pair(distance1[source.first][source.second],source));
  ll flag=0;
  while(qu.size()&&flag==0)
  {
    auto it=qu.begin();
    pair<ll,pair<ll,ll>> pi=*it;
    qu.erase(it);        
    if(visited[pi.second.first][pi.second.second]==1)
      continue;
    visited[pi.second.first][pi.second.second]=1;
    pair<ll,ll> current=make_pair(pi.second.first,pi.second.second);
    ll value=pi.first-heuristic1(pi.second.first,pi.second.second,destination.first,destination.second);
    for(auto u : v[current])
    {
        if(u.first==destination.first&&u.second==destination.second)
        {
          parent[u.first][u.second]=current;
          flag=1;
          break;
        }
        if((value+1+heuristic1(u.first,u.second,destination.first,destination.second))<distance1[u.first][u.second])
        {
          parent[u.first][u.second]=current;
          distance1[u.first][u.second]=value+1+heuristic1(u.first,u.second,destination.first,destination.second);
          qu.insert(make_pair(distance1[u.first][u.second],u));
        }
    }
  }
  track();
  display();
}
int main() {
  // your code goes here
  cout<<"Enter Dimensions of Grid:";
  cin>>n>>m;
  init();
  input();
  if(a[source.first][source.second]==0||a[destination.first][destination.second]==0)
    cout<<"Traversal not possible"<<endl;
  else
    a_star();
  return 0;
}
/*
Output:
Enter Dimensions of Grid: 9 10
Enter Grid:
 1 0 1 1 1 1 0 1 1 1
 1 1 1 0 1 1 1 0 1 1 
 1 1 1 0 1 1 0 1 0 1 
 0 0 1 0 1 0 0 0 0 1 
 1 1 1 0 1 1 1 0 1 0 
 1 0 1 1 1 1 0 1 0 0 
 1 0 0 0 0 1 0 0 0 1 
 1 0 1 1 1 1 0 1 1 1 
 1 1 1 0 0 0 1 0 0 1
Enter Source Node: 1 1
Enter Destination Node: 9 10
 --- --- --- --- --- --- --- --- --- ---
| P | X |   |   |   |   | X |   |   |   |
 --- --- --- --- --- --- --- --- --- ---
|   | P |   | X |   |   |   | X |   |   |
 --- --- --- --- --- --- --- --- --- ---
|   |   | P | X |   |   | X |   | X |   |
 --- --- --- --- --- --- --- --- --- ---
| X | X | P | X |   | X | X | X | X |   |
 --- --- --- --- --- --- --- --- --- ---
|   |   | P | X |   |   |   | X |   | X |
 --- --- --- --- --- --- --- --- --- ---
|   | X |   | P | P |   | X |   | X | X |
 --- --- --- --- --- --- --- --- --- ---
|   | X | X | X | X | P | X | X | X |   |
 --- --- --- --- --- --- --- --- --- ---
|   | X |   |   |   | P | X | P | P |   |
 --- --- --- --- --- --- --- --- --- ---
|   |   |   | X | X | X | P | X | X | P |
 --- --- --- --- --- --- --- --- --- ---

*/
