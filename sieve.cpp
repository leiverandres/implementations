#include <bits/stdc++.h>
#define N 1000

using namespace std;

int main() {
  int count = 0;
  vector<bool> sieve(N+1, false);
  vector<int> primes;
  sieve[0] = sieve[1] = true;
  for (int i = 2; i <= N; i++) {
    if (!sieve[i]) {
      count++;
      primes.push_back(i);
      for (int j = i*2; j <= N; j += i) {
        sieve[j] = true;
      }
    }
  }
  for (int i = 0; i < primes.size(); i++) {
    cout << primes[i] << " ";
  }
  cout << endl;
  return 0;
}
