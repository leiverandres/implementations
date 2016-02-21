#include <bits/stdc++.h>
using namespace std;

int arr[100];
inr size[100];
// initialize parent of each node with itself
void initialize(int arr, int N) {
  for (int i = 0; i < N; i++) {
    arr[i] = i;
    size[i] = 1;
  }
}

// find root of an element and path compression
int find(int arr, int elem) {
  return ((arr[elem] == elem)? elem : arr[elem] = root(arr, elem));
}

void union(int arr, int a, int b) {
  int pa = find(arr, a);
  int pb = find(arr, b);

  if (pa != pb) {
    arr[pa] = pb;
    size[pb] += size[pa]; 
  } else {
    return;
  }
}

int main() {
  return 0;
}
