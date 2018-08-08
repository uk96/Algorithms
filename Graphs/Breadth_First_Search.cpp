#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define ll long long
int main()
{
	ll vertex,i,j,k;
    cin>>vertex;
	
	vector<ll> graph[vertex+1];
	ll edges;
	cin>>edges;
	while(edges--)
	{
		ll vertex1,vertex2;
		cin>>vertex1>>vertex2;
		
		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}
	queue<ll> q;
	ll start_node;
	cin>>start_node;
	
	q.push(start_node);
	bool visited[vertex+1];
	
	for(i=1;i<=vertex;i++)
		visited[i]=false;
	cout<<"Breadth First Traversal:"<<endl;
	while(!q.empty())
	{
		ll current_node=q.front();
		q.pop();
		if(visited[current_node]==true)
			continue;
		visited[current_node]=true;
		
		cout<<current_node<<" ";
		
		for(auto neighbour=graph[current_node].begin();neighbour!=graph[current_node].end();neighbour++)
			q.push(*neighbour);
	}
	return 0;
}
