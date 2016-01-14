#include <bits/stdc++.h>

using namespace std;

class Graph {
  list<int> *adj;
  int vertices;
  void init_visited();
public:
  bool *visited;
  Graph(int vertices);
  void add_edge(int v, int w);
  void dfs(int s);
};

Graph::Graph(int vertices) {
  this->vertices = vertices;
  adj = new list<int>[vertices];
  visited = new bool[vertices];
  init_visited();
}

void Graph::init_visited() {
  for (int i = 0; i < vertices; i++) {
    visited[i] = false;
  }
}

void Graph::add_edge(int v, int w) {
  adj[v].push_back(w);
  adj[w].push_back(v);
}

void Graph::dfs(int s) {
  visited[s] = true;
  list<int>::iterator it;
  for (it = adj[s].begin(); it != adj[s].end(); it++) {
    if (!visited[*it]) {
      dfs(*it);
    }
  }
}

int main() {
  int nodes, edges, x, y, components = 0;
  cin >> nodes >> edges;
  Graph g(nodes);
  while (edges--) {
    cin >> x >> y;
    g.add_edge(x, y);
  }

  for (int i = 0; i < nodes; i++) {
    if (!g.visited[i]) {
      g.dfs(i);
      components++;
    }
  }

  cout << "Number of connected components: " << components << endl;
  return 0;
}
