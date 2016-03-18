/*
* Tested with http://www.spoj.com/problems/EZDIJKST/
*/
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << x << endl
#define INF INT_MAX

using namespace std;

struct Edge {
  int to, dist;
  Edge() {}
  Edge(int t,int d): to(t), dist(d) {}
  bool operator < (const Edge &e) const {
    return dist > e.dist;
  }
};

int dijkstra(int s, int t,vector <vector<Edge> > &adj, vector<int> &d, vector<int> &p) {
  priority_queue<Edge> pq;
  d[s] = 0;
  pq.push(Edge(s, 0));
  while (!pq.empty()) {
    int cur = pq.top().to;
    int dist = pq.top().dist;
    pq.pop();
    if (cur == t) {
      if (dist > d[cur]) continue;
      // cout << "Path: " << endl;
      // while (cur != -1) {
      //   cout << cur << " ";
      //   cur = p[cur];
      // }
      // cout << endl;
      return dist;
    }
    for (int i = 0; i < adj[cur].size(); i++) {
      int to = adj[cur][i].to;
      int weight_extra = adj[cur][i].dist;
      if (dist + weight_extra < d[to]) {
        d[to] = dist + weight_extra;
        p[to] = cur;
        pq.push(Edge(to, d[to]));
      }
    }
  }
  return INF;
}

int main() {
  int nodes, edges, tc, s, t, a, b, w;
  cin >> tc;
  while (tc--) {
    cin >> nodes >> edges;

    vector <vector<Edge> > adj(nodes, vector<Edge>());
    vector<int> d(nodes, INF);
    vector<int> p(nodes, -1);

    for (int i = 0; i < edges; i++) {
      cin >> a >> b >> w;
      adj[a-1].push_back(Edge(b-1, w));
    }

    cin >> s >> t;
    int ans = dijkstra(s-1, t-1, adj, d, p);

    if (ans == INF) {
      cout << "NO" << endl;
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}
