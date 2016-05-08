#include <bits/stdc++.h>
#define N 1000
using namespace std;
/*
  when is used Weighted-union with path compression
  it take O(log*(N)) for each union find operation.
  Where N is the numbre of elements in the set.
  in real world log*(N) reaches at most up 5
*/
int p[N];
int rank[N];
// initialize each node as your self root
void initialize(int n) {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    rank[i] = 1;
  }
}

// find_set root of an element and path compression
int find_set(int elem) {
  return ((p[elem] == elem)? elem : p[elem] = find_set(p[elem]));
}

/* find_set iterative
  int find_set(int elem) {
  while (p[elem] != elem) {
    p[elem] = p[p[elem]];
    elem = p[elem];
  }
}
*/

void join_sets(int a, int b) {
  int pa = find_set(a);
  int pb = find_set(b);

  if (pa != pb) {
    p[pa] = pb;
    rank[pb] += rank[pa];
  } else {
    return;
  }
}

/* Weighted-join_sets(rank)
void join_sets(int a, int b) {
  int root_a = find_set(a);
  int root_b = find_set(b);
  if (rank[root_a] > rank[root_b]) {
    p[root_b] = root_a;
  } else {
    p[root_a] = root_b;
  }
  if (rank[root_a] == rank[root_b]) {
    rank[root_b] = rank[root_a] + 1;
  }
}
*/

// Are u and v in the same connected component?
bool same_component(int u, int v) {
  return find_set(u) == find_set(v);
}

void show_dsu(int nodes) {
  for (int i = 0; i < nodes; i++) {
    cout << find_set(i) << " ";
  }
  cout << endl;
}

int main() {
  int nodes, edges, u, w, q;
  cin >> nodes >> edges;
  initialize(nodes);
  while (edges--) {
    cin >> u >> w;
    join_sets(u, w);
  }
  // queries
  while ((cin >> u >> w) && (u != -1 || w != -1)) {
    cout << ((same_component(u, w))? "same :)" : "not same :(") << endl;
  }
  show_dsu(nodes);
  return 0;
}
