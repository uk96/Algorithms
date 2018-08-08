#include<iostream>
#include<vector>
using namespace std;
#define ll long long

vector<ll> graph[1000];
bool visited[1000];

void dfs(ll current_node)
{
	if(!visited[current_node])
	{
		visited[current_node]=true;
		cout<<current_node<<" ";
		for(auto neighbour=graph[current_node].begin();neighbour!=graph[current_node].end();neighbour++)
			dfs(*neighbour);
	}	
}

int main()
{
	ll vertex,i,j,k;
    cin>>vertex;
	ll edges;
	cin>>edges;
	while(edges--)
	{
		ll vertex1,vertex2;
		cin>>vertex1>>vertex2;
		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}
	ll start_node;
	cin>>start_node;
	for(i=1;i<=vertex;i++)
		visited[i]=false;
	dfs(start_node);
	return 0;
}