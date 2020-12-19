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
vi ordering;
vector<vi> graph;


void DFS(int node) {
	
	visited[node] = true;
	
	vi neighbours = graph[node];
	
	FEI(i,neighbours){
		if(!visited[i])	 DFS(i);
	}
	ordering.pb(node);
	
}

void topsort() {
	
	FOR(j,0, (int)graph.size()) {
		if(!visited[j]) {
			DFS(j);
		}
	}
	
}


int main()
{
	// adjacency list for graph
	graph.pb(vi{5,0});	//0
	graph.pb(vi{5,2});	//1
	graph.pb(vi{2,3});	//2
	graph.pb(vi{3,1});	//3
	graph.pb(vi{4,1});	//4
	graph.pb(vi{4,0});	//5
	//graph.pb(vi{5});	//6
	//graph.pb(vi{0});	//7
	//graph.pb(vi{7,9});	//8
	//graph.pb(vi{0});	//9
	//graph.pb(vi{1,9});	//10
	//graph.pb(vi());	//11
	//graph.pb(vi());	//12
	
	//DFS(0);
	//TEST("VISITED NODES"); NL;
	//FOR(i,0,(int)graph.size()){
		//cout<<i<<":"<<(visited[i] ? "VISITED" : "NOT VISITED");
		//NL;
	//}
	topsort();
	TEST("ORDERING"); NL;
	FEI(el , ordering) {
		cout<<el<<TAB;
	}
}

