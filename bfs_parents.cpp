#include <bits/stdc++.h>

using namespace std;

class Graph {
  int vertices;
  list<int> *adj;
  int *parent;

public:
  Graph(int v);
  void addEdge(int x, int y);
  void bfs(int start, int end);
  void route(int s);
};

Graph::Graph(int v) {
  vertices = v;
  adj = new list<int>[v];
  parent = new int[v];
}

void Graph::addEdge(int x, int y) {
  adj[x].push_back(y);
}

void Graph::route(int s) {
  stack<int> st;
  st.push(s);
  while (s != -1) {
    s = parent[s];
    st.push(s);
  }
  int n = st.size()-1;
  st.pop();
  for (int i = 0; i < n; ++i) {
    cout << st.top() << " ";
    st.pop();
  }
}

void Graph::bfs(int start, int end) {
  vector<bool> visited(vertices, false);
  queue<int> q;

  q.push(start);
  visited[start];
  parent[start] = -1;
  list<int>::iterator i;

  while (!q.empty()) {
    start = q.front();
    q.pop();
    for (i = adj[start].begin(); i != adj[start].end(); i++) {
      if (*i == end){
        parent[*i] = start;
        visited[*i] = true;
        route(start);
        break;
      }
      if(!visited[*i]){
        q.push(*i);
        parent[*i] = start;
        visited[*i] = true;
      }
    }
  }
}

int main() {
  int v, e, x, y, start, end;
  cin >> v >> e;
  Graph g(v);
  for (int i = 0; i < e; ++i) {
    cin >> x >> y;
    g.addEdge(x, y);
  }
  cin >> start >> end;
  g.bfs(start, end);
  return 0;
}
