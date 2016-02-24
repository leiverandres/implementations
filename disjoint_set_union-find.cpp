#include <bits/stdc++.h>
using namespace std;
/*
  when is used Weighted-union with path compression
  it take O(log*(N)) for each union find operatin.
  Where N is the numbre of elements in the set.
  in real world log*(N) reaches at most up 5
*/
int arr[100];
inr size[100];
// initialize each node as your self root
void initialize(int N) {
  for (int i = 0; i < N; i++) {
    arr[i] = i;
    size[i] = 1;
  }
}

// find root of an element and path compression
int find(int elem) {
  return ((arr[elem] == elem)? elem : arr[elem] = find(arr[elem]));
}

/* find iterative
  int find(int elem) {
  while (arr[elem] != elem) {
    arr[elem] = arr[arr[elem]];
    elem = arr[elem];
  }
}
*/

void join(int a, int b) {
  int pa = find(a);
  int pb = find(b);

  if (pa != pb) {
    arr[pa] = pb;
    size[pb] += size[pa];
  } else {
    return;
  }
}

/* Weighted-join(rank)
void join(int a, int b) {
  int root_a = find(a);
  int root_b = find(b);
  if (size[root_a] < size[root_b]) {
    arr[root_a] = arr[root_b];
    size[root_b] += arr[root_a];
  } else {
    arr[root_b] = arr[root_a];
    size[root_a] += size[root_b];
  }
}

*/

int main() {
  return 0;
}
