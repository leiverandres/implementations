#include <bits/stdc++.h>

using namespace std;

class Graph {
  int nvertices;
  list<int> *adj;
  vector<bool> visited;
  int *level;
public:
  Graph(int v);
  void add_edge(int v, int w, bool directed);
  void bfs(int s);
  void show_levels();
};

Graph::Graph(int v) {
  this->nvertices = v;
  adj = new list<int>[v];
  level = new int[v];
  visited.assign(v, false);
}

void Graph::add_edge(int v, int w, bool directed) {
  adj[v].push_back(w);
  if (!directed)
    add_edge(w, v, true);
}

void Graph::bfs(int s) {
  queue<int> q;
  list<int>::iterator i;

  q.push(s);
  level[s] = 0;
  visited[s] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (i = adj[cur].begin(); i != adj[cur].end(); i++) {
      if (!visited[*i]) {
        level[*i] = level[cur] + 1;
        q.push(*i);
        visited[*i] = true;
      }
    }
  }
}

void Graph::show_levels() {
  for (int i = 0; i < nvertices; i++) {
    cout << "Nodo " << i << " con nivel " << level[i] << endl;
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

  g.bfs(0);
  g.show_levels();

  return 0;
}
