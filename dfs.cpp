#include <bits/stdc++.h>

using namespace std;
/*
  APPLICATIONS OF DFS
  http://www.geeksforgeeks.org/applications-of-depth-first-search/
*/
class Graph {
  int vertices;
  list<int> *adj;
  void dfs_util(int s, bool visited[]);
public:
  Graph(int v);
  void add_edge(int v, int w);
  void dfs(int s);
};

Graph::Graph(int v) {
  vertices = v;
  adj = new list<int>[v];
}

void Graph::add_edge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::dfs_util(int s, bool visited[]) {
  visited[s] = true;
  cout << s << " ";
  list<int>::iterator i;
  for (i = adj[s].begin(); i != adj[s].end(); ++i) {
    if (!visited[*i]) {
      dfs_util(*i, visited);
    }
  }
}

void Graph::dfs(int s) {
  bool *visited = new bool[vertices];
  for (int i = 0; i < vertices; ++i)
    visited[i] = false;

  dfs_util(s, visited);
}

int main() {
  int v, e, x, y;
  cout << "Number of vertices: ";
  cin >> v;
  cout << "Number of Edges: ";
  cin >> e;
  Graph g(v);
  for (int i = 0; i < e; ++i) {
    cin >> x >> y;
    g.add_edge(x, y);
  }

  cout << "Following is Depth First Traversal (starting from vertex 2) \n";
  g.dfs(2);
  return 0;
}
