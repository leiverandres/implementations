#include <bits/stdc++.h>
/*
  Builds a Trie from several patterns and print the links
  this way (source->target:value)
*/
using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  t.push_back(map<char, int>()); // init with root
  for (const auto & p : patterns) {
    int currentNode = 0;
    for (int i = 0; i < p.size(); i++) {
      char currentSymbol = p[i];
      if (t[currentNode].count(currentSymbol)) {
        currentNode = t[currentNode][currentSymbol];
      } else {
        t.push_back(map<char, int>());
        t[currentNode][currentSymbol] = t.size() - 1;
        currentNode = t.size() - 1;
        cout << currentSymbol << " no esta agrego edge a " << currentNode << endl;
      }
    }
  }

  return t;
}

int main() {
  size_t n;
  string s;
  cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
