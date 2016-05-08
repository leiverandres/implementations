#include <bits/stdc++.h>
#define N 1000
using namespace std;

class Graph {
  int vertices;
  list<int> *adj;
  vector<int> time_init,
              time_fin,
              state;
public:
  Graph(int vertices) {
    this->vertices = vertices;
    adj = new list<int> [vertices];
    time_init.assign(vertices, -1);
    time_fin.assign(vertices, -1);
    state.assign(vertices, 0);
  }
};

int main() {
  int nodes, edges, u, w;
  cin >> nodes >> edges;
  cout << adj.size() << endl;

  while (edges--) {
    cin >> u >> w;
  }
  return 0
}
