#include <bits/stdc++.h>

using namespace std;

void make_sets(vector<int> &p) {
  for (int i = 0; i < p.size(); i++) {
    p[i] = i;
  }
}

int find_set(vector<int> &p, int x) {
  return ((p[x] == x)? x : p[x] = find_set(p, p[x]));
}

int union_sets(vector<int> &p, int x, int y) {
  if (find_set(p, x) != find_set(p, y)) {
    p[find_set(p, y)] = find_set(p, x);
  }
}

bool same_component(vector<int> &p, int u, int v) {
  return find_set(p, u) == find_set(p, v);
}

void show_dsu(vector<int> &p) {
  for (int i = 0; i < p.size(); i++) {
    cout << find_set(p, p[i]) << " ";
  }
  cout << endl;
}

int main() {
  int nodes, edges, u, w, q;
  cin >> nodes >> edges;
  vector<int> p(nodes);
  make_sets(p);
  while (edges--) {
    cin >> u >> w;
    union_sets(p, u, w);
  }
  // queries
  while ((cin >> u >> w) && (u != -1 || w != -1)) {
    cout << ((same_component(p, u, w))? "same" : "not same") << endl;
  }
}
