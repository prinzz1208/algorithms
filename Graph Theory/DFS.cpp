#include <bits/stdc++.h>
using namespace std;

#define TAB '\t'
#define pb push_back
#define vi vector<int>
#define FEI(el,s) for(int el : s)
#define FOR(index,a,n) for (int index = a; index < n; index++)
#define NL cout<<endl
#define TEST(string) cout<<string

bool visited[20]{false};
vector<vi> graph;

void DFS(int node) {
	
	if(visited[node]) return;
	visited[node] = true;
	vi neighbors = graph[node];
	FEI(i,neighbors) DFS(i);
}

int main()
{
	// adjacency list for graph
	graph.pb(vi{1,9});	//0
	graph.pb(vi{0,8});	//1
	graph.pb(vi{3});	//2
	graph.pb(vi{2,4,5,7});	//3
	graph.pb(vi{3});	//4
	graph.pb(vi{3,6});	//5
	graph.pb(vi{5,7});	//6
	graph.pb(vi{3,6,10,11});	//7
	graph.pb(vi{7,9});	//8
	graph.pb(vi{8});	//9
	graph.pb(vi{7,11});	//10
	graph.pb(vi{7});	//11
	graph.pb(vi());	//12
	
	DFS(0);
	TEST("VISITED NODES"); NL;
	FOR(i,0,(int)graph.size()){
		cout<<i<<":"<<(visited[i] ? "VISITED" : "NOT VISITED");
		NL;
	}
}
