#include <bits/stdc++.h>
#define N 1000
using namespace std;
// longest substring palindrome
int memo[N][N];

int dp_pal(int i, int j, string &t) {
  if (j <= i) return 1;
  if (memo[i][j] != -1) return memo[i][j];
  if (t[i] != t[j])
    return memo[i][j] = 0;
  return memo[i][j] = dp_pal(i+1, j-1, t);
}

int main() {
  int q, a, b;
  string t;
  cin >> t;
  memset(memo, -1, sizeof(memo));
  for (int i = 0; i < t.size(); i++) {
    for (int j = t.size() - 1; j >= i; j--) {
      dp_pal(i, j, t);
    }
  }
  cin >> q;
  while (q--) {
    cin >> a >> b;
    cout << ((memo[a][b])? "YES": "NO") << endl;
  }
  return 0;
}
