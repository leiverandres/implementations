#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 2147483647;

ll power(ll base, ll expo) {
  ll ans = 1;
  while (expo) {
    if (expo & 1) {
      ans *= base;
      ans %= mod;
    }
    expo >>= 1;
    base = base * base;
    base %= mod;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll expo, base;
  cin >> base >> expo;
  cout << power(base, expo) << endl;
  return 0;
}
