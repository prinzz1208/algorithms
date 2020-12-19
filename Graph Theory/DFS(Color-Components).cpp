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
int components[100];



void DFS(int node) {
	//TEST("NODE")<<node; NL;
	//if(visited[node]) return;
	visited[node] = true;
	components[node] = c;
	vi neighbours = graph[node];
	FEI(i,neighbours) if(!visited[i]) DFS(i);
	
}


void findComponenets(int n) {
	FOR(i,0,n){
		if(!visited[i]){
			c++;
			DFS(i);
		}
	}
	TEST("Count:")<<c; NL;
	TEST("Components:");
	FOR(i,0,n) cout<<components[i]<<TAB;
	NL;
}

int main()
{
	// adjacency list for graph
	graph.pb(vi{8});	//0
	graph.pb(vi{5});	//1
	graph.pb(vi{9});	//2
	graph.pb(vi{9});	//3
	graph.pb(vi{0});	//4
	graph.pb(vi{16,17});	//5
	graph.pb(vi{11});	//6
	graph.pb(vi{6});	//7
	graph.pb(vi{4,14});	//8
	graph.pb(vi{15});	//9
	graph.pb(vi());	//10
	graph.pb(vi{7});	//11
	graph.pb(vi());	//12
	graph.pb(vi{0});	//13
	graph.pb(vi{0,13});	//14
	graph.pb(vi{2,10});	//15
	graph.pb(vi());	//16
	
	int n = (int)graph.size();
	
	//DFS(0);
	
	
	findComponenets(n);
	TEST("VISITED NODES"); NL;
	
	FOR(i,0,n){
		cout<<i<<":"<<(visited[i] ? "VISITED" : "NOT VISITED");
		NL;
	}
	
}
