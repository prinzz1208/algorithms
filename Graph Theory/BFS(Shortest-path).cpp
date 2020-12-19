
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
int c = -1;
int prv[100]{-1};

void BFS(int node){ //start node and end node as arguments
	queue<int> q;
	q.push(node);
	
	visited[node] = true;
	while( !q.empty() ){
		int node = q.front();
		q.pop();
		vi neighbours = graph[node];
		
		FEI(el,neighbours){
			if(!visited[el]){
				q.push(el);
				visited[el] = true;
				prv[el] = node;
			}
		}
	}
}

void reconstructPath(int start, int end) {
	vi path;
	for (int i = end; i != -1; i = prv[i])
		path.pb(i);
	
	TEST("PATH"); NL;
	reverse(path.begin(),path.end());
	FEI(el,path) cout<<el<<TAB;
	NL;
	
}
int main()
{
	// adjacency list for graph
	graph.pb(vi{9,7,11});	//0
	graph.pb(vi{8,10});	//1
	graph.pb(vi{12,3});	//2
	graph.pb(vi{2,4,7});	//3
	graph.pb(vi());	//4
	graph.pb(vi());	//5
	graph.pb(vi{5,7});	//6
	graph.pb(vi{0,11,3});	//7
	graph.pb(vi{9,1,12});	//8
	graph.pb(vi{10,1,8});	//9
	graph.pb(vi{1,9});	//10
	graph.pb(vi{0,7});	//11
	graph.pb(vi{2,8});	//12
	
	int n = (int)graph.size();
	//DFS(0);
	
	
	//TEST("VISITED NODES"); NL;
	
	FOR(i,0,n){
		cout<<i<<":"<<(visited[i] ? "VISITED" : "NOT VISITED");
		NL;
	}
	BFS(0);
	reconstructPath(0,4);
	
}
