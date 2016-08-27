#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
/*
Detect Cycle in a Directed Graph
*/
using namespace std;

bool hasCycle(int node, vector<bool> &vi,
              vector<bool> &inExpan, vector<vector<int>> &g) {
  vi[node] = true;
  inExpan[node] = true;
  for (const auto &w : g[node]) {
    if (!vi[w] and hasCycle(w, vi, inExpan, g)) {
      return true;
    } else if (inExpan[w]) {
      return true;
    }
  }
  inExpan[node] = false;
  return false;
}

int main(int argc, char const *argv[]) {
  fast;
  int tc, nodes, vertices, u, v;
  cin >> tc;
  while (tc--) {
    cin >> nodes >> vertices;
    vector<vector<int>> g(nodes, vector<int> ());
    vector<bool> visited(nodes, false);
    vector<bool> inExpansion(nodes, false);

    for (int i = 0; i < vertices; i++) {
      cin >> u >> v;
      g[u-1].push_back(v-1);
    }
    bool cycle = false;
    for (int i = 0; i < vertices; i++) {
      if (!visited[i]) {
        if (hasCycle(i, visited, inExpansion,g)) {
          cycle = true;
          break;
        }
      }
    }

    cout << ((cycle)? "SIM" : "NAO") << endl;
  }
  return 0;
}
