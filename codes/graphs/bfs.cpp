#include <bits/stdc++.h>
/*
APPLICATIONS OF BFS
http://www.geeksforgeeks.org/applications-of-breadth-first-traversal/
*/
using namespace std;

class Graph {
  int nvertices;
  list<int> *adj;

public:
  Graph(int v);
  void add_edge(int v, int w, bool directed);
  void bfs(int s);
};

Graph::Graph(int v) {
  this->nvertices = v;
  adj = new list<int>[v];
}

void Graph::add_edge(int v, int w, bool directed) {
  adj[v].push_back(w);
  if (!directed)
    add_edge(w, v, true);
}

void Graph::bfs(int s) {
  vector<bool> visited(nvertices, false);
  queue<int> q;

  q.push(s);
  visited[s] = true;
  list<int>::iterator it;

  while (!q.empty()) {
    s = q.front();
    cout << s << " ";
    q.pop();
    for (it = adj[s].begin(); it != adj[s].end(); ++it) {
      if (!visited[*it]) {
        visited[*it] = true;
        q.push(*it);
      }
    }
  }
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
      g.add_edge(x, y, true);
    }

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.bfs(2);

    return 0;
}
