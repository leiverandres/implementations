#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

const string alpha = "abc";

bool match(vector<vector<int> > &P, string &T) {
  int state = 0;
  for (int i = 0; i < T.size(); ++i) {
    state = P[state][T[i] - 'a'];
    D(state);
    D(T[i] - 'a');
    if (state == P.size() - 1) {
      return true;
    }
  }
  return false;
}

vector<vector<int> > build_automata(string &s) {
  vector<vector<int> > g(s.size() + 1, vector<int> (alpha.size()));

  for (int i = 0; i < s.size(); ++i) {
      string cur = s.substr(0, i);
      for (int j = 0; j < alpha.size(); ++j) {
        string next = cur;
        next.push_back(alpha[j]);
        int best = 0;
        for (int k = 1; k <= next.size(); ++k) {
          string suffix = next.substr(next.size() - k, k);
          string preffix = s.substr(0, k);
          if (suffix == preffix) {
            best = k;
          }
        }
        g[i][j] = best;
      }
  }
  return g;
}

int main() {
  string pattern, text;
  while (cin >> pattern >> text) {
    cout << "p " << pattern << endl;
    cout << "t " << text << endl;
    vector<vector<int> > automata = build_automata(pattern);
    cout << "Automata" << endl;
    for (int i = 0; i < automata.size(); i++) {
      for (int j = 0; j < automata[i].size(); j++) {
        cout << automata[i][j] << " ";
      }
      cout << endl;
    }
    cout << ((match(automata, text))? "Match" : "Not match :(") << endl;
  }
  return 0;
}
